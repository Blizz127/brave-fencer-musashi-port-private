#include "musashi_device_epoch.h"
#include <assert.h>
#include <string.h>

typedef struct Fixture {
    uint64_t owner, now, frequency;
    MusashiIrqSourceBatch next;
    unsigned collects, advances, edges, wait_calls;
    unsigned fail_advance, fail_edge;
    int wait_fails, wait_stalls;
    uint64_t device_cycle;
    unsigned parity, irq;
    char order[32];
    unsigned order_size;
} Fixture;

static uint64_t owner(void *p) { return ((Fixture *)p)->owner; }
static int collect(void *p, MusashiIrqSourceBatch *out) {
    Fixture *f = p;
    ++f->collects;
    *out = f->next;
    out->cut_tick = f->now;
    out->frequency = f->frequency;
    f->next.count = 0;
    return 1;
}
static int wait_until(void *p, uint64_t tick) {
    Fixture *f = p;
    ++f->wait_calls;
    if (f->wait_fails) return 0;
    if (!f->wait_stalls) f->now = tick;
    return 1;
}
static int device_advance(void *p, uint64_t cycle) {
    Fixture *f = p;
    ++f->advances;
    if (f->fail_advance == f->advances) return 0;
    assert(cycle >= f->device_cycle);
    f->device_cycle = cycle;
    f->order[f->order_size++] = 'A';
    return 1;
}
static int edge(void *p, uint64_t sequence, uint64_t cycle) {
    Fixture *f = p;
    ++f->edges;
    if (f->fail_edge == f->edges) return 0;
    assert(sequence == f->edges && cycle == f->device_cycle);
    f->parity ^= 1;
    f->irq |= 1;
    f->order[f->order_size++] = 'V';
    return 1;
}
static void fresh(Fixture *f, MusashiDeviceEpoch *epoch) {
    MusashiDeviceEpochAdapter adapter = {f,owner,collect,wait_until,device_advance,edge};
    memset(f, 0, sizeof(*f));
    f->owner = 7;
    f->frequency = MUSASHI_DEVICE_CLOCK_HZ;
    f->now = 100;
    assert(musashi_device_epoch_init(epoch, &adapter));
}

static void test_order_pacing_and_elapsed_wait(void) {
    Fixture f;
    MusashiDeviceEpoch epoch;
    fresh(&f, &epoch);
    f.now = 110;
    f.next.count = 2;
    f.next.edges[0] = (MusashiIrqSourceEdge){1,105};
    f.next.edges[1] = (MusashiIrqSourceEdge){2,105};
    assert(musashi_device_epoch_sync(&epoch));
    assert(epoch.cycle == 10 && epoch.last_sequence == 2);
    assert(f.parity == 0 && f.irq == 1 && f.edges == 2);
    assert(f.order_size == 5 && !memcmp(f.order, "AVAVA", 5));
    assert(musashi_device_epoch_advance_cost(&epoch, 3));
    assert(epoch.cycle == 13 && epoch.waits == 1 && f.wait_calls == 1);
    f.now = 120; /* Measured host work/wait, not invented source instructions. */
    assert(musashi_device_epoch_sync(&epoch) && epoch.cycle == 20);
    assert(musashi_device_epoch_sync(&epoch) && epoch.cycle == 20);
    assert(f.edges == 2 && f.wait_calls == 1);
    assert(musashi_device_epoch_shutdown(&epoch));
    assert(!musashi_device_epoch_sync(&epoch));
}

static void test_partial_failure_keeps_remaining_metadata(void) {
    Fixture f;
    MusashiDeviceEpoch epoch;
    unsigned collects;
    fresh(&f, &epoch);
    f.now = 110;
    f.next.count = 2;
    f.next.edges[0] = (MusashiIrqSourceEdge){1,105};
    f.next.edges[1] = (MusashiIrqSourceEdge){2,108};
    f.fail_advance = 2;
    assert(!musashi_device_epoch_sync(&epoch));
    assert(epoch.faulted && !epoch.busy && epoch.cycle == 5);
    assert(epoch.pending.count == 2 && epoch.pending_next == 1);
    assert(epoch.pending.edges[1].sequence == 2 && f.edges == 1 && f.irq == 1);
    collects = f.collects;
    assert(!musashi_device_epoch_sync(&epoch) && f.collects == collects);
    assert(musashi_device_epoch_shutdown(&epoch));
}

