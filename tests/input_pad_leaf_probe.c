/* S3a G1: native libpad leaves vs the interpreted retail words, same input.
 *
 * Two identical universes (guest RAM, scratchpad, BIOS callback frame, SIO0
 * model, Timer2 model, I_STAT latch, clock) run the same script; universe A
 * keeps every leaf on its retail words (musashi_input_pad_leaves_set(NULL)),
 * universe B runs the native leaves. After every step the probe compares all
 * guest RAM and scratchpad, the frame (stack bytes, busy, faulted), the full
 * SIO and Timer2 state, I_STAT, the per-byte tx/rx log with the tx cycle and
 * ACK due cycle, button samples, clock call count and cycles, results and
 * stop addresses. Leaf-level cases also compare the whole register file and
 * the remaining budget.
 *
 *   input_pad_leaf_probe <SLUS_007.26>            all cases; exit 0 iff 0 differ
 *   input_pad_leaf_probe <SLUS_007.26> --break N  with deliberate break N;
 *                                                 exit 0 iff a difference shows */
#include "../pc_port/mips_formatter.c"
#include "../pc_port/platform/psyq/bfm_psyq_libpad.c"
#include "../pc_port/include/musashi_sio_controller.h"
#include "../pc_port/include/musashi_timer2.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void musashi_sio_controller_set_analog_axes(const MusashiSioController *sio,
                                            uint8_t rx, uint8_t ry, uint8_t lx, uint8_t ly);

enum {
    SIO_STATUS = 0x1f801044u,
    IRQ_STATUS = 0x1f801070u,
    T2_COUNT_A = 0x1f801120u, T2_MODE_A = 0x1f801124u, T2_TARGET_A = 0x1f801128u,
    RECORD = 0x80078a48u,
    LOG_MAX = 4096,
};

typedef struct Fixture {
    MusashiSioController sio;
    MusashiTimer2 timer;
    MusashiExecutionClock clock;
    MusashiInputDevice device;
    MusashiSioPadDevice pad;
    uint64_t epoch;
    unsigned steps, fail_step;
    int freeze;                     /* host stop: the clock accepts, nothing advances */
    uint16_t buttons;
    unsigned pad_samples;
    uint32_t irq_status;
    unsigned irq_count;
    /* perturbations (identical in both universes) */
    uint32_t seed;
    unsigned drop_ack_pct, late_ack_max, ackline_max, rx_mutate_pct;
    int t2_mode_200;
    uint64_t late_due;              /* pending delayed I_STAT bit 7, 0 = none */
    uint64_t ackline_until;         /* STAT bit 7 (/ACK low) until this cycle */
    /* logs */
    unsigned tx_n, rx_n;
    uint8_t tx[LOG_MAX], rx[LOG_MAX];
    uint64_t tx_cycle[LOG_MAX], tx_due[LOG_MAX];
    unsigned reads16, writes16, reads32, writes32;
} Fixture;

typedef struct Universe {
    MusashiBootMemory memory;
    uint8_t guard_before[16];
    MusashiBiosCallbackFrame frame;
    uint8_t guard_after[16];
    Fixture fx;
} Universe;

static Universe g_a, g_b, g_snap_a, g_snap_b;
static unsigned g_differences, g_cases, g_native_done, g_native_refused;
static int g_break;

static uint32_t mix(uint32_t x) {
    x ^= x >> 16; x *= 0x7feb352du; x ^= x >> 15; x *= 0x846ca68bu; x ^= x >> 16;
    return x;
}
static uint32_t g_rng = 1;
static uint32_t rnd(void) { g_rng = mix(g_rng + 0x9e3779b9u); return g_rng; }

/* ---- fixture --------------------------------------------------------------- */

