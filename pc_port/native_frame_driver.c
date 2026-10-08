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
#include <stdint.h>

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
int musashi_frame_driver_irq_enabled(void) { return g_irq_enabled && !g_in_irq; }

/* ---- libcd (80043060..80046D1C) ------------------------------------------
 * Native replacements written from the retail disassembly, as a set: they
 * share libcd's guest RAM state, so the game's direct reads (CdStatus,
 * CdMode, the sync/ready results) and the remaining guest callers see what
 * retail would leave. Hardware goes through the CD register device (the
 * 1F801800..3 ports, CDROM/COMMON delay, DPCR, DMA3) and the SPU device
 * (CD volume). The CD IRQ handler 80045290 is registered with the native
 * InterruptCallback and runs from the driver's interrupt point; every retail
 * busy-wait (CD_sync, CD_ready, CD_cw, CD_datasync, the DMA/FIFO polls,
 * VSync(n)) spends guest time and checks for interrupts on each iteration.
 *
 * RAM: 8006CC84 sync callback, 8006CC88 ready callback, 8006CC90 debug
 * level, 8006CC94/98 status bytes 0/1 (words), 8006CC9C shell-open count,
 * 8006CCA0 last Setloc position, 8006CCA4 mode, 8006CCA5 last command;
 * 8006CF64/65/66 sync/ready/data-end interrupt codes with 8-byte results at
 * 800763D8/E0/E8; the timeout record at 800763F0. Per-command tables:
 * 8006CBFC (Setloc first), 8006CD4C (acknowledge then complete), 8006CDCC
 * (clears the ready code), 8006CE4C (acknowledge updates the status),
 * 8006CECC (parameter count). Register addresses come from the pointer
 * cells 8006CF4C..8006CF90 as in retail. */
int bfm_psyq_VSync(uint32_t *r);
int bfm_psyq_SetFarColor(uint32_t *r);
int bfm_psyq_ClearImage(uint32_t *r);
int bfm_psyq_SetColorMatrix(uint32_t *r);
int bfm_psyq_InitGeom(uint32_t *r);
int bfm_psyq_SetGeomOffset(uint32_t *r);
static uint32_t g_cd_sp;

enum {
    CD_CBSYNC = 0x8006CC84u, CD_CBREADY = 0x8006CC88u, CD_DEBUG = 0x8006CC90u,
    CD_STATUS = 0x8006CC94u, CD_STATUS1 = 0x8006CC98u, CD_NOPEN = 0x8006CC9Cu,
    CD_POS = 0x8006CCA0u, CD_MODE = 0x8006CCA4u, CD_COM = 0x8006CCA5u,
    CD_T_SETLOC = 0x8006CBFCu, CD_T_ACK2 = 0x8006CD4Cu, CD_T_RDCLR = 0x8006CDCCu,
    CD_T_STATUPD = 0x8006CE4Cu, CD_T_NPARAM = 0x8006CECCu,
    CD_C_REG0 = 0x8006CF4Cu, CD_C_COMDELAY = 0x8006CF5Cu, CD_C_SPU = 0x8006CF60u,
    CD_C_CDDELAY = 0x8006CF80u, CD_C_DPCR = 0x8006CF84u, CD_C_MADR = 0x8006CF88u,
    CD_C_BCR = 0x8006CF8Cu, CD_C_CHCR = 0x8006CF90u,
    CD_INTR = 0x8006CF64u, CD_RES_SYNC = 0x800763D8u, CD_RES_READY = 0x800763E0u,
    CD_RES_END = 0x800763E8u, CD_TO_TICK = 0x800763F0u, CD_TO_COUNT = 0x800763F4u,
    CD_TO_MSG = 0x800763F8u, CD_READCB = 0x8006CF9Cu, CD_CB_CFD0 = 0x8006CFD0u,
    CD_IRQ_HANDLER = 0x80045290u, CD_SPIN = 256u
};

static const MusashiCdRegisterDevice *cd_dev(void) {
    return g_driver.devices ? g_driver.devices->cd_registers : NULL;
}
static uint8_t cd_r8(unsigned reg) {
    const MusashiCdRegisterDevice *d = cd_dev();
    uint8_t v = 0;
    if (!d || !d->read8 || !d->read8(d->userdata, rd32(CD_C_REG0 + reg * 4u), &v))
        driver_stop("cd_register_read_refused", 0x80043B9Cu);
    return v;
}
static void cd_w8(unsigned reg, uint8_t v) {
    const MusashiCdRegisterDevice *d = cd_dev();
    if (!d || !d->write8 || !d->write8(d->userdata, rd32(CD_C_REG0 + reg * 4u), v))
        driver_stop("cd_register_write_refused", 0x80044670u);
}
static uint32_t cd_r32(uint32_t cell) {
    const MusashiCdRegisterDevice *d = cd_dev();
    uint32_t v = 0;
    if (!d || !d->read32 || !d->read32(d->userdata, rd32(cell), &v))
        driver_stop("cd_word_read_refused", cell);
    return v;
}
static void cd_w32(uint32_t cell, uint32_t v) {
    const MusashiCdRegisterDevice *d = cd_dev();
    if (!d || !d->write32 || !d->write32(d->userdata, rd32(cell), v))
        driver_stop("cd_word_write_refused", cell);
}

/* One iteration of a retail busy-wait: guest time passes and a pending
 * interrupt is delivered (outside interrupt context, as on hardware). */
static void driver_spin(uint32_t cycles) {
    if (g_driver.ops && g_driver.ops->spend && !g_driver.ops->spend(g_driver.ops->user, cycles))
        driver_stop("spend_refused", 0u);
    driver_irq_poll();
}

static uint32_t vcount(void) { return rd32(ETC_VS_TICK); }

static uint32_t cd_call2(uint32_t fn, uint32_t a0, uint32_t a1) {
    uint32_t a[2] = {a0, a1};
    return call_at(g_cd_sp, fn, 2, a);
}

static void cd_copy8(uint32_t dst, uint32_t src) {
    unsigned i;
    if (!dst) return;
    for (i = 0; i < 8u; ++i) wr8(dst + i, rd8(src + i));
}

static void cd_ack_all(void) {
    /* the ack loop shared by 80044B14 and 80044D38 */
    cd_w8(0, 1);
    while (!g_driver.quit && (cd_r8(3) & 7u)) {
        cd_w8(0, 1);
        cd_w8(3, 7);
        cd_w8(2, 7);
    }
    wr8(CD_INTR + 2u, 0);
    wr8(CD_INTR + 1u, 0);
    wr8(CD_INTR, 2);
    cd_w8(0, 0);
    cd_w8(3, 0);
    cd_w32(CD_C_COMDELAY, 0x1325u);
}

static void cd_flush(void) { cd_ack_all(); }   /* 80044B14 */

static int cd_getintr(void) {
    /* 80043B9C */
    uint8_t intr, res[8];
    unsigned n = 0, i;
    int s1 = 0, v;
    uint32_t com;
    cd_w8(0, 1);
    intr = cd_r8(3) & 7u;
    if (!intr) return 0;
    for (;;) {
        uint8_t now = cd_r8(3) & 7u;
        if (now == intr) break;
        intr = cd_r8(3) & 7u;
    }
    while (n < 8u && (cd_r8(0) & 0x20u)) res[n++] = cd_r8(1);
    for (i = n; i < 8u; ++i) res[i] = 0;
    cd_w8(0, 1);
    cd_w8(3, 7);
    cd_w8(2, 7);
    com = rd8(CD_COM);
    if (intr != 3u || rd32(CD_T_STATUPD + com * 4u)) {
        if (!(rd32(CD_STATUS) & 0x10u) && (res[0] & 0x10u))
            wr32(CD_NOPEN, rd32(CD_NOPEN) + 1u);
        wr32(CD_STATUS, res[0]);
        wr32(CD_STATUS1, res[1]);
        s1 = res[0] & 0x1Du;
    }
    if (intr == 5u && (int32_t)rd32(CD_DEBUG) > 0)
        fprintf(stderr, "native_boot: libcd DiskError com=%02x stat=%02x %02x\n",
                (unsigned)com, res[0], res[1]);
    switch (intr) {
    case 1:   /* DataReady */
        v = 1;
        if (s1) {
            if (n == 1u) s1 = 0;
            if (s1) v = 5;
        }
        wr8(CD_INTR + 1u, (uint8_t)v);
        for (i = 0; i < 8u; ++i) wr8(CD_RES_READY + i, res[i]);
        cd_w8(0, 0);
        cd_w8(3, 0);
        return 4;
    case 2:   /* Complete */
        wr8(CD_INTR, s1 ? 5u : 2u);
        for (i = 0; i < 8u; ++i) wr8(CD_RES_SYNC + i, res[i]);
        return 2;
    case 3:   /* Acknowledge */
        v = s1 ? 5 : rd32(CD_T_ACK2 + com * 4u) ? 3 : 2;
        wr8(CD_INTR, (uint8_t)v);
        for (i = 0; i < 8u; ++i) wr8(CD_RES_SYNC + i, res[i]);
        return v == 3 ? 1 : 2;
    case 4:   /* DataEnd */
        wr8(CD_INTR + 2u, 4);
        wr8(CD_INTR + 1u, 4);
        for (i = 0; i < 8u; ++i) wr8(CD_RES_END + i, res[i]);
        for (i = 0; i < 8u; ++i) wr8(CD_RES_READY + i, res[i]);
        return 4;
    case 5:   /* DiskError */
        wr8(CD_INTR + 1u, 5);
        wr8(CD_INTR, 5);
        for (i = 0; i < 8u; ++i) wr8(CD_RES_SYNC + i, res[i]);
        for (i = 0; i < 8u; ++i) wr8(CD_RES_READY + i, res[i]);
        return 6;
    default:
        fprintf(stderr, "native_boot: libcd unknown intr %u\n", (unsigned)intr);
        return 0;
    }
}

static void cd_service(void) {
    /* the body of the IRQ handler 80045290 (and of the in-interrupt paths
     * of CD_sync/CD_ready/CD_cw): drain interrupts, run the callbacks */
    uint8_t save = cd_r8(0) & 3u;
    int r;
    while (!g_driver.quit && (r = cd_getintr()) != 0) {
        if ((r & 4) && rd32(CD_CBREADY))
            (void)cd_call2(rd32(CD_CBREADY), rd8(CD_INTR + 1u), CD_RES_READY);
        if ((r & 2) && rd32(CD_CBSYNC))
            (void)cd_call2(rd32(CD_CBSYNC), rd8(CD_INTR), CD_RES_SYNC);
    }
    cd_w8(0, save);
}

static void cd_to_start(uint32_t msg) {
    wr32(CD_TO_TICK, vcount() + 960u);
    wr32(CD_TO_COUNT, 0);
    wr32(CD_TO_MSG, msg);
}

static int cd_to_expired(void) {
    uint32_t c;
    if (!((int32_t)rd32(CD_TO_TICK) < (int32_t)vcount())) {
        c = rd32(CD_TO_COUNT);
        wr32(CD_TO_COUNT, c + 1u);
        if (!((int32_t)c > 0x3C0000)) return 0;
    }
    fprintf(stderr, "native_boot: libcd timeout (msg %08x) sync=%u ready=%u com=%02x\n",
            rd32(CD_TO_MSG), rd8(CD_INTR), rd8(CD_INTR + 1u), rd8(CD_COM));
    cd_flush();
    return 1;
}

/* wait-loop step: in interrupt context retail polls the controller itself */
static void cd_wait_step(void) {
    if (rd16(ETC_STATE + 2u)) {
        if (g_driver.ops && g_driver.ops->spend)
            (void)g_driver.ops->spend(g_driver.ops->user, CD_SPIN);
        cd_service();
    } else {
        driver_spin(CD_SPIN);
    }
}

static int32_t cd_sync(int mode, uint32_t result) {
    /* 80044124 CdSync */
    cd_to_start(0x800737E0u);
    for (;;) {
        uint8_t s;
        if (cd_to_expired()) return -1;
        if (g_driver.quit) return -1;
        s = rd8(CD_INTR);
        if (s == 2u || s == 5u) {
            wr8(CD_INTR, 2);
            cd_copy8(result, CD_RES_SYNC);
            return s;
        }
        if (mode) return 0;
        cd_wait_step();
    }
}

static int32_t cd_ready(int mode, uint32_t result) {
    /* 800443A4 CdReady */
    cd_to_start(0x800737E8u);
    for (;;) {
        uint8_t s;
        if (cd_to_expired()) return -1;
        if (g_driver.quit) return -1;
        s = rd8(CD_INTR + 2u);
        if (s) {
            wr8(CD_INTR + 2u, 0);
            cd_copy8(result, CD_RES_END);
            return s;
        }
        s = rd8(CD_INTR + 1u);
        if (s) {
            wr8(CD_INTR + 1u, 0);
            cd_copy8(result, CD_RES_READY);
            return s;
        }
        if (mode) return 0;
        cd_wait_step();
    }
}

static int32_t cd_cw(uint32_t com, uint32_t param, uint32_t result, int async) {
    /* 80044670: issue one command; wait for its first response */
    int32_t i, n;
    com &= 0xFFu;
    if ((int32_t)rd32(CD_DEBUG) >= 2)
        fprintf(stderr, "native_boot: libcd com %02x\n", (unsigned)com);
    if (rd32(CD_T_NPARAM + com * 4u) && !param) return -2;
    (void)cd_sync(0, 0);
    if (com == 2u)
        for (i = 0; i < 4; ++i) wr8(CD_POS + (uint32_t)i, rd8(param + (uint32_t)i));
    if (com == 14u) wr8(CD_MODE, rd8(param));
    wr8(CD_INTR, 0);
    if (rd32(CD_T_RDCLR + com * 4u)) wr8(CD_INTR + 1u, 0);
    cd_w8(0, 0);
    n = (int32_t)rd32(CD_T_NPARAM + com * 4u);
    for (i = 0; i < n; ++i) cd_w8(2, rd8(param + (uint32_t)i));
    wr8(CD_COM, (uint8_t)com);
    cd_w8(1, (uint8_t)com);
    if (async) return 0;
    cd_to_start(0x8007380Cu);
    while (rd8(CD_INTR) == 0u) {
        if (cd_to_expired() || g_driver.quit) return -1;
        cd_wait_step();
    }
    cd_copy8(result, CD_RES_SYNC);
    return rd8(CD_INTR) == 5u ? -1 : 0;
}

static int cd_control_common(uint32_t com, uint32_t param, uint32_t result,
                             uint32_t final_result, int async) {
    /* 800435CC / 80043704 / 80043830: four tries; a Setloc first for
     * position commands; Getstat first while the shell is open. The sync
     * callback is suspended during the retries. */
    uint32_t cb = rd32(CD_CBSYNC);
    int tries = 3;
    com &= 0xFFu;
    for (;;) {
        wr32(CD_CBSYNC, 0);
        if (com != 1u && (rd8(CD_STATUS) & 0x10u)) (void)cd_cw(1, 0, 0, 0);
        if (!param || !rd32(CD_T_SETLOC + com * 4u) || cd_cw(2, param, result, 0) == 0) {
            wr32(CD_CBSYNC, cb);
            if (cd_cw(com, param, final_result, async) == 0) return 1;
        }
        if (--tries == -1 || g_driver.quit) {
            wr32(CD_CBSYNC, cb);
            return 0;
        }
    }
}

static int32_t cd_initvol(void) {
    /* 80044BF4: SPU CD/main volumes, then the CD mix 80/00/80/00 */
    const MusashiCdSpuDevice *spu = g_driver.devices ? g_driver.devices->cd_spu : NULL;
    uint32_t base = rd32(CD_C_SPU);
    uint16_t a = 0, b = 0;
    if (!spu || !spu->read16 || !spu->write16) {
        driver_stop("cd_spu_device_missing", 0x80044BF4u);
        return -1;
    }
    if (!spu->read16(spu->userdata, base + 440u, &a)) driver_stop("spu_read_refused", 0x80044BF4u);
    if (!a && (!spu->read16(spu->userdata, base + 442u, &b) || !b)) {
        if (!spu->write16(spu->userdata, base + 384u, 0x3FFF) ||
            !spu->write16(spu->userdata, base + 386u, 0x3FFF))
            driver_stop("spu_write_refused", 0x80044BF4u);
    }
    if (!spu->write16(spu->userdata, base + 432u, 0x3FFF) ||
        !spu->write16(spu->userdata, base + 434u, 0x3FFF) ||
        !spu->write16(spu->userdata, base + 426u, 0xC001))
        driver_stop("spu_write_refused", 0x80044BF4u);
    cd_w8(0, 2);
    cd_w8(2, 0x80);
    cd_w8(3, 0);
    cd_w8(0, 3);
    cd_w8(1, 0x80);
    cd_w8(2, 0);
    cd_w8(3, 0x20);
    return 0;
}

static void cd_initintr(void) {
    /* 80044CE8 */
    wr32(CD_CBREADY, 0);
    wr32(CD_CBSYNC, 0);
    wr32(CD_STATUS1, 0);
    wr32(CD_STATUS, 0);
    (void)etc_init();
    (void)etc_irq_set(2, CD_IRQ_HANDLER);
}

static int32_t cd_init(void) {
    /* 80044D38 */
    fprintf(stderr, "native_boot: FRAME_DRIVER libcd CD_init\n");
    wr8(CD_COM, 0);
    wr8(CD_MODE, 0);
    cd_initintr();
    cd_ack_all();
    (void)cd_cw(1, 0, 0, 0);
    if (rd32(CD_STATUS) & 0x10u) (void)cd_cw(1, 0, 0, 0);
    if (cd_cw(10, 0, 0, 0)) return -1;
    if (cd_cw(12, 0, 0, 0)) return -1;
    return cd_sync(0, 0) == 2 ? 0 : -1;
}

static int32_t cd_reset(int32_t mode) {
    /* 80043450 CdReset */
    if (mode == 2) {
        cd_initintr();
        return 1;
    }
    if (cd_init()) return 0;
    if (mode == 1 && cd_initvol()) return 0;
    return 1;
}

static int cd_wait_fifo_then(uint32_t chcr, int wait_done) {
    /* tail of 80045090 / 80045190 */
    while (!g_driver.quit && !(cd_r8(0) & 0x40u)) driver_spin(16u);
    cd_w32(CD_C_CHCR, chcr);
    if (wait_done)
        while (!g_driver.quit && (cd_r32(CD_C_CHCR) & 0x01000000u)) driver_spin(16u);
    else
        (void)cd_r32(CD_C_CHCR);
    return 0;
}

static int32_t cd_getsector(uint32_t madr, uint32_t size) {
    /* 80045090: BFRD, DMA3 burst, wait for completion */
    cd_w8(0, 0);
    cd_w8(3, 0x80);
    cd_w32(CD_C_CDDELAY, 0x00020943u);
    cd_w32(CD_C_COMDELAY, 0x1323u);
    cd_w32(CD_C_DPCR, cd_r32(CD_C_DPCR) | 0x8000u);
    cd_w32(CD_C_MADR, madr);
    cd_w32(CD_C_BCR, size | 0x10000u);
    (void)cd_wait_fifo_then(0x11000000u, 1);
    cd_w32(CD_C_COMDELAY, 0x1325u);
    if (getenv("MUSASHI_CD_SECTOR_TRACE") && size == 3u)
        fprintf(stderr, "native_boot: CD_SECTOR hdr=%08x want=%d frame=%lu mode=%d rs=%d pac=%u/%u "
                "remain=%d busy=%d lst=%d dsz=%d\n", rd32(madr),
                (int)rd32(0x800AE7ACu), (unsigned long)g_driver.frames, (int)rd32(0x800AE6F8u),
                (int)rd32(0x800AE74Cu), rd8(0x80079A74u), rd8(0x80079A75u), (int)rd32(0x800AE748u),
                (int)rd32(0x800AE720u), (int)rd32(0x800AE6F0u), (int)rd32(0x800AE7A8u));
    return 0;
}

static int32_t cd_getsector2(uint32_t madr, uint32_t size) {
    /* 80045190: the same set-up, started without waiting */
    cd_w8(0, 0);
    cd_w8(3, 0x80);
    cd_w32(CD_C_CDDELAY, 0x21020843u);
    cd_w32(CD_C_COMDELAY, 0x1325u);
    cd_w32(CD_C_DPCR, cd_r32(CD_C_DPCR) | 0x8000u);
    cd_w32(CD_C_MADR, madr);
    cd_w32(CD_C_BCR, size | 0x10000u);
    (void)cd_wait_fifo_then(0x11400100u, 0);
    return 0;
}

static int32_t cd_datasync(int mode) {
    /* 80044F24 */
    cd_to_start(0x80073860u);
    for (;;) {
        if (cd_to_expired() || g_driver.quit) return -1;
        if (!(cd_r32(CD_C_CHCR) & 0x01000000u)) return 0;
        if (mode) return 1;
        driver_spin(CD_SPIN);
    }
}

static void driver_vsync_wait(uint32_t fields) {
    /* VSync(n) from native code: n fields of guest time, interrupts on */
    uint32_t target = vcount() + fields;
    unsigned long guard = 0;
    while (!g_driver.quit && (int32_t)(vcount() - target) < 0) {
        driver_spin(2048u);
        if (++guard > 4000000ul) {
            driver_stop("vsync_wait_no_vblank", F_VSYNC);
            return;
        }
    }
}

/* lane entries */
#define CD_ENTRY(name) static int name(MusashiNativeLaneCall *call)
#define CD_SP() (g_cd_sp = call->r[29] - 0x40u)

