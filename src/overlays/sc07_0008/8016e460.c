/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E460 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32  func_80017DC4(void *a0, void *a1);
extern void func_80048EAC(void *a0, void *a1);
extern s32  func_80017758(void *a0, void *a1);
extern void func_8012A568(void (*a0)(void));

void func_8016E460(void *arg0, void *arg1) {
    u8 buf[0x5C];               /* spans $sp+0x10 .. $sp+0x6B */
    u8 *p = buf + 0x38;          /* $sp+0x48, passed to calls */
    u8 *q = buf + 0x58;          /* $sp+0x68, first call a0 */
    u8 v1;
    u8 v0;
    u8 w;
    u16 t2c;
    s32 c7  = 7;
    s32 cm7 = -7;
    s32 c3  = 3;
    s32 cm3 = -3;
    *(s16 *)(buf + 0x00) = c7;    /* 0x10 */
    *(s16 *)(buf + 0x10) = 0;     /* 0x20 */
    *(s16 *)(buf + 0x08) = 0;     /* 0x18 */
    *(s16 *)(buf + 0x18) = cm7;   /* 0x28 */
    *(s16 *)(buf + 0x0a) = c3;    /* 0x1A */
    *(s16 *)(buf + 0x1a) = 0;     /* 0x2A */
    *(s16 *)(buf + 0x02) = 0;     /* 0x12 */
    *(s16 *)(buf + 0x12) = cm3;   /* 0x22 */
    *(s16 *)(buf + 0x1c) = 0;     /* 0x2C */
    *(s16 *)(buf + 0x14) = 0;     /* 0x24 */
    *(s16 *)(buf + 0x0c) = 0;     /* 0x1C */
    *(s16 *)(buf + 0x04) = 0;     /* 0x14 */
    v1 = *(u8 *)((u8 *)arg0 + 0x30);
    *(s32 *)(buf + 0x30) = 0x50000000;  /* 0x40 */
    v0 = v1 >> 2;
    w  = v0 >> 2;
    *(u8 *)(buf + 0x2a) = v1;     /* 0x3A */
    *(u8 *)(buf + 0x26) = v1;     /* 0x36 */
    *(u8 *)(buf + 0x28) = v1;     /* 0x38 */
    *(u8 *)(buf + 0x24) = v1;     /* 0x34 */
    *(u8 *)(buf + 0x29) = v0;     /* 0x39 */
    *(u8 *)(buf + 0x25) = v0;     /* 0x35 */
    *(u8 *)(buf + 0x2c) = w;      /* 0x3C */
    *(u8 *)(buf + 0x20) = w;      /* 0x30 */
    *(u8 *)(buf + 0x2e) = w;      /* 0x3E */
    *(u8 *)(buf + 0x22) = w;      /* 0x32 */
    *(u8 *)(buf + 0x2d) = w;      /* 0x3D */
    *(u8 *)(buf + 0x21) = w;      /* 0x31 */
    t2c = *(u16 *)((u8 *)arg0 + 0x2c);
    *(u16 *)(q + 0x02) = t2c;  /* 0x6A */
    *(u16 *)(q + 0x00) = t2c;  /* 0x68 */
    func_80017DC4(q, p);
    func_80048EAC(arg1, p);
    *(s32 *)(buf + 0x4c) = (s32)*(s16 *)((u8 *)arg0 + 6);   /* 0x5C */
    *(s32 *)(buf + 0x50) = (s32)*(s16 *)((u8 *)arg0 + 0xa); /* 0x60 */
    *(s32 *)(buf + 0x54) = (s32)*(s16 *)((u8 *)arg0 + 0xe); /* 0x64 */
    func_80017758(buf + 0x00, p);
    *(s16 *)(buf + 0x00) = c3;    /* 0x10 */
    *(s16 *)(buf + 0x10) = 0;     /* 0x20 */
    *(s16 *)(buf + 0x08) = 0;     /* 0x18 */
    *(s16 *)(buf + 0x18) = cm3;   /* 0x28 */
    *(s16 *)(buf + 0x0a) = c7;    /* 0x1A */
    *(s16 *)(buf + 0x1a) = 0;     /* 0x2A */
    *(s16 *)(buf + 0x02) = 0;     /* 0x12 */
    *(s16 *)(buf + 0x12) = cm7;   /* 0x22 */
    func_80017758(buf + 0x00, p);
}