static uint64_t pad_owner(void *u) { (void)u; return 1; }
static int pad_sample(void *u, uint16_t *buttons) {
    Fixture *f = u;
    ++f->pad_samples;
    *buttons = f->buttons;
    return 1;
}
static int pad_raise_irq(void *u, uint16_t mask) {
    Fixture *f = u;
    uint32_t h = mix(f->seed ^ (f->irq_count * 0x10001u));
    if (mask != 0x80u) return 0;
    f->irq_count++;
    if (f->ackline_max) f->ackline_until = f->sio.cycle + 1u + h % f->ackline_max;
    if (f->drop_ack_pct && h % 100u < f->drop_ack_pct) return 1;           /* lost */
    if (f->late_ack_max && (h >> 8) % 3u == 0u) {                            /* late */
        f->late_due = f->sio.cycle + 1u + (h >> 12) % f->late_ack_max;
        return 1;
    }
    f->irq_status |= mask;
    return 1;
}
static int advance_clock(void *u, uint32_t cycles) {
    Fixture *f = u;
    ++f->steps;
    if (f->fail_step && f->steps == f->fail_step) return 0;
    if (f->freeze) return 1;
    f->epoch += cycles;
    if (!musashi_timer2_advance(&f->timer, f->epoch) ||
        !musashi_sio_controller_advance(&f->sio, f->epoch)) return 0;
    if (f->late_due && f->epoch >= f->late_due) { f->irq_status |= 0x80u; f->late_due = 0; }
    return 1;
}
static int fx_read16(void *u, uint32_t address, uint16_t *value) {
    Fixture *f = u;
    f->reads16++;
    if (address == T2_COUNT_A || address == T2_MODE_A || address == T2_TARGET_A) {
        if (!musashi_timer2_read16(&f->timer, address, value)) return 0;
        if (address == T2_MODE_A && f->t2_mode_200) *value |= 0x200u;
        return 1;
    }
    if (!musashi_sio_controller_read16(&f->sio, address, value)) return 0;
    if (address == SIO_STATUS && f->epoch < f->ackline_until) *value |= 0x80u;
    return 1;
}
static int fx_write16(void *u, uint32_t address, uint16_t value) {
    Fixture *f = u;
    f->writes16++;
    return musashi_sio_controller_write16(&f->sio, address, value);
}
static int fx_read8(void *u, uint32_t address, uint8_t *value) {
    Fixture *f = u;
    if (!musashi_sio_controller_read8(&f->sio, address, value)) return 0;
    if (f->rx_mutate_pct) {
        uint32_t h = mix(f->seed ^ 0x55u ^ (f->rx_n * 0x3779u));
        if (h % 100u < f->rx_mutate_pct) {
            static const uint8_t pick[] = {0x80u, 0x81u, 0x82u, 0x84u, 0x88u, 0xf3u, 0x73u,
                                           0x41u, 0x5au, 0x12u, 0x00u, 0xffu};
            *value = (h >> 8) & 1u ? pick[(h >> 9) % sizeof pick] : (uint8_t)(h >> 16);
        }
    }
    if (f->rx_n < LOG_MAX) f->rx[f->rx_n] = *value;
    f->rx_n++;
    return 1;
}
static int fx_write8(void *u, uint32_t address, uint8_t value) {
    Fixture *f = u;
    unsigned i = f->tx_n;
    uint64_t cycle = f->sio.cycle;
    if (!musashi_sio_controller_write8(&f->sio, address, value)) return 0;
    if (i < LOG_MAX) {
        f->tx[i] = value;
        f->tx_cycle[i] = cycle;
        f->tx_due[i] = f->sio.ack_pending ? f->sio.ack_due : 0;
    }
    f->tx_n++;
    return 1;
}
static int fx_read32(void *u, uint32_t address, uint32_t *value) {
    Fixture *f = u;
    if (address != IRQ_STATUS) return 0;
    f->reads32++;
    *value = f->irq_status;
    return 1;
}
static int fx_write32(void *u, uint32_t address, uint32_t value) {
    Fixture *f = u;
    if (address != IRQ_STATUS) return 0;
    f->writes32++;
    f->irq_status &= value;
    return 1;
}

/* Re-point every self reference after a struct copy. */
static void fx_bind(Fixture *f) {
    f->pad.userdata = f;
    f->sio.pad_device.userdata = f;
    f->clock.userdata = f;
    f->device.userdata = f;
    f->device.clock = &f->clock;
}

static void fx_init(Fixture *f) {
    memset(f, 0, sizeof *f);
    f->buttons = 0xffffu;
    musashi_sio_controller_init_disconnected(&f->sio);
    musashi_timer2_init(&f->timer, 0);
    f->pad.owner_thread = pad_owner;
    f->pad.sample_buttons = pad_sample;
    f->pad.raise_irq = pad_raise_irq;
    f->pad.userdata = f;
    assert(musashi_sio_controller_bind_digital_pad(&f->sio, &f->pad));
    f->clock.advance = advance_clock;
    f->device.read16 = fx_read16;
    f->device.write16 = fx_write16;
    f->device.read8 = fx_read8;
    f->device.write8 = fx_write8;
    f->device.read32 = fx_read32;
    f->device.write32 = fx_write32;
    fx_bind(f);
}

static uint8_t *g_exe;
static size_t g_exe_size;

static void universe_cold(Universe *u) {
    MusashiResetGraphPrefixStop stop = {0};
    memset(&u->memory, 0, sizeof u->memory);
    assert(musashi_boot_map_exe(&u->memory, g_exe, g_exe_size));
    assert(musashi_boot_run_8005f0c8_prefix(&u->memory, &stop) ==
           MUSASHI_RESETGRAPH_PREFIX_COMPLETE);
    memset(u->guard_before, 0xa5, 16);
    memset(u->guard_after, 0xa5, 16);
    musashi_boot_bios_callback_frame_init(&u->frame);
    fx_init(&u->fx);
}

static void universe_copy(Universe *dst, const Universe *src) {
    memcpy(dst, src, sizeof *dst);
    fx_bind(&dst->fx);
}

/* ---- comparison ------------------------------------------------------------ */

static int differ(const char *what, const char *field) {
    if (g_differences < 12)
        fprintf(stderr, "PAD_LEAF_DIFF case=%u %s: %s\n", g_cases, what, field);
    ++g_differences;
    return 0;
}

