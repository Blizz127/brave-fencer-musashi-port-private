/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016B114 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016B234();
extern void func_800D22E4(s32 a0);
extern void func_80146C3C();
extern void func_8012A568(void (*a0)(void));

void func_8016B114(void *arg0)
{
    s32 s1;
    u32 state;
    s32 cv;
    s1 = *(s32 *)((u8 *)arg0 + 0x20);
    if ((u32)*(s32 *)((u8 *)arg0 + 0x2C) < 6U) {
        func_8016B234();
    }
    state = *(u32 *)((u8 *)arg0 + 0x2C);
    switch (state) {
    case 6:
    case 7:
        cv = *(u8 *)((u8 *)s1 + 0x26) - 0x10;
        *(u8 *)((u8 *)s1 + 0x26) = cv;
        *(u8 *)((u8 *)s1 + 0x25) = cv;
        *(u8 *)((u8 *)s1 + 0x24) = cv;
        *(u16 *)((u8 *)arg0 + 0xA) = *(u16 *)((u8 *)arg0 + 0xA) - 2;
        break;
    case 1:
    case 5:
    {
        register s32 r26 __asm__("$4");
        register s32 r14 __asm__("$2");
        register s32 r24 __asm__("$3");
        func_800D22E4((s32)arg0);
        r26 = *(u16 *)((u8 *)arg0 + 0x26);
        r14 = *(s32 *)((u8 *)arg0 + 0x14);
        r24 = *(u16 *)((u8 *)arg0 + 0x24);
        r26 += 1;
        r14 += 0x18000;
        r24 -= 0x10;
        *(s32 *)((u8 *)arg0 + 0x14) = r14;
        *(u16 *)((u8 *)arg0 + 0x26) = r26;
        *(u16 *)((u8 *)arg0 + 0x24) = r24;
        break;
    }
    default:
    {
        register s32 d26 __asm__("$2");
        register s32 dA  __asm__("$3");
        register s32 d24 __asm__("$4");
        d26 = *(u16 *)((u8 *)arg0 + 0x26);
        dA  = *(u16 *)((u8 *)arg0 + 0xA);
        d24 = *(u16 *)((u8 *)arg0 + 0x24);
        d26 += 1;
        dA  -= 2;
        d24 -= 0x10;
        *(u16 *)((u8 *)arg0 + 0xA) = dA;
        *(u16 *)((u8 *)arg0 + 0x26) = d26;
        *(u16 *)((u8 *)arg0 + 0x24) = d24;
        break;
    }
    }
    cv = *(s32 *)((u8 *)arg0 + 0x1C) - 1;
    *(s32 *)((u8 *)arg0 + 0x1C) = cv;
    if (cv == 0) {
        ((void (*)(s32))func_80146C3C)((s32)arg0);
    }
}
