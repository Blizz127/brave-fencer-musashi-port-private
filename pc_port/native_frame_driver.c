/* Strict-native frame driver (docs/NATIVE-FRAME-DRIVER.md).
 *
 * Owner-written, clean room, from the retail disassembly of main (80010178,
 * -O0) and of the short Sony entry points it replaces; no vendor C and no
 * Sony source or SDK material. Every guest call goes through the native lane
 * table (musashi_native_lane_invoke); a callee the lane cannot run stops the
 * process with seam=frame_driver. Built only with MUSASHI_STRICT_NATIVE. */
#include "musashi_native_frame_driver.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musashi_native_lane_psyq.h"
#include "musashi_strict.h"

#ifndef MUSASHI_STRICT_NATIVE
#error "native_frame_driver.c is part of the strict-native build only"
#endif

/* ---- guest addresses (main's retail words) ------------------------------ */
enum {
    MAIN_STATE          = 0x800AF630u, /* s1 in main: the game state block */
    CTOR_DONE           = 0x80062998u, /* __main's run-once flag (800100A0) */
    OT_TAIL_INDEX       = 0x80074778u, /* = 0x3E0 at init; CatPrim's tail slot */
    INIT_RESULT         = 0x800A2B7Cu, /* main stores 80043300()'s v0 here */
    FRAME_COUNT         = 0x800C7C70u, /* never 0 */
    BUFFER_INDEX        = 0x800C7C74u, /* s16, toggled each frame */
    PRIM_CURSOR         = 0x800A5E60u, /* primitive area for this buffer */
    PRIM_AREA           = 0x8007BA70u, /* + idx * 80000 */
    PACKET_AREA         = 0x800A4F48u, /* + idx * 1600, slot word 2 */
    OT_TABLE            = 0x800A651Cu, /* 20-byte rows: [0] ot, [3] ot (alt) */
    OT_MAIN             = 0x800A6610u, /* + idx * 0x4000, 4096 entries */
    OT_ALT              = 0x800AA60Cu, /* + idx * 0x4000 */
    OT2_TABLE           = 0x800AE7BCu, /* 20-byte rows: [0] ot2, [3] ot2b */
    OT2_AREA            = 0x800BA0D8u, /* + idx * 16, 4 entries */
    OT2B_AREA           = 0x800BA0E4u, /* + idx * 16 */
    SCRATCH_SP          = 0x1F8003FCu, /* main's scratchpad stack */
    /* crt0 (80010000..8001009F), checked against the retail words: it
     * clears [BSS_LO, BSS_HI) (BSS_LO is also gp), sets
     * sp = (RAM_SIZE_VAR - 8) | 0x80000000 (the EXE header's s_addr
     * 0x801FFFF0 is overridden), stores the heap base BSS_HI and the heap
     * size (RAM_SIZE_VAR - 8 - STACK_SIZE_VAR - (BSS_HI & 0x1FFFFFFF)),
     * saves ra at gp[0] and calls main (80010178), whose frame is 56. */
    BSS_LO              = 0x80074750u,
    BSS_HI              = 0x800C7F08u,
    HEAP_BASE_VAR       = 0x8006299Cu,
    HEAP_SIZE_VAR       = 0x800629A0u,
    RAM_SIZE_VAR        = 0x800629BCu, /* 0x00200000 in the retail EXE */
    STACK_SIZE_VAR      = 0x800629C0u, /* 0x00000C00 in the retail EXE */
    MAIN_FRAME          = 56u
};
#define MAIN_SP (g_driver.main_sp)

/* main's state block offsets */
enum {
    ST_DISP_CUR   = 0x188, /* u16 display buffer */
    ST_DRAW_CUR   = 0x18A, /* u16 draw buffer (0/1) */
    ST_DRAWENV    = 0x038, /* 2 x DRAWENV (92 bytes) */
    ST_DISPENV    = 0x14C, /* 2 x DISPENV (20 bytes) */
    ST_TICKS      = 0xA3A8, /* u16 += 1 per game frame */
    ST_TICK_SUM   = 0xA3AC, /* u16 += ticks */
    ST_IDX_COPY   = 0xA3D2, /* u16 buffer index, reread by main every use */
    ST_SESSION_END= 0xA3D4, /* u16: nonzero ends the inner loop */
    ST_ALT_FRAME  = 0xA3E3, /* u8: nonzero runs the overlay frame */
    ST_VSYNC_MODE = 0xA3E8  /* s32: main's VSync argument */
};