static int same_universe(const Universe *a, const Universe *b, const char *what) {
    const Fixture *x = &a->fx, *y = &b->fx;
    const MusashiSioController *s = &x->sio, *t = &y->sio;
    unsigned n = x->tx_n < LOG_MAX ? x->tx_n : LOG_MAX, m = x->rx_n < LOG_MAX ? x->rx_n : LOG_MAX;
    if (memcmp(a->memory.bytes, b->memory.bytes, sizeof a->memory.bytes)) {
        size_t i;
        for (i = 0; i < sizeof a->memory.bytes && a->memory.bytes[i] == b->memory.bytes[i]; ++i) {}
        if (g_differences < 12) fprintf(stderr, "  first RAM difference at %08zx\n", 0x80000000u + i);
        return differ(what, "guest RAM");
    }
    if (memcmp(a->memory.scratchpad, b->memory.scratchpad, sizeof a->memory.scratchpad))
        return differ(what, "scratchpad");
    if (memcmp(a->frame.scratch, b->frame.scratch, sizeof a->frame.scratch) ||
        a->frame.busy != b->frame.busy || a->frame.faulted != b->frame.faulted)
        return differ(what, "callback frame");
    if (memcmp(a->guard_before, b->guard_before, 16) || memcmp(a->guard_after, b->guard_after, 16))
        return differ(what, "frame guards");
    if (s->mode != t->mode || s->control != t->control || s->baud != t->baud ||
        s->selected_port != t->selected_port || s->status != t->status ||
        s->rx_data != t->rx_data || s->rx_count != t->rx_count || s->rx_head != t->rx_head ||
        memcmp(s->rx_fifo, t->rx_fifo, sizeof s->rx_fifo) ||
        s->protocol_ignore != t->protocol_ignore || s->transmitted_bytes != t->transmitted_bytes ||
        s->cycle != t->cycle || s->ack_pending != t->ack_pending || s->ack_due != t->ack_due ||
        s->sampled_buttons != t->sampled_buttons || s->pad_state != t->pad_state ||
        s->pad_cursor != t->pad_cursor || s->faulted != t->faulted ||
        s->selected_device != t->selected_device || s->analog_mode != t->analog_mode)
        return differ(what, "SIO state");
    if (x->timer.count != y->timer.count || x->timer.mode != y->timer.mode ||
        x->timer.target != y->timer.target || x->timer.last_cycles != y->timer.last_cycles)
        return differ(what, "Timer2 state");
    if (x->epoch != y->epoch) return differ(what, "cycles");
    if (x->steps != y->steps) return differ(what, "clock charges");
    if (x->irq_status != y->irq_status || x->irq_count != y->irq_count ||
        x->late_due != y->late_due || x->ackline_until != y->ackline_until)
        return differ(what, "I_STAT / ACK");
    if (x->pad_samples != y->pad_samples) return differ(what, "button samples");
    if (x->tx_n != y->tx_n || x->rx_n != y->rx_n || memcmp(x->tx, y->tx, n) ||
        memcmp(x->rx, y->rx, m) || memcmp(x->tx_cycle, y->tx_cycle, n * sizeof x->tx_cycle[0]) ||
        memcmp(x->tx_due, y->tx_due, n * sizeof x->tx_due[0]))
        return differ(what, "tx/rx log");
    if (x->reads16 != y->reads16 || x->writes16 != y->writes16 ||
        x->reads32 != y->reads32 || x->writes32 != y->writes32)
        return differ(what, "device access counts");
    return 1;
}

/* ---- frame-level runs ------------------------------------------------------ */

typedef struct Outcome { int ok; int32_t result; MusashiResetGraphPrefixStop stop; } Outcome;

static Outcome invoke(Universe *u, int native) {
    Outcome o;
    o.result = 0x2468ace0;
    o.stop.call_address = o.stop.target_address = 0x13579bdfu;
    musashi_input_pad_leaves_set(native ? &bfm_psyq_pad_leaf_api : NULL);
    o.ok = musashi_boot_execute_input_bios_callback(&u->memory, &u->fx.device, &u->frame,
                                                    0x8005d734u, 1, &o.result, &o.stop);
    musashi_input_pad_leaves_set(NULL);
    return o;
}

/* One handler call in both universes; 1 if both completed. */
static int both_handler(const char *what) {
    Outcome a = invoke(&g_a, 0), b = invoke(&g_b, 1);
    ++g_cases;
    if (a.ok != b.ok || a.result != b.result || a.stop.call_address != b.stop.call_address ||
        a.stop.target_address != b.stop.target_address) {
        if (g_differences < 12)
            fprintf(stderr, "  A ok=%d r=%d stop=%08x/%08x  B ok=%d r=%d stop=%08x/%08x\n",
                    a.ok, a.result, a.stop.call_address, a.stop.target_address,
                    b.ok, b.result, b.stop.call_address, b.stop.target_address);
        differ(what, "handler outcome");
        return 0;
    }
    if (!same_universe(&g_a, &g_b, what)) return 0;
    return a.ok;
}

static void both_cold(void) {
    universe_cold(&g_a);
    universe_copy(&g_b, &g_a);
}

/* Apply the same mutation to both universes. */
/* `stmt` is evaluated once per universe: draw any random value BEFORE the
 * macro (probe history: rnd() inside BOTH gave the universes different
 * inputs, which showed up as false RAM/Timer2 differences). */
