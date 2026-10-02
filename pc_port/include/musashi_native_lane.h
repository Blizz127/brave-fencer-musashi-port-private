#ifndef MUSASHI_NATIVE_LANE_H
#define MUSASHI_NATIVE_LANE_H

/* Generic native lane: guest-PC keyed host implementations of guest
 * functions, consulted by formatter_step before it fetches a word, so the
 * startup CPU, the IRQ routers and nested source execution all use it.
 *
 * Register ABI (PS1 o32): a0-a3 are r[4..7], further arguments are words at
 * guest sp+0x10, +0x14, ... ; results go to v0/v1 (r[2], r[3]); on success
 * the lane returns to ra with the interpreter's delay-slot state clean.
 *
 * The implementation lives in mips_formatter.c, so every translation unit
 * that already links the formatter gets it without a new source file. */

#include <stddef.h>
#include <stdint.h>

#include "musashi_boot_memory.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Guest main RAM must be host-mapped at this address for natively compiled
 * decomp C, which dereferences 32-bit guest addresses directly. */
#define MUSASHI_NATIVE_LANE_GUEST_BASE 0x80000000u

typedef struct MusashiNativeLaneCall {
    MusashiBootMemory *memory;
    uint32_t *r; /* the live guest register file, r[0..31] */
} MusashiNativeLaneCall;

/* A host implementation. Return 1 when the call completed (v0/v1 written as
 * needed), 0 to refuse; a refusal before any guest-visible side effect makes
 * the lane fall back to the interpreter. */
typedef int (*MusashiNativeLaneFn)(MusashiNativeLaneCall *call);

typedef struct MusashiNativeLaneEntry {
    uint32_t guest_pc;
    uint32_t cost_cycles; /* charged once to the execution clock per call */
    MusashiNativeLaneFn fn;
    const char *name;
    uint8_t argc;    /* o32 argument words the host function consumes */
    uint8_t returns; /* 1 when it produces v0, 0 for void */
    /* D-011: 1 when the body charges its mapped retail cost into the ledger
     * as it runs (cost_cycles is then not charged); 0: fixed cost_cycles. */
    uint8_t ledger;
} MusashiNativeLaneEntry;

/* D-011 cycle ledger. A mapped native body adds the interpreter's cost of
 * the retail instructions it stands for (tools/lane_cycles.py); the runtime
 * flushes it to the execution clock before each guest call from native code
 * and when the lane call returns. musashi_lane_ledger_lost is set when a
 * body left its mapped graph (a mapping error: its charge is then
 * incomplete); musashi_lane_fixed counts fixed (unmapped) charges. */
extern uint64_t musashi_lane_ledger;
extern uint32_t musashi_lane_ledger_lost;
extern uint32_t musashi_lane_fixed;

/* D-011 deadline guard. musashi_lane_budget is the ledger value at which the
 * next device deadline falls due (UINT64_MAX: none known). A mapped body
 * that charges up to it calls musashi_native_lane_tick with its segment
 * table and product state; the tick charges the clock up to the retail
 * instruction where the deadline falls and runs the interpreter's
 * checkpoint there (device commit and IRQ delivery at that retail pc).
 * MUSASHI_LANE_GUARD_STRICT=1 (tests only) checkpoints before every retail
 * instruction instead. */
/* flags: 1 = in a delay slot; 2 = a division idiom's data-dependent
 * instruction, run only when its extra was charged (musashi_lane_seg_extra) */
typedef struct MusashiLaneSegInsn { uint32_t pc; uint8_t cost; uint8_t flags; } MusashiLaneSegInsn;
typedef struct MusashiLaneSegRow { uint32_t first; uint32_t count; } MusashiLaneSegRow;
typedef struct MusashiLaneSegTable {
    const MusashiLaneSegRow *rows;
    uint32_t nrows;
    const MusashiLaneSegInsn *insns;
} MusashiLaneSegTable;
extern uint64_t musashi_lane_budget;
extern uint64_t musashi_lane_seg_extra;
/* The retail pc a mapped body's guest call returns to (set before the call,
 * consumed by musashi_native_guest_call): an IRQ left pending by the callee's
 * return is delivered at that pc before the native body continues, as the
 * interpreter's checkpoint at the caller's next instruction would. */
