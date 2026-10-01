/* Exact retail word export for [80029A58,80029A94); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (15/15 words at 0x80029A58). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern u8 D_80078F28[];

void func_80029A58(s32 arg0) {
    void *temp_v0;

    temp_v0 = &D_80078F28[arg0 * 0x2DC];
    (*(u32 *) ((s8 *) (temp_v0) + (0x38))) = (u32) ((u32) (*(u32 *) ((s8 *) (temp_v0) + (0x38))) >> 1);
}