#define BOTH(stmt) do { Universe *u_ = &g_a; stmt; u_ = &g_b; stmt; } while (0)
static void put8(Universe *u, uint32_t a, uint8_t v) { u->memory.bytes[a & 0x1fffffu] = v; }
static void put32(Universe *u, uint32_t a, uint32_t v) { assert(musashi_boot_write32(&u->memory, a, v)); }

/* PadSetAct-like record contents: a motor buffer, its length and the slot
 * flags the TX byte routine consults. */
static void random_actuators(void) {
    uint32_t act = 0x80100000u + (rnd() % 64u) * 16u, cfg = 0x80101000u + (rnd() % 64u) * 16u;
    uint8_t bytes[16];
    unsigned i, len = rnd() % 8u;
    uint8_t cmd = (uint8_t)(rnd() % 4u == 0 ? 0x4du : 0);
    for (i = 0; i < 16; ++i) bytes[i] = (uint8_t)rnd();
    BOTH(for (i = 0; i < 16; ++i) { put8(u_, act + i, bytes[i]); put8(u_, cfg + i, bytes[15 - i]); });
    BOTH(put32(u_, RECORD + 0x28u, act));
    BOTH(put32(u_, RECORD + 0x2cu, cfg));
    BOTH(put8(u_, RECORD + 0x34u, (uint8_t)len));
    { uint8_t v = (uint8_t)(rnd() % 8u); BOTH(put8(u_, RECORD + 0x35u, v)); }
    BOTH(for (i = 0; i < 6; ++i) put8(u_, RECORD + 0x57u + i, (uint8_t)(bytes[i] & 1u)));
    if (rnd() % 3u == 0) BOTH(put8(u_, RECORD + 0x36u, cmd));
}

static unsigned g_vblanks_done;
static void scenario(const char *what, unsigned vblanks, unsigned flags, uint32_t seed) {
    unsigned v;
    g_vblanks_done = 0;
    both_cold();
    g_rng = seed;
    BOTH(u_->fx.seed = seed);
    if (flags & 1u) BOTH((u_->fx.drop_ack_pct = 10, u_->fx.late_ack_max = 4500));
    if (flags & 2u) BOTH(u_->fx.ackline_max = 900);
    if (flags & 4u) BOTH(u_->fx.t2_mode_200 = 1);
    if (flags & 8u) BOTH(u_->fx.rx_mutate_pct = 12);
    if (flags & 16u) { uint16_t v = (uint16_t)(0x4000u + rnd() % 0xb000u); BOTH(u_->fx.timer.target = v); }
    {
        uint64_t phase = rnd() % 0x20000u;   /* Timer2 phase, exercises the wrap */
        BOTH((u_->fx.epoch = phase, musashi_timer2_advance(&u_->fx.timer, phase),
              musashi_sio_controller_advance(&u_->fx.sio, phase)));
    }
    for (v = 0; v < vblanks; ++v) {
        uint16_t buttons = (uint16_t)rnd();
        uint8_t ax[4];
        unsigned i;
        for (i = 0; i < 4; ++i) ax[i] = (uint8_t)rnd();
        BOTH(u_->fx.buttons = buttons);
        BOTH(musashi_sio_controller_set_analog_axes(&u_->fx.sio, ax[0], ax[1], ax[2], ax[3]));
        if ((flags & 32u) && rnd() % 4u == 0) random_actuators();
        if ((flags & 64u) && rnd() % 16u == 0) {
            uint32_t bad = rnd() & 1u ? 0x1f801041u : 0x1f801080u;
            BOTH(put32(u_, 0x800729c0u, bad));
            both_handler(what);
            BOTH(put32(u_, 0x800729c0u, 0x1f801040u));
            continue;
        }
        if (!both_handler(what)) break;
        ++g_vblanks_done;
        /* VBlank gap: the main CPU advances the clock between handlers. */
        {
            uint64_t gap = 500000u + rnd() % 70000u;
            BOTH((u_->fx.epoch += gap, musashi_timer2_advance(&u_->fx.timer, u_->fx.epoch),
                  musashi_sio_controller_advance(&u_->fx.sio, u_->fx.epoch)));
        }
    }
    fprintf(stderr, "PAD_LEAF_SCENARIO %s: vblanks=%u/%u tx_bytes=%u samples=%u irq=%u differences=%u\n",
            what, g_vblanks_done, vblanks, g_a.fx.tx_n, g_a.fx.pad_samples, g_a.fx.irq_count,
            g_differences);
}

/* Every budget 1..N and every clock refusal point 1..N of one handler call
 * from the same warm state: both universes must stop at the same PC with the
 * same partial effects. */
