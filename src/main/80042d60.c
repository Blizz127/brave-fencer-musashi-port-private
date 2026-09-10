#include "psx_types.h"

/* Exact callback-slot write [80042D60,80042D8C). */

/* Decompiled and verified byte-exact against the registered retail EXE. */
extern s32 D_8006CB98[];

void func_80042D60(s32 index, s32 value) {
    s32 *base = D_8006CB98;
    s32 *slot = base + index;
    if (value == *slot)
        return;
    *slot = value;
}
