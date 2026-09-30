#ifndef MUSASHI_DEVICE_EPOCH_H
#define MUSASHI_DEVICE_EPOCH_H

#include "musashi_irq_scheduler.h"

#define MUSASHI_DEVICE_CLOCK_HZ 33868800u

/* All callbacks execute on the installing owner. collect_source atomically
 * samples a monotonic host clock and transfers actual source metadata only.
 * Neither wait nor any device operation may dispatch guest code. */
typedef struct MusashiDeviceEpochAdapter {
    void *userdata;
    uint64_t (*owner_thread)(void *);
    int (*collect_source)(void *, MusashiIrqSourceBatch *);
    int (*wait_until_counter)(void *, uint64_t target_tick);
    int (*advance_devices)(void *, uint64_t device_cycle);
    int (*vblank_edge)(void *, uint64_t sequence, uint64_t device_cycle);
    /* Optional, for the lazy fast path below. Called right after a commit
     * with the committed device cycle: return 1 when the devices and the
     * source are quiescent there (another commit to any cycle below *due
     * would only move device clocks), with *due the earliest cycle at which
     * any device deadline or source edge falls. Return 0 when not quiescent.
     * It must not change any state. */
    int (*next_deadline)(void *, uint64_t device_cycle, uint64_t *due);
} MusashiDeviceEpochAdapter;

/* Fresh native elapsed-time profile, never a captured BIOS/device phase.
 * Source instruction costs reserve time; host work and waits also elapse.
 * The independent source-cost ledger is owned by the caller. */
typedef struct MusashiDeviceEpoch {
    MusashiDeviceEpochAdapter adapter;
    MusashiIrqSourceBatch pending;
    uint32_t pending_next;
    uint64_t owner;
    uint64_t frequency;
    uint64_t origin_tick;
    uint64_t last_cut_tick;
    uint64_t cycle;
    uint64_t last_sequence;
    uint64_t last_edge_tick;
    uint64_t cuts;
    uint64_t waits;
    int active;
    int busy;
    int faulted;
    /* Which check faulted the epoch (static string), for diagnostics. */
    const char *fault_reason;
    /* Lazy fast path (musashi_device_epoch_lazy_*): charged cycles not yet
     * committed, the deadline cached by the last refresh and the commit
     * count it was taken at. Any commit or invalidation drops the cache. */
    uint64_t lazy_deferred;
    uint64_t lazy_due;
    uint64_t lazy_cuts;
    /* Device cycle of the last deferral: eager time at that checkpoint. */
    uint64_t lazy_last_target;
    int lazy_valid;
    uint64_t lazy_deferrals, lazy_commits;
    /* Refreshes the adapter reported not quiescent (or already due). */
    uint64_t lazy_unsettled;
} MusashiDeviceEpoch;

/* Fresh-storage constructor only: never reinitialize an active/faulted epoch
 * to resume or reanchor it. A rejected nonempty initial collection may already
 * have transferred source metadata; failure is not a retry boundary.
 * init requires a source-empty cut, before source installation. Host clock
 * frequencies 1..UINT32_MAX are supported by overflow-safe C99 conversion. */
int musashi_device_epoch_init(MusashiDeviceEpoch *, const MusashiDeviceEpochAdapter *);
int musashi_device_epoch_advance_cost(void *, uint32_t cost);
int musashi_device_epoch_sync(MusashiDeviceEpoch *);
int musashi_device_epoch_shutdown(MusashiDeviceEpoch *);

/* Lazy fast path. An eager caller commits every charge (advance_cost, then
 * sync). A lazy caller hands the charge to lazy_defer instead: while the
 * adapter's next_deadline snapshot stays valid and cycle + deferred stays
 * below it, nothing is committed and 1 is returned. Otherwise 0 is
 * returned (the charge is still deferred) and the caller must lazy_commit,
 * which runs exactly the eager sequence (advance_cost(deferred), then sync)
 * with the accumulated cycles, then refreshes the snapshot. advance_cost and
 * sync refuse (fault) while cycles are deferred.
 *
 * Exactness rests on the adapter: next_deadline may only report quiescent
 * when committing to any cycle below *due changes device clocks and nothing
 * else. Any device access outside a commit must first lazy_commit (so it
 * observes eager time) and then lazy_invalidate (so the next charge commits
 * and re-reads the deadlines it may have changed). */
int musashi_device_epoch_lazy_defer(MusashiDeviceEpoch *, uint32_t cost);
/* Commit `cycles` of the deferred cycles (all of them: lazy_commit), with
 * the eager sequence. A remainder stays deferred and the cache is dropped. */
int musashi_device_epoch_lazy_commit_part(MusashiDeviceEpoch *, uint64_t cycles);
int musashi_device_epoch_lazy_commit(MusashiDeviceEpoch *);
void musashi_device_epoch_lazy_invalidate(MusashiDeviceEpoch *);
/* Deadline check: 1 when the cached snapshot is valid and the adapter,
 * asked again now, reports the same deadline (nothing changed it without
 * an invalidation). */
int musashi_device_epoch_lazy_verify(MusashiDeviceEpoch *, uint64_t *fresh_due);

#endif