/* the guest functions main calls */
enum {
    F_CTORS        = 0x800100A0u,
    F_RESETCB      = 0x80043060u,
    F_STARTUP      = 0x800141F0u,
    F_8005FC68     = 0x8005FC68u,
    F_8005FCB8     = 0x8005FCB8u,
    F_80018918     = 0x80018918u,
    F_80043300     = 0x80043300u,
    F_8002C8F4     = 0x8002C8F4u,
    F_8001971C     = 0x8001971Cu,
    F_SESSION      = 0x80014238u,
    F_80014390     = 0x80014390u,
    F_800191A8     = 0x800191A8u,
    F_80010A98     = 0x80010A98u,
    F_PAD_POLL     = 0x800189A8u,
    F_80015208     = 0x80015208u,
    F_CLEAR_OTAGR  = 0x80059BFCu,
    F_80010B40     = 0x80010B40u,
    F_80015498     = 0x80015498u,
    F_8001C00C     = 0x8001C00Cu,
    F_OVL_FRAME    = 0x800D25FCu,
    F_FRAME_END    = 0x800184F0u,
    F_DRAWSYNC     = 0x800596F4u,
    F_VSYNC        = 0x8004239Cu,
    F_PUTDISPENV   = 0x80059FC0u,
    F_PUTDRAWENV   = 0x80059D68u,
    F_CATPRIM      = 0x80058CE4u,
    F_DRAWOTAG     = 0x80059CF4u,
    F_8003500C     = 0x8003500Cu,
    F_SOUND_TICK   = 0x8002D034u,
    F_8001AF34     = 0x8001AF34u,
    F_8001513C     = 0x8001513Cu,
    F_SESSION_EXIT = 0x80042610u
};

typedef struct Driver {
    MusashiBootMemory *memory;
    const MusashiStartupPrefixDevice *devices;
    const MusashiFrameDriverOps *ops;
    uint32_t pad_buf[2];   /* PadInitDirect's receive buffers (0: none) */
    unsigned long frames, frame_limit;
    uint32_t main_sp; /* crt0 stack top - main's 56-byte frame */
    int quit;
} Driver;

static Driver g_driver;

/* ---- guest RAM ------------------------------------------------------------ */
static void driver_stop(const char *what, uint32_t pc) {
    musashi_strict_abort("frame_driver", what, pc);
}

static uint32_t rd32(uint32_t a) {
    uint32_t v;
    if (!musashi_boot_read32(g_driver.memory, a, &v)) driver_stop("guest_read", a);
    return v;
}
static uint16_t rd16(uint32_t a) {
    uint16_t v;
    if (!musashi_boot_read16(g_driver.memory, a, &v)) driver_stop("guest_read", a);
    return v;
}
static uint8_t rd8(uint32_t a) {
    uint8_t *p = musashi_boot_ram_span(g_driver.memory, a, 1);
    if (!p) driver_stop("guest_read", a);
    return *p;
}
static void wr32(uint32_t a, uint32_t v) {
    if (!musashi_boot_write32(g_driver.memory, a, v)) driver_stop("guest_write", a);
}
static void wr16(uint32_t a, uint16_t v) {
    if (!musashi_boot_write16(g_driver.memory, a, v)) driver_stop("guest_write", a);
}
static void wr8(uint32_t a, uint8_t v) {
    uint8_t *p = musashi_boot_ram_span(g_driver.memory, a, 1);
    if (!p) driver_stop("guest_write", a);
    *p = v;
}

/* ---- lane-table dispatch ---------------------------------------------- */
static char g_stop_name[96];