CD_ENTRY(hle_cd_init) {
    /* 80043300 CdInit */
    int tries;
    CD_SP();
    for (tries = 4; tries > 0 && !g_driver.quit; --tries) {
        if (cd_reset(1) == 1) {
            wr32(CD_CBSYNC, 0x80043398u);
            wr32(CD_CBREADY, 0x800433C0u);
            wr32(CD_READCB, 0x800433E8u);
            wr32(CD_CB_CFD0, 0);
            call->r[2] = 1;
            return 1;
        }
    }
    fprintf(stderr, "native_boot: FRAME_DRIVER CdInit failed\n");
    call->r[2] = 0;
    return 1;
}
CD_ENTRY(hle_cd_reset) { CD_SP(); call->r[2] = (uint32_t)cd_reset((int32_t)call->r[4]); return 1; }
CD_ENTRY(hle_cd_flush) { CD_SP(); cd_flush(); return 1; }
CD_ENTRY(hle_cd_sync) {
    CD_SP();
    call->r[2] = (uint32_t)cd_sync((int)call->r[4], call->r[5]);
    return 1;
}
CD_ENTRY(hle_cd_ready) {
    CD_SP();
    call->r[2] = (uint32_t)cd_ready((int)call->r[4], call->r[5]);
    return 1;
}
CD_ENTRY(hle_cd_cw) {
    CD_SP();
    call->r[2] = (uint32_t)cd_cw(call->r[4], call->r[5], call->r[6], (int)call->r[7]);
    return 1;
}
CD_ENTRY(hle_cd_getintr) { CD_SP(); call->r[2] = (uint32_t)cd_getintr(); return 1; }
CD_ENTRY(hle_cd_control) {
    CD_SP();
    call->r[2] = (uint32_t)cd_control_common(call->r[4], call->r[5], call->r[6], call->r[6], 0);
    return 1;
}
CD_ENTRY(hle_cd_control_f) {
    CD_SP();
    call->r[2] = (uint32_t)cd_control_common(call->r[4], call->r[5], 0, 0, 1);
    return 1;
}
CD_ENTRY(hle_cd_control_b) {
    CD_SP();
    if (cd_control_common(call->r[4], call->r[5], call->r[6], call->r[6], 0))
        call->r[2] = cd_sync(0, call->r[6]) == 2 ? 1u : 0u;
    else
        call->r[2] = 0;
    return 1;
}
CD_ENTRY(hle_cd_getsector) {
    CD_SP();
    call->r[2] = cd_getsector(call->r[4], call->r[5]) == 0;
    return 1;
}
CD_ENTRY(hle_cd_getsector2) {
    CD_SP();
    call->r[2] = cd_getsector2(call->r[4], call->r[5]) == 0;
    return 1;
}
CD_ENTRY(hle_cd_datasync) { CD_SP(); call->r[2] = (uint32_t)cd_datasync((int)call->r[4]); return 1; }
CD_ENTRY(hle_cd_data_callback) {
    /* 800439D4 CdDataCallback(f) = DMACallback(3, f) */
    uint32_t previous = 0;
    if (!g_driver.ops || !g_driver.ops->dma_irq ||
        !musashi_boot_call_80042f8c(g_driver.memory, g_driver.ops->dma_irq, 3,
                                    call->r[4], &previous))
        driver_stop("CdDataCallback_refused", 0x800439D4u);
    call->r[2] = previous;
    return 1;
}
CD_ENTRY(hle_cd_irq) {   /* 80045290 */
    uint32_t saved = g_cd_sp;
    CD_SP();
    cd_service();
    g_cd_sp = saved;
    return 1;
}
CD_ENTRY(hle_cd_initvol) { CD_SP(); call->r[2] = (uint32_t)cd_initvol(); return 1; }
CD_ENTRY(hle_cd_initintr) { CD_SP(); cd_initintr(); return 1; }
CD_ENTRY(hle_cd_init_body) { CD_SP(); call->r[2] = (uint32_t)cd_init(); return 1; }

static int cd_xchg(MusashiNativeLaneCall *call, uint32_t cell) {
    call->r[2] = rd32(cell);
    wr32(cell, call->r[4]);
    return 1;
}
CD_ENTRY(hle_cd_sync_callback) { return cd_xchg(call, CD_CBSYNC); }      /* 8004359C */
CD_ENTRY(hle_cd_ready_callback) { return cd_xchg(call, CD_CBREADY); }    /* 800435B4 */
CD_ENTRY(hle_cd_set_debug) { return cd_xchg(call, CD_DEBUG); }           /* 800434DC */
CD_ENTRY(hle_cd_read_callback) { return cd_xchg(call, CD_READCB); }      /* 8004654C */
CD_ENTRY(hle_cd_cb_cfd0) { return cd_xchg(call, CD_CB_CFD0); }           /* 80046564 */
CD_ENTRY(hle_cd_status) { call->r[2] = rd8(CD_STATUS); return 1; }       /* 80043410 */
CD_ENTRY(hle_cd_mode) { call->r[2] = rd8(CD_MODE); return 1; }           /* 80043420 */
CD_ENTRY(hle_cd_lastcom) { call->r[2] = rd8(CD_COM); return 1; }         /* 80043430 */
CD_ENTRY(hle_cd_lastpos) { call->r[2] = CD_POS; return 1; }              /* 80043440 */
CD_ENTRY(hle_cd_get_cbe8) { call->r[2] = rd32(0x8006CBE8u); return 1; }  /* 80043078 */
CD_ENTRY(hle_cd_comstr) {
    /* 800434F4: command name pointer (28 commands) or "none" */
    uint32_t c = call->r[4] & 0xFFu;
    call->r[2] = c < 28u ? rd32(0x8006CCACu + c * 4u) : 0x80073614u;
    return 1;
}
CD_ENTRY(hle_cd_intstr) {
    uint32_t c = call->r[4] & 0xFFu;
    call->r[2] = c < 7u ? rd32(0x8006CD2Cu + c * 4u) : 0x80073614u;
    return 1;
}
static int cd_deliver(uint32_t spec) {
    /* 80043398 / 800433C0 / 800433E8: DeliverEvent(F0000003, spec) (B0:07) */
    if (!g_driver.ops || !g_driver.ops->deliver_event ||
        !g_driver.ops->deliver_event(g_driver.ops->user, 0xF0000003u, spec))
        driver_stop("DeliverEvent_refused", 0x8005CE68u);
    return 1;
}
CD_ENTRY(hle_cd_cb_sync_default) { (void)call; return cd_deliver(0x20u); }
CD_ENTRY(hle_cd_cb_ready_default) { (void)call; return cd_deliver(0x40u); }

static uint32_t bcd2int(uint8_t b) { return (uint32_t)(b >> 4) * 10u + (b & 15u); }

static uint32_t cd_get_toc(uint32_t loc) {
    /* 800430DC(1, loc): GetTN, then GetTD for the lead-out (track 0) and
     * each track; loc[k] = {mm, ss, 0, -}. Returns the track count. */
    uint32_t old = rd32(CD_CBSYNC), first, last, t, n = 1, res = g_cd_sp + 0x18u,
             param = g_cd_sp + 0x20u, out = loc + 4u;
    wr32(CD_CBSYNC, 0);
    if (!(cd_control_common(19, 0, res, res, 0) && cd_sync(0, res) == 2)) goto fail;
    first = bcd2int(rd8(res + 1u));
    last = bcd2int(rd8(res + 2u));
    wr8(param, 0);
    if (!(cd_control_common(20, param, res, res, 0) && cd_sync(0, res) == 2)) goto fail;
    wr8(loc, rd8(res + 1u));
    wr8(loc + 1u, rd8(res + 2u));
    wr8(loc + 2u, 0);
    for (t = first; t <= last; ++t) {
        wr8(param, (uint8_t)(((t / 10u) << 4) | (t % 10u)));
        if (!(cd_control_common(20, param, res, res, 0) && cd_sync(0, res) == 2)) goto fail;
        ++n;
        wr8(out, rd8(res + 1u));
        wr8(out + 2u, 0);
        wr8(out + 1u, rd8(res + 2u));
        out += 4u;
    }
    wr32(CD_CBSYNC, old);
    return n - 1u;
fail:
    wr32(CD_CBSYNC, old);
    return 0;
}
CD_ENTRY(hle_cd_get_toc) { CD_SP(); call->r[2] = cd_get_toc(call->r[4]); return 1; }
CD_ENTRY(hle_cd_get_toc2) { CD_SP(); call->r[2] = cd_get_toc(call->r[5]); return 1; }

static int cd_controlb(uint32_t com, uint32_t param, uint32_t res) {
    return cd_control_common(com, param, res, res, 0) && cd_sync(0, res) == 2;
}

CD_ENTRY(hle_cd_disk_ready) {
    /* 80046630(mode): Nop; shell open -> 0x10; GetTN until the drive
     * spins (mode 1: one try) */
    uint32_t res = call->r[29] - 0x30u, ok, tries = 0;
    uint8_t st;
    g_cd_sp = call->r[29] - 0x80u;
    (void)cd_controlb(1, 0, res);
    if (rd8(res) & 0x10u) { call->r[2] = 16; return 1; }
    ok = (uint32_t)cd_controlb(19, 0, res);
    if (call->r[4] == 1u) {
        call->r[2] = (rd8(res) == 2u && ok) ? 2u : 5u;
        return 1;
    }
    for (;;) {
        if (g_driver.quit) { call->r[2] = 5; return 1; }
        st = rd8(res);
        if (st & 2u) {
            if (st == 2u && ok) { call->r[2] = 2; return 1; }
            driver_vsync_wait(30);
            ok = (uint32_t)cd_controlb(19, 0, res);
            continue;
        }
        driver_vsync_wait(30);
        ok = (uint32_t)cd_controlb(19, 0, res);
        if (++tries >= 10u) { call->r[2] = 5; return 1; }
    }
}

CD_ENTRY(hle_cd_disk_type) {
    /* 8004674C: Getstat; ReadS at 00:02:16 (sector 16); wait for a sector;
     * Pause; read 2048 bytes; "CD001" at byte 1 -> 2 (PlayStation/ISO),
     * else 1; no sector: 0x10 shell open, 1 error with seek, 0/1 status */
    uint32_t frame = call->r[29] - 2096u, res = frame + 2072u, pos = frame + 16u,
             buf = frame + 24u, s0 = 0, i;
    int32_t r;
    g_cd_sp = frame - 0x40u;
    (void)cd_control_common(1, 0, res, res, 0);
    if (rd8(res) & 0x10u) { call->r[2] = 16; return 1; }
    {   /* CdIntToPos(16, pos) */
        uint32_t l = 16u + 150u, m = l / 4500u, sec = (l / 75u) % 60u, f = l % 75u;
        wr8(pos, (uint8_t)(((m / 10u) << 4) | (m % 10u)));
        wr8(pos + 1u, (uint8_t)(((sec / 10u) << 4) | (sec % 10u)));
        wr8(pos + 2u, (uint8_t)(((f / 10u) << 4) | (f % 10u)));
    }
    (void)cd_control_common(27, pos, 0, 0, 0);
    for (;;) {
        r = cd_ready(0, res);
        ++s0;
        if (r == 1 || s0 >= 10u || g_driver.quit) break;
        (void)cd_control_common(27, pos, 0, 0, 0);
    }
    if (r == 1) {
        static const char iso[5] = {'C', 'D', '0', '0', '1'};
        (void)cd_control_common(9, 0, 0, 0, 0);
        (void)cd_getsector(buf, 512u);
        for (i = 0; i < 5u && rd8(buf + 1u + i) == (uint8_t)iso[i]; ++i) {}
        call->r[2] = i == 5u ? 2u : 1u;
        return 1;
    }
    if (rd8(res) & 0x10u) { call->r[2] = 16; return 1; }
    if ((rd8(res) & 1u) && (rd8(res + 1u) & 0x40u)) { call->r[2] = 1; return 1; }
    call->r[2] = (rd8(res) & 2u) ? 1u : 0u;
    return 1;
}


/* ---- libcd CdRead / CdSearchFile (retail 8004637C..80046548, 80045374) */
enum {
    CR_TOTAL = 0x8006CFA0u, CR_BUF0 = 0x8006CFA4u, CR_BUF = 0x8006CFA8u,
    CR_MODE = 0x8006CFACu, CR_SIZE = 0x8006CFB0u, CR_LEFT = 0x8006CFB4u,
    CR_LAST = 0x8006CFB8u, CR_START = 0x8006CFBCu, CR_POS = 0x8006CFC0u,
    CR_SVSYNC = 0x8006CFC4u, CR_SVREADY = 0x8006CFC8u, CR_SVDMA = 0x8006CFCCu,
    CR_RESULT = 0x8006CFD4u, CR_READY_CB = 0x80045D00u, CR_DMA_CB = 0x80045FD0u,
    CS_NOPEN_SEEN = 0x8006CF98u, CS_SECTOR = 0x80078000u, CS_FILES = 0x800763F8u
};

static uint32_t cd_dmacb(uint32_t f) {
    uint32_t previous = 0;
    if (!g_driver.ops || !g_driver.ops->dma_irq ||
        !musashi_boot_call_80042f8c(g_driver.memory, g_driver.ops->dma_irq, 3, f, &previous))
        driver_stop("DMACallback3_refused", 0x80042F8Cu);
    return previous;
}

static void cd_inttopos(uint32_t lba, uint32_t pos) {
    uint32_t l = lba + 150u, m = l / 4500u, s = (l / 75u) % 60u, f = l % 75u;
    wr8(pos, (uint8_t)(((m / 10u) << 4) | (m % 10u)));
    wr8(pos + 1u, (uint8_t)(((s / 10u) << 4) | (s % 10u)));
    wr8(pos + 2u, (uint8_t)(((f / 10u) << 4) | (f % 10u)));
}

static uint32_t cd_postoint(uint32_t pos) {
    return (bcd2int(rd8(pos)) * 60u + bcd2int(rd8(pos + 1u))) * 75u + bcd2int(rd8(pos + 2u)) - 150u;
}

static void cd_read_finish(void) {
    /* restore the caller's callbacks; Pause */
    wr32(CD_CBSYNC, rd32(CR_SVSYNC));
    wr32(CD_CBREADY, rd32(CR_SVREADY));
    if (rd32(CD_CB_CFD0) & 1u) (void)cd_dmacb(rd32(CR_SVDMA));
    (void)cd_control_common(9, 0, 0, 0, 1);
}

static int32_t cd_read_start(int retry) {
    /* 800460CC: (re)issue Setloc/Setmode/ReadN for the current request */
    uint32_t param = g_cd_sp + 0x18u, mode;
    wr32(CD_CBSYNC, 0);
    wr32(CD_CBREADY, 0);
    if (rd32(CD_CB_CFD0) & 1u) (void)cd_dmacb(0);
    if (rd8(CD_STATUS) & 0x10u) {
        if (!(vcount() & 0x3Fu)) fprintf(stderr, "native_boot: CdRead: Shell open...\n");
        (void)cd_control_common(1, 0, 0, 0, 1);
        wr32(CR_START, vcount());
        wr32(CR_LEFT, UINT32_MAX);
        return -1;
    }
    if (retry) {
        fprintf(stderr, "native_boot: CdRead: retry...\n");
        (void)cd_control_common(9, 0, 0, 0, 0);
        if (!cd_control_common(2, CD_POS, 0, 0, 0)) { wr32(CR_LEFT, UINT32_MAX); return -1; }
    }
    cd_flush();
    mode = rd32(CR_MODE) & 0xFFu;
    wr8(param, (uint8_t)mode);
    if ((mode != rd8(CD_MODE) || retry) && !cd_control_common(14, param, 0, 0, 0)) {
        wr32(CR_LEFT, UINT32_MAX);
        return -1;
    }
    wr32(CR_POS, cd_postoint(CD_POS));
    wr32(CD_CBREADY, CR_READY_CB);
    if (rd32(CD_CB_CFD0) & 1u) (void)cd_dmacb(CR_DMA_CB);
    wr32(CR_BUF, rd32(CR_BUF0));
    (void)cd_control_common(6, 0, 0, 0, 1);
    wr32(CR_LEFT, rd32(CR_TOTAL));
    wr32(CR_LAST, vcount());
    return (int32_t)rd32(CR_LEFT);
}

static int32_t cd_read(uint32_t sectors, uint32_t buf, uint32_t mode) {
    /* 8004637C CdRead(sectors, buf, mode) */
    uint32_t m = mode & 0x30u;
    wr32(CR_MODE, mode);
    wr32(CR_SIZE, m == 0u ? 512u : m == 0x20u ? 585u : 582u);
    wr32(CR_MODE, mode | 0x20u);
    wr32(CR_BUF0, buf);
    wr32(CR_TOTAL, sectors);
    wr32(CR_SVSYNC, rd32(CD_CBSYNC)); wr32(CD_CBSYNC, 0);
    wr32(CR_SVREADY, rd32(CD_CBREADY)); wr32(CD_CBREADY, 0);
    if (rd32(CD_CB_CFD0) & 1u) wr32(CR_SVDMA, cd_dmacb(0));
    wr32(CR_START, vcount());
    if (rd8(CD_STATUS) & 0xE0u) (void)cd_controlb(9, 0, 0);
    return cd_read_start(0) > 0;
}

static int32_t cd_read_sync(int mode, uint32_t result) {
    /* 80046480 CdReadSync */
    int32_t left;
    for (;;) {
        if (g_driver.quit) { left = -1; break; }
        if ((int32_t)(vcount() - (rd32(CR_START) + 1200u)) > 0) {
            left = -1;
        } else if ((int32_t)rd32(CR_LEFT) < 0 ||
                   (int32_t)(vcount() - (rd32(CR_LAST) + 60u)) > 0) {
            (void)cd_read_start(1);
            left = (int32_t)rd32(CR_TOTAL);
        } else {
            left = (int32_t)rd32(CR_LEFT);
        }
        if (mode || left <= 0) break;
        driver_spin(CD_SPIN);
    }
    (void)cd_ready(1, result);
    return left;
}

static void cd_read_tail(uint32_t result) {
    /* 80045EA4: timeout / completion check after each sector */
    int32_t left;
    wr32(CR_LAST, vcount());
    if ((int32_t)rd32(CR_LEFT) < 0) (void)cd_read_start(1);
    if ((int32_t)(vcount() - (rd32(CR_START) + 1200u)) > 0) wr32(CR_LEFT, UINT32_MAX);
    left = (int32_t)rd32(CR_LEFT);
    if (left != 0 && (int32_t)(vcount() - (rd32(CR_START) + 1200u)) <= 0) return;
    cd_read_finish();
    if (rd32(CD_READCB)) (void)cd_call2(rd32(CD_READCB), left == 0 ? 2u : 5u, result);
}

CD_ENTRY(hle_cd_read_ready_cb) {
    /* 80045D00(intr, result): one sector per data-ready interrupt */
    uint32_t intr = call->r[4] & 0xFFu, result = call->r[5], hdr = call->r[29] - 0x10u;
    CD_SP();
    wr32(CR_RESULT, result);
    if (intr != 1u) {
        wr32(CR_LEFT, UINT32_MAX);
    } else if ((int32_t)rd32(CR_LEFT) > 0) {
        if (rd32(CR_SIZE) == 512u) {
            /* header + subheader first, checked against the expected sector */
            if (rd32(CD_CB_CFD0) & 1u) {
                (void)cd_dmacb(0);
                (void)cd_getsector2(hdr, 3);
                (void)cd_datasync(0);
                (void)cd_dmacb(CR_DMA_CB);
            } else {
                (void)cd_getsector(hdr, 3);
            }
            if (cd_postoint(hdr) != rd32(CR_POS)) {
                fprintf(stderr, "native_boot: CdRead: sector error\n");
                wr32(CR_LEFT, UINT32_MAX);
            }
        }
        if (rd32(CD_CB_CFD0) & 1u) {
            (void)cd_getsector2(rd32(CR_BUF), rd32(CR_SIZE));
        } else {
            (void)cd_getsector(rd32(CR_BUF), rd32(CR_SIZE));
            wr32(CR_BUF, rd32(CR_BUF) + rd32(CR_SIZE) * 4u);
            wr32(CR_LEFT, rd32(CR_LEFT) - 1u);
            wr32(CR_POS, rd32(CR_POS) + 1u);
        }
    }
    cd_read_tail(result);
    return 1;
}

CD_ENTRY(hle_cd_read_dma_cb) {
    /* 80045FD0: DMA-completion form of the sector step */
    CD_SP();
    wr32(CR_BUF, rd32(CR_BUF) + rd32(CR_SIZE) * 4u);
    wr32(CR_LEFT, rd32(CR_LEFT) - 1u);
    wr32(CR_POS, rd32(CR_POS) + 1u);
    if (rd32(CR_LEFT) == 0u) {
        cd_read_finish();
        if (rd32(CD_READCB)) (void)cd_call2(rd32(CD_READCB), 2u, rd32(CR_RESULT));
    }
    return 1;
}

CD_ENTRY(hle_cd_read) {
    CD_SP();
    call->r[2] = (uint32_t)cd_read(call->r[4], call->r[5], call->r[6]);
    return 1;
}
CD_ENTRY(hle_cd_read_sync) {
    CD_SP();
    call->r[2] = (uint32_t)cd_read_sync((int)call->r[4], call->r[5]);
    return 1;
}
CD_ENTRY(hle_cd_read_start) {
    CD_SP();
    call->r[2] = (uint32_t)cd_read_start((int)call->r[4]);
    return 1;
}
CD_ENTRY(hle_cd_read_break) {
    /* 800462E0 CdReadBreak */
    CD_SP();
    if (rd32(CD_CB_CFD0) & 1u) (void)cd_datasync(0);
    wr32(CR_LEFT, 0);
    cd_read_finish();
    return 1;
}

static int cd_read_lba(uint32_t lba, uint32_t sectors, uint32_t buf) {
    /* 80045C94: Setloc, CdRead(mode 0x80), CdReadSync(0) == 0 */
    uint32_t pos = g_cd_sp + 0x20u;
    cd_inttopos(lba, pos);
    (void)cd_control_common(2, pos, 0, 0, 0);
    (void)cd_read(sectors, buf, 0x80u);
    return cd_read_sync(0, 0) == 0;
}
CD_ENTRY(hle_cd_read_lba) {
    CD_SP();
    call->r[2] = (uint32_t)cd_read_lba(call->r[5], call->r[4], call->r[6]);
    return 1;
}

/* CdSearchFile: the ISO 9660 path table and directory records, read
 * through CdRead into the library's sector buffer at 80078000. A found
 * entry is cached in the library's file table (CdlFILE, 24 bytes:
 * pos[4] BCD, size, name[16]) and copied out. */
static struct { uint32_t lba; uint16_t parent; char name[32]; } g_cs_dirs[128];
static unsigned g_cs_ndirs;

