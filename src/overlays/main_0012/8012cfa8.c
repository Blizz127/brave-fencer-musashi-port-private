/* Overlay range [8012CFA8,8012D098) from MAIN.CD member 0012.
 * SHA256(span)=f8f06bb2e73a72eebd4d58250840b3256059f037f726f9e6df91578437337328.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012CFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#define AddPrim func_80058C6C
#define RotTransPers func_8004955C
#define SetPolyF3 func_80058D70


void func_8012CFA8(s32 arg0)
{
    extern s32 AddPrim(s32, void *);
    extern s32 RotTransPers(s32, s32 *, s32 *, s32 *);
    extern void SetPolyF3(void *);
    extern void *func_80010A08(s32);
    extern void func_8004914C(void *a0);
    extern void func_800491AC(void *a0);
    extern s32 D_800A651C;
    extern u8 D_800AF648;
    extern short D_800B9A02;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 temp_a2;
    void *temp_v0;
    temp_v0 = func_80010A08(0x14);
    (*(s32 *)((s8 *)(temp_v0) + (4))) = 0xFF;
    SetPolyF3(temp_v0);
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    temp_a2 = (RotTransPers(arg0, &sp10, &sp14, &sp18) >> 2) - 0x20;
    if (temp_a2 > 0) {
        *(s32 *)((s8 *)temp_v0 + 8) = sp10;
        *(s16 *)((s8 *)temp_v0 + 0xC) = *(u16 *)((s8 *)temp_v0 + 8) + 8;
        *(s16 *)((s8 *)temp_v0 + 0xE) = *(u16 *)((s8 *)temp_v0 + 0xA);
        *(s16 *)((s8 *)temp_v0 + 0x10) = *(u16 *)((s8 *)temp_v0 + 8);
        *(s16 *)((s8 *)temp_v0 + 0x12) = *(u16 *)((s8 *)temp_v0 + 0xA) + 8;
        AddPrim(*(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + (temp_a2 * 4), temp_v0);
    }
}
