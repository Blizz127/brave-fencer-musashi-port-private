/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013B204 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_800A651C;
extern s16 D_800B9A02;
extern short D_800B9A02;
extern void func_8013B274(s32 a0, s32 a1, void *a2);

void func_8013B204(s32 a0, s32 a1)
{
    void *a2;
    s32 idx;
    a2 = a1;
    if (*(s16 *)((u8 *)a2 + 0xC) != 0) {
        return;
    }
    if (*(s16 *)a2 != 2) {
        return;
    }
    a2 = (u8 *)a2 + 8;
    idx = (u16)D_800B9A02;
    func_8013B274(
        (&D_800A651C)[idx * 5] + ((u16)(*(u16 *)((u8 *)a0 + 0x1A)) << 2),
        *(s16 *)((u8 *)a0 + 0x1C),
        a2);
}
