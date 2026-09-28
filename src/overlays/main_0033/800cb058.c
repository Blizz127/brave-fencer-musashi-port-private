/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB058 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB058(s32 arg0)
{
    extern u8 D_800CB8B0[];
    extern s32 D_800CB984;
    extern u8 D_800CB988[];
    extern void func_80146578(void);
    extern void func_800CB384(void);
    extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);
    extern void func_80149374(s32 a0, s32 a1);
    extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
    extern void func_80146E90(s32 *a0, s32 a1);
    extern void func_80146CA0(void *a0);
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern void func_80147324(s32 a0);
    register s32 s1a __asm__("$17");
    register s32 s2a __asm__("$18");
    register s32 s0a __asm__("$16");
    register s32 maska __asm__("$6");
    register s32 fptr __asm__("$6");
    register s32 q __asm__("$5");
    register s32 p __asm__("$4");
    s32 v0w;
    s32 cnt;

    s1a = arg0;
    s2a = *(s32 *)(s1a + 0x4C);
    s0a = ((s32 (*)(void))func_80146578)();
    *(s32 *)(s1a + 0x20) = s0a;
    if (s0a == 0) goto fail;
    func_8001CB6C((u8 *)s0a, (s32)D_800CB8B0, 0x1A0, 0x100);
    maska = 0x50001000;
    p = s2a;
    q = (s32)(s1a + 4);
    v0w = *(u32 *)(s0a + 4);
    *(u8 *)(s0a + 0x27) = 0x19;
    *(u32 *)(s0a + 4) = (v0w | maska) & ~0x40;
    fptr = *(s32 *)(p + 0x20);
    cnt = D_800CB984++;
    *(s16 *)(s0a + 0x12) = *(s16 *)(fptr + 0x12);
    *(s16 *)(s0a + 0x10) = 0x400;
    *(s32 *)(s0a + 0x34) = (s32)D_800CB988 + ((cnt & 7) * 32);
    func_80149374(p, q);
    func_80146DE8(s1a, 0, 0, -0x100000);
    func_80146E90(s1a, 0x3C);
    func_80146CA0(s1a);
    func_80146A6C(0x4A, s1a, *(s16 *)(s1a + 6), *(s16 *)(s1a + 0xA), *(s16 *)(s1a + 0xE), 0, 0);
    func_80147324(0x8EF);
    return;
fail:
    ((void (*)(s32))func_800CB384)(s1a);
}
