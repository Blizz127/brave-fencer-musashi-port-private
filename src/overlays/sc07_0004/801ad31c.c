/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD31C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801AD31C;
extern const Blk4_801AD31C D_801A0224 ;  /* data at its retail address */
extern const Blk4_801AD31C D_801A0228 ;  /* data at its retail address */
extern u8 D_801F8D98[];
extern Blk4_801AD31C D_801A021C;
extern void func_800233CC(void *a0, unsigned short a1);
extern void func_8001CD50(s32 a0, s32 a1);
extern void func_801AD4C0(void *a0);
extern void func_801AD4D4(void *a0);

void func_801AD31C(void *s1)
{
    u8 *s0;
    u16 v0;
    u16 flags;
    u16 c;
    s32 sub;

    v0 = *(u16 *)((u8 *)s1 + 0x2E);
    s0 = D_801F8D98 + ((v0 & 3) << 6);
    flags = v0 & 0xF00;

    switch (flags) {
    case 0:
        func_800233CC(s0, 0x80);
        *(Blk4_801AD31C *)(s0 + 0) = D_801A021C;
        *(Blk4_801AD31C *)(s0 + 4) = D_801A021C;
        func_8001CD50(*(s32 *)((u8 *)s1 + 0x20), (s32)s0);
        sub = *(s32 *)((u8 *)s1 + 0x20);
        c = 0x5000;
        *(s16 *)(sub + 0x1A) = c;
        *(s16 *)(sub + 0x18) = c;
        *(s16 *)(*(s32 *)((u8 *)s1 + 0x20) + 0x10) = 0xC00;
        *(s16 *)(*(s32 *)((u8 *)s1 + 0x20) + 0x12) = *(u16 *)((u8 *)s1 + 0x2C);
        *(s16 *)(*(s32 *)((u8 *)s1 + 0x20) + 0x1E) = 0xD00;
        *(s32 *)(*(s32 *)((u8 *)s1 + 0x20) + 0x4) = 0x50000000;
        *(u16 *)(*(s32 *)((u8 *)s1 + 0x20) + 0x2C) = 0xC040;
        func_801AD4C0(s1);
        break;
    case 0x100:
        func_800233CC(s0, 0x80);
        *(Blk4_801AD31C *)(s0 + 0) = D_801A0224;
        *(Blk4_801AD31C *)(s0 + 4) = D_801A0228;
        func_8001CD50(*(s32 *)((u8 *)s1 + 0x20), (s32)s0);
        sub = *(s32 *)((u8 *)s1 + 0x20);
        c = 0x100;
        *(s16 *)(sub + 0x1A) = c;
        *(s16 *)(sub + 0x18) = c;
        *(s16 *)(*(s32 *)((u8 *)s1 + 0x20) + 0x10) = 0xC80;
        *(s16 *)(*(s32 *)((u8 *)s1 + 0x20) + 0x12) = *(u16 *)((u8 *)s1 + 0x2C);
        *(s16 *)(*(s32 *)((u8 *)s1 + 0x20) + 0x1E) = 0xC00;
        *(s32 *)(*(s32 *)((u8 *)s1 + 0x20) + 0x4) = 0x50000000;
        *(u16 *)(*(s32 *)((u8 *)s1 + 0x20) + 0x2C) = 0xC100;
        func_801AD4D4(s1);
        break;
    }
}
