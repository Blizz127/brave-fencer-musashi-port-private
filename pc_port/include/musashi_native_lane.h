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
} MusashiNativeLaneEntry;

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

/* Interpreter thunk for natively compiled code: call guest function target
 * with argc words (a0-a3, then guest stack), on the invoking CPU and its
 * run loop, and return v0 (v1 through *v1 when non-NULL). A refusal inside
 * the guest callee aborts the whole native call (longjmp to the lane). Only
 * valid while a lane function is running. */
uint32_t musashi_native_guest_call(uint32_t target, unsigned argc,
                                   const uint32_t *args, uint32_t *v1);

/* Map a zeroed region of size bytes at exactly host address
 * MUSASHI_NATIVE_LANE_GUEST_BASE (64-bit Linux: MAP_FIXED_NOREPLACE).
 * Returns NULL when the address is unavailable or the host is unsupported. */
void *musashi_native_lane_map_guest_window(size_t size);

/* Executed-path tracer (MUSASHI_TRACE_FUNCS=path). Called by the formatter
 * for jal/jalr targets and CPU dispatch entries; exposed for host routers
 * that enter guest code without a jal. kind: 'j' jal, 'r' jalr, 'd' entry. */
void musashi_trace_function_entry(uint32_t target, uint32_t caller, char kind);

#ifdef __cplusplus
}
#endif

#endif
