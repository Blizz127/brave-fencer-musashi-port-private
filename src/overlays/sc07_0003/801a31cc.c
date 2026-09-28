/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A31CC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A31CC(void *arg0) {
    s32 v0;
    u8 *a1;

    extern u8 D_801A6D58[];
    extern s32 func_8012C1B8(void);
    extern void func_8012CAE4(void *a0);
    extern void func_8001C214(s32 a0, s32 a1);

    *(s32 *)((u8 *)arg0 + 0x78) = (s32)D_801A6D58;
    v0 = func_8012C1B8();
    *(s32 *)((u8 *)arg0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(arg0);
        return;
    }
    func_8001C214(v0, 0);
    a1 = (u8 *)arg0 + 0xCC;
    *(s32 *)((u8 *)arg0 + 0x58) = (s32)a1 | 0x50000000;
    *(u8 *)((u8 *)arg0 + 0x75) = 2;
    *(s32 *)((u8 *)arg0 + 0xF8) = *(s16 *)(*(s32 *)((u8 *)arg0 + 0x64) + 0x36);
    switch (*(s16 *)((u8 *)arg0 + 0x70)) {
    case 0: {
        s32 link;
        link = (s32)(a1 + 0x10);
        *(s32 *)a1 = link;
        a1 = (u8 *)link;
        link = (s32)(a1 + 0x10);
        *(s32 *)a1 = link;
        __asm__ __volatile__("" : "=r"(link) : "0"(link));
        *(s32 *)link = 0;
        __asm__ __volatile__("" : : : "memory");
        *(u16 *)((u8 *)arg0 + 0x5C) = 0xC800;
        *(s16 *)((u8 *)arg0 + 0xAE) = -1;
        *(s16 *)((u8 *)arg0 + 0x2) = 1;
        break;
    }
    case 1:
        *(s16 *)((u8 *)arg0 + 0xAE) = -3;
        *(u16 *)((u8 *)arg0 + 0x5C) = 0x8800;
        *(s16 *)((u8 *)arg0 + 0x2) = 2;
        break;
    case 2:
        *(u16 *)((u8 *)arg0 + 0x5C) = 0x8800;
        *(s16 *)((u8 *)arg0 + 0xAE) = -0x10;
        *(s16 *)((u8 *)arg0 + 0x2) = 3;
        break;
    case 3:
        *(u16 *)((u8 *)arg0 + 0x5C) = 0xC000;
        *(s16 *)((u8 *)arg0 + 0xAE) = -1;
        *(s16 *)((u8 *)arg0 + 0x2) = 4;
        break;
    case 4:
        *(u16 *)((u8 *)arg0 + 0x5C) = 0x800;
        *(s16 *)((u8 *)arg0 + 0xAE) = -1;
        *(s16 *)((u8 *)arg0 + 0x2) = 5;
        *(s16 *)(a1 + 4) = -0x10;
        *(s16 *)(a1 + 6) = 0x10;
        *(s16 *)(a1 + 8) = -0x100;
        *(s16 *)(a1 + 0xA) = 0;
        *(s16 *)(a1 + 0xC) = -0x10;
        *(s16 *)(a1 + 0xE) = 0x10;
        break;
    }
}
