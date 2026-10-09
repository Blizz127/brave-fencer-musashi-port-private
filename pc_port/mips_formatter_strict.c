/* mips_formatter_strict.c — the strict-native abort reporter.
 *
 * Compiled into musashi_pc_port in every build (a few hundred bytes when
 * unused); only MUSASHI_STRICT_NATIVE builds ever call it, from the seam
 * guards in mips_formatter.c and from the PsyQ compat refusal path
 * (bfm_psyq_compat.c). See docs/STRICT-NATIVE-BUILD.md.
 */
#include "musashi_strict.h"

#include <stdio.h>
#include <stdlib.h>
#if defined(__GLIBC__)
#include <execinfo.h>
#endif

void (*musashi_strict_pre_abort)(void);

void musashi_strict_abort(const char *seam, const char *routine, uint32_t guest_pc)
{
    static int aborting;
    fflush(stdout);
    fprintf(stderr,
            "native_boot: STRICT_INTERPRETER_ENTRY seam=%s routine=%s guest_pc=%08x\n"
            "native_boot: this build has no CPU interpreter; the native slice does not\n"
            "native_boot: cover this path yet. See docs/STRICT-NATIVE-BUILD.md (seam catalog).\n",
            seam ? seam : "?", routine ? routine : "?", guest_pc);
#if defined(__GLIBC__)
    {
        void *frames[24];
        int n = backtrace(frames, 24);
        if (n > 0) {
            fputs("native_boot: host call chain:\n", stderr);
            backtrace_symbols_fd(frames, n, 2);
        }
    }
#endif
    /* Diagnostics registered by the boot (render stats + VRAM dump at the
     * stop, MUSASHI_DUMP_VRAM=1); run once, never recursively. */
    if (musashi_strict_pre_abort && !aborting) {
        aborting = 1;
        musashi_strict_pre_abort();
    }
    fflush(stderr);
    abort();
}