static uint32_t le32_at(uint32_t a) {
    return rd8(a) | (uint32_t)rd8(a + 1u) << 8 | (uint32_t)rd8(a + 2u) << 16 |
           (uint32_t)rd8(a + 3u) << 24;
}

static int cd_search_load_paths(void) {
    uint32_t ptsize, ptlba, off = 0;
    if (!cd_read_lba(16, 1, CS_SECTOR)) return 0;
    if (rd8(CS_SECTOR) != 1u || rd8(CS_SECTOR + 1u) != 'C' || rd8(CS_SECTOR + 2u) != 'D' ||
        rd8(CS_SECTOR + 3u) != '0' || rd8(CS_SECTOR + 4u) != '0' || rd8(CS_SECTOR + 5u) != '1') {
        fprintf(stderr, "native_boot: CdSearchFile: disc error\n");
        return 0;
    }
    ptsize = le32_at(CS_SECTOR + 132u);
    ptlba = le32_at(CS_SECTOR + 140u);
    if (!cd_read_lba(ptlba, 1, CS_SECTOR)) return 0;
    g_cs_ndirs = 0;
    if (ptsize > 2048u) ptsize = 2048u;
    while (off + 8u <= ptsize && g_cs_ndirs < 128u) {
        uint32_t len = rd8(CS_SECTOR + off), i;
        if (!len) break;
        g_cs_dirs[g_cs_ndirs].lba = le32_at(CS_SECTOR + off + 2u);
        g_cs_dirs[g_cs_ndirs].parent = (uint16_t)(rd8(CS_SECTOR + off + 6u) |
                                                  rd8(CS_SECTOR + off + 7u) << 8);
        for (i = 0; i < len && i < 31u; ++i)
            g_cs_dirs[g_cs_ndirs].name[i] = (char)rd8(CS_SECTOR + off + 8u + i);
        g_cs_dirs[g_cs_ndirs].name[i] = 0;
        ++g_cs_ndirs;
        off += 8u + len + (len & 1u);
    }
    return g_cs_ndirs != 0;
}

static uint32_t cd_search_file(uint32_t fp, uint32_t name) {
    char comp[8][32];
    unsigned ncomp = 0, i, dir = 1;   /* path-table records are 1-based */
    uint32_t p = name, off;
    if (rd32(CS_NOPEN_SEEN) != rd32(CD_NOPEN)) {
        if (!cd_search_load_paths()) return 0;
        wr32(CS_NOPEN_SEEN, rd32(CD_NOPEN));
    }
    if (rd8(p) != '\\') return 0;
    while (rd8(p) == '\\' && ncomp < 8u) {
        unsigned n = 0;
        ++p;
        while (rd8(p) && rd8(p) != '\\' && n < 31u) comp[ncomp][n++] = (char)rd8(p++);
        comp[ncomp][n] = 0;
        ++ncomp;
    }
    if (rd8(p) || !ncomp || !comp[ncomp - 1u][0]) {
        fprintf(stderr, "native_boot: CdSearchFile: path level error\n");
        return 0;
    }
    for (i = 0; i + 1u < ncomp; ++i) {
        unsigned d, found = 0;
        for (d = 0; d < g_cs_ndirs; ++d)
            if (g_cs_dirs[d].parent == dir && d + 1u != dir &&
                !strcmp(g_cs_dirs[d].name, comp[i])) { found = d + 1u; break; }
        if (!found) {
            fprintf(stderr, "native_boot: CdSearchFile: dir not found\n");
            return 0;
        }
        dir = found;
    }
    if (dir > g_cs_ndirs || !cd_read_lba(g_cs_dirs[dir - 1u].lba, 1, CS_SECTOR)) return 0;
    for (off = 0; off + 33u < 2048u;) {
        uint32_t len = rd8(CS_SECTOR + off), nlen, k;
        char ident[32];
        if (!len) break;
        nlen = rd8(CS_SECTOR + off + 32u);
        for (k = 0; k < nlen && k < 31u; ++k) ident[k] = (char)rd8(CS_SECTOR + off + 33u + k);
        ident[k] = 0;
        if (!strcmp(ident, comp[ncomp - 1u])) {
            uint32_t entry = CS_FILES, size = le32_at(CS_SECTOR + off + 10u);
            cd_inttopos(le32_at(CS_SECTOR + off + 2u), entry);
            wr8(entry + 3u, 0);
            wr32(entry + 4u, size);
            for (k = 0; k < 16u; ++k) wr8(entry + 8u + k, 0);
            for (k = 0; k < 15u && ident[k]; ++k) wr8(entry + 8u + k, (uint8_t)ident[k]);
            for (k = 0; k < 24u; ++k) wr8(fp + k, rd8(entry + k));
            return entry;
        }
        off += len;
    }
    fprintf(stderr, "native_boot: CdSearchFile: %s not found\n", comp[ncomp - 1u]);
    return 0;
}
CD_ENTRY(hle_cd_search_file) {
    CD_SP();
    g_cd_sp = call->r[29] - 0x80u;
    call->r[2] = cd_search_file(call->r[4], call->r[5]);
    return 1;
}


/* ---- libspu / libsnd startup (retail 8003A424..8003C928, 8003D518..
 * 8003D62C, 8003FA64..80040934), written from the retail disassembly. The
 * library reaches the SPU through pointer cells (8006B54C regs, 8006B550..
 * 8006B55C DMA4 MADR/BCR/CHCR/DPCR, 8006B560 SPU_DELAY; libsnd's 8006B8FC);
 * a queued SpuSetEnv redirects voice-bit writes to the RAM shadow 800A6288. */
enum {
    SP_REGS = 0x8006B54Cu, SP_MADR = 0x8006B550u, SP_BCR = 0x8006B554u,
    SP_CHCR = 0x8006B558u, SP_DPCR = 0x8006B55Cu, SP_DELAY = 0x8006B560u,
    SP_TADDR = 0x8006B564u, SP_DMAINIT = 0x8006B568u, SP_G56C = 0x8006B56Cu,
    SP_G570 = 0x8006B570u, SP_SHIFT = 0x8006B574u, SP_G578 = 0x8006B578u,
    SP_G57C = 0x8006B57Cu, SP_G580 = 0x8006B580u, SP_TCB = 0x8006B584u,
    SP_G588 = 0x8006B588u, SP_ZERO16 = 0x8006B58Cu, SP_TMODE = 0x8006B59Cu,
    SP_TADR = 0x8006B5A0u, SP_TBLK = 0x8006B5A4u, SP_MNUM = 0x8006B5A8u,
    SP_MCNT = 0x8006B5ACu, SP_MTBL = 0x8006B5B0u, SP_REVTOP = 0x8006B5B4u,
    SP_ENV = 0x8006B544u, SP_EVINIT = 0x8006B548u, SP_EVENT = 0x8006B0E0u,
    SP_G0E4 = 0x8006B0E4u, SP_G0E8 = 0x8006B0E8u, SP_REVON = 0x8006B0ECu,
    SP_REVRSV = 0x8006B0F0u, SP_REVADDR = 0x8006B0F4u, SP_REVMODE = 0x8006B0FCu,
    SP_DEPTHL = 0x8006B100u, SP_DEPTHR = 0x8006B102u, SP_DELAYV = 0x8006B104u,
    SP_FEEDBK = 0x8006B108u, SP_G10C = 0x8006B10Cu, SP_VBITS = 0x8006B110u,
    SP_VOLTBL = 0x8006B112u, SP_ZERO1K = 0x8006B144u, SP_PRESET = 0x8006B604u,
    SP_SHADOW = 0x800A6288u, SP_DMA_IRQ = 0x8003AA18u, SV_REGS = 0x8006B8FCu
};
enum { SR_MVOLL = 384, SR_MVOLR = 386, SR_RVOLL = 388, SR_RVOLR = 390,
       SR_KONL = 392, SR_KONH = 394, SR_KOFFL = 396, SR_KOFFH = 398,
       SR_PMONL = 400, SR_NONL = 404, SR_EONL = 408, SR_EONH = 410,
       SR_MBASE = 418, SR_TADDR = 422, SR_FIFO = 424, SR_CNT = 426,
       SR_TCTRL = 428, SR_STAT = 430, SR_CDL = 432, SR_EXTL = 436 };

static uint16_t hw16(uint32_t a) {
    uint16_t v = 0;
    if ((a & 0xFFFFFC00u) == 0x1F801C00u) {
        const MusashiCdSpuDevice *d = g_driver.devices ? g_driver.devices->cd_spu : NULL;
        if (!d || !d->read16 || !d->read16(d->userdata, a, &v)) driver_stop("spu_read", a);
        return v;
    }
    return rd16(a);
}
static void hw16w(uint32_t a, uint16_t v) {
    if ((a & 0xFFFFFC00u) == 0x1F801C00u) {
        const MusashiCdSpuDevice *d = g_driver.devices ? g_driver.devices->cd_spu : NULL;
        if (!d || !d->write16 || !d->write16(d->userdata, a, v)) driver_stop("spu_write", a);
        return;
    }
    wr16(a, v);
}
static uint32_t hw32(uint32_t a) {
    uint32_t v = 0;
    if ((a & 0xFFFFF000u) == 0x1F801000u) {
        const MusashiCdRegisterDevice *d = cd_dev();
        if (!d || !d->read32 || !d->read32(d->userdata, a, &v)) driver_stop("io_read32", a);
        return v;
    }
    return rd32(a);
}
static void hw32w(uint32_t a, uint32_t v) {
    if ((a & 0xFFFFF000u) == 0x1F801000u) {
        const MusashiCdRegisterDevice *d = cd_dev();
        if (!d || !d->write32 || !d->write32(d->userdata, a, v)) driver_stop("io_write32", a);
        return;
    }
    wr32(a, v);
}
static uint16_t spu_r(unsigned off) { return hw16(rd32(SP_REGS) + off); }
static void spu_w(unsigned off, uint16_t v) { hw16w(rd32(SP_REGS) + off, v); }

static uint32_t hle_call(uint32_t pc, unsigned argc, uint32_t a0, uint32_t a1,
                         uint32_t a2, uint32_t a3) {
    uint32_t a[4] = {a0, a1, a2, a3};
    return call_at(g_cd_sp, pc, argc, a);
}

static void spu_delay(void) {
    /* 8003B0E4: a fixed 60-step multiply loop */
    if (g_driver.ops && g_driver.ops->spend) (void)g_driver.ops->spend(g_driver.ops->user, 600u);
}

/* retail 3840-iteration register polls; the timeout message as retail */
static int spu_poll(unsigned off, uint16_t mask, uint16_t want, const char *what) {
    unsigned i;
    for (i = 0; i <= 3840u; ++i) {
        if ((spu_r(off) & mask) == want) return 1;
        if (g_driver.ops && g_driver.ops->spend) (void)g_driver.ops->spend(g_driver.ops->user, 8u);
    }
    fprintf(stderr, "native_boot: SPU:T/O [%s]\n", what);
    return 0;
}

static void spu_write_manual(uint32_t src, uint32_t size) {
    /* 8003A84C: FIFO writes in 64-byte bursts */
    uint16_t stat = spu_r(SR_STAT) & 0x7FFu;
    spu_w(SR_TADDR, rd16(SP_TADDR));
    spu_delay();
    while (size) {
        uint32_t n = size < 65u ? size : 64u, i;
        for (i = 0; i < n; i += 2u, src += 2u) spu_w(SR_FIFO, rd16(src));
        spu_w(SR_CNT, (uint16_t)((spu_r(SR_CNT) & 0xFFCFu) | 0x10u));
        spu_delay();
        (void)spu_poll(SR_STAT, 0x400u, 0, "wait (wrdy H -> L)");
        spu_delay();
        spu_delay();
        size -= n;
    }
    spu_w(SR_CNT, spu_r(SR_CNT) & 0xFFCFu);
    (void)spu_poll(SR_STAT, 0x7FFu, stat, "wait (dmaf clear/W)");
}

static void spu_init_hw(int mode) {
    /* 8003A5B8 _spu_init */
    unsigned v;
    hw32w(rd32(SP_DPCR), hw32(rd32(SP_DPCR)) | 0xB0000u);
    wr32(SP_DMAINIT, 0); wr32(SP_G56C, 0); wr16(SP_TADDR, 0);
    spu_w(SR_MVOLL, 0); spu_w(SR_MVOLR, 0); spu_w(SR_CNT, 0);
    spu_delay();
    spu_w(SR_MVOLL, 0); spu_w(SR_MVOLR, 0);
    (void)spu_poll(SR_STAT, 0x7FFu, 0, "wait (reset)");
    wr32(SP_G570, 2); wr32(SP_SHIFT, 3); wr32(SP_G578, 8); wr32(SP_G57C, 7);
    spu_w(SR_TCTRL, 4);
    spu_w(SR_RVOLL, 0); spu_w(SR_RVOLR, 0);
    spu_w(SR_KOFFL, 0xFFFFu); spu_w(SR_KOFFH, 0xFFFFu);
    spu_w(SR_EONL, 0); spu_w(SR_EONH, 0);
    for (v = 0; v < 10u; ++v) wr16(0x800A6410u + v * 2u, 0);
    if (!mode) {
        wr16(SP_TADDR, 0x200u);
        for (v = 0; v < 4u; ++v) spu_w(SR_PMONL + v * 2u, 0);
        for (v = 0; v < 4u; ++v) spu_w(SR_CDL + v * 2u, 0);
        spu_write_manual(SP_ZERO16, 16u);
        for (v = 0; v < 24u; ++v) {
            spu_w(v * 16u + 0u, 0); spu_w(v * 16u + 2u, 0);
            spu_w(v * 16u + 4u, 0x3FFFu); spu_w(v * 16u + 6u, 0x200u);
            spu_w(v * 16u + 8u, 0); spu_w(v * 16u + 10u, 0);
        }
        spu_w(SR_KONL, 0xFFFFu); spu_w(SR_KONH, 0xFFu);
        for (v = 0; v < 4u; ++v) spu_delay();
        spu_w(SR_KOFFL, 0xFFFFu); spu_w(SR_KOFFH, 0xFFu);
        for (v = 0; v < 4u; ++v) spu_delay();
    }
    wr32(SP_G580, 1);
    spu_w(SR_CNT, 0xC000u);
    wr32(SP_TCB, 0); wr32(SP_G588, 0);
}

static void spu_init_events(void) {
    /* 8003A53C: the DMA4 completion event, once */
    if (rd32(SP_EVINIT)) return;
    wr32(SP_EVINIT, 1);
    (void)hle_call(0x8005CF08u, 0, 0, 0, 0, 0);
    (void)hle_call(0x800425E0u, 2, 4, SP_DMA_IRQ, 0, 0);
    wr32(SP_EVENT, hle_call(0x8005CE78u, 4, 0xF0000009u, 0x20u, 0x2000u, 0));
    (void)hle_call(0x8005CEB8u, 1, rd32(SP_EVENT), 0, 0, 0);
    (void)hle_call(0x8005CF18u, 0, 0, 0, 0, 0);
}

static void spu_init(int mode) {
    /* 8003A444 _SpuInit(mode) */
    unsigned v;
    (void)hle_call(0x80042580u, 0, 0, 0, 0, 0);
    spu_init_hw(mode);
    if (!mode) for (v = 0; v < 24u; ++v) wr16(SP_VOLTBL + v * 2u, 0xC000u);
    spu_init_events();
    wr32(SP_REVON, 0); wr32(SP_REVRSV, 0); wr32(SP_REVMODE, 0);
    wr16(SP_DEPTHL, 0); wr16(SP_DEPTHR, 0); wr32(SP_DELAYV, 0); wr32(SP_FEEDBK, 0);
    wr32(SP_REVADDR, rd32(SP_REVTOP));
    spu_w(SR_MBASE, (uint16_t)rd32(SP_REVTOP));   /* 8003AF04(209, addr, 0) */
    wr32(SP_MNUM, 0); wr32(SP_MCNT, 0); wr32(SP_MTBL, 0);
    wr32(SP_G0E8, 0); wr32(SP_DMAINIT, 0); wr32(SP_G0E4, 0);
    wr32(SP_VBITS, 0); wr32(SP_G10C, 0); wr32(SP_ENV, 0);
}

static int spu_overlap(uint32_t addr) {
    /* 8003B3D0: does a SpuMalloc block lie at or above addr? */
    uint32_t a = addr << rd32(SP_SHIFT), e = rd32(SP_MTBL);
    if (!e) return 0;
    for (;; e += 8u) {
        uint32_t w = rd32(e), start;
        if (w & 0x80000000u) continue;
        if (w & 0x40000000u) return 0;
        start = w & 0x0FFFFFFFu;
        if (start >= a || a < start + rd32(e + 4u)) return 1;
    }
}

static int32_t spu_transfer(int cmd, uint32_t a1, uint32_t a2) {
    /* 8003AB84 _spu_t(cmd, ...) */
    switch (cmd) {
    case 2:
        wr16(SP_TADDR, (uint16_t)(a1 >> rd32(SP_SHIFT)));
        spu_w(SR_TADDR, rd16(SP_TADDR));
        return 0;
    case 1:
    case 0:
        wr32(SP_TMODE, cmd ? 0u : 1u);
        if (!spu_poll(SR_TADDR, 0xFFFFu, rd16(SP_TADDR), "taddr")) return -2;
        spu_w(SR_CNT, (uint16_t)(cmd ? (spu_r(SR_CNT) & 0xFFCFu) | 0x20u : spu_r(SR_CNT) | 0x30u));
        return 0;
    case 3: {
        int rd = rd32(SP_TMODE) == 1u;
        uint32_t d;
        if (!spu_poll(SR_CNT, 0x30u, rd ? 0x30u : 0x20u, "dma mode")) return -2;
        d = rd32(SP_DELAY);
        hw32w(d, (hw32(d) & 0xF0FFFFFFu) | (rd ? 0x22000000u : 0x20000000u));
        wr32(SP_TADR, a1);
        wr32(SP_TBLK, (a2 >> 6) + ((a2 & 63u) != 0));
        hw32w(rd32(SP_MADR), a1);
        hw32w(rd32(SP_BCR), (rd32(SP_TBLK) << 16) | 0x10u);
        hw32w(rd32(SP_CHCR), rd ? 0x01000200u : 0x01000201u);
        return 0;
    }
    default:
        return 0;
    }
}

static int32_t bios_wait_event(int32_t h) {
    /* B0:0A WaitEvent from native code: TestEvent until the event fires;
     * the wait is an interrupt point */
    unsigned long guard = 0;
    for (;;) {
        int32_t r = 0;
        if (!g_driver.ops || !g_driver.ops->bios_event ||
            !g_driver.ops->bios_event(g_driver.ops->user, 0x0Bu, (uint32_t)h, 0, 0, 0, &r))
            driver_stop("TestEvent_refused", 0x8005CEA8u);
        if (r || g_driver.quit) return 1;
        driver_spin(CD_SPIN);
        if (++guard > 20000000ul) { driver_stop("WaitEvent_never", 0x8005CE98u); return 0; }
    }
}

static int32_t spu_clear_reverb(uint32_t mode) {
    /* 8003C0A0 SpuClearReverbWorkArea */
    uint32_t size, addr, saved_init, saved_cb = 0;
    int restore = 0, more;
    if (mode >= 10u || spu_overlap(rd32(SP_REVTOP + mode * 4u))) return -1;
    if (!mode) {
        size = 16u << rd32(SP_SHIFT);
        addr = 0xFFF0u << rd32(SP_SHIFT);
    } else {
        uint32_t top = rd32(SP_REVTOP + mode * 4u);
        size = (0x10000u - top) << rd32(SP_SHIFT);
        addr = top << rd32(SP_SHIFT);
    }
    saved_init = rd32(SP_DMAINIT);
    if (saved_init == 1u) { wr32(SP_DMAINIT, 0); restore = 1; }
    if (rd32(SP_TCB)) { saved_cb = rd32(SP_TCB); wr32(SP_TCB, 0); }
    do {
        uint32_t n;
        more = size > 1024u;
        n = more ? 1024u : size;
        (void)spu_transfer(2, addr, 0);
        (void)spu_transfer(1, 0, 0);
        (void)spu_transfer(3, SP_ZERO1K, n);
        (void)bios_wait_event((int32_t)rd32(SP_EVENT));
        size -= 1024u;
        addr += 1024u;
    } while (more && !g_driver.quit);
    if (restore) wr32(SP_DMAINIT, saved_init);
    if (saved_cb) wr32(SP_TCB, saved_cb);
    return 0;
}

static uint32_t spu_voice_bits(uint32_t on, uint32_t bits, unsigned rlo, unsigned rhi) {
    /* 8003BE98: set/clear a 24-bit voice mask register pair */
    int queued = rd32(SP_ENV) & 1u;
    uint32_t base = queued ? SP_SHADOW : rd32(SP_REGS), cur;
    cur = ((uint32_t)(hw16(base + rhi * 2u) & 0xFFu) << 16) | hw16(base + rlo * 2u);
    if (on == 0u || on == 1u) {
        uint16_t lo = hw16(base + rlo * 2u), hi = hw16(base + rhi * 2u);
        if (on) { lo |= (uint16_t)bits; hi |= (uint16_t)((bits >> 16) & 0xFFu); }
        else { lo &= (uint16_t)~bits; hi &= (uint16_t)~((bits >> 16) & 0xFFu); }
        hw16w(base + rlo * 2u, lo);
        hw16w(base + rhi * 2u, hi);
        if (queued) wr32(SP_VBITS, rd32(SP_VBITS) | (1u << ((rlo - 198u) >> 1)));
        if (on) cur |= bits & 0xFFFFFFu;
        else cur &= ~(bits & 0xFFFFFFu);
    }
    return cur & 0xFFFFFFu;
}

static void spu_set_reverb_regs(uint32_t p) {
    /* 8003B954: the reverb register block 1DC0..1DFE under the mask */
    uint32_t mask = rd32(p);
    unsigned i;
    for (i = 0; i < 32u; ++i)
        if (!mask || (mask & (1u << i))) spu_w(448u + i * 2u, rd16(p + 4u + i * 2u));
}