static void test_refused_clocks_and_metadata(void) {
    unsigned choice;
    for (choice = 0; choice < 5; ++choice) {
        Fixture f;
        MusashiDeviceEpoch epoch;
        fresh(&f, &epoch);
        f.now = 110;
        if (choice == 0) f.now = 99;
        if (choice == 1) f.frequency++;
        if (choice >= 2) {
            f.next.count = 1;
            f.next.edges[0] = (MusashiIrqSourceEdge){1,105};
            if (choice == 2) f.next.edges[0].sequence = 2;
            if (choice == 3) f.next.edges[0].tick = 99;
            if (choice == 4) f.next.edges[0].tick = 111;
        }
        assert(!musashi_device_epoch_sync(&epoch));
        assert(epoch.faulted && !f.advances && !f.edges);
    }
}

static void test_owner_stall_and_overflow(void) {
    Fixture f;
    MusashiDeviceEpoch epoch;
    unsigned calls;
    fresh(&f, &epoch);
    calls = f.collects;
    f.owner = 8;
    assert(!musashi_device_epoch_sync(&epoch) && f.collects == calls);
    f.owner = 7;
    epoch.busy = 1;
    assert(!musashi_device_epoch_sync(&epoch) && f.collects == calls);
    epoch.busy = 0;
    f.wait_stalls = 1;
    assert(!musashi_device_epoch_advance_cost(&epoch, 2));
    assert(epoch.faulted && epoch.cycle == 0 && f.wait_calls == 1);
    fresh(&f, &epoch);
    epoch.cycle = UINT64_MAX;
    calls = f.collects;
    assert(!musashi_device_epoch_advance_cost(&epoch, 1));
    assert(epoch.faulted && f.collects == calls);
    fresh(&f, &epoch);
    epoch.frequency = f.frequency = 1;
    f.now = UINT64_MAX;
    assert(!musashi_device_epoch_sync(&epoch) && epoch.faulted && !f.advances);
}

static void test_fractional_conversion_and_initial_refusal(void) {
    Fixture f = {0};
    MusashiDeviceEpoch epoch, before;
    MusashiDeviceEpochAdapter adapter = {&f,owner,collect,wait_until,device_advance,edge};
    f.owner = 7;
    memset(&epoch, 0xa5, sizeof(epoch));
    before = epoch;
    assert(!musashi_device_epoch_init(&epoch, &adapter));
    assert(!memcmp(&before, &epoch, sizeof(epoch)));
    f.frequency = (uint64_t)UINT32_MAX + 1;
    assert(!musashi_device_epoch_init(&epoch, &adapter));
    f.frequency = 1000000000;
    f.now = 500;
    f.next.count = 1;
    f.next.edges[0] = (MusashiIrqSourceEdge){1,500};
    assert(!musashi_device_epoch_init(&epoch, &adapter));
    assert(!memcmp(&before, &epoch, sizeof(epoch)));
    /* A distinct fresh source fixture, not a retry of the consumed batch. */
    memset(&f, 0, sizeof(f));
    f.owner = 7;
    f.frequency = 1000000000;
    f.now = 500;
    assert(musashi_device_epoch_init(&epoch, &adapter));
    assert(musashi_device_epoch_advance_cost(&epoch, 1));
    assert(f.now == 530 && epoch.cycle == 1); /* ceil(1GHz/33.8688MHz). */
    f.now = 1000000500;
    assert(musashi_device_epoch_sync(&epoch) && epoch.cycle == MUSASHI_DEVICE_CLOCK_HZ);
}

/* Lazy fast path against the eager sequence on a guest-clock source: the
 * device model has scheduled events (fire in the first pass at or past
 * their due, like the CD/SIO/DMA owners), a sample boundary every
 * GUEST_SAMPLE cycles (like the SPU) and an additive counter (like the
 * timers). A "program" charges instruction costs and, at some
 * instructions, observes the device and schedules a new event relative to
 * its clock (like an MMIO command write). Eager and lazy must log the same
 * observations, event cycles and VBlank edges. */
enum { GUEST_FRAME = 1000u, GUEST_SAMPLE = 96u, GUEST_EVENTS = 8u, GUEST_LOG = 4096u };

