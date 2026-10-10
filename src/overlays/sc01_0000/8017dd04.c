/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017DD04 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u32 addr : 24; u32 len : 8; u8 r0, g0, b0, code; } P_TAG;
typedef void (*code)(unsigned short *);

void func_8017DD04(s32 arg0, s32 arg1)
{
    typedef struct { u32 addr:24; u32 len:8; } P_TAG;
    extern void func_8017E1A8();
    extern u8 *D_800A5E60;
    extern u8 D_800AA60C[];
    extern s16 D_800B9A02;
    extern u8 D_801826EC[];
    extern s32 D_801A5734;
    extern u16 D_801826F0, D_801826F2, D_801826F8, D_801826FA;
    extern u16 D_80182700, D_80182702;
    extern u16 D_80182708, D_8018270A, D_80182710, D_80182712;
    extern u16 D_80182718, D_8018271A;
    extern u16 D_80182720, D_80182722, D_80182728, D_8018272A;
    extern u16 D_80182730, D_80182732;
    u8 *pkt;
    register u8 *ob __asm__("$10");
    u32 mlo;
    u32 c80;
    register u32 cFF __asm__("$8");
    register u32 cDF __asm__("$9");
    u32 pad[2];

    func_8017E1A8(D_801826EC, arg0, arg1, D_801A5734);
    pkt = D_800A5E60;

    *(u8 *)(pkt + 3) = 9;
    *(u8 *)(pkt + 7) = 0x2C;
    *(s16 *)(pkt + 0x16) = 0x8E;
    *(s16 *)(pkt + 0xE) = 0x7DC0;
    c80 = 0x80;
    *(u8 *)(pkt + 6) = c80;
    *(u8 *)(pkt + 5) = c80;
    *(u8 *)(pkt + 4) = c80;
    *(u8 *)(pkt + 0xC) = 0x0;
    *(u8 *)(pkt + 0xD) = 0;
    cFF = 0xFF;
    *(u8 *)(pkt + 0x14) = cFF;
    *(u8 *)(pkt + 0x15) = 0;
    *(u8 *)(pkt + 0x1C) = 0x0;
    *(u8 *)(pkt + 0x1D) = cFF;
    *(u8 *)(pkt + 0x24) = cFF;
    *(u8 *)(pkt + 0x25) = cFF;
    *(s16 *)(pkt + 0x8) = D_801826F0;
    *(s16 *)(pkt + 0xA) = D_801826F2;
    *(s16 *)(pkt + 0x10) = D_801826F8;
    *(s16 *)(pkt + 0x12) = D_801826FA;
    *(s16 *)(pkt + 0x18) = D_80182708;
    *(s16 *)(pkt + 0x1A) = D_8018270A;
    *(s16 *)(pkt + 0x20) = D_80182710;
    *(s16 *)(pkt + 0x22) = D_80182712;
    mlo = 0xFFFFFF;
    *(u32 *)pkt = (*(u32 *)pkt & 0xFF000000) | (*(u32 *)(D_800AA60C + (((u16)D_800B9A02) << 14)) & mlo);
    ob = D_800AA60C;
    ((P_TAG *)((s32)ob + (((u16)D_800B9A02) << 14)))->addr = (u32)pkt;
    pkt += 0x28;

    *(u8 *)(pkt + 3) = 9;
    *(u8 *)(pkt + 7) = 0x2C;
    *(s16 *)(pkt + 0x16) = 0x9F;
    *(s16 *)(pkt + 0xE) = 0x7DC0;
    *(u8 *)(pkt + 6) = c80;
    *(u8 *)(pkt + 5) = c80;
    *(u8 *)(pkt + 4) = c80;
    *(u8 *)(pkt + 0xC) = 0x40;
    *(u8 *)(pkt + 0xD) = 0;
    *(u8 *)(pkt + 0x14) = 0x7F;
    *(u8 *)(pkt + 0x15) = 0;
    *(u8 *)(pkt + 0x1C) = 0x40;
    *(u8 *)(pkt + 0x1D) = cFF;
    *(u8 *)(pkt + 0x24) = 0x7F;
    *(u8 *)(pkt + 0x25) = cFF;
    *(s16 *)(pkt + 0x8) = D_801826F8;
    *(s16 *)(pkt + 0xA) = D_801826FA;
    *(s16 *)(pkt + 0x10) = D_80182700;
    *(s16 *)(pkt + 0x12) = D_80182702;
    *(s16 *)(pkt + 0x18) = D_80182710;
    *(s16 *)(pkt + 0x1A) = D_80182712;
    *(s16 *)(pkt + 0x20) = D_80182718;
    *(s16 *)(pkt + 0x22) = D_8018271A;
    *(u32 *)pkt = (*(u32 *)pkt & 0xFF000000) | (*(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)) & mlo);
    ((P_TAG *)((s32)ob + (((u16)D_800B9A02) << 14)))->addr = (u32)pkt;
    pkt += 0x28;

    *(u8 *)(pkt + 3) = 9;
    *(u8 *)(pkt + 7) = 0x2C;
    *(s16 *)(pkt + 0x16) = 0x8C;
    *(s16 *)(pkt + 0xE) = 0x7DC0;
    *(u8 *)(pkt + 6) = c80;
    *(u8 *)(pkt + 5) = c80;
    *(u8 *)(pkt + 4) = c80;
    *(u8 *)(pkt + 0xC) = 0x0;
    *(u8 *)(pkt + 0xD) = 0;
    *(u8 *)(pkt + 0x14) = cFF;
    *(u8 *)(pkt + 0x15) = 0;
    *(u8 *)(pkt + 0x1C) = 0x0;
    cDF = 0xDF;
    *(u8 *)(pkt + 0x1D) = cDF;
    *(u8 *)(pkt + 0x24) = cFF;
    *(u8 *)(pkt + 0x25) = cDF;
    *(s16 *)(pkt + 0x8) = D_80182708;
    *(s16 *)(pkt + 0xA) = D_8018270A;
    *(s16 *)(pkt + 0x10) = D_80182710;
    *(s16 *)(pkt + 0x12) = D_80182712;
    *(s16 *)(pkt + 0x18) = D_80182720;
    *(s16 *)(pkt + 0x1A) = D_80182722;
    *(s16 *)(pkt + 0x20) = D_80182728;
    *(s16 *)(pkt + 0x22) = D_8018272A;
    *(u32 *)pkt = (*(u32 *)pkt & 0xFF000000) | (*(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)) & mlo);
    ((P_TAG *)((s32)ob + (((u16)D_800B9A02) << 14)))->addr = (u32)pkt;
    pkt += 0x28;
    __asm__("" :: "r"(mlo), "r"(mlo), "r"(mlo), "r"(mlo), "r"(mlo), "r"(mlo));

    *(u8 *)(pkt + 3) = 9;
    *(u8 *)(pkt + 7) = 0x2C;
    *(s16 *)(pkt + 0x16) = 0x9F;
    *(s16 *)(pkt + 0xE) = 0x7DC0;
    *(u8 *)(pkt + 6) = c80;
    *(u8 *)(pkt + 5) = c80;
    *(u8 *)(pkt + 4) = c80;
    *(u8 *)(pkt + 0xC) = 0x0;
    *(u8 *)(pkt + 0xD) = 0;
    *(u8 *)(pkt + 0x14) = 0x3F;
    *(u8 *)(pkt + 0x15) = 0;
    *(u8 *)(pkt + 0x1C) = 0x0;
    *(u8 *)(pkt + 0x1D) = cDF;
    *(u8 *)(pkt + 0x24) = 0x3F;
    *(u8 *)(pkt + 0x25) = cDF;
    *(s16 *)(pkt + 0x8) = D_80182710;
    *(s16 *)(pkt + 0xA) = D_80182712;
    *(s16 *)(pkt + 0x10) = D_80182718;
    *(s16 *)(pkt + 0x12) = D_8018271A;
    *(s16 *)(pkt + 0x18) = D_80182728;
    *(s16 *)(pkt + 0x1A) = D_8018272A;
    *(s16 *)(pkt + 0x20) = D_80182730;
    *(s16 *)(pkt + 0x22) = D_80182732;
    *(u32 *)pkt = (*(u32 *)pkt & 0xFF000000) | (*(u32 *)((s32)ob + (((u16)D_800B9A02) << 14)) & mlo);
    ((P_TAG *)((s32)ob + (((u16)D_800B9A02) << 14)))->addr = (u32)pkt;
    pkt += 0x28;

    D_800A5E60 = pkt;
}