extern uint32_t musashi_lane_resume_pc;
/* Sum of the retail stack frames of the native bodies running in the
 * current lane call (each adds its own at entry, removes it at return): a
 * guest call from native code runs the callee at the retail stack pointer,
 * entry sp minus this. */
extern uint32_t musashi_lane_sp_adj;
/* The guest sp at the current lane entry. A native body's retail sp is
 * musashi_lane_entry_sp - musashi_lane_sp_adj (after its own adjustment);
 * a local whose address the body passes to a callee lives in guest RAM at
 * its retail offset from that sp (tools/native_lane_gen.py,
 * place_guest_locals), where the retail code keeps it. */
extern uint32_t musashi_lane_entry_sp;
/* One guest-frame local of a generated entry: frame is the body's retail
 * frame size, the local is guest RAM [sp + off, sp + off + size) where sp is
 * its retail sp (entry sp - frame for a body entered from the interpreter).
 * Tables: musashi_native_lane_guest_locals[_count] (generated). */
typedef struct MusashiNativeLaneGuestLocal {
    uint32_t guest_pc;
    uint32_t frame, off, size;
    const char *member; /* overlay member, or NULL for the main EXE */
} MusashiNativeLaneGuestLocal;
void musashi_native_lane_tick(const void *segment_table, uint32_t state);
/* The checkpoint at a zero-cost native entry (a host intrinsic's PC). */
void musashi_native_lane_tick_entry(uint32_t pc);
typedef struct MusashiNativeLaneGuardStats {
    uint64_t ticks;        /* tick calls */
    uint64_t checkpoints;  /* mid-native checkpoints run */
    uint64_t unknown;      /* budget refreshes with no known deadline */
    uint64_t refreshes;
} MusashiNativeLaneGuardStats;
void musashi_native_lane_guard_stats(MusashiNativeLaneGuardStats *out);

/* Overlay functions (MAIN.CD / scene members) share load addresses, so an
 * overlay entry runs natively only when the bytes resident in guest RAM at
 * [guest_pc, guest_pc + size) hash to the member's own digest (FNV-1a 64,
 * computed at build time from the user's extracted member file). Checked on
 * every call, never inferred; on a mismatch the interpreter runs the words
 * that are actually there. Several entries may share a guest_pc (one per
 * member). */
typedef struct MusashiNativeLaneOverlayEntry {
    MusashiNativeLaneEntry entry;
    uint32_t size;   /* bytes hashed: the function's registry extent */
    uint64_t digest; /* FNV-1a 64 of the member's bytes over that extent */
    const char *member; /* e.g. "main_0003" */
} MusashiNativeLaneOverlayEntry;

/* Install the overlay table (copied and sorted; replaces any previous one).
 * MUSASHI_NATIVE_LANE_DENY / _RANGE filter it as they filter the main table.
 * Returns the number of entries kept, or -1 on an unaligned PC or a
 * (guest_pc, digest) duplicate. */
int musashi_native_lane_install_overlay(const MusashiNativeLaneOverlayEntry *entries,
                                        size_t count);

/* 1 when guest RAM at [pc, pc + size) hashes to digest (used by generated
 * stubs before a direct native call to another overlay function). */
int musashi_native_lane_overlay_resident(uint32_t pc, uint32_t size, uint64_t digest);

/* Generated direct calls between native overlay functions bracket the call
 * with enter/leave, so the callee is on the overlay frame stack. After every
 * guest call (interpreter thunk) from native code, each overlay frame of the
 * running lane entry is re-hashed; a mismatch aborts the lane call (the step
 * is refused: fail closed). Only valid while a lane function runs. */