static uint32_t call_at(uint32_t sp, uint32_t pc, unsigned argc, const uint32_t *args) {
    uint32_t v0 = 0;
    int ran = musashi_native_lane_invoke(g_driver.memory, g_driver.devices, pc, args, argc, sp, &v0);
    if (ran > 0) return v0;
    if (ran < 0 && musashi_native_lane_last_abort() == 5) {
        /* a host stop requested from inside the call (quit) */
        g_driver.quit = 1;
        return 0;
    }
    {
        const char *held = musashi_native_lane_psyq_held_back(pc);
        snprintf(g_stop_name, sizeof g_stop_name, "%s func_%08X%s%s",
                 ran < 0 ? "lane_abort" : "not_in_lane", (unsigned)pc,
                 held ? " psyq=" : "", held ? held : "");
    }
    driver_stop(g_stop_name, pc);
    return 0;
}

static uint32_t call0(uint32_t pc) { return call_at(MAIN_SP, pc, 0, NULL); }
static uint32_t call1(uint32_t pc, uint32_t a0) {
    uint32_t a[1] = {a0};
    return call_at(MAIN_SP, pc, 1, a);
}
static uint32_t call2(uint32_t pc, uint32_t a0, uint32_t a1) {
    uint32_t a[2] = {a0, a1};
    return call_at(MAIN_SP, pc, 2, a);
}
/* main switches sp to the scratchpad around three calls: it saves its sp at
 * 1F8003FC and enters the callee with sp = 1F8003FC (the delay slot adds 4
 * back). The host keeps main's sp itself, so only the entry sp matters. */
static void call_scratch(uint32_t pc) {
    /* the scratchpad page itself (the lane aliases it at host 1F800000) */
    uint8_t *word = g_driver.memory->scratchpad + (SCRATCH_SP - 0x1F800000u);
    word[0] = (uint8_t)MAIN_SP;
    word[1] = (uint8_t)(MAIN_SP >> 8);
    word[2] = (uint8_t)(MAIN_SP >> 16);
    word[3] = (uint8_t)(MAIN_SP >> 24);
    (void)call_at(SCRATCH_SP, pc, 0, NULL);
}

/* ---- PsyQ replacements (lane entries) ----------------------------------- */
/* Each mirrors the observable effect of the retail entry point on the
 * port's device owners; see musashi_frame_driver_lane_entries(). */

static int hle_init_heap(MusashiNativeLaneCall *call) {
    /* 8005CE18: li t2,0xA0; jr t2; li t1,0x39: BIOS A0:39 InitHeap(base,
     * size). The selected BIOS preserves v0. */
    const MusashiHeapDevice *heap = g_driver.devices ? g_driver.devices->heap : NULL;
    if (!heap || !heap->init_heap ||
        !heap->init_heap(heap->userdata, call->r[4], call->r[5]))
        driver_stop("InitHeap_refused", 0x8005CE18u);
    return 1;
}

static int hle_enter_critical(MusashiNativeLaneCall *call) {
    /* 8005CF08: li a0,1; syscall: SYS1 EnterCriticalSection; v0 = whether
     * interrupts were enabled. */
    const MusashiCdDevice *cd = g_driver.devices ? g_driver.devices->cd : NULL;
    int32_t previous = 0;
    if (!cd || !cd->enter_critical_result ||
        !cd->enter_critical_result(cd->userdata, &previous))
        driver_stop("EnterCriticalSection_refused", 0x8005CF08u);
    call->r[4] = 1u;
    call->r[2] = (uint32_t)previous;
    return 1;
}

static int hle_exit_critical(MusashiNativeLaneCall *call) {
    /* 8005CF18: li a0,2; syscall: SYS2 ExitCriticalSection. */
    const MusashiCallbackDevice *cb = g_driver.devices ? g_driver.devices->callback : NULL;
    if (!cb || !cb->exit_critical_section || !cb->exit_critical_section(cb->userdata))
        driver_stop("ExitCriticalSection_refused", 0x8005CF18u);
    call->r[4] = 2u;
    return 1;
}