static void sweep(const char *what, unsigned warm, unsigned flags, uint32_t seed, unsigned stride) {
    unsigned steps, k;
    scenario(what, warm, flags, seed);
    universe_copy(&g_snap_a, &g_a);
    universe_copy(&g_snap_b, &g_b);
    steps = g_a.fx.steps;
    (void)invoke(&g_a, 0);
    steps = g_a.fx.steps - steps;
    for (k = 1; k <= steps + 2u; k += stride) {
        universe_copy(&g_a, &g_snap_a);
        universe_copy(&g_b, &g_snap_b);
        g_input_callback_budget = k;
        both_handler(what);
        g_input_callback_budget = 16384;
        universe_copy(&g_a, &g_snap_a);
        universe_copy(&g_b, &g_snap_b);
        BOTH(u_->fx.fail_step = u_->fx.steps + k);
        both_handler(what);
    }
    fprintf(stderr, "PAD_LEAF_SWEEP %s instructions=%u points=%u\n", what, steps, (steps + 2u) / stride + 1u);
}

/* ---- leaf-level cases (whole register file) -------------------------------- */

static const uint32_t kLeaves[7] = {
    0x8005fba8u, 0x8005fbc8u, 0x8005e0acu, 0x8005e13cu, 0x8005dca0u, 0x8005de78u, 0x8005f394u
};

typedef struct LeafRun {
    int kind;                       /* 1 done, -1 fault */
    FormatterCpu cpu;
    unsigned remaining;
    MusashiResetGraphPrefixStop stop;
} LeafRun;

static LeafRun leaf_interpreted(Universe *u, uint32_t target, const uint32_t regs[32], unsigned budget) {
    LeafRun out;
    memset(&out, 0, sizeof out);
    out.cpu.input_device = &u->fx.device;
    out.cpu.bios_frame = &u->frame;
    out.cpu.clock = &u->fx.clock;
    memcpy(out.cpu.r, regs, sizeof out.cpu.r);
    out.cpu.r[31] = UINT_MAX;
    out.cpu.pc = target;
    out.cpu.npc = target + 4u;
    out.remaining = budget;
    for (;;) {
        if (out.cpu.pc == UINT_MAX) { out.kind = 1; break; }
        if (!input_callback_step(&u->memory, &out.cpu, &out.remaining, &out.stop)) {
            out.kind = -1;
            break;
        }
    }
    return out;
}

static LeafRun leaf_native(Universe *u, uint32_t target, const uint32_t regs[32], unsigned budget,
                           int *refused) {
    LeafRun out;
    int r;
    memset(&out, 0, sizeof out);
    out.cpu.input_device = &u->fx.device;
    out.cpu.bios_frame = &u->frame;
    out.cpu.clock = &u->fx.clock;
    memcpy(out.cpu.r, regs, sizeof out.cpu.r);
    out.cpu.r[31] = UINT_MAX;
    out.cpu.pc = target;
    out.cpu.npc = target + 4u;
    out.remaining = budget;
    musashi_input_pad_leaves_set(&bfm_psyq_pad_leaf_api);
    r = input_pad_leaf(&u->memory, &out.cpu, target, UINT_MAX - 8u, regs[29], 0,
                       &out.remaining, &out.stop);
    musashi_input_pad_leaves_set(NULL);
    *refused = r == 0;
    out.kind = r > 0 ? 1 : -1;
    return out;
}

static int same_leaf(const LeafRun *a, const LeafRun *b, const char *what) {
    if (a->kind != b->kind) return differ(what, "completion");
    /* Registers are compared only for a completed leaf. On any fault the
     * frame's CPU is a local (`FormatterCpu cpu = {0};` in
     * musashi_boot_execute_input_bios_callback, pc_port/mips_formatter.c)
     * that the fault path abandons (`frame->faulted = 1; return 0;`), and the
     * sticky frame->faulted refuses every later call, so no register value at
     * a fault is ever observable. Faults compare completion, remaining
     * budget, stop PC and all guest/device state. (Probe history: an early
     * version compared registers after faults too and flagged the native
     * leaves' block-granular register writes, e.g. v0 after a budget stop
     * between FBA8's LUI and ORI; those are unobservable for this reason.) */
    if (a->kind > 0 && (memcmp(a->cpu.r, b->cpu.r, sizeof a->cpu.r) || a->cpu.hi != b->cpu.hi ||
        a->cpu.lo != b->cpu.lo)) {
        unsigned i;
        for (i = 0; i < 32; ++i)
            if (a->cpu.r[i] != b->cpu.r[i] && g_differences < 12)
                fprintf(stderr, "  r%u retail=%08x native=%08x\n", i, a->cpu.r[i], b->cpu.r[i]);
        return differ(what, "registers");
    }
    if (a->remaining != b->remaining) return differ(what, "budget");
    if (a->kind < 0 && (a->stop.call_address != b->stop.call_address ||
                        a->stop.target_address != b->stop.target_address))
        return differ(what, "fault PC");
    return 1;
}

