/* Exact retail word export [8004768C,800476C0); verified against pinned EXE and asm. */
#include "psx_types.h"

/* Decompiled by hand from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

/* Word-copy loop with an early empty-count exit. Post-increments keep
 * the pointers walking (no indexed scaling); the unsigned counter
 * gives `sltu`. The address-taken dead local reserves the phantom
 * 8-byte frame with zero `$sp` traffic. */
void func_8004768C(s32 *dst, s32 *src, s32 n) {
    s32 du;
    u32 i = 0;

    (void)&du;
    if (n == 0) {
        return;
    }
    do {
        *dst++ = *src++;
        i++;
    } while (i < (u32)n);
}