static int32_t spu_set_reverb_mode_param(uint32_t attr, uint32_t buf) {
    /* 8003B45C SpuSetReverbModeParam(attr{mask, mode, depth.l/r, delay,
     * feedback}); buf is the 68-byte preset copy */
    uint32_t mask = rd32(attr), mode, i;
    int all = !mask, set_mode = 0, set_delay = 0, set_fb = 0, clear = 0, was_on = 0;
    wr32(buf, 0);
    if (all || (mask & 1u)) {
        mode = rd32(attr + 4u);
        if (mode & 0x100u) { mode &= ~0x100u; clear = 1; }
        if (mode >= 10u || spu_overlap(rd32(SP_REVTOP + mode * 4u))) return -1;
        set_mode = 1;
        wr32(SP_REVMODE, mode);
        wr32(SP_REVADDR, rd32(SP_REVTOP + mode * 4u));
        for (i = 0; i < 68u; ++i) wr8(buf + i, rd8(SP_PRESET + mode * 68u + i));
        if (mode == 7u) { wr32(SP_FEEDBK, 127); wr32(SP_DELAYV, 127); }
        else if (mode == 8u) { wr32(SP_FEEDBK, 0); wr32(SP_DELAYV, 127); }
        else { wr32(SP_FEEDBK, 0); wr32(SP_DELAYV, 0); }
    }
    mode = rd32(SP_REVMODE);
    if ((all || (mask & 8u)) && mode >= 7u && mode <= 8u) {
        int32_t delay, d13, d12;
        set_delay = 1;
        if (!set_mode) {
            for (i = 0; i < 68u; ++i) wr8(buf + i, rd8(SP_PRESET + mode * 68u + i));
            wr32(buf, 0x0C011C00u);
        }
        delay = (int32_t)rd32(attr + 12u);
        wr32(SP_DELAYV, (uint32_t)delay);
        d13 = (delay << 13) / 127;
        d12 = (delay << 12) / 127;
        wr16(buf + 24u, (uint16_t)(d13 - rd16(buf + 4u)));
        wr16(buf + 26u, (uint16_t)(d12 - rd16(buf + 6u)));
        wr16(buf + 36u, (uint16_t)(rd16(buf + 38u) + d12));
        wr16(buf + 28u, (uint16_t)(rd16(buf + 30u) + d12));
        wr16(buf + 58u, (uint16_t)(rd16(buf + 62u) + d12));
        wr16(buf + 56u, (uint16_t)(rd16(buf + 60u) + d12));
    }
    if ((all || (mask & 0x10u)) && mode >= 7u && mode <= 8u) {
        int32_t fb;
        set_fb = 1;
        if (!set_mode) {
            if (!set_delay) {
                for (i = 0; i < 68u; ++i) wr8(buf + i, rd8(SP_PRESET + mode * 68u + i));
                wr32(buf, 0x80u);
            } else {
                wr32(buf, rd32(buf) | 0x80u);
            }
        }
        fb = (int32_t)rd32(attr + 16u);
        wr32(SP_FEEDBK, (uint32_t)fb);
        wr16(buf + 18u, (uint16_t)((fb * 129 * 256) / 127));
    }
    if (set_mode) {
        was_on = (spu_r(SR_CNT) >> 7) & 1u;
        if (was_on) spu_w(SR_CNT, spu_r(SR_CNT) & 0xFF7Fu);
        spu_w(SR_RVOLL, 0); spu_w(SR_RVOLR, 0);
        wr16(SP_DEPTHL, 0); wr16(SP_DEPTHR, 0);
    } else {
        if (all || (mask & 2u)) { spu_w(SR_RVOLL, rd16(attr + 8u)); wr16(SP_DEPTHL, rd16(attr + 8u)); }
        if (all || (mask & 4u)) { spu_w(SR_RVOLR, rd16(attr + 10u)); wr16(SP_DEPTHR, rd16(attr + 10u)); }
    }
    if (set_mode || set_delay || set_fb) spu_set_reverb_regs(buf);
    if (clear) (void)spu_clear_reverb(rd32(SP_REVMODE));
    if (set_mode) {
        spu_w(SR_MBASE, (uint16_t)rd32(SP_REVADDR));
        if (was_on) spu_w(SR_CNT, spu_r(SR_CNT) | 0x80u);
    }
    return 0;
}

static uint16_t spu_vol(uint32_t attr, unsigned voff, unsigned moff, int use_mode) {
    /* volume word: raw, or a sweep mode (1..7 -> 8000..E000) with 0..127 */
    int16_t mode = use_mode ? (int16_t)rd16(attr + moff) : 0;
    int16_t v = (int16_t)rd16(attr + voff);
    if (mode >= 1 && mode <= 7) {
        int32_t c = v > 127 ? 127 : v < 0 ? 0 : v;
        return (uint16_t)((0x8000u + (uint32_t)(mode - 1) * 0x1000u) | ((uint32_t)c & 0x7FFFu));
    }
    return (uint16_t)(rd16(attr + voff) & 0x7FFFu);
}

static void spu_set_common_attr(uint32_t attr) {
    /* 8003C598 SpuSetCommonAttr */
    uint32_t m = rd32(attr);
    int all = !m;
    if (all || (m & 1u)) spu_w(SR_MVOLL, spu_vol(attr, 4u, 8u, all || (m & 4u)));
    if (all || (m & 2u)) spu_w(SR_MVOLR, spu_vol(attr, 6u, 10u, all || (m & 8u)));
    if (all || (m & 0x40u)) spu_w(SR_CDL, rd16(attr + 16u));
    if (all || (m & 0x80u)) spu_w(SR_CDL + 2u, rd16(attr + 18u));
    if (all || (m & 0x400u)) spu_w(SR_EXTL, rd16(attr + 28u));
    if (all || (m & 0x800u)) spu_w(SR_EXTL + 2u, rd16(attr + 30u));
    if (all || (m & 0x100u)) spu_w(SR_CNT, rd32(attr + 20u) ? spu_r(SR_CNT) | 4u : spu_r(SR_CNT) & 0xFFFBu);
    if (all || (m & 0x200u)) spu_w(SR_CNT, rd32(attr + 24u) ? spu_r(SR_CNT) | 1u : spu_r(SR_CNT) & 0xFFFEu);
    if (all || (m & 0x1000u)) spu_w(SR_CNT, rd32(attr + 32u) ? spu_r(SR_CNT) | 8u : spu_r(SR_CNT) & 0xFFF7u);
    if (all || (m & 0x2000u)) spu_w(SR_CNT, rd32(attr + 36u) ? spu_r(SR_CNT) | 2u : spu_r(SR_CNT) & 0xFFFDu);
}

/* libsnd voice manager */
enum { SV_REC = 0x80079588u, SV_NVOICE = 0x800AE614u, SV_CUR = 0x800B9B3Au,
       SV_KOFFL = 0x800C7F04u, SV_KOFFH = 0x800C7F06u, SV_KONL = 0x80078D8Cu,
       SV_KONH = 0x80078D8Eu, SV_EONL = 0x80078D90u, SV_EONH = 0x80078D92u,
       SV_DIRTY = 0x800A4620u, SV_REGBUF = 0x800B9B58u, SV_SLOTIDX = 0x800BA1B0u,
       SV_SLOTS = 0x800C7EC0u, SV_NOFLUSH = 0x800BA100u, SV_CB1 = 0x800BA0D0u,
       SV_CB2 = 0x800AE828u };

static void snd_vm_keyoff_cur(void) {
    /* 80040868: key off the voice in 800B9B3A */
    uint32_t v = rd16(SV_CUR), lo = v < 16u ? 1u << v : 0, hi = v < 16u ? 0 : 1u << (v - 16u);
    uint32_t r = SV_REC + v * 52u;
    wr8(r + 27u, 0); wr16(r + 4u, 0); wr16(r, 0);
    wr16(SV_KOFFL, (uint16_t)(rd16(SV_KOFFL) | lo));
    wr16(SV_KONL, (uint16_t)(rd16(SV_KONL) & ~rd16(SV_KOFFL)));
    wr16(SV_KOFFH, (uint16_t)(rd16(SV_KOFFH) | hi));
    wr16(SV_KONH, (uint16_t)(rd16(SV_KONH) & ~rd16(SV_KOFFH)));
}

static void snd_vm_flush(void) {
    /* 8003FA64 SpuVmFlush: envelope scan, dirty voice registers, key words */
    uint32_t c = (rd32(SV_SLOTIDX) + 1u) & 15u, slot = SV_SLOTS + c * 4u, n = rd8(SV_NVOICE), v;
    uint32_t regs = rd32(SV_REGS);
    uint16_t koffl, koffh, konl, konh, eonl, eonh;
    wr32(SV_SLOTIDX, c);
    wr32(slot, 0);
    for (v = 0; v < n; ++v) {
        uint16_t env = hw16(regs + v * 16u + 12u);
        wr16(SV_REC + v * 52u + 6u, env);
        if (!env) wr32(slot, rd32(slot) | (1u << v));
    }
    if (!rd8(SV_NOFLUSH)) {
        uint32_t idle = 0xFFFFFFFFu, i;
        for (i = 0; i < 15u; ++i) idle &= rd32(SV_SLOTS + i * 4u);
        for (v = 0; v < rd8(SV_NVOICE); ++v)
            if (idle & (1u << v)) {
                if (rd8(SV_REC + v * 52u + 27u) == 2u) (void)spu_voice_bits(0, 0xFFFFFFu, 202, 203);
                wr8(SV_REC + v * 52u + 27u, 0);
            }
    }
    wr16(SV_KONL, (uint16_t)(rd16(SV_KONL) & ~rd16(SV_KOFFL)));
    wr16(SV_KONH, (uint16_t)(rd16(SV_KONH) & ~rd16(SV_KOFFH)));
    for (v = 0; v < 24u; ++v) {
        if ((int16_t)rd16(SV_REC + v * 52u + 28u)) (void)hle_call(rd32(SV_CB1), 1, v, 0, 0, 0);
        if ((int16_t)rd16(SV_REC + v * 52u + 40u)) (void)hle_call(rd32(SV_CB2), 1, v, 0, 0, 0);
    }
    for (v = 0; v < 24u; ++v) {
        uint8_t f = rd8(SV_DIRTY + v);
        uint32_t hw = regs + v * 16u, src = SV_REGBUF + v * 16u;
        if (f & 1u) { hw16w(hw, rd16(src)); hw16w(hw + 2u, rd16(src + 2u)); }
        if (f & 4u) hw16w(hw + 4u, rd16(src + 4u));
        if (f & 8u) hw16w(hw + 6u, rd16(src + 6u));
        if (f & 0x10u) { hw16w(hw + 8u, rd16(src + 8u)); hw16w(hw + 10u, rd16(src + 10u)); }
        wr8(SV_DIRTY + v, 0);
    }
    koffl = rd16(SV_KOFFL); koffh = rd16(SV_KOFFH); konl = rd16(SV_KONL);
    konh = rd16(SV_KONH); eonl = rd16(SV_EONL); eonh = rd16(SV_EONH);
    wr16(SV_KOFFL, 0); wr16(SV_KOFFH, 0); wr16(SV_KONL, 0); wr16(SV_KONH, 0);
    hw16w(regs + SR_KOFFL, koffl); hw16w(regs + SR_KOFFH, koffh);
    hw16w(regs + SR_KONL, konl); hw16w(regs + SR_KONH, konh);
    hw16w(regs + SR_EONL, eonl); hw16w(regs + SR_EONH, eonh);
}

static void snd_vm_init(uint32_t nvoice) {
    /* 8003FE3C _SsVmInit */
    uint32_t i, n;
    wr32(SP_G580, 1);                       /* 800401A0(0) */
    wr16(0x800A5F60u, 0);
    wr32(0x800762D0u, 0x40001010u);         /* 8004014C SpuInitMalloc(32, 800762D0) */
    wr32(SP_MTBL, 0x800762D0u); wr32(SP_MCNT, 0); wr32(SP_MNUM, 32);
    wr32(0x800762D4u, (0x10000u << rd32(SP_SHIFT)) - 0x1010u);
    for (i = 0; i < 192u; ++i) wr16(SV_REGBUF + i * 2u, 0);
    for (i = 0; i < 24u; ++i) wr8(SV_DIRTY + i, 0);
    wr16(0x800C7CD8u, 0);
    for (i = 0; i < 16u; ++i) wr8(0x800B9B40u + i, 0);
    n = (nvoice & 0xFFu) < 24u ? (nvoice & 0xFFu) : 24u;
    wr8(SV_NVOICE, (uint8_t)n);
    for (i = 0; i < n; ++i) {
        uint32_t r = SV_REC + i * 52u, hw = rd32(SV_REGS) + i * 16u;
        static const uint8_t zero16[] = {4, 6, 8, 16, 18, 28, 30, 32, 34, 36, 40, 42, 44, 46, 48};
        unsigned k;
        wr16(r + 2u, 24); wr16(r + 14u, 0xFFFFu); wr16(r, 255); wr8(r + 27u, 0);
        for (k = 0; k < sizeof zero16; ++k) wr16(r + zero16[k], 0);
        wr16(r + 20u, 255); wr8(r + 10u, 64);
        hw16w(hw + 6u, 512); hw16w(hw + 4u, 4096); hw16w(hw + 8u, 0x80FFu);
        hw16w(hw, 0); hw16w(hw + 2u, 0); hw16w(hw + 10u, 0x4000u);
        wr16(SV_CUR, (uint16_t)i);
        snd_vm_keyoff_cur();
    }
    wr16(0x800A2B88u, 0x3FFFu); wr16(0x800A2B8Au, 0x3FFFu);
    wr16(SV_KONL, 0); wr16(SV_KONH, 0); wr16(SV_KOFFL, 0); wr16(SV_EONL, 0); wr16(SV_EONH, 0);
    wr32(0x800A2B80u, 0); wr32(0x800A2B84u, 0); wr8(SV_NOFLUSH, 0);
    wr16(0x800A6434u, 0); wr16(0x800A6540u, 128);
    snd_vm_flush();
}

static void snd_init_body(void) {
    /* 8003D548 _SsInit */
    uint32_t v, k;
    for (v = 0; v < 24u; ++v)
        for (k = 0; k < 8u; ++k) hw16w(0x1F801C00u + v * 16u + k * 2u, rd16(0x8006B8B4u + k * 2u));
    for (k = 0; k < 16u; ++k) hw16w(0x1F801D80u + k * 2u, rd16(0x8006B8C4u + k * 2u));
    snd_vm_init(24);
    for (v = 0; v < 32u; ++v)
        for (k = 0; k < 16u; ++k) wr32(0x800C7458u + v * 64u + k * 4u, 0);
    wr32(0x800C6D30u, 60);
    wr32(0x800AE818u, 0);
    wr32(0x800A6510u, 0);
}

#define SPU_ENTRY(name) static int name(MusashiNativeLaneCall *call)
SPU_ENTRY(hle_spu_init) { CD_SP(); spu_init(0); call->r[2] = 0; return 1; }           /* 8003A424 */
SPU_ENTRY(hle_spu_init_mode) { CD_SP(); spu_init((int)call->r[4]); call->r[2] = 0; return 1; }
SPU_ENTRY(hle_spu_init_hw) { CD_SP(); spu_init_hw((int)call->r[4]); call->r[2] = 0; return 1; }
SPU_ENTRY(hle_spu_init_events) { CD_SP(); spu_init_events(); return 1; }
SPU_ENTRY(hle_spu_write_manual) { CD_SP(); spu_write_manual(call->r[4], call->r[5]); return 1; }
SPU_ENTRY(hle_spu_transfer) {
    CD_SP();
    call->r[2] = (uint32_t)spu_transfer((int)call->r[4], call->r[5], call->r[6]);
    return 1;
}
SPU_ENTRY(hle_spu_delay) { (void)call; spu_delay(); return 1; }
SPU_ENTRY(hle_spu_overlap) { call->r[2] = (uint32_t)spu_overlap(call->r[4]); return 1; }
SPU_ENTRY(hle_spu_set_env) {
    /* 8003B1EC SpuSetEnv(env{mask, queueing}) */
    uint32_t m = rd32(call->r[4]);
    if (!m || (m & 1u))
        wr32(SP_ENV, rd32(call->r[4] + 4u) ? rd32(SP_ENV) | 1u : rd32(SP_ENV) & ~1u);
    return 1;
}
SPU_ENTRY(hle_spu_set_reverb) {
    /* 8003B280 SpuSetReverb(on) */
    uint32_t on = call->r[4];
    if (on == 0u) {
        wr32(SP_REVON, 0);
        spu_w(SR_CNT, spu_r(SR_CNT) & 0xFF7Fu);
    } else if (on == 1u) {
        if (rd32(SP_REVRSV) != 1u && spu_overlap(rd32(SP_REVADDR))) {
            wr32(SP_REVON, 0);
            spu_w(SR_CNT, spu_r(SR_CNT) & 0xFF7Fu);
        } else {
            wr32(SP_REVON, 1);
            spu_w(SR_CNT, spu_r(SR_CNT) | 0x80u);
        }
    }
    call->r[2] = rd32(SP_REVON);
    return 1;
}
SPU_ENTRY(hle_spu_reserve_reverb) {
    /* 8003BE24 SpuReserveReverbWorkArea(on) */
    if (call->r[4] && !spu_overlap(rd32(SP_REVADDR))) {
        wr32(SP_REVRSV, 1);
        call->r[2] = 1;
    } else {
        wr32(SP_REVRSV, 0);
        call->r[2] = 0;
    }
    return 1;
}
SPU_ENTRY(hle_spu_set_reverb_mode_param) {
    g_cd_sp = call->r[29] - 0x100u;   /* below the preset copy */
    call->r[2] = (uint32_t)spu_set_reverb_mode_param(call->r[4], call->r[29] - 0x80u);
    return 1;
}
SPU_ENTRY(hle_spu_set_reverb_regs) { spu_set_reverb_regs(call->r[4]); return 1; }
SPU_ENTRY(hle_spu_clear_reverb) { CD_SP(); call->r[2] = (uint32_t)spu_clear_reverb(call->r[4]); return 1; }
SPU_ENTRY(hle_spu_set_reverb_voice) {   /* 8003BE74 */
    call->r[2] = spu_voice_bits(call->r[4], call->r[5], 204, 205);
    return 1;
}
SPU_ENTRY(hle_spu_set_noise_voice) {    /* 8003FE18 */
    call->r[2] = spu_voice_bits(call->r[4], call->r[5], 202, 203);
    return 1;
}
SPU_ENTRY(hle_spu_voice_bits) {         /* 8003BE98 */
    call->r[2] = spu_voice_bits(call->r[4], call->r[5], call->r[6], call->r[7]);
    return 1;
}
SPU_ENTRY(hle_spu_set_common_attr) { spu_set_common_attr(call->r[4]); return 1; }
SPU_ENTRY(hle_spu_dma_irq) {
    /* 8003AA18: DMA4 completion */
    uint32_t saved = g_cd_sp;
    CD_SP();
    if (!rd32(SP_TMODE)) spu_delay();
    spu_w(SR_CNT, spu_r(SR_CNT) & 0xFFCFu);
    (void)spu_poll(SR_CNT, 0x30u, 0, "dma end");
    if (rd32(SP_TCB)) (void)hle_call(rd32(SP_TCB), 0, 0, 0, 0, 0);
    else if (!g_driver.ops || !g_driver.ops->deliver_event ||
             !g_driver.ops->deliver_event(g_driver.ops->user, 0xF0000009u, 0x20u))
        driver_stop("DeliverEvent_refused", 0x8005CE68u);
    g_cd_sp = saved;
    return 1;
}
SPU_ENTRY(hle_ss_init) {                /* 8003D518 SsInit */
    CD_SP();
    (void)hle_call(0x80042580u, 0, 0, 0, 0, 0);
    spu_init(0);
    snd_init_body();
    return 1;
}
SPU_ENTRY(hle_ss_init_body) { CD_SP(); snd_init_body(); return 1; }
SPU_ENTRY(hle_ss_vm_init) { CD_SP(); snd_vm_init(call->r[4]); return 1; }
SPU_ENTRY(hle_ss_vm_flush) { CD_SP(); snd_vm_flush(); return 1; }
SPU_ENTRY(hle_ss_vm_keyoff_cur) { (void)call; snd_vm_keyoff_cur(); return 1; }
SPU_ENTRY(hle_spu_init_malloc) {
    /* 8004014C SpuInitMalloc(num, top) */
    uint32_t n = call->r[4], top = call->r[5];
    if ((int32_t)n <= 0) { call->r[2] = 0; return 1; }
    wr32(top, 0x40001010u);
    wr32(SP_MTBL, top); wr32(SP_MCNT, 0); wr32(SP_MNUM, n);
    wr32(top + 4u, (0x10000u << rd32(SP_SHIFT)) - 0x1010u);
    call->r[2] = n;
    return 1;
}
SPU_ENTRY(hle_spu_set_g580) { wr32(SP_G580, call->r[4] == 1u ? 0u : 1u); return 1; }  /* 800401A0 */

/* B0 event services from native code */
static int bios_event_entry(MusashiNativeLaneCall *call, unsigned fn, uint32_t pc) {
    int32_t r = 0;
    if (fn == 0x0Au) { call->r[2] = (uint32_t)bios_wait_event((int32_t)call->r[4]); return 1; }
    if (!g_driver.ops || !g_driver.ops->bios_event ||
        !g_driver.ops->bios_event(g_driver.ops->user, fn, call->r[4], call->r[5], call->r[6],
                                  call->r[7], &r))
        driver_stop("bios_event_refused", pc);
    call->r[2] = (uint32_t)r;
    return 1;
}
SPU_ENTRY(hle_b0_deliver_event) { return bios_event_entry(call, 0x07u, 0x8005CE68u); }
SPU_ENTRY(hle_b0_open_event) { return bios_event_entry(call, 0x08u, 0x8005CE78u); }
SPU_ENTRY(hle_b0_close_event) { return bios_event_entry(call, 0x09u, 0x8005CE88u); }
SPU_ENTRY(hle_b0_wait_event) { return bios_event_entry(call, 0x0Au, 0x8005CE98u); }
SPU_ENTRY(hle_b0_test_event) { return bios_event_entry(call, 0x0Bu, 0x8005CEA8u); }
SPU_ENTRY(hle_b0_enable_event) { return bios_event_entry(call, 0x0Cu, 0x8005CEB8u); }
SPU_ENTRY(hle_b0_disable_event) { return bios_event_entry(call, 0x0Du, 0x8005CEC8u); }