void musashi_native_lane_overlay_enter(uint32_t pc, uint32_t size, uint64_t digest);
void musashi_native_lane_overlay_leave(void);

/* Since process start: lane entries at an overlay PC that ran natively
 * (entry_verified) or fell back to the interpreter because no member's digest
 * matched the resident bytes (entry_refused); direct native-to-native overlay
 * calls taken (guard_verified) or sent to the interpreter thunk
 * (guard_refused); post-guest-call frame re-checks passed and failed. */
typedef struct MusashiNativeLaneOverlayStats {
    uint64_t entry_verified, entry_refused;
    uint64_t guard_verified, guard_refused;
    uint64_t recheck_ok, recheck_failed;
} MusashiNativeLaneOverlayStats;
void musashi_native_lane_overlay_stats_get(MusashiNativeLaneOverlayStats *out);

/* Entry plus guard counters, summed (verified, refused). */
void musashi_native_lane_overlay_stats(uint64_t *verified, uint64_t *refused);

/* Argument n (0-based) under the o32 register ABI. */
uint32_t musashi_native_lane_arg(const MusashiNativeLaneCall *call, unsigned n);

/* Install one sorted-or-unsorted table (copied into an index; entries and
 * names must outlive the lane). Replaces any previous table. Returns the
 * number of accepted entries, or -1 on a duplicate/unaligned PC. */
int musashi_native_lane_install(const MusashiNativeLaneEntry *entries,
                                size_t count);

/* Nonzero when MUSASHI_NATIVE_LANE is not "0" and guest RAM is mapped at
 * MUSASHI_NATIVE_LANE_GUEST_BASE for this memory. */
int musashi_native_lane_usable(const MusashiBootMemory *memory);

/* Nesting suspension: while suspended, every PC runs on the interpreter.
 * Host routers whose checks count interpreted calls (the IRQ dispatcher)
 * suspend the lane for their duration. */
void musashi_native_lane_suspend(int suspend);

/* Interpreter thunk for natively compiled code: call guest function target
 * with argc words (a0-a3, then guest stack), on the invoking CPU and its
 * run loop, and return v0 (v1 through *v1 when non-NULL). A refusal inside
 * the guest callee aborts the whole native call (longjmp to the lane). Only
 * valid while a lane function is running. */
uint32_t musashi_native_guest_call(uint32_t target, unsigned argc,
                                   const uint32_t *args, uint32_t *v1);

/* Maps size bytes of shared memory at MUSASHI_NATIVE_LANE_GUEST_BASE (the
 * guest window: MusashiBootMemory first) and aliases its scratchpad page at
 * guest 0x1F800000. Returns the window or NULL; *scratchpad_aliased says
 * whether the alias took. */
void *musashi_native_lane_map_guest(size_t size, int *scratchpad_aliased);

/* Guest PC of the innermost running lane entry, or 0 (diagnostics). */
uint32_t musashi_native_lane_current(void);

/* Aborts the running native call (the lane step is refused). Only valid
 * while a lane function runs. */
void musashi_native_lane_abort(void);
/* Guarded 32-bit division for natively compiled code (tools/native_lane_gen.py
 * lowers variable divisors to these); a trapping divisor aborts the call. */
int32_t lane_sdiv32(int32_t a, int32_t b);
int32_t lane_srem32(int32_t a, int32_t b);
uint32_t lane_udiv32(uint32_t a, uint32_t b);
uint32_t lane_urem32(uint32_t a, uint32_t b);

/* Reference execution for differential checks: run guest function target
 * with argc argument words on a fresh device-less CPU (gp=0x80074750,
 * ra=sentinel, stack args at sp+0x10) until it returns. use_lane=0 forces
 * the interpreter for every PC. Returns 1 on a normal return. */
int musashi_native_lane_reference_call(MusashiBootMemory *memory, uint32_t target,
                                       const uint32_t *args, unsigned argc,
                                       uint32_t sp, int use_lane,
                                       uint32_t *v0, uint32_t *v1);