/* A random device/record state for one leaf call, applied to both. */
static void random_leaf_state(uint32_t regs[32], uint32_t target) {
    unsigned i;
    uint32_t rec = rnd() % 4u ? RECORD : 0x80110000u + (rnd() % 256u) * 0x100u;
    uint32_t rxbuf = 0x80120000u + (rnd() % 64u) * 0x40u;
    uint32_t sp_phys = 0x85d8u - 8u * (rnd() % 12u);
    static const uint32_t seg[3] = {0u, 0x80000000u, 0xa0000000u};
    uint8_t bytes[0x100];
    for (i = 0; i < sizeof bytes; ++i) bytes[i] = (uint8_t)rnd();
    for (i = 0; i < 32; ++i) regs[i] = rnd();
    regs[0] = 0;
    regs[29] = seg[rnd() % 3u] | sp_phys;
    regs[4] = rec;
    regs[5] = rnd() % 3u == 0 ? (uint32_t)-2 : rnd() % 2u ? rnd() & 0xffu : rnd();
    BOTH(for (i = 0; i < 0xf0u; ++i) put8(u_, rec + i, bytes[i]));
    BOTH(for (i = 0; i < 0x40u; ++i) put8(u_, rxbuf + i, bytes[(i * 7u) & 0xffu]));
    BOTH(put32(u_, rec + 0x3cu, rxbuf));
    BOTH(put32(u_, rec + 0x40u, rxbuf + 0x20u));
    BOTH(put32(u_, rec + 0x28u, rxbuf + 8u));
    BOTH(put32(u_, rec + 0x2cu, rxbuf + 16u));
    if (rnd() % 2u) { uint8_t v = (uint8_t)(rnd() % 2u ? 0 : 0x4d); BOTH(put8(u_, rec + 0x36u, v)); }
    if (rnd() % 2u) { uint8_t v = (uint8_t)(rnd() % 12u); BOTH(put8(u_, rec + 0x44u, v)); }
    if (rnd() % 3u == 0) BOTH(put8(u_, rec + 0x44u, 0xffu));
    if (rnd() % 3u == 0) { uint8_t v = (uint8_t)(0x80u | (rnd() & 15u)); BOTH(put8(u_, rxbuf, v)); }
    if (rnd() % 3u == 0) BOTH(put8(u_, rec + 0xe8u, 8));
    { uint32_t v = rnd() % 6u; BOTH(put32(u_, 0x800729a0u, v)); }
    {
        static const uint32_t waits[5] = {0x3cu, 0x50u, 0x91u, 0x190u, 0x1aeu};
        uint32_t w = rnd() % 4u ? waits[rnd() % 5u] : rnd() % 0x400u;
        uint32_t st = rnd() & 0xffffu;
        BOTH(put32(u_, 0x800c5320u, w));
        BOTH(put32(u_, 0x80078f24u, st));
    }
    /* SIO model: select a port, then 0..3 protocol bytes, then some time. */
    {
        static const uint16_t ctrls[4] = {0x1003u, 0x3003u, 0x1003u, 0x0002u};
        uint16_t ctrl = ctrls[rnd() % 4u];
        unsigned bytes_n = rnd() % 4u, k;
        static const uint8_t proto[3] = {0x01u, 0x42u, 0x00u};
        uint64_t later = rnd() % 4000u;
        BOTH((musashi_sio_controller_write16(&u_->fx.sio, 0x1f801048u, 0x0d),
              musashi_sio_controller_write16(&u_->fx.sio, 0x1f80104eu, 0x88),
              musashi_sio_controller_write16(&u_->fx.sio, 0x1f80104au, ctrl)));
        for (k = 0; k < bytes_n; ++k) BOTH(musashi_sio_controller_write8(&u_->fx.sio, 0x1f801040u, proto[k]));
        if (rnd() % 2u) BOTH(musashi_sio_controller_read8(&u_->fx.sio, 0x1f801040u, &bytes[0]));
        BOTH((u_->fx.epoch += later, musashi_timer2_advance(&u_->fx.timer, u_->fx.epoch),
              musashi_sio_controller_advance(&u_->fx.sio, u_->fx.epoch)));
        if (rnd() % 4u == 0) BOTH(u_->fx.irq_status |= 0x80u);
    }
    (void)target;
}