static int hle_vsync(MusashiNativeLaneCall *call) {
    /* 8004239C VSync(mode) from native code. mode < 0: the tick (v1: the
     * root-counter latch word, as retail leaves it). 0: one field; 1: no
     * wait; n > 1: n fields of guest time with interrupts delivered. */
    int32_t mode = (int32_t)call->r[4];
    if (mode < 0) return bfm_psyq_VSync(call->r);   /* the compat row's exact form */
    driver_vsync_wait(mode == 0 ? 1u : mode == 1 ? 0u : (uint32_t)mode);
    call->r[2] = 0;
    return 1;
}

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
        uint32_t a = 1u, fn = rd32(rd32(0x80072780u) + 52u);
        if (fn == 0x8005BD7Cu) {
            /* The table's reset entry is the port-owned 8005BD7C HLE (B27). */
            if (!cb || !musashi_boot_call_8005bd7c(g_driver.memory, cb->reset_device, 1,
                                                   &result))
                driver_stop("ResetGraph_reset_refused", 0x8005BD7Cu);
            call->r[2] = (uint32_t)result;
            return 1;
        }
        call->r[2] = call_at(call->r[29] - 0x40u, fn, 1, &a);
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

/* ---- libgs startup (B27) ---------------------------------------------------
 * GsInitGraph (800525DC) and its libgs8 helpers, from the retail disassembly.
 * libgpu/libgte callees go through the lane (ResetGraph, PutDrawEnv and
 * PutDispEnv HLE); InitGeom, SetFarColor and SetGeomOffset use the compat
 * module's PsyCross wrappers over the GTE bridge. */
static void gs_call(MusashiNativeLaneCall *call, uint32_t pc, unsigned argc, uint32_t a0,
                    uint32_t a1) {
    uint32_t a[2] = {a0, a1};
    (void)call_at(call->r[29] - 0x40u, pc, argc, a);
}

static void gs_set_geom_offset(MusashiNativeLaneCall *call, uint32_t ox, uint32_t oy) {
    /* 8004921C SetGeomOffset through the compat module's GTE bridge */
    uint32_t r[32] = {0};
    r[4] = ox; r[5] = oy; r[29] = call->r[29];
    if (!bfm_psyq_SetGeomOffset(r)) driver_stop("SetGeomOffset_refused", 0x8004921Cu);
}

static void gs_copy32(uint32_t dst, uint32_t src) {
    unsigned i;
    for (i = 0; i < 32u; i += 4u) wr32(dst + i, rd32(src + i));
}

static void gs_init_graph_body(MusashiNativeLaneCall *call, uint32_t x, uint32_t y,
                               uint32_t intmode, uint32_t dith, uint32_t vram) {
    /* 80052654: ResetGraph, the DRAWENV at 800A6438, the DISPENV at 800A6498 */
    static const uint32_t zero16[] = {0x800A6442u, 0x800A6440u, 0x800A644Au, 0x800A6448u,
                                      0x800A6446u, 0x800A6444u, 0x800A644Cu};
    unsigned i;
    gs_call(call, 0x80059234u, 1, ((intmode >> 4) & 3u) == 3u ? 3u : 0u, 0);
    for (i = 0; i < sizeof zero16 / sizeof zero16[0]; i++) wr16(zero16[i], 0);
    wr8(0x800A644Eu, (uint8_t)dith);
    wr8(0x800A644Fu, 0);
    wr8(0x800A6450u, 0);
    gs_call(call, 0x80059D68u, 1, 0x800A6438u, 0);
    for (i = 0; i < 8u; i++) wr16(0x800A6498u + i * 2u, 0);
    wr16(0x800A649Cu, (uint16_t)x);
    wr16(0x800A649Eu, (uint16_t)y);
    if (rd32(0x8006CBE8u) == 1u) {          /* GetVideoMode() == MODE_PAL */
        wr16(0x800A64A2u, 24);
        wr8(0x800A64AAu, 1);
    }
    wr8(0x800A64A8u, (uint8_t)(intmode & 1u));
    wr16(0x800C7C88u, (uint16_t)(intmode & 4u));
    wr8(0x800A64A9u, (uint8_t)vram);
    gs_call(call, 0x80059FC0u, 1, 0x800A6498u, 0);
}

static void gs_init_coord(uint32_t x, uint32_t y) {
    /* 8005283C: projection/screen globals from the resolution */
    static const uint32_t zero16[] = {0x800AE624u, 0x800AE622u, 0x800AE62Au, 0x800AE626u,
                                      0x800AE62Eu, 0x800AE62Cu};
    int32_t q;
    unsigned i;
    wr32(0x800AE61Cu, y);
    wr32(0x800AE618u, x);
    if (x == 0u) driver_stop("GsInitGraph_div0", 0x80052868u);
    q = (int32_t)(y << 14) / (int32_t)x;
    for (i = 0; i < sizeof zero16 / sizeof zero16[0]; i++) wr16(zero16[i], 0);
    wr32(0x800AE63Cu, 0); wr32(0x800AE638u, 0); wr32(0x800AE634u, 0);
    wr16(0x800AE620u, 4096); wr16(0x800AE628u, 4096); wr16(0x800AE630u, 4096);
    gs_copy32(0x800AE7F0u, 0x800AE620u);
    gs_copy32(0x800A63F0u, 0x800AE620u);
    wr16(0x800A6400u, 0); wr16(0x800A63F8u, 0); wr16(0x800A63F0u, 0);
    gs_copy32(0x800A6558u, 0x800A63F0u);
    wr16(0x800A4F3Cu, 0); wr16(0x800A4F3Eu, 0); wr16(0x800A4F40u, 0); wr16(0x800A4F42u, 0);
    wr16(0x800A5E52u, 0); wr16(0x800A5E50u, 0); wr16(0x800AE822u, 0);
    wr16(0x800AE7F8u, (uint16_t)(q / 3));
    wr16(0x800AE820u, 0);
    wr8(0x80078817u, 2); wr8(0x80078827u, 2);
    wr16(0x800AE824u, (uint16_t)rd32(0x800AE618u));
    wr16(0x800AE826u, (uint16_t)rd32(0x800AE61Cu));
    wr8(0x80078813u, 3); wr8(0x80078823u, 3);
    wr32(0x800C7C70u, 1);
}

static void gs_set_clip(MusashiNativeLaneCall *call) {
    /* 80052D00: clip rectangle of the current buffer, PutDrawEnv */
    uint32_t i = (uint32_t)(int32_t)(int16_t)rd16(0x800C7C74u) * 2u;
    int16_t ox = (int16_t)rd16(0x800794E0u + i), oy = (int16_t)rd16(0x800794E4u + i);
    wr16(0x800A643Cu, rd16(0x800AE824u));
    wr16(0x800A643Eu, rd16(0x800AE826u));
    wr16(0x800A6438u, (uint16_t)((int16_t)rd16(0x800AE820u) + ox));
    wr16(0x800A643Au, (uint16_t)((int16_t)rd16(0x800AE822u) + oy));
    gs_call(call, 0x80059D68u, 1, 0x800A6438u, 0);
}

static void gs_set_offset(MusashiNativeLaneCall *call) {
    /* 80052BEC: draw offset (interlaced: in the DRAWENV) or geometry offset */
    int16_t buf = (int16_t)rd16(0x800C7C74u);
    if ((int16_t)rd16(0x800C7C88u) != 0) {
        uint32_t i = (uint32_t)(int32_t)buf * 2u;
        wr16(0x800A654Au, 0);
        wr16(0x800A6548u, 0);
        wr16(0x800A6440u, (uint16_t)(rd16(0x800A5E50u) + rd16(0x800794E0u + i)));
        wr16(0x800A6442u, (uint16_t)(rd16(0x800A5E52u) + rd16(0x800794E4u + i)));
        gs_call(call, 0x80059D68u, 1, 0x800A6438u, 0);
    } else {
        int32_t ox = (int16_t)rd16(0x800A5E50u) + (int16_t)rd16(buf ? 0x800794E0u : 0x800794E2u);
        int32_t oy = (int16_t)rd16(0x800A5E52u) + (int16_t)rd16(buf ? 0x800794E4u : 0x800794E6u);
        gs_set_geom_offset(call, (uint32_t)ox, (uint32_t)oy);
        wr16(0x800A6548u, (uint16_t)ox);
        wr16(0x800A654Au, (uint16_t)oy);
    }
}

static int hle_gs_init_graph(MusashiNativeLaneCall *call) {
    /* 800525DC GsInitGraph(x, y, intmode, dith, vram) */
    uint32_t x = call->r[4] & 0xFFFFu, y = call->r[5] & 0xFFFFu;
    uint32_t far[32] = {0};
    gs_init_graph_body(call, x, y, call->r[6] & 0xFFFFu, call->r[7] & 0xFFFFu,
                       rd16(call->r[29] + 16u));
    /* 80053CF8: InitGeom, SetFarColor(0, 0, 0), SetGeomOffset(0, 0) */
    /* 80047CB4 InitGeom: _patch_gte (8004D16C) rewrites the BIOS RAM
     * exception handler for GTE-in-delay-slot returns; the native exception
     * path runs no MIPS handler, so that patch has nothing to act on. Then
     * Status CU2 on and the PsyCross InitGeom control-register setup. */
    if (!g_driver.ops || !g_driver.ops->cop2_enable || !g_driver.ops->cop2_enable(g_driver.ops->user))
        driver_stop("InitGeom_cu2_refused", 0x80047CD0u);
    if (!bfm_psyq_InitGeom(far)) driver_stop("InitGeom_refused", 0x80047CB4u);
    if (!bfm_psyq_SetFarColor(far)) driver_stop("SetFarColor_refused", 0x80053AD8u);
    gs_set_geom_offset(call, 0, 0);
    wr16(0x800A654Au, 0);
    wr16(0x800A6548u, 0);
    wr16(0x800C7C74u, 0);
    gs_init_coord(x, y);
    gs_set_clip(call);
    gs_set_offset(call);
    return 1;
}

static int hle_gs_def_disp_buff(MusashiNativeLaneCall *call) {
    /* 80053178 GsDefDispBuff(x0, y0, x1, y1): the two buffer origins; the
     * non-interlaced case also keeps them as the clip origins */
    wr16(0x800794E0u, (uint16_t)call->r[4]);
    wr16(0x800794E2u, (uint16_t)call->r[6]);
    wr16(0x800794E4u, (uint16_t)call->r[5]);
    wr16(0x800794E6u, (uint16_t)call->r[7]);
    if ((int16_t)rd16(0x800C7C88u) != 0) {
        wr16(0x800A4F3Cu, 0); wr16(0x800A4F3Eu, 0); wr16(0x800A4F40u, 0); wr16(0x800A4F42u, 0);
    } else {
        wr16(0x800A4F3Cu, (uint16_t)call->r[4]);
        wr16(0x800A4F3Eu, (uint16_t)call->r[6]);
        wr16(0x800A4F40u, (uint16_t)call->r[5]);
        wr16(0x800A4F42u, (uint16_t)call->r[7]);
    }
    gs_set_clip(call);
    gs_set_offset(call);
    return 1;
}

static int hle_gs_init_3d(MusashiNativeLaneCall *call) {
    /* 80053218: projection centre = half the resolution, the offset, and
     * three libgs defaults */
    int32_t w = (int32_t)rd32(0x800AE618u), h = (int32_t)rd32(0x800AE61Cu);
    wr16(0x800A5E50u, (uint16_t)(w / 2));
    wr16(0x800A5E52u, (uint16_t)(h / 2));
    gs_set_offset(call);
    wr32(0x800C73D0u, 10);
    wr32(0x800C6DC8u, 0);
    wr32(0x800AE7E8u, 16383);
    return 1;
}

static int hle_gs_init_graph2(MusashiNativeLaneCall *call) {
    /* 800527C4 GsInitGraph2(x, y, intmode, dith, vram): no ResetGraph */
    uint32_t intmode = call->r[6];
    wr16(0x800A649Cu, (uint16_t)call->r[4]);
    wr16(0x800A649Eu, (uint16_t)call->r[5]);
    wr16(0x800A644Cu, 0);
    wr8(0x800A644Eu, (uint8_t)call->r[7]);
    wr8(0x800A644Fu, 0);
    wr8(0x800A6450u, 0);
    wr8(0x800A64A8u, (uint8_t)(intmode & 1u));
    wr16(0x800C7C88u, (uint16_t)(intmode & 4u));
    wr8(0x800A64A9u, (uint8_t)rd16(call->r[29] + 16u));
    gs_init_coord(call->r[4] & 0xFFFFu, call->r[5] & 0xFFFFu);
    return 1;
}

static int hle_gs_def_disp_buff2(MusashiNativeLaneCall *call) {
    /* 80053EEC: GsDefDispBuff without the clip/offset refresh */
    wr16(0x800794E0u, (uint16_t)call->r[4]);
    wr16(0x800794E2u, (uint16_t)call->r[6]);
    wr16(0x800794E4u, (uint16_t)call->r[5]);
    wr16(0x800794E6u, (uint16_t)call->r[7]);
    if ((int16_t)rd16(0x800C7C88u) != 0) {
        wr16(0x800A4F3Cu, 0); wr16(0x800A4F3Eu, 0); wr16(0x800A4F40u, 0); wr16(0x800A4F42u, 0);
    } else {
        wr16(0x800A4F3Cu, (uint16_t)call->r[4]);
        wr16(0x800A4F3Eu, (uint16_t)call->r[6]);
        wr16(0x800A4F40u, (uint16_t)call->r[5]);
        wr16(0x800A4F42u, (uint16_t)call->r[7]);
    }
    return 1;
}

static int hle_set_def_draw_env(MusashiNativeLaneCall *call) {
    /* 80058A4C SetDefDrawEnv(env, x, y, w, h) -> env */
    uint32_t env = call->r[4], x = call->r[5], y = call->r[6];
    int32_t h = (int32_t)rd32(call->r[29] + 16u);
    unsigned i;
    wr16(env + 0u, (uint16_t)x);
    wr16(env + 2u, (uint16_t)y);
    wr16(env + 4u, (uint16_t)call->r[7]);
    for (i = 12u; i <= 18u; i += 2u) wr16(env + i, 0);
    wr8(env + 25u, 0); wr8(env + 26u, 0); wr8(env + 27u, 0);
    wr8(env + 22u, 1);
    wr16(env + 6u, (uint16_t)h);
    wr8(env + 23u, (uint8_t)(rd32(0x8006CBE8u) ? h < 289 : h < 257));   /* dfe */
    wr16(env + 8u, (uint16_t)x);
    wr16(env + 10u, (uint16_t)y);
    wr16(env + 20u, 10);
    wr8(env + 24u, 0);
    call->r[2] = env;
    return 1;
}

static int hle_clear_image(MusashiNativeLaneCall *call) {
    /* 80059888 ClearImage(rect, r, g, b): the debug-level rect check
     * (80059760) only prints; the queued GPU fill runs at once through the
     * renderer (the frame driver's DrawSync points find an idle queue). */
    if ((int8_t)rd8(0x8007278Au) >= 2)
        fprintf(stderr, "native_boot: FRAME_DRIVER ClearImage rect=%08x\n", (unsigned)call->r[4]);
    if (!bfm_psyq_ClearImage(call->r)) driver_stop("ClearImage_refused", 0x80059888u);
    return 1;
}

/* ---- libgte/libgs view helpers (B28) ----------------------------------------
 * From the retail disassembly. Table reads use the same guest addresses as
 * the retail code (the sine table at 8006D0A8 and its mirrored indexing, the
 * square-root table at 8006D8EC). MulMatrix, MulMatrix2, ApplyMatrixLV and
 * GsGetLw run as their compat lane rows. */
static int32_t gte_rcos(int32_t a) {
    uint32_t x = (uint32_t)(a < 0 ? -a : a) & 0xFFFu;
    if (x < 2049u)
        return x < 1025u ? (int16_t)rd16(0x8006D0A8u + (1024u - x) * 2u)
                         : -(int32_t)(int16_t)rd16(0x8006C8A8u + x * 2u);
    return x < 3073u ? -(int32_t)(int16_t)rd16(0x8006D0A8u + (3072u - x) * 2u)
                     : (int16_t)rd16(0x8006B8A8u + x * 2u);
}

static int32_t gte_sin_core(uint32_t x) {           /* 800478B8, x in 0..4095 */
    if (x < 2049u)
        return x < 1025u ? (int16_t)rd16(0x8006D0A8u + x * 2u)
                         : (int16_t)rd16(0x8006D0A8u + (2048u - x) * 2u);
    return x < 3073u ? -(int32_t)(int16_t)rd16(0x8006C0A8u + x * 2u)
                     : -(int32_t)(int16_t)rd16(0x8006D0A8u + (4096u - x) * 2u);
}

static int32_t gte_rsin(int32_t a) {
    return a >= 0 ? gte_sin_core((uint32_t)a & 0xFFFu) : -gte_sin_core((uint32_t)-a & 0xFFFu);
}

static uint32_t gte_lzc(uint32_t v) {               /* GTE LZCR: leading sign bits */
    uint32_t n = 0, sign = v >> 31;
    while (n < 32u && ((v >> (31u - n)) & 1u) == sign) n++;
    return n;
}

static int32_t gte_sqrt0(int32_t a) {                /* 80047D3C SquareRoot0 */
    uint32_t lz = gte_lzc((uint32_t)a), even, sh;
    int32_t t4;
    if (lz == 32u) return 0;
    even = lz & ~1u;
    sh = (uint32_t)((int32_t)(31u - even) >> 1);
    t4 = (int32_t)even - 24 >= 0 ? (int32_t)((uint32_t)a << (even - 24u))
                                 : a >> (24u - even);
    t4 = (t4 - 64) * 2;
    return (int32_t)(((uint32_t)(int32_t)(int16_t)rd16(0x8006D8ECu + (uint32_t)t4) << sh) >> 12);
}

static void gte_copy_matrix(uint32_t dst, uint32_t src) { gs_copy32(dst, src); }

static void gte_call(uint32_t sp, uint32_t pc, unsigned argc, uint32_t a0, uint32_t a1,
                     uint32_t a2) {
    uint32_t a[3] = {a0, a1, a2};
    (void)call_at(sp, pc, argc, a);
}

static void gte_rot_axis(uint32_t m, int32_t s, int32_t c, uint32_t axis) {
    /* 80053E28(m, s, c, axis): identity from 800AE620, then one rotation */
    gte_copy_matrix(m, 0x800AE620u);
    switch (axis & 0xFFu) {
    case 'X': case 'x':
        wr16(m + 8u, (uint16_t)c); wr16(m + 16u, (uint16_t)c);
        wr16(m + 10u, (uint16_t)-s); wr16(m + 14u, (uint16_t)s);
        break;
    case 'Y': case 'y':
        wr16(m + 0u, (uint16_t)c); wr16(m + 16u, (uint16_t)c);
        wr16(m + 4u, (uint16_t)s); wr16(m + 12u, (uint16_t)-s);
        break;
    case 'Z': case 'z':
        wr16(m + 0u, (uint16_t)c); wr16(m + 8u, (uint16_t)c);
        wr16(m + 2u, (uint16_t)-s); wr16(m + 6u, (uint16_t)s);
        break;
    default:
        break;
    }
}

static void gte_transpose(uint32_t m, uint32_t out) {  /* 8004974C TransposeMatrix */
    uint16_t v[9];
    unsigned i, j;
    for (i = 0; i < 9u; i++) v[i] = rd16(m + i * 2u);
    for (i = 0; i < 3u; i++)
        for (j = 0; j < 3u; j++) wr16(out + (i * 3u + j) * 2u, v[j * 3u + i]);
}

static void gs_rot_z(uint32_t sp, uint32_t m, int32_t angle) {
    /* 80053B20(m, angle): m = m * RotZ(angle / 360), skipped for angle 0 */
    int32_t a = angle / 360, c = gte_rcos(a), sn = gte_rsin(a);
    uint32_t r = sp + 16u;
    if (angle == 0) return;
    wr16(r + 0u, (uint16_t)c); wr16(r + 2u, (uint16_t)-sn); wr16(r + 4u, 0);
    wr16(r + 6u, (uint16_t)sn); wr16(r + 8u, (uint16_t)c); wr16(r + 10u, 0);
    wr16(r + 12u, 0); wr16(r + 14u, 0); wr16(r + 16u, 4096);
    wr32(r + 20u, 0); wr32(r + 24u, 0); wr32(r + 28u, 0);
    gte_call(sp, 0x80048D9Cu, 2, m, r, 0);
}

static void gs_scale_view(uint32_t pv, uint32_t out) {
    /* 80054340: the six view words, shifted right so the largest magnitude
     * fits 16 bits (80054430 max |v|, 800544F8 bit count) */
    int32_t mx = 0, v;
    unsigned i, bits = 0;
    for (i = 0; i < 6u; i++) {
        v = (int32_t)rd32(pv + i * 4u);
        if (v < 0) v = -v;
        if (i == 0u || mx < v) mx = v;
    }
    for (v = mx; v > 0; v >>= 1) bits++;
    for (i = 0; i < 6u; i++) {
        v = (int32_t)rd32(pv + i * 4u);
        wr32(out + i * 4u, (uint32_t)(bits >= 16u ? v >> (bits - 15u) : v));
    }
}

static int32_t gs_div(int32_t n, int32_t d, uint32_t pc) {
    if (d == 0 || (d == -1 && n == INT32_MIN)) driver_stop("libgs_div_trap", pc);
    return d ? n / d : 0;
}

