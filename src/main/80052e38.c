/* Main-exec range [80052E38,80052E68) from the SLUS executable.
 * SHA256(span)=1420ce53d0fc3939c3b5d35b7207c64d0e792bffda78edff21a24188e33989c8.
 * Word export for the native seam; the C body below keeps its
 * own oracle match claim. */
#include "psx_types.h"

/* Decompiled by m2c from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

void func_8004914C();                                  /* static */
void func_800491AC(s32);                               /* static */

void func_80052E38(s32 arg0) {
    func_8004914C();
    func_800491AC(arg0);
}
