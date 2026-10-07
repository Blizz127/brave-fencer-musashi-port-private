/* Owner re-derivation from retail assembly (clean input set). */
#include "psx_types.h"

/* Clears the 8-byte block at D_800747C0. */
extern u8 D_800747C0[];
extern void func_80016714(u8 *dst, s32 size);

void func_8001903C(void)
{
    func_80016714(D_800747C0, 8);
}