static void gs_comp_matrix(uint32_t sp, uint32_t m0, uint32_t m1) {
    /* 80052FCC(m0, m1): t = m0 * m1.t; m1 = m0 * m1 (MulMatrix2); m1.t = t + m0.t */
    uint32_t t = sp + 16u;
    unsigned i;
    gte_call(sp, 0x800484ECu, 3, m0, m1 + 20u, t);
    gte_call(sp, 0x80048EACu, 2, m0, m1, 0);
    for (i = 0; i < 3u; i++) wr32(m1 + 20u + i * 4u, rd32(t + i * 4u) + rd32(m0 + 20u + i * 4u));
}

static uint32_t gs_set_ref_view2(uint32_t caller_sp, uint32_t pv) {
    /* 80053F6C GsSetRefView2(pv): GsWSMATRIX (800AE688) from the view
     * point/reference point, roll and super coordinate; copy to 800A5EB8 */
    const uint32_t ws = 0x800AE688u, sp = caller_sp - 192u;
    const uint32_t v = sp + 16u, m = sp + 48u, mt = sp + 80u, neg = sp + 144u;
    int32_t dx, dy, dz, len, flat, s, c;
    gte_copy_matrix(ws, 0x800AE7F0u);
    gs_rot_z(sp - 64u, ws, -(int32_t)rd32(pv + 24u));
    gs_scale_view(pv, v);
    dx = (int32_t)(rd32(v + 12u) - rd32(v + 0u));
    dy = (int32_t)(rd32(v + 16u) - rd32(v + 4u));
    dz = (int32_t)(rd32(v + 20u) - rd32(v + 8u));
    len = gte_sqrt0((int32_t)((uint32_t)dx * (uint32_t)dx + (uint32_t)dy * (uint32_t)dy +
                              (uint32_t)dz * (uint32_t)dz));
    if (len == 0) return 1;
    s = -gs_div((int32_t)((uint32_t)-dy << 12), len, 0x80054070u);
    flat = gte_sqrt0((int32_t)((uint32_t)dx * (uint32_t)dx + (uint32_t)dz * (uint32_t)dz));
    c = gs_div((int32_t)((uint32_t)flat << 12), len, 0x800540E0u);
    gte_rot_axis(m, (int16_t)s, (int16_t)c, 'x');
    gte_call(sp, 0x80048D9Cu, 2, ws, m, 0);
    if (flat != 0) {
        s = gs_div((int32_t)((uint32_t)dx << 12), flat, 0x80054154u);
        c = gs_div((int32_t)((uint32_t)dz << 12), flat, 0x80054194u);
        gte_rot_axis(m, (int16_t)-s, (int16_t)c, 'y');
        gte_call(sp, 0x80048D9Cu, 2, ws, m, 0);
    }
    wr32(neg + 0u, (uint32_t)-(int32_t)rd32(pv + 0u));
    wr32(neg + 4u, (uint32_t)-(int32_t)rd32(pv + 4u));
    wr32(neg + 8u, (uint32_t)-(int32_t)rd32(pv + 8u));
    gte_call(sp, 0x800484ECu, 3, ws, neg, ws + 20u);
    if (rd32(pv + 28u) != 0u) {
        gte_call(sp, 0x80054514u, 2, rd32(pv + 28u), m, 0);       /* GsGetLw */
        gte_transpose(m, mt);
        gte_call(sp, 0x800484ECu, 3, mt, m + 20u, neg);
        wr32(mt + 20u, (uint32_t)-(int32_t)rd32(neg + 0u));
        wr32(mt + 28u, (uint32_t)-(int32_t)rd32(neg + 8u));
        wr32(mt + 24u, (uint32_t)-(int32_t)rd32(neg + 4u));
        gs_comp_matrix(sp, ws, mt);
        gte_copy_matrix(ws, mt);
    }
    gte_copy_matrix(0x800A5EB8u, ws);
    return 0;
}

static int hle_gs_set_ref_view2(MusashiNativeLaneCall *call) {
    call->r[2] = gs_set_ref_view2(call->r[29], call->r[4]);
    return 1;
}
static int hle_rcos(MusashiNativeLaneCall *call) { call->r[2] = (uint32_t)gte_rcos((int32_t)call->r[4]); return 1; }
static int hle_rsin(MusashiNativeLaneCall *call) { call->r[2] = (uint32_t)gte_rsin((int32_t)call->r[4]); return 1; }
static int hle_sqrt0(MusashiNativeLaneCall *call) { call->r[2] = (uint32_t)gte_sqrt0((int32_t)call->r[4]); return 1; }
static int hle_transpose(MusashiNativeLaneCall *call) {
    gte_transpose(call->r[4], call->r[5]);
    call->r[2] = call->r[5];
    return 1;
}
static int hle_gs_rot_axis(MusashiNativeLaneCall *call) {
    gte_rot_axis(call->r[4], (int16_t)call->r[5], (int16_t)call->r[6], call->r[7]);
    return 1;
}
static int hle_gs_rot_z(MusashiNativeLaneCall *call) {
    gs_rot_z(call->r[29] - 64u, call->r[4], (int32_t)call->r[5]);
    return 1;
}
static int hle_gs_scale_view(MusashiNativeLaneCall *call) { gs_scale_view(call->r[4], call->r[5]); return 1; }
static int hle_gs_comp_matrix(MusashiNativeLaneCall *call) {
    gs_comp_matrix(call->r[29] - 48u, call->r[4], call->r[5]);
    return 1;
}

static void gte_set_color_matrix(uint32_t m) {          /* 800538BC */
    uint32_t r[32] = {0};
    r[4] = m;
    if (!bfm_psyq_SetColorMatrix(r)) driver_stop("SetColorMatrix_refused", 0x800538BCu);
}

static void gs_set_color_matrix(uint32_t m) {          /* 80053804 */
    gte_copy_matrix(0x800A6558u, m);
    gte_set_color_matrix(0x800A6558u);
}

static int16_t gs_color12(uint32_t c) {                 /* (c << 12) / 255, retail form */
    int32_t v = (int32_t)(c << 12);
    int32_t hi = (int32_t)(((int64_t)v * (int64_t)(int32_t)0x80808081u) >> 32);
    return (int16_t)((hi + v) >> 7);
}

static uint32_t gs_set_flat_light(uint32_t caller_sp, int32_t id, uint32_t lt) {
    /* 80053328 GsSetFlatLight(id, lt): light direction row `id` of the light
     * matrix (800A63F0) and colour column `id` of the colour matrix */
    const uint32_t sp = caller_sp - 176u, lm = sp + 16u, cm = sp + 48u;
    uint32_t cr = rd8(lt + 12u), cg = rd8(lt + 13u), cb = rd8(lt + 14u);
    int32_t vx = (int32_t)rd32(lt + 0u), vy = (int32_t)rd32(lt + 4u), vz = (int32_t)rd32(lt + 8u);
    int32_t len;
    gte_copy_matrix(lm, 0x800A63F0u);
    gte_copy_matrix(cm, 0x800A6558u);
    len = gte_sqrt0((int32_t)((uint32_t)vx * (uint32_t)vx + (uint32_t)vy * (uint32_t)vy +
                              (uint32_t)vz * (uint32_t)vz));
    if (len == 0) return (uint32_t)-1;
    if (id >= 0 && id <= 2) {
        uint32_t row = lm + (uint32_t)id * 6u, col = cm + (uint32_t)id * 2u;
        wr16(row + 0u, (uint16_t)gs_div((int32_t)((uint32_t)-vx << 12), len, 0x8005343Cu));
        wr16(row + 2u, (uint16_t)gs_div((int32_t)((uint32_t)-vy << 12), len, 0x80053480u));
        wr16(row + 4u, (uint16_t)gs_div((int32_t)((uint32_t)-vz << 12), len, 0x800534C4u));
        wr16(col + 0u, (uint16_t)gs_color12(cr));
        wr16(col + 6u, (uint16_t)gs_color12(cg));
        wr16(col + 12u, (uint16_t)gs_color12(cb));
    }
    gte_copy_matrix(0x800A63F0u, lm);
    gs_set_color_matrix(cm);
    return 0;
}

static int hle_gs_set_flat_light(MusashiNativeLaneCall *call) {
    call->r[2] = gs_set_flat_light(call->r[29], (int32_t)call->r[4], call->r[5]);
    return 1;
}
static int hle_gs_set_color_matrix(MusashiNativeLaneCall *call) { gs_set_color_matrix(call->r[4]); return 1; }
static int hle_set_color_matrix(MusashiNativeLaneCall *call) { gte_set_color_matrix(call->r[4]); return 1; }

static int hle_draw_sync_callback(MusashiNativeLaneCall *call) {
    /* 800595FC DrawSyncCallback(func): the debug-level log, then swap the
     * libgpu draw-sync callback word 80072794 and return the old one. The
     * native GPU path completes draws synchronously, so no completion
     * interrupt invokes it (see docs/NATIVE-FRAME-DRIVER.md B28). */
    uint32_t old = rd32(0x80072794u);
    if (rd8(0x8007278Au) >= 2u)
        fprintf(stderr, "native_boot: FRAME_DRIVER DrawSyncCallback(%08x)\n", (unsigned)call->r[4]);
    wr32(0x80072794u, call->r[4]);
    call->r[2] = old;
    return 1;
}

static int hle_spu_get_all_keys_status(MusashiNativeLaneCall *call) {
    /* 8003D25C SpuGetAllKeysStatus(min, max, status): clamp the voice range
     * to 0..23 (-3 when empty), then per voice the key-on shadow bit
     * (8006B0E4) and the voice's ENVX register (regs cell 8006B54C,
     * voice*16 + 12): 1 on+env, 3 on+silent, 2 off+env, 0 off+silent. */
    int32_t lo = (int32_t)call->r[4], hi = (int32_t)call->r[5], i;
    uint32_t st = call->r[6];
    if (lo < 0) lo = 0;
    if (lo >= 24) { call->r[2] = (uint32_t)-3; return 1; }
    if (hi >= 24) hi = 23;
    if (hi < 0 || hi < lo) { call->r[2] = (uint32_t)-3; return 1; }
    for (i = lo; i <= hi; ++i) {
        uint16_t env = hw16(rd32(SP_REGS) + (uint32_t)i * 16u + 12u);
        int on = (rd32(SP_G0E4) & (1u << i)) != 0;
        wr8(st + (uint32_t)i, (uint8_t)(on ? (env ? 1 : 3) : (env ? 2 : 0)));
    }
    call->r[2] = 0;
    return 1;
}

/* ---- libspu transfer API (retail 8003AE14, 8003AF4C, 8003C438..8003C598),
 * written from the retail disassembly (B28) ---------------------------- */
static uint32_t spu_fset_rxx(int32_t reg, uint32_t addr) {
    /* 8003AF4C _spu_FsetRXX: round up to the transfer block when 8006B570
     * is set, scale by the address shift; -2 returns the rounded address,
     * -1 the scaled 16-bit value, otherwise store it to SPU register reg */
    uint32_t v;
    if (rd32(SP_G570)) {
        uint32_t blk = rd32(SP_G578);
        if (!blk) { driver_stop("spu_fsetrxx_div0", 0x8003AF78u); return 0; }
        if (addr % blk) addr = (addr + blk) & ~rd32(SP_G57C);
    }
    v = addr >> (rd32(SP_SHIFT) & 31u);
    if (reg == -2) return addr;
    if (reg == -1) return v & 0xFFFFu;
    hw16w(rd32(SP_REGS) + (uint32_t)reg * 2u, (uint16_t)v);
    return addr;
}
static uint32_t spu_write_data(uint32_t src, uint32_t size) {
    /* 8003AE14 _spu_write: DMA (_spu_t 2/1/3) unless 8006B568 selects I/O */
    if (!rd32(SP_DMAINIT)) {
        (void)spu_transfer(2, (uint32_t)rd16(SP_TADDR) << (rd32(SP_SHIFT) & 31u), 0);
        (void)spu_transfer(1, 0, 0);
        (void)spu_transfer(3, src, size);
    } else {
        spu_write_manual(src, size);
    }
    return size;
}
SPU_ENTRY(hle_spu_fset_rxx) { call->r[2] = spu_fset_rxx((int32_t)call->r[4], call->r[5]); return 1; }
SPU_ENTRY(hle_spu_write_data) { CD_SP(); call->r[2] = spu_write_data(call->r[4], call->r[5]); return 1; }
SPU_ENTRY(hle_spu_write) {
    /* 8003C438 SpuWrite(addr, size) */
    uint32_t size = call->r[5] > 0x7EFF0u ? 0x7EFF0u : call->r[5];
    CD_SP();
    (void)spu_write_data(call->r[4], size);
    if (!rd32(SP_TCB)) wr32(SP_G580, 0);
    call->r[2] = size;
    return 1;
}
SPU_ENTRY(hle_spu_set_transfer_start_addr) {
    /* 8003C498 SpuSetTransferStartAddr(addr) */
    uint32_t a = call->r[4];
    if (a - 0x1010u <= 0x7EFE8u) {
        wr16(SP_TADDR, (uint16_t)spu_fset_rxx(-1, a));
        call->r[2] = (uint32_t)rd16(SP_TADDR) << (rd32(SP_SHIFT) & 31u);
    } else {
        call->r[2] = 0;
    }
    return 1;
}
static int32_t spu_is_transfer_completed(int32_t flag) {
    /* 8003C4F0 SpuIsTransferCompleted(flag): I/O mode or no pending DMA -> 1;
     * else TestEvent on the transfer event (flag 1 waits for it) */
    int32_t r = 0;
    if (rd32(SP_G0E8) == 1u || rd32(SP_G580) == 1u) return 1;
    if (flag == 1) {
        (void)bios_wait_event((int32_t)rd32(SP_EVENT));
        wr32(SP_G580, 1);
        return 1;
    }
    if (!g_driver.ops || !g_driver.ops->bios_event ||
        !g_driver.ops->bios_event(g_driver.ops->user, 0x0Bu, rd32(SP_EVENT), 0, 0, 0, &r))
        driver_stop("TestEvent_refused", 0x8003C4F0u);
    if (r == 1) wr32(SP_G580, 1);
    return r;
}
SPU_ENTRY(hle_spu_is_transfer_completed) {
    call->r[2] = (uint32_t)spu_is_transfer_completed((int32_t)call->r[4]);
    return 1;
}

/* ---- libspu SPU-RAM allocator and libsnd VAB header open (retail 800416A8,
 * 80041E8C, 80041A20..80041E88), written from the retail disassembly (B28).
 * Table 8006B5B0: 8-byte entries {addr | flags, size}; bit 31 free, bit 30
 * the tail, 0x2FFFFFFF an empty slot; 8006B5AC the tail index, 8006B5A8
 * the table size. */
#define MT_E(i) (rd32(SP_MTBL) + (uint32_t)(i) * 8u)
static void spu_gc(void) {
    /* 800416A8 _spu_gcSPU */
    int32_t t1, a2, cnt;
    uint32_t a3, a1, v1;
    if ((int32_t)rd32(SP_MCNT) >= 0) {           /* merge adjacent free blocks */
        t1 = 0;
        a3 = rd32(SP_MTBL);
        while (!((int32_t)rd32(SP_MCNT) < t1)) {
            if (rd32(a3) & 0x80000000u) {
                a2 = t1 + 1;
                while (rd32(MT_E(a2)) == 0x2FFFFFFFu) ++a2;
                a1 = MT_E(a2);
                v1 = rd32(a1);
                if ((v1 & 0x80000000u) &&
                    (v1 & 0x0FFFFFFFu) == (rd32(a3) & 0x0FFFFFFFu) + rd32(a3 + 4u)) {
                    wr32(a1, 0x2FFFFFFFu);
                    wr32(a3 + 4u, rd32(a3 + 4u) + rd32(a1 + 4u));
                    continue;                    /* same entry again */
                }
            }
            a3 += 8u;
            ++t1;
        }
    }
    cnt = (int32_t)rd32(SP_MCNT);
    if (cnt >= 0) {                              /* empty sizes become empty slots */
        uint32_t e = rd32(SP_MTBL);
        for (t1 = 0; t1 <= cnt; ++t1, e += 8u)
            if (rd32(e + 4u) == 0) wr32(e, 0x2FFFFFFFu);
    }
    cnt = (int32_t)rd32(SP_MCNT);
    if (cnt >= 0) {                              /* sort by address up to the tail */
        uint32_t tb = rd32(SP_MTBL), t2 = tb;
        t1 = 0;
        for (;;) {
            if (rd32(t2) & 0x40000000u) break;
            a2 = t1 + 1;
            if (!(cnt < a2)) {
                int32_t t3 = (int32_t)rd32(SP_MCNT);
                uint32_t a0 = tb + (uint32_t)a2 * 8u;
                do {
                    uint32_t w = rd32(a0), a3w;
                    if (w & 0x40000000u) break;
                    a3w = rd32(t2);
                    if ((w & 0x0FFFFFFFu) < (a3w & 0x0FFFFFFFu)) {
                        uint32_t s0 = rd32(a0 + 4u), s1 = rd32(t2 + 4u);
                        wr32(t2, w); wr32(t2 + 4u, s0);
                        wr32(a0, a3w); wr32(a0 + 4u, s1);
                    }
                    ++a2;
                    a0 += 8u;
                } while (!(t3 < a2));
            }
            cnt = (int32_t)rd32(SP_MCNT);
            ++t1;
            t2 += 8u;
            if (cnt < t1) break;
        }
    }
    cnt = (int32_t)rd32(SP_MCNT);
    if (cnt >= 0) {                              /* move the tail into the first empty slot */
        uint32_t tb = rd32(SP_MTBL), e = tb;
        for (t1 = 0;; ++t1, e += 8u) {
            uint32_t w = rd32(e);
            if (w & 0x40000000u) break;
            if (w == 0x2FFFFFFFu) {
                uint32_t src = tb + (uint32_t)cnt * 8u;
                wr32(e, rd32(src));
                wr32(SP_MCNT, (uint32_t)t1);
                wr32(e + 4u, rd32(src + 4u));
                break;
            }
            cnt = (int32_t)rd32(SP_MCNT);
            if (cnt < t1 + 1) break;
        }
    }
    t1 = (int32_t)rd32(SP_MCNT) - 1;             /* free blocks before the tail join it */
    if (t1 >= 0) {
        uint32_t tb = rd32(SP_MTBL), e = tb + (uint32_t)t1 * 8u;
        do {
            uint32_t w = rd32(e), tail;
            if (!(w & 0x80000000u)) break;
            tail = rd32(SP_MCNT);
            wr32(e, (w & 0x0FFFFFFFu) | 0x40000000u);
            wr32(SP_MCNT, (uint32_t)t1);
            wr32(e + 4u, rd32(e + 4u) + rd32(tb + tail * 8u + 4u));
            --t1;
            e -= 8u;
        } while (t1 >= 0);
    }
}

static int32_t spu_malloc(uint32_t size) {
    /* 80041E8C SpuMalloc */
    uint32_t s1 = size, s3 = 0, g = rd32(SP_G57C), sh = rd32(SP_SHIFT) & 31u, a0, w;
    int32_t s2 = -1, s0, n;
    if (rd32(SP_REVRSV)) s3 = (0x10000u - rd32(SP_REVADDR)) << sh;
    a0 = (s1 & ~g) ? s1 + g : s1;
    s1 = (uint32_t)(((int32_t)a0 >> sh) << sh);
    if (rd32(rd32(SP_MTBL)) & 0x40000000u) {
        s2 = 0;
    } else {
        spu_gc();
        n = (int32_t)rd32(SP_MNUM);
        for (s0 = 0; s0 < n; ++s0) {
            w = rd32(MT_E(s0));
            if ((w & 0x40000000u) || ((w & 0x80000000u) && !(rd32(MT_E(s0) + 4u) < s1))) {
                s2 = s0;
                break;
            }
        }
    }
    if (s2 == -1) return -1;
    {
        uint32_t e = MT_E(s2), v1 = rd32(e);
        if (v1 & 0x40000000u) {
            uint32_t nx;
            if (!(s2 < (int32_t)rd32(SP_MNUM))) return -1;
            if (rd32(e + 4u) - s3 < s1) return -1;
            nx = MT_E(s2 + 1);
            wr32(nx, ((rd32(e) & 0x0FFFFFFFu) + s1) | 0x40000000u);
            wr32(nx + 4u, rd32(e + 4u) - s1);
            v1 = rd32(e);
            wr32(SP_MCNT, (uint32_t)(s2 + 1));
            wr32(e + 4u, s1);
            wr32(e, v1 & 0x0FFFFFFFu);
        } else {
            uint32_t t0 = rd32(e + 4u);
            if (s1 < t0) {
                int32_t tail = (int32_t)rd32(SP_MCNT);
                if (tail < (int32_t)rd32(SP_MNUM)) {
                    uint32_t te = MT_E(tail), a1 = rd32(te), a0w = rd32(te + 4u);
                    wr32(te, (v1 + s1) | 0x80000000u);
                    wr32(te + 4u, t0 - s1);
                    wr32(SP_MCNT, (uint32_t)(tail + 1));
                    wr32(te + 8u, a1);
                    wr32(te + 12u, a0w);
                }
            }
            e = MT_E(s2);
            v1 = rd32(e);
            wr32(e + 4u, s1);
            wr32(e, v1 & 0x0FFFFFFFu);
        }
        spu_gc();
        return (int32_t)rd32(MT_E(s2));
    }
}

enum { VAB_SLOT = 0x800B9B40u, VAB_COUNT = 0x800C7CD8u, VAB_HDR = 0x800A5F20u,
       VAB_PROG = 0x800A5ED8u, VAB_TONE = 0x800A60B0u, VAB_SPU = 0x800C7CE0u,
       VAB_SIZE = 0x800C7C98u, VAB_MAXPROG = 0x800A6540u };

