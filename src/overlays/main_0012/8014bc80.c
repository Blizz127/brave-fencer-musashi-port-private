/* Exact retail word export for [8014BC80,8014BCC0); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (16/16 words at 0x8014BC80). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern u16 D_80078EB4;
extern s8 D_800B9A17;

void func_8014BC80(s32 arg0, s32 arg1) {
    if ((s32) D_80078EB4 < arg1) {
        D_80078EB4 = 0;
        D_800B9A17 = 0;
        return;
    }
    D_80078EB4 -= arg1;
}