static int hle_cd_mix(MusashiNativeLaneCall *call) {
    /* 80043974 CdMix(vol) calls 80044A8C, which writes the CD audio volume
     * matrix through the four register pointers at 8006CF4C..8006CF58
     * (index/data ports): [0]=2, [2]=vol[0], [3]=vol[1], [0]=3, [1]=vol[2],
     * [2]=vol[3], [3]=0x20 (apply). CdMix returns 1. */
    const struct MusashiCdRegisterDevice *regs =
        g_driver.devices ? g_driver.devices->cd_registers : NULL;
    uint32_t vol = call->r[4];
    uint32_t r0 = rd32(0x8006CF4Cu), r1 = rd32(0x8006CF50u);
    uint32_t r2 = rd32(0x8006CF54u), r3 = rd32(0x8006CF58u);
    if (regs && regs->write8) {
        if (!regs->write8(regs->userdata, r0, 2u) ||
            !regs->write8(regs->userdata, r2, rd8(vol + 0u)) ||
            !regs->write8(regs->userdata, r3, rd8(vol + 1u)) ||
            !regs->write8(regs->userdata, r0, 3u) ||
            !regs->write8(regs->userdata, r1, rd8(vol + 2u)) ||
            !regs->write8(regs->userdata, r2, rd8(vol + 3u)) ||
            !regs->write8(regs->userdata, r3, 0x20u))
            driver_stop("CdMix_register_refused", 0x80043974u);
    }
    /* No CD drive owner (no disc): the mix has nowhere to go; same result. */
    call->r[2] = 1u;
    return 1;
}

/* libpad, direct mode. The driver owns both receive buffers: each frame it
 * writes the host pad in the controller's wire form (byte 0 = 0x00 when a
 * pad answered, 0xFF when none did; byte 1 = id; bytes 2.. = data). */
static void pad_fill(unsigned port) {
    uint32_t buf = g_driver.pad_buf[port];
    uint8_t wire[8];
    size_t n = 0, i;
    if (!buf) return;
    if (g_driver.ops && g_driver.ops->pad_wire)
        n = g_driver.ops->pad_wire(g_driver.ops->user, port, wire);
    if (n < 4u) {
        wr8(buf, 0xFFu);
        return;
    }
    wr8(buf, 0x00u);
    wr8(buf + 1u, wire[0]);
    for (i = 2; i < n; ++i) wr8(buf + (uint32_t)i, wire[i]);
}

static int pad_connected(unsigned port) {
    uint8_t wire[8];
    return g_driver.ops && g_driver.ops->pad_wire &&
           g_driver.ops->pad_wire(g_driver.ops->user, port, wire) >= 4u;
}

static int hle_pad_init_direct(MusashiNativeLaneCall *call) {
    /* PadInitDirect(buf1, buf2): remembers the two receive buffers. */
    g_driver.pad_buf[0] = call->r[4];
    g_driver.pad_buf[1] = call->r[5];
    fprintf(stderr, "native_boot: FRAME_DRIVER PadInitDirect buf1=%08x buf2=%08x\n",
            call->r[4], call->r[5]);
    if (g_driver.pad_buf[0]) wr8(g_driver.pad_buf[0], 0xFFu);
    if (g_driver.pad_buf[1]) wr8(g_driver.pad_buf[1], 0xFFu);
    return 1;
}

static int hle_pad_start_stop(MusashiNativeLaneCall *call) {
    /* PadStartCom/PadStopCom: the driver exchanges at its frame boundary. */
    (void)call;
    return 1;
}

static int hle_pad_get_state(MusashiNativeLaneCall *call) {
    /* PadGetState(port): 2 (FindCTP1, a pad without extended functions,
     * its settled state) when the host pad answers, 0 (Discon) otherwise. */
    uint32_t port = call->r[4];
    call->r[2] = (port & 0x0Fu) == 0u && (port >> 4) < 2u && pad_connected(port >> 4) ? 2u : 0u;
    return 1;
}

