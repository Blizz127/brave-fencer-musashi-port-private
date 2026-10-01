/* Exact retail word export for [80033324,80033398); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (29/29 words at 0x80033324). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

extern u8 D_800A46E8[];

void func_80033324(s32 arg0, s32 arg1) {
    u16 temp_v0;
    void *temp_a1;

    temp_a1 = &D_800A46E8[arg1 * 0x54];
    if (((*(u16 *) ((s8 *) (temp_a1) + (0))) & 0x3F) == 1) {
        (*(s8 *) ((s8 *) ((temp_a1 + arg0)) + (0xE))) = 0;
        temp_v0 = (*(u16 *) ((s8 *) (temp_a1) + (0xC))) - 1;
        (*(u16 *) ((s8 *) (temp_a1) + (0xC))) = temp_v0;
        if (!(temp_v0 & 0xFFFF) && ((*(u8 *) ((s8 *) (temp_a1) + (0xA))) != 5)) {
            (*(u8 *) ((s8 *) (temp_a1) + (0xA))) = 0U;
            (*(u16 *) ((s8 *) (temp_a1) + (0))) = 0U;
        }
    }
}
