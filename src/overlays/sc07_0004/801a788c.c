/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A788C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A7358;
extern void func_800233CC(void *a0, unsigned short a1);
extern void func_8001CD9C(s32, s32);
extern void func_801A7AF8(s32);
extern void func_801A7C34(s32);
extern void func_801A7D34(s32);
extern void func_801A7F84(s32);
extern void func_801A8054(s32);
extern void func_801A8228(s32);
extern Blk4_801A7358 D_801A01E8;
extern Blk4_801A7358 D_801A01EC;
extern Blk4_801A7358 D_801F88B8;
extern Blk4_801A7358 D_801F88BC;
extern Blk4_801A7358 D_801F88F8;
extern Blk4_801A7358 D_801F8938;

void func_801A788C(s32 a0) {
    /* Block scope on purpose: md_SC07_004.c declares these four at FILE scope with
       other types further down (u8[3] / Blk4_801AB8C0 / s32[] / u8[4]); a file-scope
       Blk4_801A7358 decl here would be a conflicting-types error for the whole TU. */
    extern Blk4_801A7358 D_801F8978;
    extern Blk4_801A7358 D_801F897C;
    extern Blk4_801A7358 D_801F89B8;
    extern Blk4_801A7358 D_801F89F8;
    register void *s0 __asm__("$16");
    s32 v1;

    switch (*(s16 *)(a0 + 0x2E)) {
    case 0:
        s0 = &D_801F88B8;
        func_800233CC(s0, 0x80);
        D_801F88B8 = D_801A01E8;
        D_801F88BC = D_801A01E8;
        func_8001CD9C(*(s32 *)(a0 + 0x20), (s32)s0);
        v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = 0xC020;
        v1 = *(s32 *)(a0 + 0x20);
        *(s32 *)(v1 + 4) = 0x50000000;
        func_801A7AF8(a0);
        break;
    case 1:
        s0 = &D_801F8978;
        func_800233CC(s0, 0x80);
        D_801F8978 = D_801A01EC;
        D_801F897C = D_801A01E8;
        func_8001CD9C(*(s32 *)(a0 + 0x20), (s32)s0);
        v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = 0xC020;
        v1 = *(s32 *)(a0 + 0x20);
        *(s32 *)(v1 + 4) = 0x50800000;
        func_801A7C34(a0);
        break;
    case 2:
        *(s32 *)(a0 + 0x24) = (s32)&D_801F88F8;
        func_801A7D34(a0);
        break;
    case 3:
        *(s32 *)(a0 + 0x24) = (s32)&D_801F8938;
        func_801A7D34(a0);
        break;
    case 4:
        *(s32 *)(a0 + 0x24) = (s32)&D_801F88F8;
        *(s32 *)(a0 + 0x30) = 0x404;
        func_801A7F84(a0);
        break;
    case 5:
        *(s32 *)(a0 + 0x24) = (s32)&D_801F8938;
        *(s32 *)(a0 + 0x30) = 0x40004;
        func_801A7F84(a0);
        break;
    case 6:
        s0 = &D_801F89B8;
        func_800233CC(s0, 0x80);
        func_8001CD9C(*(s32 *)(a0 + 0x20), (s32)s0);
        v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = 0xC020;
        v1 = *(s32 *)(a0 + 0x20);
        *(s32 *)(v1 + 4) = 0x50000000;
        v1 = *(s32 *)(a0 + 0x20);
        *(s16 *)(v1 + 0x1E) = 0xE00;
        func_801A8054(a0);
        break;
    case 7:
        s0 = &D_801F89F8;
        func_800233CC(s0, 0x80);
        func_8001CD9C(*(s32 *)(a0 + 0x20), (s32)s0);
        v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = 0xC080;
        v1 = *(s32 *)(a0 + 0x20);
        *(s32 *)(v1 + 4) = 0x50800000;
        func_801A8228(a0);
        break;
    }
}
