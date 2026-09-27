#include "psx_types.h"


extern void (*D_80072784)(const char *, s32, s32, s32);
extern u8 D_80072788;
extern u8 D_8007278A;
extern u8 D_8007278B;
extern char D_800740D0[];

/* Decompiled from retail and verified byte-exact with gcc-2.7.2-psx -O2.
 * The range ends at 80059530; the final word is this routine's JR delay slot. */
u8 func_800594CC(u8 arg0) {
    u8 *state;
    u8 previous;

    state = &D_8007278A;
    previous = *state;
    *state = arg0;
    if (arg0 != 0)
        D_80072784(D_800740D0, arg0 & 0xFF, D_80072788, D_8007278B);
    return previous;
}
