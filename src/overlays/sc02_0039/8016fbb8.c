/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016FBB8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_80171B44(s32 *a0);
extern void func_8016FC24();

void func_8016FBB8(s32 a0) {
    u8 *p;
    *(s16 *)(a0 + 0x136) = 2;
    p = *(u8 **)(a0 + 0x20);
    *(s16 *)(a0 + 0x132) = *(u16 *)(p + 0x12);
    p = *(u8 **)(a0 + 0x20);
    *(s16 *)(p + 0x12) = (*(u16 *)(p + 0x12) + 0x800) & 0xFFF;
    func_801719A4(a0, 1);
    func_80171B44((s32 *)a0);
    func_80171990((u8 *)a0);
    func_8016FC24(a0);
}