static int hle_pad_info_mode(MusashiNativeLaneCall *call) {
    /* PadInfoMode(port, term, offs): 1 = current id (4: digital pad);
     * 2 = current extended id, 3 = its offset, 4 = id table: none (0). */
    uint32_t port = call->r[4], term = call->r[5];
    uint8_t wire[8];
    uint32_t v = 0;
    if (term == 1u && (port >> 4) < 2u && g_driver.ops && g_driver.ops->pad_wire &&
        g_driver.ops->pad_wire(g_driver.ops->user, port >> 4, wire) >= 4u)
        v = wire[0] >> 4;
    call->r[2] = v;
    return 1;
}

static int hle_pad_set_act(MusashiNativeLaneCall *call) {
    /* PadSetAct(port, data, len) / PadSetActAlign(port, data): accepted;
     * a pad without actuators ignores them. */
    call->r[2] = 1u;
    return 1;
}

static int hle_exchange_cbe8(MusashiNativeLaneCall *call) {
    /* 80043060: v0 = *(s32 *)8006CBE8; *(s32 *)8006CBE8 = a0 (main calls it
     * with 0). The interpreter answers it with the same decomp-owned
     * exchange (musashi_boot_call_80043060). */
    int32_t previous = 0;
    if (!musashi_boot_call_80043060(g_driver.memory, (int32_t)call->r[4], &previous))
        driver_stop("exchange_8006CBE8_refused", 0x80043060u);
    call->r[2] = (uint32_t)previous;
    return 1;
}

static const MusashiNativeLaneEntry k_driver_entries[] = {
    {0x80043060u, 0, hle_exchange_cbe8,   "exchange_8006CBE8",   1, 1, 0},
    {0x80043974u, 0, hle_cd_mix,          "CdMix",               1, 1, 0},
    {0x8005CE18u, 0, hle_init_heap,       "InitHeap",            2, 0, 0},
    {0x8005CF08u, 0, hle_enter_critical,  "EnterCriticalSection",0, 1, 0},
    {0x8005CF18u, 0, hle_exit_critical,   "ExitCriticalSection", 0, 0, 0},
    {0x8005D0F8u, 0, hle_pad_start_stop,  "PadStartCom",         0, 0, 0},
    {0x8005D118u, 0, hle_pad_start_stop,  "PadStopCom",          0, 0, 0},
    {0x8005D184u, 0, hle_pad_get_state,   "PadGetState",         1, 1, 0},
    {0x8005D244u, 0, hle_pad_info_mode,   "PadInfoMode",         3, 1, 0},
    {0x8005D4B8u, 0, hle_pad_set_act,     "PadSetActAlign",      2, 1, 0},
    {0x8005D538u, 0, hle_pad_set_act,     "PadSetAct",           3, 1, 0},
    {0x8005F0C8u, 0, hle_pad_init_direct, "PadInitDirect",       2, 0, 0},
};

size_t musashi_frame_driver_lane_entries(MusashiNativeLaneEntry *out, size_t cap) {
    size_t n = sizeof k_driver_entries / sizeof k_driver_entries[0];
    if (out) memcpy(out, k_driver_entries, (cap < n ? cap : n) * sizeof *out);
    return n;
}

/* ---- main ------------------------------------------------------------------ */
static uint32_t buffer_index(void) { return rd16(MAIN_STATE + ST_IDX_COPY); }

static void vsync_point(void) {
    /* VSync(p[0xA3E8]). mode < 0 only reads the counter (the lane's VSync
     * HLE); 0 waits one field, 1 returns at once, n > 1 waits n fields. The
     * wait becomes the platform's present + pace, then guest time moves. */
    int32_t mode = (int32_t)rd32(MAIN_STATE + ST_VSYNC_MODE);
    unsigned fields;
    if (mode < 0) {
        (void)call1(F_VSYNC, (uint32_t)mode);
        return;
    }
    fields = mode == 0 ? 1u : mode == 1 ? 0u : (unsigned)mode;
    if (g_driver.ops && g_driver.ops->frame_end &&
        g_driver.ops->frame_end(g_driver.ops->user, fields))
        g_driver.quit = 1;
    if (fields && g_driver.ops && g_driver.ops->vblank &&
        !g_driver.ops->vblank(g_driver.ops->user, fields))
        driver_stop("vblank_refused", F_VSYNC);
}

