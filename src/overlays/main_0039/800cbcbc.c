/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBCBC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80149374(s32 a0, s32 a1);
extern void func_80146C3C(void);
extern void func_801465C0();
extern s32 func_8001CC3C(s32, s32, s32, s32);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_80146C3C();
extern void func_801465C0(void);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);

void func_800CBCBC(void *a0)
{
    extern u8 D_800D387C[];
    extern u8 D_800D3888[];
    void *s1;
    void *s0;
    s32 pad[14];

    s1 = *(void **)((u8 *)a0 + 0x34);
    s0 = ((void *(*)(void))func_801465C0)();
    *(void **)((u8 *)a0 + 0x20) = s0;

    if (s0 != ((void *)0) ) {
        func_8001CC3C((s32)s0, (s32)&D_800D387C, 0, 0);

        *(u8 *)((u8 *)s0 + 0x27) = 0x9C;
        *(u16 *)((u8 *)s0 + 0x1A) = 0x2000;
        *(u16 *)((u8 *)s0 + 0x18) = 0x2000;
        *(u8 *)((u8 *)s0 + 0x24) = 0xFF;
        *(u8 *)((u8 *)s0 + 0x25) = 0;
        *(u8 *)((u8 *)s0 + 0x26) = 0;
        *(s32 *)((u8 *)s0 + 4) |= 0x50000000;

        func_80149374((s32)s1, (s32)((u8 *)a0 + 4));
        func_80128EA8((s32)s0, (s32)((u8 *)a0 + 0x24), (s32)&D_800D3888);

        *(u16 *)((u8 *)a0 + 2) = *(u16 *)((u8 *)a0 + 2) + 1;
    } else {
        ((void (*)(void *))func_80146C3C)(a0);
    }
}
