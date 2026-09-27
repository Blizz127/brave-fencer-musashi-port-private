/* Exact retail word export for [801717A0,801717F4); EXE and assembly verified. */
/* Verified byte-exact against retail by tools/match_function.py
 * (21/21 words at 0x801717A0). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */
#include "psx_types.h"

s32 func_800D0F8C(u8);
void func_800D0FE0(s32);
void func_80171928(s32);
void func_801719A4(s32, s32);
extern u8 D_8011F738;

void func_801717A0(s32 arg0) {
    s32 temp_v0;

    func_801719A4(arg0, 1);
    temp_v0 = func_800D0F8C(D_8011F738);
    if (temp_v0 != 0) {
        func_800D0FE0(temp_v0);
    }
    func_80171928(arg0);
}