typedef struct GuestFixture {
    uint64_t owner, now, next_vblank, sequence;
    uint64_t clock, counter, samples;
    uint64_t due[GUEST_EVENTS];
    unsigned events;
    uint64_t log[GUEST_LOG];
    unsigned logged;
    unsigned passes, deadline_calls;
    int held;
} GuestFixture;

static void guest_log(GuestFixture *g, uint64_t a, uint64_t b) {
    assert(g->logged + 2u <= GUEST_LOG);
    g->log[g->logged++] = a;
    g->log[g->logged++] = b;
}
static uint64_t guest_owner(void *p) { return ((GuestFixture *)p)->owner; }
static int guest_collect(void *p, MusashiIrqSourceBatch *out) {
    GuestFixture *g = p;
    out->frequency = MUSASHI_DEVICE_CLOCK_HZ;
    out->cut_tick = g->now;
    out->count = 0;
    while (g->next_vblank <= g->now) {
        out->edges[out->count++] = (MusashiIrqSourceEdge){++g->sequence, g->next_vblank};
        g->next_vblank += GUEST_FRAME;
    }
    return 1;
}
static int guest_wait(void *p, uint64_t tick) {
    GuestFixture *g = p;
    if (tick < g->now) return 0;
    g->now = tick;
    return 1;
}
static int guest_advance(void *p, uint64_t cycle) {
    GuestFixture *g = p;
    unsigned i;
    ++g->passes;
    assert(cycle >= g->clock);
    for (i = 0; i < g->events; ++i)
        if (g->due[i] && cycle >= g->due[i]) {
            guest_log(g, 0x1000u + i, cycle); /* observed at the pass cycle */
            g->due[i] = 0;
        }
    while ((g->samples + 1u) * GUEST_SAMPLE <= cycle) {
        ++g->samples;
        guest_log(g, 0x2000u, cycle);
    }
    g->counter += cycle - g->clock;
    g->clock = cycle;
    return 1;
}
static int guest_edge(void *p, uint64_t sequence, uint64_t cycle) {
    guest_log(p, 0x3000u + sequence, cycle);
    return 1;
}
static int guest_deadline(void *p, uint64_t cycle, uint64_t *due) {
    GuestFixture *g = p;
    uint64_t d = g->next_vblank;
    unsigned i;
    ++g->deadline_calls;
    if (g->held || g->clock != cycle) return 0;
    for (i = 0; i < g->events; ++i)
        if (g->due[i] && g->due[i] < d) d = g->due[i];
    if ((g->samples + 1u) * GUEST_SAMPLE < d) d = (g->samples + 1u) * GUEST_SAMPLE;
    *due = d;
    return 1;
}
static void guest_fresh(GuestFixture *g, MusashiDeviceEpoch *epoch) {
    MusashiDeviceEpochAdapter adapter = {g, guest_owner, guest_collect, guest_wait,
                                         guest_advance, guest_edge, guest_deadline};
    memset(g, 0, sizeof(*g));
    g->owner = 7;
    g->next_vblank = GUEST_FRAME;
    g->events = GUEST_EVENTS;
    assert(musashi_device_epoch_init(epoch, &adapter));
}

/* A device access: observe, then schedule an event relative to the clock. */
static void guest_access(GuestFixture *g, unsigned step) {
    guest_log(g, 0x4000u + step, g->clock);
    guest_log(g, 0x5000u, g->counter);
    g->due[step % GUEST_EVENTS] = g->clock + 37u + (step * 13u) % 400u;
}

static void guest_program(GuestFixture *g, MusashiDeviceEpoch *epoch, int lazy,
                          unsigned *commits) {
    unsigned step;
    *commits = 0;
    for (step = 0; step < 3000u; ++step) {
        uint32_t cost = 2u + (step % 3u == 0u);
        if (step == 2999u) cost = 0;
        if (lazy) {
            if (!musashi_device_epoch_lazy_defer(epoch, cost)) {
                assert(musashi_device_epoch_lazy_commit(epoch));
                ++*commits;
            }
        } else {
            if (cost) assert(musashi_device_epoch_advance_cost(epoch, cost));
            assert(musashi_device_epoch_sync(epoch));
            ++*commits;
        }
        if (step % 97u == 5u || step % 211u == 0u) {
            if (lazy) {
                assert(musashi_device_epoch_lazy_commit(epoch));
                musashi_device_epoch_lazy_invalidate(epoch);
            }
            assert(!epoch->lazy_deferred && epoch->cycle == g->clock);
            guest_access(g, step);
        }
    }
    if (lazy) assert(musashi_device_epoch_lazy_commit(epoch));
    assert(!epoch->lazy_deferred);
}

