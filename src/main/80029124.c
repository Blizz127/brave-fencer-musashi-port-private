#include "psx_types.h"


/* Decompiled from main.s; byte storage and unsigned shifts match the observed
 * instruction semantics, not an asserted original API. */
extern u8 D_800AE648[];

void func_80029124(s32 selector, s32 enabled) {
    u8 mask = 1u << (selector & 7);
    u8 *value = &D_800AE648[(u32)selector >> 3];
    if ((u8)enabled)
        *value |= mask;
    else
        *value &= ~mask;
}