static int32_t ss_vab_open_head(uint32_t addr, int32_t vabid, uint32_t mode, uint32_t sbaddr) {
    /* 80041AB0 _SsVabOpenHeadWithMode(addr, vabid, mode, sbaddr) */
    int32_t s1 = 16, id, i, maxprog, vs, ps;
    uint32_t sizes[256], a1, prog, tone, vagoff, total, base;
    if (rd32(SP_G580) != 1u) return -1;
    wr32(SP_G580, 0);                            /* 800401A0(1) */
    id = (int16_t)vabid;
    if (id < 16) {
        int found = 0;
        if (id == -1) {
            for (i = 0; i < 16; ++i)
                if (!rd8(VAB_SLOT + (uint32_t)i)) { found = 1; s1 = i; break; }
        } else if (!rd8(VAB_SLOT + (uint32_t)id)) {
            found = 1;
            s1 = (int16_t)vabid;
        }
        if (found) {
            wr8(VAB_SLOT + (uint32_t)s1, 1);
            wr16(VAB_COUNT, (uint16_t)(rd16(VAB_COUNT) + 1u));
        }
    }
    s1 = (int16_t)s1;
    if (s1 >= 16) { wr32(SP_G580, 1); return -1; }   /* 800401A0(0) */
    wr32(VAB_HDR + (uint32_t)s1 * 4u, addr);
    a1 = rd32(addr);
    if ((a1 >> 8) != 0x564142u) {                /* "VAB" */
        wr8(VAB_SLOT + (uint32_t)s1, 0);
        goto fail_count;
    }
    wr16(VAB_MAXPROG, ((a1 & 0xFFu) == 112u && (int32_t)rd32(addr + 4u) >= 5) ? 128 : 64);
    maxprog = (int16_t)rd16(VAB_MAXPROG);
    if (maxprog < (int32_t)rd16(addr + 18u)) goto fail_slot;
    prog = addr + 32u;
    wr32(VAB_PROG + (uint32_t)s1 * 4u, prog);
    tone = prog + (uint32_t)maxprog * 16u;
    {
        uint32_t n = 0;
        for (i = 0; i < maxprog; ++i) {
            uint32_t p = prog + (uint32_t)i * 16u;
            wr32(p + 8u, n);
            if (rd8(p)) ++n;
        }
    }
    wr32(VAB_TONE + (uint32_t)s1 * 4u, tone);
    ps = rd16(addr + 18u);
    vs = rd8(addr + 22u);
    vagoff = tone + (uint32_t)ps * 512u;
    total = 0;
    for (i = 0; i < 256; ++i, vagoff += 2u) {
        if (i <= vs) {
            uint32_t v = rd16(vagoff);
            sizes[i] = (int32_t)rd32(addr + 4u) >= 5 ? v << 3 : v << 2;
            total += sizes[i];
        }
    }
    if ((mode & 0xFFFFu) == 0) {
        int32_t m = spu_malloc(total);
        if (m == -1) goto fail_slot;
        base = (uint32_t)m;
    } else {
        base = sbaddr;
    }
    if (0x80000u < base + total) goto fail_slot;
    wr32(VAB_SPU + (uint32_t)s1 * 4u, base);
    total = 0;
    for (i = 0; i <= vs; ++i) {
        total += sizes[i];
        wr16(prog + (uint32_t)(i / 2) * 16u + ((i & 1) ? 14u : 12u), (uint16_t)((base + total) >> 3));
    }
    wr32(VAB_SIZE + (uint32_t)s1 * 4u, total);
    wr8(VAB_SLOT + (uint32_t)s1, 2);
    return s1;
fail_slot:
    wr8(VAB_SLOT + (uint32_t)s1, 0);
fail_count:
    wr32(SP_G580, 1);                            /* 800401A0(0) */
    wr16(VAB_COUNT, (uint16_t)(rd16(VAB_COUNT) - 1u));
    return -1;
}
static void spu_free(uint32_t addr) {
    /* 8004162C SpuFree(addr): mark the block free, then _spu_gcSPU */
    int32_t i;
    for (i = 0; i < (int32_t)rd32(SP_MNUM); ++i) {
        uint32_t w = rd32(MT_E(i));
        if (w & 0x40000000u) break;
        if (w == addr) { wr32(MT_E(i), addr | 0x80000000u); break; }
    }
    spu_gc();
}
static uint32_t spu_write_partly(uint32_t src, uint32_t size) {
    /* 800422E8 SpuWritePartly(addr, size) */
    uint32_t addr;
    if (size > 0x7EFF0u) size = 0x7EFF0u;
    addr = (uint32_t)rd16(SP_TADDR) << (rd32(SP_SHIFT) & 31u);
    (void)spu_write_data(src, size);
    wr16(SP_TADDR, (uint16_t)spu_fset_rxx(-1, addr + size));
    if (!rd32(SP_TCB)) wr32(SP_G580, 0);
    return size;
}
enum { VAB_TRANS_LEFT = 0x8006BA84u, VAB_TRANS_ID = 0x8006BA88u };
SPU_ENTRY(hle_spu_free) { spu_free(call->r[4]); return 1; }
SPU_ENTRY(hle_spu_write_partly) { CD_SP(); call->r[2] = spu_write_partly(call->r[4], call->r[5]); return 1; }
SPU_ENTRY(hle_spu_set_transfer_mode) {
    /* 800422B4 SpuSetTransferMode(mode) */
    wr32(SP_G0E8, call->r[4]);
    wr32(SP_DMAINIT, call->r[4] == 1u ? 1u : 0u);
    return 1;
}
SPU_ENTRY(hle_ss_vab_close) {
    /* 800415A8 SsVabClose(id) */
    int16_t n = (int16_t)call->r[4];
    if ((uint16_t)n < 16u && rd8(VAB_SLOT + (uint32_t)(int32_t)n) == 1u) {
        spu_free(rd32(VAB_SPU + (uint32_t)(int32_t)n * 4u));
        wr8(VAB_SLOT + (uint32_t)(int32_t)n, 0);
        wr16(VAB_COUNT, (uint16_t)(rd16(VAB_COUNT) - 1u));
    }
    return 1;
}
SPU_ENTRY(hle_ss_vab_trans_start) {
    /* 800419B0 (id): a header-open VAB (state 2) becomes loaded (1) */
    int16_t n = (int16_t)call->r[4];
    if ((uint16_t)n <= 16u && rd8(VAB_SLOT + (uint32_t)(int32_t)n) == 2u) {
        wr32(SP_G580, 1);                        /* 800401A0(0) */
        wr8(VAB_SLOT + (uint32_t)(int32_t)n, 1);
        call->r[2] = (uint32_t)(int32_t)n;
    } else {
        call->r[2] = (uint32_t)-1;
    }
    return 1;
}
SPU_ENTRY(hle_ss_vab_trans_body_partly) {
    /* 80042154 SsVabTransBodyPartly(addr, size, id) */
    uint32_t src = call->r[4], n = call->r[5];
    int16_t vab = (int16_t)call->r[6], cur;
    CD_SP();
    if ((uint16_t)call->r[6] > 16u || rd8(VAB_SLOT + (uint32_t)(int32_t)vab) != 2u) {
        wr32(SP_G580, 1);
        call->r[2] = (uint32_t)-1;
        return 1;
    }
    if (!rd32(VAB_TRANS_LEFT)) {
        wr16(VAB_TRANS_ID, (uint16_t)vab);
        wr32(VAB_TRANS_LEFT, rd32(VAB_SIZE + (uint32_t)(int32_t)vab * 4u));
        wr32(SP_G0E8, 0); wr32(SP_DMAINIT, 0);   /* SpuSetTransferMode(0) */
        {
            uint32_t a = rd32(VAB_SPU + (uint32_t)(int32_t)vab * 4u);
            if (a - 0x1010u <= 0x7EFE8u) wr16(SP_TADDR, (uint16_t)spu_fset_rxx(-1, a));
        }
    }
    cur = (int16_t)rd16(VAB_TRANS_ID);
    if (cur != vab) {
        wr32(SP_G580, 1);
        call->r[2] = (uint32_t)-1;
        return 1;
    }
    if (rd32(VAB_TRANS_LEFT) < n) n = rd32(VAB_TRANS_LEFT);
    wr32(SP_G580, 0);                            /* 800401A0(1) */
    (void)spu_write_partly(src, n);
    wr32(VAB_TRANS_LEFT, rd32(VAB_TRANS_LEFT) - n);
    if (rd32(VAB_TRANS_LEFT)) { call->r[2] = (uint32_t)-2; return 1; }
    wr16(VAB_TRANS_ID, 0xFFFFu);
    wr32(VAB_TRANS_LEFT, 0);
    wr8(VAB_SLOT + (uint32_t)(int32_t)cur, 1);
    call->r[2] = (uint32_t)(int32_t)cur;
    return 1;
}
SPU_ENTRY(hle_ss_vab_trans_completed) {
    /* 80042374 SsVabTransCompleted(flag) */
    call->r[2] = (uint32_t)(int32_t)(int16_t)spu_is_transfer_completed((int16_t)call->r[4]);
    return 1;
}
static int32_t ss_vm_set_vab(uint32_t a0, uint32_t a1) {
    /* 800414E4 (vab, prog): select the VAB's header, program and tone
     * tables and the program's first tone index for the libsnd voice code */
    int32_t id, prog;
    uint32_t hdr, pt, tt;
    if ((a0 & 0xFFFFu) >= 16u) return -1;
    id = (int16_t)a0;
    if (rd8(VAB_SLOT + (uint32_t)id) != 1u) return -1;
    prog = (int16_t)a1;
    if (!(prog < (int16_t)rd16(VAB_MAXPROG))) return -1;
    hdr = rd32(VAB_HDR + (uint32_t)id * 4u);
    pt = rd32(VAB_PROG + (uint32_t)id * 4u);
    tt = rd32(VAB_TONE + (uint32_t)id * 4u);
    wr8(0x800B9B21u, (uint8_t)a0);
    wr8(0x800B9B26u, (uint8_t)a1);
    wr32(0x800A6580u, hdr);
    wr32(0x800A6578u, pt);
    wr32(0x800A6584u, tt);
    wr8(0x800B9B27u, (uint8_t)rd32(pt + (uint32_t)prog * 16u + 8u));
    return 0;
}
SPU_ENTRY(hle_ss_vm_set_vab) { call->r[2] = (uint32_t)ss_vm_set_vab(call->r[4], call->r[5]); return 1; }
/* ---- libpress MDEC low level, linked into the movie overlays (B28) ----
 * main_0003 and main_0004 carry the same bytes at 800D2D68..800D3200. Those
 * functions touch MDEC and DMA0/1 registers through the pointer cells
 * 800DB63C..800DB674, which the lane refuses (rule "memory"), so they are
 * reproduced here from the disassembly. Overlays share addresses, so each
 * entry first checks that the resident bytes hash (FNV-1a 64, the lane's
 * member digest) to the expected function; a hash is not game data. */
enum { MD_DMA0_MADR = 0x800DB63Cu, MD_DMA0_BCR = 0x800DB640u, MD_DMA0_CHCR = 0x800DB644u,
       MD_DMA1_MADR = 0x800DB648u, MD_DMA1_BCR = 0x800DB64Cu, MD_DMA1_CHCR = 0x800DB650u,
       MD_CMD = 0x800DB66Cu, MD_CTRL = 0x800DB670u, MD_DPCR = 0x800DB674u };

static void ovl_resident(uint32_t pc, uint32_t size, uint64_t want) {
    uint64_t h = 0xCBF29CE484222325ull;
    uint32_t i;
    for (i = 0; i < size; ++i) h = (h ^ rd8(pc + i)) * 0x100000001B3ull;
    if (h != want) driver_stop("overlay_hle_not_resident", pc);
}
static uint32_t md_r(uint32_t cell) {
    uint32_t a = rd32(cell), v = 0;
    const MusashiGpuIoDevice *g = g_driver.devices ? g_driver.devices->gpu_io : NULL;
    if (g && g->read32 && g->read32(g->userdata, a, &v)) return v;
    return hw32(a);
}
static void md_w(uint32_t cell, uint32_t v) {
    uint32_t a = rd32(cell);
    const MusashiGpuIoDevice *g = g_driver.devices ? g_driver.devices->gpu_io : NULL;
    if (g && g->write32 && g->write32(g->userdata, a, v)) return;
    hw32w(a, v);
}
static void mdec_reset_regs(int read_back) {
    md_w(MD_CTRL, 0x80000000u);
    md_w(MD_DMA0_CHCR, 0);
    md_w(MD_DMA1_CHCR, 0);
    if (read_back) (void)md_r(MD_DMA1_CHCR);
    md_w(MD_CTRL, 0x60000000u);
}
static uint32_t mdec_timeout(const char *what) {
    /* 800D30D0: report and reset; returns 0 */
    uint32_t st = md_r(MD_CTRL);
    fprintf(stderr, "native_boot: MDEC %s timeout status=%08x dma0=%08x dma1=%08x\n",
            what, st, md_r(MD_DMA0_CHCR), md_r(MD_DMA1_CHCR));
    mdec_reset_regs(1);
    return 0;
}
static uint32_t mdec_in_sync(void) {
    /* 800D2F88: wait while the input FIFO is busy (bit 29), 0x100000 tries */
    int32_t count = 0x100000;
    while (md_r(MD_CTRL) & 0x20000000u) {
        if (--count == -1) { (void)mdec_timeout("in_sync"); return (uint32_t)-1; }
        driver_spin(16u);
    }
    return 0;
}
static uint32_t mdec_out_sync(void) {
    /* 800D3020: wait while DMA1 runs (CHCR bit 24), 0x100000 tries */
    int32_t count = 0x100000;
    while (md_r(MD_DMA1_CHCR) & 0x1000000u) {
        if (--count == -1) { (void)mdec_timeout("out_sync"); return (uint32_t)-1; }
        driver_spin(16u);
    }
    return 0;
}
static void mdec_in(uint32_t addr, uint32_t size) {
    /* 800D2E64: DMA0 from addr+4, first word is the MDEC command */
    (void)mdec_in_sync();
    md_w(MD_DPCR, md_r(MD_DPCR) | 0x88u);
    md_w(MD_DMA0_MADR, addr + 4u);
    md_w(MD_DMA0_BCR, ((size >> 5) << 16) | 0x20u);
    md_w(MD_CMD, rd32(addr));
    md_w(MD_DMA0_CHCR, 0x1000201u);
}
static void mdec_out(uint32_t addr, uint32_t size) {
    /* 800D2EF8 */
    (void)mdec_out_sync();
    md_w(MD_DPCR, md_r(MD_DPCR) | 0x88u);
    md_w(MD_DMA1_CHCR, 0);
    md_w(MD_DMA1_MADR, addr);
    md_w(MD_DMA1_BCR, ((size >> 5) << 16) | 0x20u);
    md_w(MD_DMA1_CHCR, 0x1000200u);
}
SPU_ENTRY(hle_mdec_reset) {
    /* 800D2D68 MDEC_reset(mode): 0 full reset plus the two default tables
     * (800DB52C, 800DB5B0, 32 bytes each, through MDEC_in), 1 registers only */
    ovl_resident(0x800D2D68u, 252u, 0x2F280E9FC3D5B9BAull);
    if (call->r[4] == 0u) {
        mdec_reset_regs(0);
        mdec_in(0x800DB52Cu, 32u);
        mdec_in(0x800DB5B0u, 32u);
    } else if (call->r[4] == 1u) {
        mdec_reset_regs(1);
    } else {
        fprintf(stderr, "native_boot: MDEC_rest:bad option(%d)\n", (int)call->r[4]);
    }
    return 1;
}
SPU_ENTRY(hle_mdec_in) {
    ovl_resident(0x800D2E64u, 148u, 0x628028B0D6EDFF60ull);
    mdec_in(call->r[4], call->r[5]);
    return 1;
}
SPU_ENTRY(hle_mdec_out) {
    ovl_resident(0x800D2EF8u, 144u, 0x17076E67904BB97Cull);
    mdec_out(call->r[4], call->r[5]);
    return 1;
}
SPU_ENTRY(hle_mdec_in_sync) {
    ovl_resident(0x800D2F88u, 152u, 0x576FF23633C63E08ull);
    call->r[2] = mdec_in_sync();
    return 1;
}
SPU_ENTRY(hle_mdec_out_sync) {
    ovl_resident(0x800D3020u, 152u, 0x44FECBF9FE4ACC6Dull);
    call->r[2] = mdec_out_sync();
    return 1;
}
SPU_ENTRY(hle_mdec_status) {
    ovl_resident(0x800D30B8u, 24u, 0x66DCECDE0526A9D6ull);
    call->r[2] = md_r(MD_CTRL);
    return 1;
}
SPU_ENTRY(hle_mdec_timeout) {
    ovl_resident(0x800D30D0u, 304u, 0x0147896EE4EA6E2Full);
    call->r[2] = mdec_timeout("print");
    return 1;
}
/* ---- libcd streaming (St*), retail 80043088.., from the disassembly ---- */
enum { ST_RING = 0x800C7C94u, ST_RING_SIZE = 0x800C7F00u };
static void st_clear_slots(uint32_t first, uint32_t count) {
    /* 80046BFC: zero the first word of each 32-byte slot header */
    uint32_t i;
    for (i = 0; i < count; ++i) wr32(rd32(ST_RING) + ((first + i) << 5), 0);
}
static void st_clear_ring(void) {
    /* 8004689C StClearRing */
    wr32(0x800C6D40u, 0);
    wr32(0x800C6D3Cu, 0);
    wr32(0x800C6D38u, 0);
    wr32(0x800AE644u, 0);
    st_clear_slots(0, rd32(ST_RING_SIZE));
    wr32(0x800A5F1Cu, 0);
    wr16(0x800A2B94u, 0);
    wr32(0x80078E38u, 0);
}
SPU_ENTRY(hle_st_set_ring) {
    /* 80043088 StSetRing(ring, size) */
    wr32(ST_RING, call->r[4]);
    wr32(ST_RING_SIZE, call->r[5]);
    st_clear_ring();
    return 1;
}
SPU_ENTRY(hle_st_clear_ring) { st_clear_ring(); return 1; }
SPU_ENTRY(hle_st_clear_slots) { st_clear_slots(call->r[4], call->r[5]); return 1; }
SPU_ENTRY(hle_ss_set_serial_attr) {
    /* 8003D650 SsSetSerialAttr(s_num, attr, mode): s_num 0 = CD, 1 = EXT;
     * attr 0 = mix, 1 = reverb. Builds a one-field SpuCommonAttr in the retail
     * frame (sp-64+16) and calls SpuSetCommonAttr. When no pair matches,
     * retail passes an uninitialised mask; here nothing is written. */
    uint32_t s = call->r[4] & 0xFFu, a = call->r[5] & 0xFFu, attr = call->r[29] - 64u + 16u;
    uint32_t mask = 0u, off = 0u;
    if (s == 0u && a == 0u) { mask = 0x200u; off = 24u; }
    else if (s == 0u && a == 1u) { mask = 0x100u; off = 20u; }
    else if (s == 1u && a == 0u) { mask = 0x2000u; off = 36u; }
    else if (s == 1u && a == 1u) { mask = 0x1000u; off = 32u; }
    if (mask) {
        wr32(attr, mask);
        wr32(attr + off, call->r[6] & 0xFFu);
        spu_set_common_attr(attr);
    }
    return 1;
}
SPU_ENTRY(hle_ss_set_serial_vol) {
    /* 8003EDE8 SsSetSerialVol(s_num, voll, volr): s_num 0 = CD (mask 0xC0,
     * attr+16/18), 1 = EXT (mask 0xC00, attr+28/30). Each volume is capped at
     * 127 (signed 16-bit compare, no lower bound) and scaled by 258. Same
     * frame layout as retail (attr at sp-64+16); no write for other s_num,
     * where retail passes an uninitialised mask. */
    uint32_t s = call->r[4] & 0xFFu, attr = call->r[29] - 64u + 16u, off;
    int32_t l = (int16_t)call->r[5], r = (int16_t)call->r[6];
    if (s > 1u) return 1;
    if (l >= 128) l = 127;
    if (r >= 128) r = 127;
    off = s ? 28u : 16u;
    wr32(attr, s ? 0xC00u : 0xC0u);
    wr16(attr + off, (uint16_t)(l * 258));
    wr16(attr + off + 2u, (uint16_t)(r * 258));
    spu_set_common_attr(attr);
    return 1;
}
SPU_ENTRY(hle_ss_ut_get_vag_addr) {
    /* 8003F380 SsUtGetVagAddr(vab, vag): the VAG's SPU address that
     * SsVabOpenHead stored in program-table slot (vag-1)/2 (+12 odd, +14 even) */
    int32_t n;
    if (ss_vm_set_vab((uint32_t)(int32_t)(int16_t)call->r[4], 0) == -1) { call->r[2] = (uint32_t)-1; return 1; }
    n = ((int32_t)(int16_t)call->r[5] - 1) / 2;
    call->r[2] = (uint32_t)rd16(rd32(0x800A6578u) + (uint32_t)n * 16u + ((call->r[5] & 1u) ? 12u : 14u)) << 3;
    return 1;
}
SPU_ENTRY(hle_ss_ut_get_vag_atr) {
    /* 8003F144 SsUtGetVagAtr(vab, prog, tone, attr): copy the tone's
     * attribute bytes 0..13 and halfwords 16..22 */
    int32_t id = (int16_t)call->r[4];
    uint32_t dst = call->r[7], src, k;
    if (rd8(VAB_SLOT + (uint32_t)id) != 1u) { call->r[2] = (uint32_t)-1; return 1; }
    (void)ss_vm_set_vab((uint32_t)id, (uint32_t)(int32_t)(int16_t)call->r[5]);
    src = rd32(0x800A6584u) +
          (uint32_t)((int32_t)(int16_t)(call->r[6] + (uint32_t)rd8(0x800B9B27u) * 16u) * 32);
    for (k = 0; k < 14u; ++k) wr8(dst + k, rd8(src + k));
    for (k = 16u; k < 24u; k += 2u) wr16(dst + k, rd16(src + k));
    call->r[2] = 0;
    return 1;
}
SPU_ENTRY(hle_spu_gc) { (void)call; spu_gc(); return 1; }
SPU_ENTRY(hle_spu_malloc) { call->r[2] = (uint32_t)spu_malloc(call->r[4]); return 1; }
SPU_ENTRY(hle_ss_vab_open_head_mode) {
    call->r[2] = (uint32_t)ss_vab_open_head(call->r[4], (int32_t)call->r[5], call->r[6], call->r[7]);
    return 1;
}
SPU_ENTRY(hle_ss_vab_open_head) {       /* 80041A20 SsVabOpenHead(addr, id) */
    call->r[2] = (uint32_t)(int32_t)(int16_t)ss_vab_open_head(call->r[4], (int16_t)call->r[5], 0, 0);
    return 1;
}
SPU_ENTRY(hle_ss_vab_open_head_sticky) { /* 80041A50 / 80041A80 (addr, id, sbaddr) */
    call->r[2] = (uint32_t)(int32_t)(int16_t)ss_vab_open_head(call->r[4], (int16_t)call->r[5], 1,
                                                              call->r[6]);
    return 1;
}