static void test_lazy_matches_eager(void) {
    static GuestFixture eager, lazy;
    MusashiDeviceEpoch e, l;
    unsigned eager_commits, lazy_commits;
    guest_fresh(&eager, &e);
    guest_program(&eager, &e, 0, &eager_commits);
    guest_fresh(&lazy, &l);
    guest_program(&lazy, &l, 1, &lazy_commits);
    assert(e.cycle == l.cycle && e.last_sequence == l.last_sequence && e.last_sequence >= 6u);
    assert(eager.clock == lazy.clock && eager.counter == lazy.counter);
    assert(eager.logged == lazy.logged && eager.logged > 200u);
    assert(!memcmp(eager.log, lazy.log, eager.logged * sizeof(eager.log[0])));
    /* The point of it: most checkpoints committed nothing. */
    assert(l.lazy_deferrals > 2000u && lazy_commits * 4u < eager_commits);
    assert(lazy.passes * 4u < eager.passes);
}

static void test_lazy_refusals_and_verify(void) {
    static GuestFixture g;
    MusashiDeviceEpoch epoch;
    uint64_t fresh_due = 0;
    guest_fresh(&g, &epoch);
    /* No snapshot before the first commit. */
    assert(!musashi_device_epoch_lazy_defer(&epoch, 2) && epoch.lazy_deferred == 2);
    assert(musashi_device_epoch_lazy_commit(&epoch) && epoch.cycle == 2 && epoch.lazy_valid);
    assert(epoch.lazy_due == GUEST_SAMPLE);
    assert(musashi_device_epoch_lazy_defer(&epoch, 50) && epoch.lazy_last_target == 52);
    assert(musashi_device_epoch_lazy_verify(&epoch, &fresh_due) && fresh_due == GUEST_SAMPLE);
    /* A change made without invalidation is visible to verify. */
    g.due[0] = 60;
    assert(!musashi_device_epoch_lazy_verify(&epoch, &fresh_due) && fresh_due == 60);
    g.due[0] = 0;
    /* Reaching the deadline refuses; the charge stays deferred. */
    assert(!musashi_device_epoch_lazy_defer(&epoch, 44) && epoch.lazy_deferred == 94);
    /* A partial commit keeps the remainder deferred and drops the cache. */
    assert(musashi_device_epoch_lazy_commit_part(&epoch, 50) && epoch.cycle == 52);
    assert(epoch.lazy_deferred == 44 && !epoch.lazy_valid);
    assert(!musashi_device_epoch_lazy_defer(&epoch, 0));
    assert(!musashi_device_epoch_lazy_commit_part(&epoch, 45));
    assert(musashi_device_epoch_lazy_commit(&epoch) && epoch.cycle == 96 && g.samples == 1);
    /* Not quiescent: never deferred. */
    g.held = 1;
    assert(musashi_device_epoch_lazy_commit(&epoch) && !epoch.lazy_valid);
    assert(!musashi_device_epoch_lazy_defer(&epoch, 2));
    g.held = 0;
    assert(musashi_device_epoch_lazy_commit(&epoch) && epoch.lazy_valid);
    /* Direct commits refuse while cycles are deferred. */
    assert(musashi_device_epoch_lazy_defer(&epoch, 2));
    assert(!musashi_device_epoch_advance_cost(&epoch, 2) && epoch.faulted);
    assert(epoch.fault_reason && !strcmp(epoch.fault_reason, "lazy-deferred"));
    guest_fresh(&g, &epoch);
    assert(!musashi_device_epoch_lazy_defer(&epoch, 2));
    assert(!musashi_device_epoch_sync(&epoch) && epoch.faulted);
}

int main(void) {
    test_order_pacing_and_elapsed_wait();
    test_partial_failure_keeps_remaining_metadata();
    test_refused_clocks_and_metadata();
    test_owner_stall_and_overflow();
    test_fractional_conversion_and_initial_refusal();
    test_lazy_matches_eager();
    test_lazy_refusals_and_verify();
    return 0;
}
