/* musashi_native_frame_driver.h: the strict-native frame driver.
 *
 * In a MUSASHI_STRICT_NATIVE build nothing interprets retail MIPS, so the
 * game's own crt0/main cannot run. The frame driver is host C that performs
 * main's sequence itself (docs/NATIVE-FRAME-DRIVER.md): the init calls, the
 * session (outer) loop and the per-frame (inner) loop with main's inline
 * bookkeeping, calling every guest function through the native lane table.
 * A callee that is not in the table is a strict stop
 * ("seam=frame_driver"), never an interpreter fallback.
 *
 * Owner-written from main's retail disassembly (80010178) and the design
 * note; no vendor C and no Sony material. Hybrid (non-strict) builds do not
 * compile any of this and keep entering the interpreter at 0x80010000. */
#ifndef MUSASHI_NATIVE_FRAME_DRIVER_H
#define MUSASHI_NATIVE_FRAME_DRIVER_H

#include <stddef.h>
#include <stdint.h>

#include "musashi_boot_memory.h"
#include "musashi_native_lane.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Runs the lane entry at `target` (a0-a3 = args[0..3], further words at
 * sp+0x10...) on a fresh CPU bound to `devices`, returning to a host
 * sentinel. 1: it ran (*v0 = v0); 0: `target` is not a lane function here
 * (the caller decides: the driver stops); -1: the native call aborted
 * (musashi_native_lane_last_abort() has the code; 5 is a host stop).
 * Strict builds only (mips_formatter.c). */
int musashi_native_lane_invoke(MusashiBootMemory *memory,
                               const MusashiStartupPrefixDevice *devices,
                               uint32_t target, const uint32_t *args, unsigned argc,
                               uint32_t sp, uint32_t *v0);

/* Platform services the driver needs once per frame. Any may be NULL. */
typedef struct MusashiFrameDriverOps {
    void *user;
    /* main's 800189A8 point (FRAME_BEGIN): input poll, pause. Blocks while
     * paused. Nonzero: quit requested, the driver returns. */
    int (*frame_begin)(void *user);
    /* main's VSync(n) point: FRAME_END, present and pace `fields` NTSC
     * fields (bfm_plat_frame_end / bfm_plat_timing). Nonzero: quit. */
    int (*frame_end)(void *user, unsigned fields);
    /* Advance guest time by `fields` VBlanks (execution clock). 0: refused. */
    int (*vblank)(void *user, unsigned fields);
    /* Host pad `port` (0 or 1) in PS1 wire form: out[0] = 0x41 digital or
     * 0x73 analog, out[1] = 0x5A, out[2..3] = ~buttons, out[4..7] sticks.
     * Returns the bytes written, 0 when no pad is connected. */
    size_t (*pad_wire)(void *user, unsigned port, uint8_t out[8]);
} MusashiFrameDriverOps;

/* The driver's own lane entries: native replacements for the Sony library
 * calls on the frame path that the PsyQ compat table still lists as STUB
 * (libpad PadInitDirect/PadStartCom/PadStopCom/PadGetState/PadInfoMode/
 * PadSetAct/PadSetActAlign, InitHeap, the libapi Enter/ExitCriticalSection
 * syscall wrappers and libcd CdMix). Copies at most `cap` entries to `out`
 * and returns how many exist. native_boot appends them to the lane table. */
size_t musashi_frame_driver_lane_entries(MusashiNativeLaneEntry *out, size_t cap);

/* Runs main from its first call until quit (or MUSASHI_DRIVER_FRAMES
 * frames). Needs the lane window (guest RAM at 0x80000000) and an installed
 * lane table; aborts with seam=frame_driver at the first callee the lane
 * cannot run. */
MusashiResetGraphPrefixStatus musashi_frame_driver_run(MusashiBootMemory *memory,
                                                       const MusashiStartupPrefixDevice *devices,
                                                       const MusashiFrameDriverOps *ops);

#ifdef __cplusplus
}
#endif

#endif /* MUSASHI_NATIVE_FRAME_DRIVER_H */
