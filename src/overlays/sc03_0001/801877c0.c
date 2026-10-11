/* sc03_0001: own C written from the retail words (no upstream definition).
 * Verified byte-exact against retail by tools/verify_registry.py. Types and
 * signatures are whatever reproduces the bytes; they are not evidence of the
 * original declaration. */
#include "psx_types.h"

extern s32 func_80029504(void);

s32 func_801877C0(void) {
    s32 v = func_80029504();
    if (v < 20) return 0;
    if (v < 70) return 1;
    if (v < 100) return 2;
    if (v < 130) return 3;
    return 4;
}
