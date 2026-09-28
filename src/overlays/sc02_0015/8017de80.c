/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DE80 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_800233CC(void *, unsigned short);

void func_8017DE80(void *a0)
{

    extern u8 D_80190330[];
    s32 s1;
    u8 *p;

    s1 = *(s32 *)((s32)a0 + 0x20);
    p = D_80190330 + *(s32 *)((s32)a0 + 0x2C) * 0x40;
    func_8001CD50(s1, (s32)p);
    *(s16 *)(s1 + 0x1E) = 0xCCC;
    *(s16 *)(s1 + 0x10) = 0x400;
    *(s16 *)(s1 + 0x1A) = 0;
    *(s16 *)(s1 + 0x18) = 0;
    *(s32 *)(s1 + 4) = *(s32 *)(s1 + 4) | 0x50000000;
    func_800233CC(p, 0x80);
    p[2] = 0xFF;
    p[1] = 0xFF;
    p[0] = 0xFF;
    p[5] = 0x40;
    p[4] = 0x40;
    p[6] = 0x80;
    *(s32 *)((s32)a0 + 0x1C) = 0x10;
    *(u16 *)((s32)a0 + 2) = *(u16 *)((s32)a0 + 2) + 1;
}