static void main_frame(void) {
    uint32_t count, idx, ot;
    uint16_t cur;

    /* frame counter (never 0) and buffer index */
    count = rd32(FRAME_COUNT) + 1u;
    wr32(FRAME_COUNT, count);
    if (rd32(FRAME_COUNT) == 0u) wr32(FRAME_COUNT, 1u);
    wr16(BUFFER_INDEX, (uint16_t)((int16_t)rd16(BUFFER_INDEX) == 0));
    wr16(MAIN_STATE + ST_IDX_COPY, rd16(BUFFER_INDEX));
    idx = buffer_index();
    wr32(PRIM_CURSOR, PRIM_AREA + idx * 80000u);
    wr32(MAIN_STATE + buffer_index() * 12u + 8u, PACKET_AREA + buffer_index() * 1600u);
    wr32(MAIN_STATE + buffer_index() * 12u + 0u, 1600u);
    wr32(MAIN_STATE + buffer_index() * 12u + 4u, 0u);

    /* 800189A8 is the FRAME_BEGIN point: the host pad lands first */
    if (g_driver.ops && g_driver.ops->frame_begin && g_driver.ops->frame_begin(g_driver.ops->user)) {
        g_driver.quit = 1;
        return;
    }
    pad_fill(0);
    pad_fill(1);
    (void)call0(F_PAD_POLL);
    (void)call0(F_80015208);

    if (rd8(MAIN_STATE + ST_ALT_FRAME) == 0u) {
        wr16(MAIN_STATE + ST_TICKS, (uint16_t)(rd16(MAIN_STATE + ST_TICKS) + 1u));
        wr16(MAIN_STATE + ST_TICK_SUM,
             (uint16_t)(rd16(MAIN_STATE + ST_TICK_SUM) + rd16(MAIN_STATE + ST_TICKS)));
        wr32(OT_TABLE + buffer_index() * 20u, OT_MAIN + buffer_index() * 0x4000u);
        wr32(OT_TABLE + 12u + buffer_index() * 20u, OT_ALT + buffer_index() * 0x4000u);
        (void)call2(F_CLEAR_OTAGR, rd32(OT_TABLE + buffer_index() * 20u), 4096u);
        wr32(OT2_TABLE + buffer_index() * 20u, OT2_AREA + buffer_index() * 16u);
        wr32(OT2_TABLE + 12u + buffer_index() * 20u, OT2B_AREA + buffer_index() * 16u);
        (void)call2(F_CLEAR_OTAGR, rd32(OT2_TABLE + buffer_index() * 20u), 4u);
        (void)call0(F_80010B40);
        call_scratch(F_80015498);
        call_scratch(F_8001C00C);
    } else {
        wr32(OT2_TABLE + buffer_index() * 20u, OT2_AREA + buffer_index() * 16u);
        wr32(OT2_TABLE + 12u + buffer_index() * 20u, OT2B_AREA + buffer_index() * 16u);
        (void)call2(F_CLEAR_OTAGR, rd32(OT2_TABLE + buffer_index() * 20u), 4u);
        call_scratch(F_OVL_FRAME);
    }

    (void)call0(F_FRAME_END);
    (void)call1(F_DRAWSYNC, 0u);
    vsync_point();
    if (g_driver.quit) return;

    /* display/draw buffer swap */
    wr16(MAIN_STATE + ST_DISP_CUR, rd16(MAIN_STATE + ST_DRAW_CUR));
    wr16(MAIN_STATE + ST_DRAW_CUR, (uint16_t)(rd16(MAIN_STATE + ST_DRAW_CUR) + 1u));
    if (rd16(MAIN_STATE + ST_DRAW_CUR) >= 2u) wr16(MAIN_STATE + ST_DRAW_CUR, 0u);
    cur = rd16(MAIN_STATE + ST_DISP_CUR);
    (void)call1(F_PUTDISPENV, MAIN_STATE + ST_DISPENV + cur * 20u);
    cur = rd16(MAIN_STATE + ST_DRAW_CUR);
    (void)call1(F_PUTDRAWENV, MAIN_STATE + ST_DRAWENV + cur * 92u);
    ot = rd32(OT_TABLE + buffer_index() * 20u);
    (void)call2(F_CATPRIM, ot + 0x3FF0u, rd32(OT_TAIL_INDEX) * 4u + rd32(OT_TABLE + buffer_index() * 20u));
    (void)call1(F_DRAWOTAG, rd32(OT_TABLE + buffer_index() * 20u) + 0x3FFCu);
    (void)call1(F_DRAWOTAG, rd32(OT2_TABLE + buffer_index() * 20u) + 12u);

    (void)call0(F_8003500C);
    (void)call0(F_SOUND_TICK);
    (void)call0(F_8001AF34);
    (void)call0(F_8001513C);
    ++g_driver.frames;
}