/* The same, returning the whole general register file at the return
 * (regs[0..31]; zeroed when the call is rejected up front). */
int musashi_native_lane_reference_call_regs(MusashiBootMemory *memory, uint32_t target,
                                            const uint32_t *args, unsigned argc,
                                            uint32_t sp, int use_lane, uint32_t regs[32]);
/* The same with an execution clock on the CPU (NULL: none), so a probe can
 * compare the guest time the interpreter charges with the native ledger. */
int musashi_native_lane_reference_call_clocked(MusashiBootMemory *memory, uint32_t target,
                                               const uint32_t *args, unsigned argc,
                                               uint32_t sp, int use_lane, uint32_t regs[32],
                                               const MusashiExecutionClock *clock);
/* ... and a checkpoint (called before every interpreted instruction and by
 * the lane's deadline guard), for tests of the D-011 mid-native checkpoint. */
int musashi_native_lane_reference_call_checkpoint(MusashiBootMemory *memory, uint32_t target,
                                                  const uint32_t *args, unsigned argc,
                                                  uint32_t sp, int use_lane, uint32_t regs[32],
                                                  const MusashiExecutionClock *clock,
                                                  int (*checkpoint)(void *, const void *),
                                                  void *userdata);
/* ... with a CPU transfer device (the GTE: CTC2/CFC2/MTC2/MFC2 and commands;
 * NULL: none), for differentials of functions whose callees use the GTE. */
int musashi_native_lane_reference_call_transfer(MusashiBootMemory *memory, uint32_t target,
                                                const uint32_t *args, unsigned argc,
                                                uint32_t sp, int use_lane, uint32_t regs[32],
                                                const MusashiExecutionClock *clock,
                                                const MusashiCpuTransferDevice *transfer);

/* ... with both a checkpoint and a transfer device. Returns 1 when the call
 * returned, 2 when a checkpoint requested a host stop (pc and npc parked at
 * the sentinel), 0 when it was refused. */
int musashi_native_lane_reference_call_device(MusashiBootMemory *memory, uint32_t target,
                                              const uint32_t *args, unsigned argc,
                                              uint32_t sp, int use_lane, uint32_t regs[32],
                                              const MusashiExecutionClock *clock,
                                              int (*checkpoint)(void *, const void *),
                                              void *userdata,
                                              const MusashiCpuTransferDevice *transfer);
/* The abort code of the most recent aborted lane call (0: none yet):
 * 4 a guest call refused, 5 a host stop during a guest call, ... */
int musashi_native_lane_last_abort(void);

/* Executed-path tracer (MUSASHI_TRACE_FUNCS=path). Called by the formatter
 * for jal/jalr targets and CPU dispatch entries; exposed for host routers
 * that enter guest code without a jal. kind: 'j' jal, 'r' jalr, 'd' entry. */
void musashi_trace_function_entry(uint32_t target, uint32_t caller, char kind);
/* Write <path>.counts now (it is also written at exit). */
void musashi_trace_function_flush(void);

/* Guest function-entry hook for the platform layer (bfm_plat hook sites,
 * mods): called once when execution reaches a jal/jalr target, after the
 * delay slot (a0-a3 final) and before the native lane. regs is the live
 * guest register file, valid only during the call. NULL disables it. */
typedef void (*MusashiEntryHook)(void *userdata, uint32_t pc, const uint32_t *regs);
void musashi_formatter_set_entry_hook(MusashiEntryHook hook, void *userdata);

/* Overlay selection notice for the platform layer: name is the selected
 * member ("SC02_031", "SC01_000", "SC01_001", "MAIN_0004", "MAIN_0007",
 * "MAIN_0010") or NULL when none is selected. Called on changes only. */
typedef void (*MusashiOverlayHook)(void *userdata, const char *name);
void musashi_formatter_set_overlay_hook(MusashiOverlayHook hook, void *userdata);

#ifdef __cplusplus
}
#endif

#endif