/* ---- strict seams for registry game functions the lane refuses (B28) -----
 * 80018A20 (pad port poll) is matched owner C, but the lane rejects it as
 * "ub": retail reads the caller's s2 as the PadGetState slot for ports other
 * than 0/1 and returns whatever v0 holds for unlisted pad states (1 for
 * negative states, 6 otherwise), which C cannot express. This entry follows
 * the retail words, including those returns; an out-of-range port stops. */
static uint32_t seam_call(MusashiNativeLaneCall *call, uint32_t pc, unsigned argc, uint32_t a0,
                          uint32_t a1, uint32_t a2) {
    uint32_t a[3] = {a0, a1, a2};
    return call_at(call->r[29] - 0x40u, pc, argc, a);
}

static int seam_pad_poll(MusashiNativeLaneCall *call) {
    uint32_t port = call->r[4], pad = 0x80078D98u + port * 76u, slot;
    int32_t state;
    if (port > 1u) driver_stop("pad_poll_port_reads_caller_s2", 0x80018A20u);
    slot = port ? 0x10u : 0u;
    state = (int32_t)seam_call(call, 0x8005D184u, 1, slot, 0, 0);       /* PadGetState */
    switch (state) {
    case 0:
        if (port == 0u) {
            uint32_t n = rd32(0x800AE610u);
            wr32(0x800AE610u, n + 1u);
            if (n >= 10u) { wr32(0x800AE610u, 0); wr32(0x800A5E78u, 0); }
        }
        /* fall through */
    case 1:
        (void)seam_call(call, 0x80018F88u, 1, pad, 0, 0);
        call->r[2] = 0;
        return 1;
    case 2:
    case 6:
        call->r[2] = 1;
        if (port != 0u) return 1;
        wr32(0x800AE610u, 0);
        if ((seam_call(call, 0x8005D244u, 3, slot, 2, 0) != 0u) == (state == 2)) return 1;
        if (seam_call(call, 0x80028D58u, 0, 0, 0, 0) == 0u) {
            if (state == 2) wr8(0x80062BBDu, (uint8_t)((rd8(pad + 0x4Au) | rd8(pad + 0x4Bu)) != 0));
            else { wr8(0x800747B8u, rd8(pad + 0x4Au)); wr8(0x800747B9u, rd8(pad + 0x4Bu)); }
            wr8(pad + 0x4Bu, 0);
            wr8(pad + 0x4Au, 0);
        } else {
            (void)seam_call(call, 0x80018FC8u, 0, 0, 0, 0);
        }
        (void)seam_call(call, 0x8005D538u, 3, slot, state == 2 ? 0x80062BBCu : 0x800747B8u, 2);
        (void)seam_call(call, 0x8005D4B8u, 2, slot, state == 2 ? 0x80062BACu : 0x80062BB4u, 0);
        call->r[2] = 1;
        return 1;
    default:
        call->r[2] = state < 0 ? 1u : 6u;
        return 1;
    }
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
    {0x8003A424u, 0, hle_spu_init,        "SpuInit",             0, 1, 0},
    {0x8003A444u, 0, hle_spu_init_mode,   "_SpuInit",            1, 1, 0},
    {0x8003A53Cu, 0, hle_spu_init_events, "_spu_init_events",    0, 0, 0},
    {0x8003A5B8u, 0, hle_spu_init_hw,     "_spu_init",           1, 1, 0},
    {0x8003A84Cu, 0, hle_spu_write_manual,"_spu_writeByIO",      2, 0, 0},
    {0x8003AA18u, 0, hle_spu_dma_irq,     "_spu_dma_irq",        0, 0, 0},
    {0x8003AB84u, 0, hle_spu_transfer,    "_spu_t",              3, 1, 0},
    {0x8003B0E4u, 0, hle_spu_delay,       "_spu_delay",          0, 0, 0},
    {0x8003B1ECu, 0, hle_spu_set_env,     "SpuSetEnv",           1, 0, 0},
    {0x8003B280u, 0, hle_spu_set_reverb,  "SpuSetReverb",        1, 1, 0},
    {0x8003B3D0u, 0, hle_spu_overlap,     "_spu_rev_overlap",    1, 1, 0},
    {0x8003B45Cu, 0, hle_spu_set_reverb_mode_param, "SpuSetReverbModeParam", 1, 1, 0},
    {0x8003B954u, 0, hle_spu_set_reverb_regs, "_spu_setReverbAttr", 1, 0, 0},
    {0x8003BE24u, 0, hle_spu_reserve_reverb, "SpuReserveReverbWorkArea", 1, 1, 0},
    {0x8003BE74u, 0, hle_spu_set_reverb_voice, "SpuSetReverbVoice", 2, 1, 0},
    {0x8003BE98u, 0, hle_spu_voice_bits,  "_spu_voice_bits",     4, 1, 0},
    {0x8003C0A0u, 0, hle_spu_clear_reverb,"SpuClearReverbWorkArea", 1, 1, 0},
    {0x8003C598u, 0, hle_spu_set_common_attr, "SpuSetCommonAttr", 1, 0, 0},
    {0x8003D518u, 0, hle_ss_init,         "SsInit",              0, 0, 0},
    {0x8003D548u, 0, hle_ss_init_body,    "_SsInit",             0, 0, 0},
    {0x8003FA64u, 0, hle_ss_vm_flush,     "SpuVmFlush",          0, 0, 0},
    {0x8003FE18u, 0, hle_spu_set_noise_voice, "SpuSetNoiseVoice", 2, 1, 0},
    {0x8003FE3Cu, 0, hle_ss_vm_init,      "_SsVmInit",           1, 0, 0},
    {0x8004014Cu, 0, hle_spu_init_malloc, "SpuInitMalloc",       2, 1, 0},
    {0x800401A0u, 0, hle_spu_set_g580,    "_spu_set_g580",       1, 0, 0},
    {0x80040868u, 0, hle_ss_vm_keyoff_cur,"SpuVmKeyOffCur",      0, 0, 0},
    {0x8004239Cu, 0, hle_vsync,           "VSync",               1, 1, 0},
    {0x80043078u, 0, hle_cd_get_cbe8,     "CdGetCbe8",           0, 1, 0},
    {0x800430B8u, 0, hle_cd_get_toc,      "CdGetToc",            1, 1, 0},
    {0x800430DCu, 0, hle_cd_get_toc2,     "CdGetToc_body",       2, 1, 0},
    {0x80043300u, 0, hle_cd_init,         "CdInit",              0, 1, 0},
    {0x80043398u, 0, hle_cd_cb_sync_default,  "CdSyncDeliver",   2, 0, 0},
    {0x800433C0u, 0, hle_cd_cb_ready_default, "CdReadyDeliver",  2, 0, 0},
    {0x800433E8u, 0, hle_cd_cb_ready_default, "CdReadDeliver",   2, 0, 0},
    {0x80043410u, 0, hle_cd_status,       "CdStatus",            0, 1, 0},
    {0x80043420u, 0, hle_cd_mode,         "CdMode",              0, 1, 0},
    {0x80043430u, 0, hle_cd_lastcom,      "CdLastCom",           0, 1, 0},
    {0x80043440u, 0, hle_cd_lastpos,      "CdLastPos",           0, 1, 0},
    {0x80043450u, 0, hle_cd_reset,        "CdReset",             1, 1, 0},
    {0x800434BCu, 0, hle_cd_flush,        "CdFlush",             0, 0, 0},
    {0x800434DCu, 0, hle_cd_set_debug,    "CdSetDebug",          1, 1, 0},
    {0x800434F4u, 0, hle_cd_comstr,       "CdComstr",            1, 1, 0},
    {0x80043528u, 0, hle_cd_intstr,       "CdIntstr",            1, 1, 0},
    {0x8004355Cu, 0, hle_cd_sync,         "CdSync",              2, 1, 0},
    {0x8004357Cu, 0, hle_cd_ready,        "CdReady",             2, 1, 0},
    {0x8004359Cu, 0, hle_cd_sync_callback,  "CdSyncCallback",    1, 1, 0},
    {0x800435B4u, 0, hle_cd_ready_callback, "CdReadyCallback",   1, 1, 0},
    {0x800435CCu, 0, hle_cd_control,      "CdControl",           3, 1, 0},
    {0x80043704u, 0, hle_cd_control_f,    "CdControlF",          2, 1, 0},
    {0x80043830u, 0, hle_cd_control_b,    "CdControlB",          3, 1, 0},
    {0x80043060u, 0, hle_exchange_cbe8,   "exchange_8006CBE8",   1, 1, 0},
    {0x80043974u, 0, hle_cd_mix,          "CdMix",               1, 1, 0},
    {0x80043994u, 0, hle_cd_getsector,    "CdGetSector",         2, 1, 0},
    {0x800439B4u, 0, hle_cd_getsector2,   "CdGetSector2",        2, 1, 0},
    {0x800439D4u, 0, hle_cd_data_callback,"CdDataCallback",      1, 1, 0},
    {0x800439F8u, 0, hle_cd_datasync,     "CdDataSync",          1, 1, 0},
    {0x80043B9Cu, 0, hle_cd_getintr,      "CD_getintr",          0, 1, 0},
    {0x80044124u, 0, hle_cd_sync,         "CD_sync",             2, 1, 0},
    {0x800443A4u, 0, hle_cd_ready,        "CD_ready",            2, 1, 0},
    {0x80044670u, 0, hle_cd_cw,           "CD_cw",               4, 1, 0},
    {0x80044B14u, 0, hle_cd_flush,        "CD_flush",            0, 0, 0},
    {0x80044BF4u, 0, hle_cd_initvol,      "CD_initvol",          0, 1, 0},
    {0x80044CE8u, 0, hle_cd_initintr,     "CD_initintr",         0, 0, 0},
    {0x80044D38u, 0, hle_cd_init_body,    "CD_init",             0, 1, 0},
    {0x80044F24u, 0, hle_cd_datasync,     "CD_datasync",         1, 1, 0},
    {0x80045090u, 0, hle_cd_getsector,    "CD_getsector",        2, 1, 0},
    {0x80045190u, 0, hle_cd_getsector2,   "CD_getsector2",       2, 1, 0},
    {0x80045290u, 0, hle_cd_irq,          "CD_irq",              0, 0, 0},
    {0x80045374u, 0, hle_cd_search_file,  "CdSearchFile",        2, 1, 0},
    {0x80045C94u, 0, hle_cd_read_lba,     "CD_read_lba",         3, 1, 0},
    {0x80045D00u, 0, hle_cd_read_ready_cb,"CdRead_ready_cb",     2, 0, 0},
    {0x80045FD0u, 0, hle_cd_read_dma_cb,  "CdRead_dma_cb",       0, 0, 0},
    {0x800460CCu, 0, hle_cd_read_start,   "CdRead_start",        1, 1, 0},
    {0x800462E0u, 0, hle_cd_read_break,   "CdReadBreak",         0, 0, 0},
    {0x8004637Cu, 0, hle_cd_read,         "CdRead",              3, 1, 0},
    {0x80046480u, 0, hle_cd_read_sync,    "CdReadSync",          2, 1, 0},
    {0x8004654Cu, 0, hle_cd_read_callback,"CdReadCallback",      1, 1, 0},
    {0x80046564u, 0, hle_cd_cb_cfd0,      "CdCallback_CFD0",     1, 1, 0},
    {0x80046630u, 0, hle_cd_disk_ready,   "CdDiskReady",         1, 1, 0},
    {0x8004674Cu, 0, hle_cd_disk_type,    "CdGetDiskType",       0, 1, 0},
    {0x8005CE18u, 0, hle_init_heap,       "InitHeap",            2, 0, 0},
    {0x8005CE68u, 0, hle_b0_deliver_event,"DeliverEvent",        2, 1, 0},
    {0x8005CE78u, 0, hle_b0_open_event,   "OpenEvent",           4, 1, 0},
    {0x8005CE88u, 0, hle_b0_close_event,  "CloseEvent",          1, 1, 0},
    {0x8005CE98u, 0, hle_b0_wait_event,   "WaitEvent",           1, 1, 0},
    {0x8005CEA8u, 0, hle_b0_test_event,   "TestEvent",           1, 1, 0},
    {0x8005CEB8u, 0, hle_b0_enable_event, "EnableEvent",         1, 1, 0},
    {0x8005CEC8u, 0, hle_b0_disable_event,"DisableEvent",        1, 1, 0},
    {0x8005CF08u, 0, hle_enter_critical,  "EnterCriticalSection",0, 1, 0},
    {0x8005CF18u, 0, hle_exit_critical,   "ExitCriticalSection", 0, 0, 0},
    {0x80059234u, 0, hle_reset_graph,     "ResetGraph",          1, 1, 0},
    {0x800594CCu, 0, hle_set_graph_debug, "SetGraphDebug",       1, 1, 0},
    {0x800525DCu, 0, hle_gs_init_graph,   "GsInitGraph",         4, 0, 0},
    {0x80053178u, 0, hle_gs_def_disp_buff,"GsDefDispBuff",       4, 0, 0},
    {0x80053218u, 0, hle_gs_init_3d,      "GsInit3D",            0, 0, 0},
    {0x800527C4u, 0, hle_gs_init_graph2,  "GsInitGraph2",        4, 0, 0},
    {0x80053EECu, 0, hle_gs_def_disp_buff2,"GsDefDispBuff2",     4, 0, 0},
    {0x80058A4Cu, 0, hle_set_def_draw_env,"SetDefDrawEnv",       4, 1, 0},
    {0x80059888u, 0, hle_clear_image,     "ClearImage",          4, 1, 0},
    {0x80053F6Cu, 0, hle_gs_set_ref_view2,"GsSetRefView2",       1, 1, 0},
    {0x80047948u, 0, hle_rcos,            "rcos",                1, 1, 0},
    {0x8004787Cu, 0, hle_rsin,            "rsin",                1, 1, 0},
    {0x80047D3Cu, 0, hle_sqrt0,           "SquareRoot0",         1, 1, 0},
    {0x8004974Cu, 0, hle_transpose,       "TransposeMatrix",     2, 1, 0},
    {0x80053E28u, 0, hle_gs_rot_axis,     "GsRotAxisMatrix",     4, 0, 0},
    {0x80053B20u, 0, hle_gs_rot_z,        "GsRotZMul",           2, 0, 0},
    {0x80054340u, 0, hle_gs_scale_view,   "GsScaleView",         2, 0, 0},
    {0x80052FCCu, 0, hle_gs_comp_matrix,  "GsCompMatrix",        2, 0, 0},
    {0x80053328u, 0, hle_gs_set_flat_light,"GsSetFlatLight",     2, 1, 0},
    {0x80053804u, 0, hle_gs_set_color_matrix,"GsSetColorMatrix", 1, 0, 0},
    {0x800538BCu, 0, hle_set_color_matrix,"SetColorMatrix",      1, 0, 0},
    {0x800595FCu, 0, hle_draw_sync_callback,"DrawSyncCallback",  1, 1, 0},
    {0x8003D25Cu, 0, hle_spu_get_all_keys_status,"SpuGetAllKeysStatus", 3, 1, 0},
    {0x800416A8u, 0, hle_spu_gc,          "_spu_gcSPU",          0, 0, 0},
    {0x800414E4u, 0, hle_ss_vm_set_vab,   "_SsVmSetVab",         2, 1, 0},
    {0x8003F144u, 0, hle_ss_ut_get_vag_atr, "SsUtGetVagAtr",     4, 1, 0},
    {0x8003F380u, 0, hle_ss_ut_get_vag_addr, "SsUtGetVagAddr",   2, 1, 0},
    {0x8003D650u, 0, hle_ss_set_serial_attr, "SsSetSerialAttr",  3, 0, 0},
    {0x8003EDE8u, 0, hle_ss_set_serial_vol, "SsSetSerialVol",    3, 0, 0},
    {0x800D2D68u, 0, hle_mdec_reset,     "MDEC_reset(ovl)",     1, 0, 0},
    {0x800D2E64u, 0, hle_mdec_in,        "MDEC_in(ovl)",        2, 0, 0},
    {0x800D2EF8u, 0, hle_mdec_out,       "MDEC_out(ovl)",       2, 0, 0},
    {0x800D2F88u, 0, hle_mdec_in_sync,   "MDEC_in_sync(ovl)",   0, 1, 0},
    {0x800D3020u, 0, hle_mdec_out_sync,  "MDEC_out_sync(ovl)",  0, 1, 0},
    {0x800D30B8u, 0, hle_mdec_status,    "MDEC_status(ovl)",    0, 1, 0},
    {0x800D30D0u, 0, hle_mdec_timeout,   "MDEC_timeout(ovl)",   1, 1, 0},
    {0x80043088u, 0, hle_st_set_ring,    "StSetRing",           2, 0, 0},
    {0x8004689Cu, 0, hle_st_clear_ring,  "StClearRing",         0, 0, 0},
    {0x80046BFCu, 0, hle_st_clear_slots, "StClearSlots",        2, 0, 0},
    {0x8004162Cu, 0, hle_spu_free,        "SpuFree",             1, 0, 0},
    {0x800415A8u, 0, hle_ss_vab_close,    "SsVabClose",          1, 0, 0},
    {0x800419B0u, 0, hle_ss_vab_trans_start, "SsVabTransBody(start)", 1, 1, 0},
    {0x80042154u, 0, hle_ss_vab_trans_body_partly, "SsVabTransBodyPartly", 3, 1, 0},
    {0x800422B4u, 0, hle_spu_set_transfer_mode, "SpuSetTransferMode", 1, 0, 0},
    {0x800422E8u, 0, hle_spu_write_partly, "SpuWritePartly",     2, 1, 0},
    {0x80042374u, 0, hle_ss_vab_trans_completed, "SsVabTransCompleted", 1, 1, 0},
    {0x80041E8Cu, 0, hle_spu_malloc,      "SpuMalloc",           1, 1, 0},
    {0x80041AB0u, 0, hle_ss_vab_open_head_mode, "_SsVabOpenHeadWithMode", 4, 1, 0},
    {0x80041A20u, 0, hle_ss_vab_open_head, "SsVabOpenHead",      2, 1, 0},
    {0x80041A50u, 0, hle_ss_vab_open_head_sticky, "SsVabOpenHeadSticky", 3, 1, 0},
    {0x80041A80u, 0, hle_ss_vab_open_head_sticky, "SsVabFakeHead",   3, 1, 0},
    {0x8003AE14u, 0, hle_spu_write_data,  "_spu_write",          2, 1, 0},
    {0x8003AF4Cu, 0, hle_spu_fset_rxx,    "_spu_FsetRXX",        2, 1, 0},
    {0x8003C438u, 0, hle_spu_write,       "SpuWrite",            2, 1, 0},
    {0x8003C498u, 0, hle_spu_set_transfer_start_addr, "SpuSetTransferStartAddr", 1, 1, 0},
    {0x8003C4F0u, 0, hle_spu_is_transfer_completed, "SpuIsTransferCompleted", 1, 1, 0},
    {0x80018A20u, 0, seam_pad_poll,       "pad_port_poll",       1, 1, 0},
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
    /* Guest time for the waited fields moves in 16-line slices with an
     * interrupt point after each, so per-sector CD interrupts (2x speed: one
     * every ~105 lines) are serviced before the next sector replaces the
     * buffer, as the retail VSync busy-wait allows (B28; whole-field steps
     * dropped sectors and the loader retried forever). */
    if (fields && g_driver.ops && g_driver.ops->spend) {
        while (fields--) {
            unsigned lines = 263u;
            while (lines) {
                unsigned n = lines < 16u ? lines : 16u;
                if (!g_driver.ops->spend(g_driver.ops->user, 2146u * n))
                    driver_stop("vblank_refused", F_VSYNC);
                lines -= n;
                driver_irq_poll();
            }
        }
    } else if (fields && g_driver.ops && g_driver.ops->vblank &&
               !g_driver.ops->vblank(g_driver.ops->user, fields)) {
        driver_stop("vblank_refused", F_VSYNC);
    }
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
    {
        /* MUSASHI_DRIVER_TRACE=N: one progress line every N frames */
        static long every = -1;
        if (every < 0) { const char *e = getenv("MUSASHI_DRIVER_TRACE"); every = e ? atol(e) : 0; }
        if (every > 0 && g_driver.frames % (unsigned long)every == 0)
            fprintf(stderr, "native_boot: FRAME_TRACE frame=%lu alt=%u ovl_state=%u prims=%u "
                    "disp=%u draw=%u st3b4=%04x ld=%u ld_n=%u ovl_flag=%u cdq=%u/%u cderr=%u cdst=%02x strm=%08x/%u lst=%d sync=%d rd=%d want=%d hdr=%08x %08x %08x\n", (unsigned long)g_driver.frames,
                    rd8(MAIN_STATE + ST_ALT_FRAME), rd16(0x800B99E4u),
                    rd32(PRIM_CURSOR) - (PRIM_AREA + buffer_index() * 80000u),
                    rd16(MAIN_STATE + ST_DISP_CUR), rd16(MAIN_STATE + ST_DRAW_CUR),
                    rd16(MAIN_STATE + 0xA3B4u), rd32(0x800BA1B4u), rd32(0x800C7C60u),
                    rd32(0x800D3C0Cu), rd32(0x8006AEF8u), rd32(0x8006AEFCu), rd8(0x80076214u),
                    rd8(0x8007620Cu), rd32(0x800AE708u), rd32(0x800AE7B0u),
                    (int)rd32(0x800AE6F0u), (int)rd32(0x800AE6E8u), (int)rd32(0x800AE734u + 0x18u),
                    (int)rd32(0x800AE7ACu), rd32(0x80078E40u), rd32(0x80078E44u), rd32(0x80078E48u));
    }
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
