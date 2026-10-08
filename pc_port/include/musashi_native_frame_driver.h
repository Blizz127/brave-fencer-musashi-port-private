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
    /* DICR owner for the native libetc DMA callbacks (80042F8C/80042E08). */
    const struct MusashiDmaCallbackRegistrationDevice *dma_irq;
    /* BIOS A0:72 (_96_remove) as libetc's init issues it. 0: refused. */
    int (*bios_a0_72)(void *user);
    /* The BIOS kernel's IRQ priority chains for `pending` (I_STAT & I_MASK),
     * run before libetc's custom exit. 0: refused. */
    int (*bios_irq)(void *user, uint16_t pending);
    /* Spend `cycles` of guest time (a retail busy-wait iteration). 0: refused. */
    int (*spend)(void *user, uint32_t cycles);
    /* BIOS B0:07 DeliverEvent(class, spec). 0: refused. */
    int (*deliver_event)(void *user, uint32_t class_word, uint32_t spec);
    /* BIOS B0 event service `fn` (07 deliver, 08 open, 09 close, 0B test,
     * 0C enable, 0D disable) with its arguments. 0: refused. */
    int (*bios_event)(void *user, unsigned fn, uint32_t a0, uint32_t a1, uint32_t a2,
                      uint32_t a3, int32_t *result);
    /* Status CU2 on (libgte InitGeom's mtc0, 80047CD0). 0: refused. */
    int (*cop2_enable)(void *user);
} MusashiFrameDriverOps;

/* The driver's own lane entries: native replacements for the Sony library
 * calls on the frame path that the PsyQ compat table still lists as STUB
 * (libpad PadInitDirect/PadStartCom/PadStopCom/PadGetState/PadInfoMode/
 * PadSetAct/PadSetActAlign, InitHeap, the libapi Enter/ExitCriticalSection
 * syscall wrappers and libcd CdMix). Copies at most `cap` entries to `out`
 * and returns how many exist. native_boot appends them to the lane table. */
/* The driver's interrupt point (strict builds): deliver a pending enabled
 * IRQ now. For host BIOS services that wait on interrupts (_bu_init). */
void musashi_frame_driver_irq_point(void);
/* Nonzero when an IRQ would be delivered now (enabled, not in a handler). */
int musashi_frame_driver_irq_enabled(void);

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