/* crt0 (80010000): the BSS clear, stack and heap globals, then main. */
static void crt0(void) {
    uint32_t a, top;
    for (a = BSS_LO; a < BSS_HI; a += 4u) wr32(a, 0u);
    top = rd32(RAM_SIZE_VAR) - 8u;
    wr32(HEAP_SIZE_VAR, top - rd32(STACK_SIZE_VAR) - (BSS_HI & 0x1FFFFFFFu));
    wr32(HEAP_BASE_VAR, (BSS_HI & 0x1FFFFFFFu) | 0x80000000u);
    /* gp[0] keeps the BIOS return address; the host is the caller here. */
    wr32(BSS_LO, 0u);
    g_driver.main_sp = (top | 0x80000000u) - MAIN_FRAME;
}

static void main_init(void) {
    /* 800100A0 (__main): sets its flag once; the constructor table is
     * empty in this executable (count 0), so nothing else runs. */
    if (rd32(CTOR_DONE) == 0u) wr32(CTOR_DONE, 1u);
    (void)call1(F_RESETCB, 0u);
    wr32(OT_TAIL_INDEX, 0x3E0u);
    (void)call0(F_STARTUP);
    (void)call1(F_8005FC68, 0u);
    (void)call0(F_8005FCB8);
    (void)call0(F_80018918);
    wr32(INIT_RESULT, call0(F_80043300));
    (void)call0(F_8002C8F4);
    (void)call0(F_8001971C);
}

MusashiResetGraphPrefixStatus musashi_frame_driver_run(MusashiBootMemory *memory,
                                                       const MusashiStartupPrefixDevice *devices,
                                                       const MusashiFrameDriverOps *ops) {
    const char *limit = getenv("MUSASHI_DRIVER_FRAMES");
    if (!memory || !devices) return MUSASHI_RESETGRAPH_PREFIX_INVALID_INPUT;
    if (!musashi_native_lane_usable(memory))
        driver_stop("lane_window_unavailable", 0x80010178u);
    memset(&g_driver, 0, sizeof g_driver);
    g_driver.memory = memory;
    g_driver.devices = devices;
    g_driver.ops = ops;
    g_driver.frame_limit = limit && limit[0] ? strtoul(limit, NULL, 0) : 0;
    fprintf(stderr, "native_boot: FRAME_DRIVER start (main 80010178, no interpreter)%s%s\n",
            g_driver.frame_limit ? " frames=" : "", g_driver.frame_limit ? limit : "");
    crt0();
    main_init();
    while (!g_driver.quit) {
        (void)call0(F_SESSION);
        (void)call0(F_80014390);
        (void)call0(F_800191A8);
        (void)call0(F_80010A98);
        while (!g_driver.quit && rd16(MAIN_STATE + ST_SESSION_END) == 0u) {
            main_frame();
            if (g_driver.frame_limit && g_driver.frames >= g_driver.frame_limit) g_driver.quit = 1;
        }
        if (g_driver.quit) break;
        (void)call1(F_SESSION_EXIT, 0u);
    }
    fprintf(stderr, "native_boot: FRAME_DRIVER stop frames=%lu\n", g_driver.frames);
    return MUSASHI_RESETGRAPH_PREFIX_COMPLETE;
}
