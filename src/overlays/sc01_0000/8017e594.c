/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E594 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char b[4]; } W;
extern u8 *D_800A5E60;
extern s16 D_800B9A02;
extern u8 D_800AA608[];

void func_8017E594(s32 arg0, s32 arg1, s32 arg2, u8 arg3)
{
    u8 *p;
    u32 *q;
    register u32 mlo __asm__("$10");
    register u32 mhi __asm__("$12");
    s32 h0;
    s32 frame_pad[2];

#define EMIT(TAG, UV, VY, W, H)                 \
    *(u8  *)(p + 0x03) = 5;                     \
    *(u32 *)(p + 0x04) = (TAG);                 \
    *(u8  *)(p + 0x0B) = 0x64;                  \
    *(u8  *)(p + 0x0A) = arg3;                  \
    *(u8  *)(p + 0x09) = arg3;                  \
    *(u8  *)(p + 0x08) = arg3;                  \
    *(s16 *)(p + 0x0C) = -0x80;                 \
    *(s16 *)(p + 0x0E) = 0;                     \
    *(u8  *)(p + 0x10) = 0;                     \
    *(u8  *)(p + 0x11) = (VY);                  \
    *(s16 *)(p + 0x12) = (UV);                  \
    *(s16 *)(p + 0x14) = 0xA0;                  \
    *(s16 *)(p + 0x16) = 0x20;                  \
    *(u8  *)(p + 0x0B) = 0x66;                  \
    *(s16 *)(p + 0x0E) = (W);                   \
    *(s16 *)(p + 0x14) = 0x100;                 \
    *(s16 *)(p + 0x16) = (H);

#define HEAD1()                                                             \
    *(u32 *)p = (*(u32 *)p & mhi) |                                  \
        (*(u32 *)&D_800AA608[(D_800B9A02 & 0xFFFF) << 14] & mlo);      \
    q = (u32 *)D_800AA608;

#define HEADN()                                                             \
    *(u32 *)p = (*(u32 *)p & mhi) |                                  \
        (*(u32 *)((s32)q + ((D_800B9A02 & 0xFFFF) << 14)) & mlo);

#define TAILL(TAIL)                                                         \
    {                                                                       \
    u32 *addrw;                                                             \
    u32 v1;                                                                 \
    u32 val;                                                                \
    addrw = (u32 *)((s32)q + ((D_800B9A02 & 0xFFFF) << 14));                \
    v1 = (u32)p & mlo;                                                 \
    val = *addrw;                                                           \
    TAIL;                                                                   \
    *addrw = (val & mhi) | v1;                                       \
    }

    (void)&frame_pad;

    h0 = arg0;
    p = D_800A5E60;

    EMIT(0xE100003E, 0x4097, 0x40, arg1 - arg0, h0)
    mlo = 0xFFFFFF;
    mhi = 0xFF000000;
    HEAD1()
    TAILL(p += 0x18)
    EMIT(0xE100005E, 0x4117, 0x90, arg1 - arg0, h0)
    HEADN()
    TAILL(p += 0x18)
    EMIT(0xE100003E, 0x4097, 0x5F - arg0, arg1, arg0 + 1)
    HEADN()
    TAILL(p += 0x18)
    EMIT(0xE100005E, 0x4117, -0x51 - arg0, arg1, arg0 + 1)
    HEADN()
    TAILL(p += 0x18)
    EMIT(0xE100003E, 0x4097, 0x60, arg2 - arg0, h0)
    HEADN()
    TAILL(p += 0x18)
    EMIT(0xE100005E, 0x4117, 0xB0, arg2 - arg0, h0)
    HEADN()
    TAILL(p += 0x18)
    EMIT(0xE100003E, 0x4097, 0x7F - arg0, arg2, arg0 + 1)
    HEADN()
    TAILL(p += 0x18)
    EMIT(0xE100005E, 0x4117, -0x31 - arg0, arg2, arg0 + 1)
    HEADN()
    TAILL(D_800A5E60 = (p += 0x18))
}