static void leaf_cases(unsigned per_leaf, unsigned flags, uint32_t seed) {
    unsigned l, c;
    g_rng = seed;
    for (l = 0; l < 7; ++l) {
        for (c = 0; c < per_leaf; ++c) {
            uint32_t regs[32];
            char what[64];
            unsigned budget = 16384, steps_before;
            int refused = 0;
            LeafRun a, b;
            both_cold();
            BOTH(u_->fx.seed = seed + c);
            if (flags & 1u) BOTH((u_->fx.drop_ack_pct = 15, u_->fx.late_ack_max = 4500));
            if (flags & 2u) BOTH(u_->fx.ackline_max = 900);
            if (rnd() % 3u == 0) BOTH(u_->fx.t2_mode_200 = 1);
            if (rnd() % 3u == 0) { uint16_t v = (uint16_t)rnd(); BOTH(u_->fx.timer.target = v); }
            if (flags & 4u) BOTH(u_->fx.rx_mutate_pct = 20);
            {
                uint64_t phase = rnd() % 0x30000u;
                BOTH((u_->fx.epoch = phase, musashi_timer2_advance(&u_->fx.timer, phase),
                      musashi_sio_controller_advance(&u_->fx.sio, phase)));
            }
            random_leaf_state(regs, kLeaves[l]);
            snprintf(what, sizeof what, "leaf %08x case %u", kLeaves[l], c);
            universe_copy(&g_snap_a, &g_a);
            universe_copy(&g_snap_b, &g_b);
            steps_before = g_a.fx.steps;
            a = leaf_interpreted(&g_a, kLeaves[l], regs, budget);
            b = leaf_native(&g_b, kLeaves[l], regs, budget, &refused);
            ++g_cases;
            if (refused) { ++g_native_refused; differ(what, "native refused"); continue; }
            ++g_native_done;
            if (!same_leaf(&a, &b, what) || !same_universe(&g_a, &g_b, what)) continue;
            /* Budget and clock-refusal sweep over this exact call. */
            if (c % 32u == 0) {
                unsigned n = 16384u - a.remaining, k, stride = n > 200u ? n / 200u : 1u;
                for (k = 0; k <= n + 1u; k += stride) {
                    universe_copy(&g_a, &g_snap_a);
                    universe_copy(&g_b, &g_snap_b);
                    a = leaf_interpreted(&g_a, kLeaves[l], regs, k);
                    b = leaf_native(&g_b, kLeaves[l], regs, k, &refused);
                    ++g_cases;
                    if (!same_leaf(&a, &b, what) || !same_universe(&g_a, &g_b, what)) break;
                    universe_copy(&g_a, &g_snap_a);
                    universe_copy(&g_b, &g_snap_b);
                    BOTH(u_->fx.fail_step = steps_before + k + 1u);
                    a = leaf_interpreted(&g_a, kLeaves[l], regs, budget);
                    b = leaf_native(&g_b, kLeaves[l], regs, budget, &refused);
                    ++g_cases;
                    if (!same_leaf(&a, &b, what) || !same_universe(&g_a, &g_b, what)) break;
                }
            }
        }
    }
}

/* ---- refusals: zero side effects ------------------------------------------- */

static const BfmPadLeafCode *wrong_code(uint32_t target, const BfmPadLeafCode **nested,
                                        unsigned *count) {
    static BfmPadLeafCode bad;
    const BfmPadLeafCode *real = bfm_psyq_pad_leaf_code(target, nested, count);
    if (!real) return NULL;
    bad = *real;
    bad.digest ^= 1u;
    return &bad;
}
static const BfmPadLeafApi kWrongDigest = {wrong_code, bfm_psyq_pad_leaf_depth, bfm_psyq_pad_leaf};

static void refusal_cases(void) {
    unsigned l, kind;
    for (l = 0; l < 7; ++l)
        for (kind = 0; kind < 6; ++kind) {
            uint32_t regs[32];
            FormatterCpu cpu;
            unsigned remaining = 16384, steps;
            MusashiResetGraphPrefixStop stop = {0x11u, 0x22u};
            int r;
            uint32_t depth = 0;
            const BfmPadLeafApi *api = &bfm_psyq_pad_leaf_api;
            both_cold();
            g_rng = 77u + l * 8u + kind;
            random_leaf_state(regs, kLeaves[l]);
            universe_copy(&g_snap_a, &g_a);
            memset(&cpu, 0, sizeof cpu);
            cpu.input_device = &g_a.fx.device;
            cpu.bios_frame = &g_a.frame;
            cpu.clock = &g_a.fx.clock;
            memcpy(cpu.r, regs, sizeof cpu.r);
            cpu.pc = kLeaves[l];
            cpu.npc = cpu.pc + 4u;
            switch (kind) {
            case 0: api = &kWrongDigest; break;                       /* code words differ */
            case 1: cpu.merge_pending = 1; break;                      /* LWL/LWR in flight */
            case 2: cpu.npc = cpu.pc + 8u; break;                      /* not a clean entry */
            case 3: depth = 7; break;                                  /* frame call depth */
            case 4: put32(&g_a, 0x800729c0u, 0x1f801041u); universe_copy(&g_snap_a, &g_a); break;
            case 5: put32(&g_a, 0x800729bcu, 0x1f801074u); universe_copy(&g_snap_a, &g_a); break;
            }
            steps = g_a.fx.steps;
            musashi_input_pad_leaves_set(api);
            r = input_pad_leaf(&g_a.memory, &cpu, kLeaves[l], UINT_MAX - 8u, regs[29], depth,
                               &remaining, &stop);
            musashi_input_pad_leaves_set(NULL);
            ++g_cases;
            {
                int expect_refusal = kind < 3 || (kind == 3 && bfm_psyq_pad_leaf_depth(kLeaves[l])) ||
                    (kind >= 4 && (l == 2 || l == 3 || l == 4 || l == 5));
                if (!expect_refusal) continue;      /* this leaf has no such dependency */
                if (r != 0) { differ("refusal", "leaf ran"); continue; }
                if (remaining != 16384u || g_a.fx.steps != steps || stop.call_address != 0x11u ||
                    memcmp(cpu.r, regs, sizeof regs) || cpu.pc != kLeaves[l])
                    differ("refusal", "side effect on CPU/budget/clock");
                if (!same_universe(&g_a, &g_snap_a, "refusal")) {}
            }
        }
}

