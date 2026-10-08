/* Strict-native frame driver (docs/NATIVE-FRAME-DRIVER.md).
 *
 * Owner-written, clean room, from the retail disassembly of main (80010178,
 * -O0) and of the short Sony entry points it replaces; no vendor C and no
 * Sony source or SDK material. Every guest call goes through the native lane
 * table (musashi_native_lane_invoke); a callee the lane cannot run stops the
 * process with seam=frame_driver. Built only with MUSASHI_STRICT_NATIVE. */
#include "musashi_native_frame_driver.h"
#include "musashi_callback_registration.h"
#include "musashi_irq_dispatch.h"
#include "musashi_vblank.h"

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
static unsigned long g_irq_dispatches;
static void driver_stop(const char *what, uint32_t pc) {
    uint32_t tick = 0;
    if (g_driver.memory) (void)musashi_boot_read32(g_driver.memory, 0x8006CBB8u, &tick);
    fprintf(stderr, "native_boot: FRAME_DRIVER stop frames=%lu vblank_tick=%u irq_dispatches=%lu\n",
            g_driver.frames, (unsigned)tick, g_irq_dispatches);
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

static void driver_irq_poll(void);
static unsigned g_call_depth;

static uint32_t call_at(uint32_t sp, uint32_t pc, unsigned argc, const uint32_t *args) {
    uint32_t v0 = 0;
    int ran;
    ++g_call_depth;
    ran = musashi_native_lane_invoke(g_driver.memory, g_driver.devices, pc, args, argc, sp, &v0);
    --g_call_depth;
    /* top-level calls are the driver's interrupt points */
    if (ran > 0 && !g_call_depth) driver_irq_poll();
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

/* SYS1/SYS2 critical sections. The driver owns interrupt delivery in
 * strict builds, so the CPU's interrupt-enable state is the driver's own
 * flag (the executable starts with interrupts disabled; libetc's init ends
 * with ExitCriticalSection). EnterCriticalSection returns whether interrupts
 * were enabled. */
static int g_irq_enabled;

static int hle_enter_critical(MusashiNativeLaneCall *call) {
    /* 8005CF08: li a0,1; syscall */
    call->r[4] = 1u;
    call->r[2] = (uint32_t)g_irq_enabled;
    g_irq_enabled = 0;
    return 1;
}

static int hle_exit_critical(MusashiNativeLaneCall *call) {
    /* 8005CF18: li a0,2; syscall */
    call->r[4] = 2u;
    g_irq_enabled = 1;
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

/* ---- libetc core (80042580..80043060) ------------------------------------
 * Native replacements written from the retail disassembly. The service table
 * at 8006CB64 (pointer cell 8006CB84) holds: [1] DMACallback setter, [2]
 * InterruptCallback 800429DC, [3] init 80042718, [4] StopCallback, [5]
 * VSyncCallbacks setter, [6] RestartCallback, [7] state 8006BAFC. The state
 * block S: u16 inited, u16 in_irq, handlers[11] at +4, u16 enabled mask at
 * +0x30, saved I_MASK/DPCR at +0x32/+0x34, the setjmp context at +0x38. The
 * MMIO addresses come from the pointer cells 8006CB88 (I_STAT), 8006CB8C
 * (I_MASK), 8006CB90 (DPCR), 8006CBBC (root-counter 1 mode), 8006CBC0 (DICR).
 *
 * The strict build delivers interrupts itself: instead of B0:19 HookEntryInt
 * arming the interpreter's exception scheduler, the frame driver polls the
 * device's I_STAT at its own points and runs the retail dispatcher body
 * (800427F4, decomp-owned) on the IRQ stack the init stores in the context. */
enum {
    ETC_STATE = 0x8006BAFCu, ETC_TABLE = 0x8006CB64u, ETC_IRQ_SP = 0x8006CB14u,
    ETC_I_STAT_CELL = 0x8006CB88u, ETC_I_MASK_CELL = 0x8006CB8Cu,
    ETC_DPCR_CELL = 0x8006CB90u, ETC_VS_TICK = 0x8006CBB8u,
    ETC_VS_SLOTS = 0x8006CB98u, ETC_RCNT1_CELL = 0x8006CBBCu,
    ETC_DICR_CELL = 0x8006CBC0u, ETC_DMA_SLOTS = 0x8006CBC4u,
    ETC_INIT = 0x80042718u, ETC_IRQ_SET = 0x800429DCu, ETC_VS_SET = 0x80042D60u,
    ETC_DMA_SET = 0x80042F8Cu, ETC_VS_HANDLER = 0x80042CE8u,
    ETC_DMA_HANDLER = 0x80042E08u, CARD_VBLANK = 0x800616D0u
};

static const MusashiCallbackDevice *etc_cb(void) {
    return g_driver.devices ? g_driver.devices->callback : NULL;
}
static const MusashiCallbackRegistrationDevice *etc_reg(void) {
    const MusashiCallbackDevice *cb = etc_cb();
    return cb ? cb->registration_device : NULL;
}
static uint16_t etc_r16(uint32_t a) {
    const MusashiCallbackDevice *cb = etc_cb();
    return cb && cb->read16 ? cb->read16(cb->userdata, a) : 0u;
}
static void etc_w16(uint32_t a, uint16_t v) {
    const MusashiCallbackDevice *cb = etc_cb();
    if (cb && cb->write16) cb->write16(cb->userdata, a, v);
}
static void etc_w32(uint32_t a, uint32_t v) {
    const MusashiCallbackDevice *cb = etc_cb();
    if (cb && cb->write32) cb->write32(cb->userdata, a, v);
}

static uint32_t etc_irq_set(int32_t index, uint32_t fn) {
    uint32_t previous = 0;
    if (!musashi_boot_call_800429dc(g_driver.memory, etc_reg(), index, fn, &previous))
        driver_stop("InterruptCallback_refused", ETC_IRQ_SET);
    return previous;
}

static uint32_t etc_init(void) {
    /* 80042718 */
    uint32_t imask = rd32(ETC_I_MASK_CELL), istat = rd32(ETC_I_STAT_CELL);
    uint32_t i;
    const MusashiCallbackDevice *cb = etc_cb();
    if (rd16(ETC_STATE)) return 0;
    etc_w16(imask, 0);
    etc_w16(istat, etc_r16(imask));
    etc_w32(rd32(ETC_DPCR_CELL), 0x33333333u);
    if (!musashi_boot_call_80042c64(g_driver.memory, ETC_STATE, 1050u))
        driver_stop("ResetCallback_clear_refused", ETC_INIT);
    /* setjmp(S+0x38): the resume point is the dispatcher call at 80042780;
     * the init then points the context's sp at the IRQ stack. */
    wr32(ETC_STATE + 0x38u, 0x80042780u);
    wr32(ETC_STATE + 0x3Cu, ETC_IRQ_SP);
    wr16(ETC_STATE, 1u);
    /* 80042C90: root counter 1 mode, VBlank tick and slots, IRQ0 handler */
    etc_w32(rd32(ETC_RCNT1_CELL), 0x107u);
    wr32(ETC_VS_TICK, 0);
    for (i = 0; i < 8u; ++i) wr32(ETC_VS_SLOTS + i * 4u, 0);
    (void)etc_irq_set(0, ETC_VS_HANDLER);
    wr32(ETC_TABLE + 20u, ETC_VS_SET);
    /* 80042DB8: DMA slots, DICR = 0, IRQ3 handler */
    for (i = 0; i < 8u; ++i) wr32(ETC_DMA_SLOTS + i * 4u, 0);
    if (g_driver.ops && g_driver.ops->dma_irq && g_driver.ops->dma_irq->write32) {
        if (!g_driver.ops->dma_irq->write32(g_driver.ops->dma_irq->userdata,
                                            rd32(ETC_DICR_CELL), 0))
            driver_stop("DICR_write_refused", ETC_INIT);
    }
    (void)etc_irq_set(3, ETC_DMA_HANDLER);
    wr32(ETC_TABLE + 4u, ETC_DMA_SET);
    /* A0:72 (_96_remove: the BIOS CD handlers go; it runs its own critical
     * section), then ExitCriticalSection */
    if (g_driver.ops && g_driver.ops->bios_a0_72 && !g_driver.ops->bios_a0_72(g_driver.ops->user))
        driver_stop("A0_72_refused", ETC_INIT);
    g_irq_enabled = 1;
    fprintf(stderr, "native_boot: FRAME_DRIVER libetc init (native IRQ delivery)\n");
    return ETC_STATE;
}

static int hle_reset_callback(MusashiNativeLaneCall *call) {
    /* 80042580 ResetCallback: tbl[3](); 80042718 is the body. */
    if (call->r[31] && rd32(ETC_TABLE + 12u) != ETC_INIT)
        driver_stop("ResetCallback_table", 0x80042580u);
    call->r[2] = etc_init();
    return 1;
}

static int hle_interrupt_callback(MusashiNativeLaneCall *call) {
    /* 800425B0 InterruptCallback(irq, f): tbl[2](irq, f) = 800429DC. */
    call->r[2] = etc_irq_set((int32_t)call->r[4], call->r[5]);
    return 1;
}

static int hle_dma_callback(MusashiNativeLaneCall *call) {
    /* 800425E0 DMACallback(ch, f): tbl[1](ch, f) = 80042F8C after init. */
    uint32_t previous = 0;
    if (rd32(ETC_TABLE + 4u) != ETC_DMA_SET || !g_driver.ops || !g_driver.ops->dma_irq ||
        !musashi_boot_call_80042f8c(g_driver.memory, g_driver.ops->dma_irq,
                                    (int32_t)call->r[4], call->r[5], &previous))
        driver_stop("DMACallback_refused", 0x800425E0u);
    call->r[2] = previous;
    return 1;
}

static uint32_t etc_vs_set(uint32_t index, uint32_t fn) {
    /* 80042D60: slot = 8006CB98[index]; v0 = old; store when changed. */
    uint32_t slot = ETC_VS_SLOTS + index * 4u, old;
    if (rd32(ETC_TABLE + 20u) != ETC_VS_SET || index >= 8u) {
        driver_stop("VSyncCallbacks_refused", ETC_VS_SET);
        return 0;
    }
    old = rd32(slot);
    if (old != fn) wr32(slot, fn);
    return old;
}

static int hle_vsync_callback(MusashiNativeLaneCall *call) {
    /* 80042610 VSyncCallback(f): tbl[5](4, f) */
    call->r[2] = etc_vs_set(4u, call->r[4]);
    return 1;
}

static int hle_vsync_callbacks(MusashiNativeLaneCall *call) {
    /* 80042644 VSyncCallbacks(i, f): tbl[5](i, f) */
    call->r[2] = etc_vs_set(call->r[4], call->r[5]);
    return 1;
}

static int hle_check_callback(MusashiNativeLaneCall *call) {
    /* 800426D4: in_irq */
    call->r[2] = rd16(ETC_STATE + 2u);
    return 1;
}

static int hle_get_intr_mask(MusashiNativeLaneCall *call) {
    /* 800426E4: *I_MASK */
    call->r[2] = etc_r16(rd32(ETC_I_MASK_CELL));
    return 1;
}

static int hle_set_intr_mask(MusashiNativeLaneCall *call) {
    /* 800426FC: old = *I_MASK; *I_MASK = a0; return old */
    uint32_t a = rd32(ETC_I_MASK_CELL);
    call->r[2] = etc_r16(a);
    etc_w16(a, (uint16_t)call->r[4]);
    return 1;
}

/* Executors for the dispatcher's handler slots and the VBlank slots. The
 * libetc handlers themselves run natively; other targets are lane calls on
 * the IRQ stack. */
static int etc_exec(void *ud, MusashiBootMemory *m, uint32_t target);
static int etc_call_one(void *ud, MusashiBootMemory *m, uint32_t target,
                        uint32_t arg, uint32_t *result) {
    uint32_t v = call_at(ETC_IRQ_SP - 0x100u, target, 1, &arg);
    (void)ud; (void)m;
    if (result) *result = v;
    return !g_driver.quit;
}
static int etc_call_two(void *ud, MusashiBootMemory *m, uint32_t target,
                        uint32_t first, uint32_t second) {
    uint32_t a[2] = {first, second};
    (void)ud; (void)m;
    (void)call_at(ETC_IRQ_SP - 0x100u, target, 2, a);
    return !g_driver.quit;
}
static const MusashiVblankExecutor k_etc_vblank_exec = {NULL, etc_call_one, etc_call_two};

static int etc_exec(void *ud, MusashiBootMemory *m, uint32_t target) {
    (void)ud;
    switch (target) {
    case ETC_VS_HANDLER: return musashi_boot_call_80042ce8(m, etc_exec, NULL);
    case ETC_DMA_HANDLER:
        return g_driver.ops && g_driver.ops->dma_irq &&
               musashi_boot_call_80042e08(m, g_driver.ops->dma_irq, etc_exec, NULL);
    case CARD_VBLANK: return musashi_boot_call_800616d0(m, &k_etc_vblank_exec);
    default:
        (void)call_at(ETC_IRQ_SP, target, 0, NULL);
        return !g_driver.quit;
    }
}

static int etc_read16(void *ud, uint32_t a, uint16_t *v) {
    (void)ud;
    *v = etc_r16(a);
    return 1;
}
static int etc_write16(void *ud, uint32_t a, uint16_t v) {
    (void)ud;
    etc_w16(a, v);
    return 1;
}
static int etc_diagnostic(void *ud, MusashiBootMemory *m, uint32_t format,
                          uint32_t first, uint32_t second, uint32_t count) {
    (void)ud; (void)m;
    fprintf(stderr, "native_boot: FRAME_DRIVER libetc diagnostic fmt=%08x %08x %08x n=%u\n",
            format, first, second, count);
    return 1;
}
static const MusashiIrqDispatchDevice k_etc_irq = {
    NULL, etc_read16, etc_write16, etc_exec, etc_diagnostic, NULL
};

static int g_in_irq;

/* The driver's interrupt point, in the BIOS exception handler's order:
 * with interrupts enabled and an unmasked IRQ pending, the BIOS kernel's
 * priority chains run first (card/SIO, CD nodes: ops->bios_irq), then the
 * custom exit libetc hooked, its dispatcher 800427F4 (acknowledge each
 * enabled bit, call its handler). */
static void driver_irq_poll(void) {
    uint16_t raw, pending;
    int r;
    if (!g_driver.memory || g_in_irq || g_driver.quit) return;
    raw = (uint16_t)(etc_r16(0x1F801070u) & etc_r16(0x1F801074u));
    if (getenv("MUSASHI_DRIVER_IRQ_TRACE"))
        fprintf(stderr, "native_boot: FRAME_DRIVER irq_point en=%d stat=%04x mask=%04x\n",
                g_irq_enabled, etc_r16(0x1F801070u), etc_r16(0x1F801074u));
    if (!g_irq_enabled) return;
    if (!raw) return;
    g_in_irq = 1;
    if (g_driver.ops && g_driver.ops->bios_irq && !g_driver.ops->bios_irq(g_driver.ops->user, raw))
        driver_stop("bios_irq_refused", 0x80000080u);
    if (rd16(ETC_STATE) && !rd16(ETC_STATE + 2u) && !g_driver.quit) {
        pending = (uint16_t)(etc_r16(rd32(ETC_I_STAT_CELL)) & etc_r16(rd32(ETC_I_MASK_CELL)) &
                             rd16(ETC_STATE + 0x30u));
        if (pending) {
            r = musashi_boot_call_800427f4(g_driver.memory, &k_etc_irq);
            if (!r) driver_stop("irq_dispatch_refused", 0x800427F4u);
            ++g_irq_dispatches;
        }
    }
    g_in_irq = 0;
}

void musashi_frame_driver_irq_point(void) { driver_irq_poll(); }

/* ---- libgpu / libcard startup ------------------------------------------- */

static int hle_reset_graph(MusashiNativeLaneCall *call) {
    /* 80059234 ResetGraph(mode). Modes 0, 3 (with a console line) and 5:
     * clear the 128-byte state at 80072788, ResetCallback, GPU_cw(jtb &
     * 0xFFFFFF), reset the GPU (8005BD7C), state[0] = type, state[1] = 1,
     * the type's width/height words from 80072808/8007281C, the two
     * environment caches at +16 (92 bytes) and +108 (20 bytes) = -1.
     * Others: jtb[13](1). */
    const MusashiCallbackDevice *cb = etc_cb();
    uint32_t mode = call->r[4] & 7u, s0 = 0x80072788u, type;
    int32_t result = 0;
    if (mode != 0u && mode != 3u && mode != 5u) {
        uint32_t a = 1u;
        call->r[2] = call_at(call->r[29] - 0x40u, rd32(rd32(0x80072780u) + 52u), 1, &a);
        return 1;
    }
    if (mode != 5u)
        fprintf(stderr, "native_boot: FRAME_DRIVER ResetGraph(%u)\n", (unsigned)call->r[4]);
    if (!musashi_boot_call_8005c29c(g_driver.memory, s0, 0, 128u))
        driver_stop("ResetGraph_clear_refused", 0x80059234u);
    (void)etc_init();
    if (!cb || !cb->gpu_cw ||
        !cb->gpu_cw(cb->userdata, rd32(0x80072780u) & 0xFFFFFFu, &result))
        driver_stop("GPU_cw_refused", 0x8005CE38u);
    if (!cb || !musashi_boot_call_8005bd7c(g_driver.memory, cb->reset_device,
                                           (int32_t)call->r[4], &result))
        driver_stop("ResetGraph_reset_refused", 0x8005BD7Cu);
    type = (uint32_t)result & 0xFFu;
    wr8(s0, (uint8_t)type);
    wr8(s0 + 1u, 1u);
    wr16(s0 + 4u, (uint16_t)rd32(0x80072808u + type * 4u));
    wr16(s0 + 6u, (uint16_t)rd32(0x8007281Cu + type * 4u));
    if (!musashi_boot_call_8005c29c(g_driver.memory, s0 + 16u, -1, 92u) ||
        !musashi_boot_call_8005c29c(g_driver.memory, s0 + 108u, -1, 20u))
        driver_stop("ResetGraph_env_refused", 0x80059234u);
    call->r[2] = type;
    return 1;
}

static int hle_set_graph_debug(MusashiNativeLaneCall *call) {
    /* 800594CC SetGraphDebug(level): old level byte at 8007278A; store the
     * new one (the nonzero case prints a console line); return old. */
    uint32_t old = rd8(0x8007278Au);
    wr8(0x8007278Au, (uint8_t)call->r[4]);
    call->r[2] = old;
    return 1;
}

static int32_t card_enter_critical(void) {
    int32_t r = g_irq_enabled;
    g_irq_enabled = 0;
    return r;
}
static void card_exit_critical(void) { g_irq_enabled = 1; }

static int ev_enter_critical(void *ud, int32_t *result) {
    (void)ud;
    *result = card_enter_critical();
    return 1;
}
static int ev_exit_critical(void *ud, int32_t *result) {
    (void)ud;
    card_exit_critical();
    if (result) *result = 0;
    return 1;
}

static int hle_init_card(MusashiNativeLaneCall *call) {
    /* 8005FC68 InitCARD(pad_enable): clear 80078C7C/80078CC0; 8006186C:
     * B0:5B(0), critical { B0:4A(8006 2A24 ? a0 : 0) }; 80062328: critical
     * { B0:4B } then B0:5B(0); 80061F38: A0:70 (_bu_init). v0 = 0. */
    const MusashiCdDevice *cd = g_driver.devices ? g_driver.devices->cd : NULL;
    int32_t r = 0, arg = (int32_t)call->r[4];
    wr32(0x80078C7Cu, 0);
    wr32(0x80078CC0u, 0);
    if (!cd || !cd->b0_5b || !cd->b0_4a || !cd->b0_4b || !cd->a0_70) {
        driver_stop("InitCARD_no_device", 0x8005FC68u);
        return 1;
    }
    if (!cd->b0_5b(cd->userdata, 0, &r)) driver_stop("ChangeClearPAD_refused", 0x8005FC68u);
    (void)card_enter_critical();
    if (!rd32(0x80072A24u)) arg = 0;
    if (!cd->b0_4a(cd->userdata, arg, &r)) driver_stop("InitCard_refused", 0x8005FC68u);
    card_exit_critical();
    (void)card_enter_critical();
    if (!cd->b0_4b(cd->userdata, &r)) driver_stop("StartCard_refused", 0x8005FC68u);
    if (!cd->b0_5b(cd->userdata, 0, &r)) driver_stop("ChangeClearPAD_refused", 0x8005FC68u);
    card_exit_critical();
    if (!cd->a0_70(cd->userdata, &r)) driver_stop("bu_init_refused", 0x8005FC68u);
    call->r[2] = 0;
    return 1;
}

static int hle_start_card(MusashiNativeLaneCall *call) {
    /* 8005FCB8 StartCARD: 80062888 (80072A34 = -1), 80078C80/84/88 = 0,
     * 80078C90 = -1; 8006189C opens, enables and tests the eight card
     * events (decomp-owned); VSyncCallbacks(7, 800616D0). */
    int32_t r = 0;
    wr32(0x80072A34u, 0xFFFFFFFFu);
    wr32(0x80078C80u, 0);
    wr32(0x80078C84u, 0);
    wr32(0x80078C88u, 0);
    wr32(0x80078C90u, 0xFFFFFFFFu);
    if (!g_driver.devices || !g_driver.devices->event) {
        driver_stop("StartCARD_no_event_device", 0x8006189Cu);
        return 1;
    }
    {
        /* its EnterCriticalSection/ExitCriticalSection are the game's own
         * 8005CF08/8005CF18: the driver's interrupt-enable flag */
        MusashiEventDevice ev = *g_driver.devices->event;
        ev.enter_critical_section = ev_enter_critical;
        ev.exit_critical_section = ev_exit_critical;
        if (!musashi_boot_call_8006189c(g_driver.memory, &ev, &r))
            driver_stop("StartCARD_events_refused", 0x8006189Cu);
    }
    call->r[2] = etc_vs_set(7u, CARD_VBLANK);
    return 1;
}

static const MusashiNativeLaneEntry k_driver_entries[] = {
    {0x80042580u, 0, hle_reset_callback,  "ResetCallback",       0, 1, 0},
    {0x800425B0u, 0, hle_interrupt_callback, "InterruptCallback", 2, 1, 0},
    {0x800425E0u, 0, hle_dma_callback,    "DMACallback",         2, 1, 0},
    {0x80042610u, 0, hle_vsync_callback,  "VSyncCallback",       1, 1, 0},
    {0x80042644u, 0, hle_vsync_callbacks, "VSyncCallbacks",      2, 1, 0},
    {0x800426D4u, 0, hle_check_callback,  "CheckCallback",       0, 1, 0},
    {0x800426E4u, 0, hle_get_intr_mask,   "GetIntrMask",         0, 1, 0},
    {0x800426FCu, 0, hle_set_intr_mask,   "SetIntrMask",         1, 1, 0},
    {0x80042718u, 0, hle_reset_callback,  "libetc_init",         0, 1, 0},
    {0x800429DCu, 0, hle_interrupt_callback, "InterruptCallback_body", 2, 1, 0},
    {0x80042D60u, 0, hle_vsync_callbacks, "VSyncCallbacks_body", 2, 1, 0},
    {0x80042F8Cu, 0, hle_dma_callback,    "DMACallback_body",    2, 1, 0},
    {0x80043060u, 0, hle_exchange_cbe8,   "exchange_8006CBE8",   1, 1, 0},
    {0x80043974u, 0, hle_cd_mix,          "CdMix",               1, 1, 0},
    {0x8005CE18u, 0, hle_init_heap,       "InitHeap",            2, 0, 0},
    {0x8005CF08u, 0, hle_enter_critical,  "EnterCriticalSection",0, 1, 0},
    {0x8005CF18u, 0, hle_exit_critical,   "ExitCriticalSection", 0, 0, 0},
    {0x80059234u, 0, hle_reset_graph,     "ResetGraph",          1, 1, 0},
    {0x800594CCu, 0, hle_set_graph_debug, "SetGraphDebug",       1, 1, 0},
    {0x8005D0F8u, 0, hle_pad_start_stop,  "PadStartCom",         0, 0, 0},
    {0x8005D118u, 0, hle_pad_start_stop,  "PadStopCom",          0, 0, 0},
    {0x8005D184u, 0, hle_pad_get_state,   "PadGetState",         1, 1, 0},
    {0x8005D244u, 0, hle_pad_info_mode,   "PadInfoMode",         3, 1, 0},
    {0x8005D4B8u, 0, hle_pad_set_act,     "PadSetActAlign",      2, 1, 0},
    {0x8005D538u, 0, hle_pad_set_act,     "PadSetAct",           3, 1, 0},
    {0x8005F0C8u, 0, hle_pad_init_direct, "PadInitDirect",       2, 0, 0},
    {0x8005FC68u, 0, hle_init_card,       "InitCARD",            1, 1, 0},
    {0x8005FCB8u, 0, hle_start_card,      "StartCARD",           0, 1, 0},
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
    driver_irq_poll();
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