/* Function-trace honesty: an entry is native only if the leaf ran. */
static void trace_cases(const char *path) {
    unsigned i;
    uint32_t index_dca0 = (0x8005dca0u & 0x1fffffffu) / 4u, index_fbc8 = (0x8005fbc8u & 0x1fffffffu) / 4u;
    setenv("MUSASHI_TRACE_FUNCS", path, 1);
    g_trace_state = 0;
    if (!trace_enabled() || !g_trace_native) { differ("trace", "tracer unavailable"); return; }
    both_cold();
    for (i = 0; i < 8; ++i) (void)invoke(&g_b, 1);
    if (!g_trace_native[index_dca0] || g_trace_native[index_dca0] != g_trace_counts[index_dca0] ||
        g_trace_native[index_fbc8] != g_trace_counts[index_fbc8] || !g_trace_counts[index_fbc8])
        differ("trace", "native leaves not all counted native");
    {   /* A refused leaf keeps its (already counted) entry interpreted. */
        uint32_t regs[32];
        FormatterCpu cpu;
        unsigned remaining = 16384;
        MusashiResetGraphPrefixStop stop = {0, 0};
        uint32_t before_n = g_trace_native[index_dca0], before_c = g_trace_counts[index_dca0];
        int r;
        both_cold();
        g_rng = 4242u;
        random_leaf_state(regs, 0x8005dca0u);
        put32(&g_b, 0x800729c0u, 0x1f801041u);
        memset(&cpu, 0, sizeof cpu);
        cpu.input_device = &g_b.fx.device;
        cpu.bios_frame = &g_b.frame;
        cpu.clock = &g_b.fx.clock;
        memcpy(cpu.r, regs, sizeof cpu.r);
        cpu.pc = 0x8005dca0u;
        cpu.npc = cpu.pc + 4u;
        musashi_trace_function_entry(0x8005dca0u, 0x8005eb10u, 'j');   /* the jal */
        musashi_input_pad_leaves_set(&bfm_psyq_pad_leaf_api);
        r = input_pad_leaf(&g_b.memory, &cpu, 0x8005dca0u, UINT_MAX - 8u, regs[29], 0,
                           &remaining, &stop);
        musashi_input_pad_leaves_set(NULL);
        if (r != 0 || g_trace_native[index_dca0] != before_n ||
            g_trace_counts[index_dca0] != before_c + 1u)
            differ("trace", "refused leaf counted native");
    }
    fprintf(stderr, "PAD_LEAF_TRACE dca0 native=%u total=%u fbc8 native=%u total=%u\n",
            g_trace_native[index_dca0], g_trace_counts[index_dca0],
            g_trace_native[index_fbc8], g_trace_counts[index_fbc8]);
}

int main(int argc, char **argv) {
    FILE *file;
    long length;
    if (argc < 2) { fprintf(stderr, "usage: %s SLUS_007.26 [--break N]\n", argv[0]); return 2; }
    if (!(file = fopen(argv[1], "rb"))) { fprintf(stderr, "no executable\n"); return 77; }
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);
    g_exe = malloc((size_t)length);
    assert(g_exe && fread(g_exe, 1, (size_t)length, file) == (size_t)length);
    fclose(file);
    g_exe_size = (size_t)length;
    if (argc >= 4 && !strcmp(argv[2], "--break")) g_break = atoi(argv[3]);
    bfm_psyq_pad_test_break = g_break;

    /* Frame level: cold TAP negotiation and long runs. */
    scenario("cold TAP, steady buttons", 96, 0u, 1u);
    scenario("random buttons and sticks", 1000, 0u, 2u);
    scenario("PadSetAct motor/config buffers", 400, 32u, 3u);
    scenario("lost/late ACK beyond the timeouts", 400, 1u, 4u);
    scenario("/ACK held low (E0AC loop)", 300, 2u, 5u);
    scenario("Timer2 mode bit 0x200, nonzero target", 300, 4u | 16u, 6u);
    scenario("reply bytes mutated (multitap/config ids)", 600, 8u, 7u);
    scenario("everything", 800, 1u | 2u | 4u | 8u | 16u | 32u, 8u);
    scenario("SIO pointer slot corrupted for single VBlanks", 400, 64u | 32u, 9u);
    {   /* host stop: clock accepts without advancing; budget exhaustion */
        both_cold();
        BOTH(u_->fx.freeze = 1);
        both_handler("host stop (frozen clock)");
    }
    sweep("budget/clock sweep, cold", 0, 0u, 10u, 1);
    sweep("budget/clock sweep, steady state", 12, 0u, 11u, 1);
    sweep("budget/clock sweep, perturbed", 40, 1u | 2u | 8u | 32u, 12u, 3);
    leaf_cases(400, 0u, 100u);
    leaf_cases(200, 1u | 2u | 4u, 200u);
    refusal_cases();
    {
        char path[4096];
        const char *tmp = getenv("TMPDIR");
        snprintf(path, sizeof path, "%s/input_pad_leaf_trace", tmp && tmp[0] ? tmp : "/tmp");
        trace_cases(path);
    }
    fprintf(stderr, "PAD_LEAF_DIFFERENTIAL cases=%u native_leaf_calls=%u refused=%u different=%u break=%d\n",
            g_cases, g_native_done, g_native_refused, g_differences, g_break);
    if (g_break) return g_differences ? 0 : 1;
    return g_differences ? 1 : 0;
}
