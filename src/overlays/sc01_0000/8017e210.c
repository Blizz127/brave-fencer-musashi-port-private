/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E210 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 *D_800A5E60;
extern s16 D_800B9A02;
extern u8 D_800AA608[];

s32 func_8017E210(s32 arg0)
{
    u8 *p;
    register u32 *q __asm__("$8");
    register u32 mlo __asm__("$7");
    register u32 mhi __asm__("$9");
    s32 frame_pad[2];

#define EMIT_E210(TAG, UV, VY)                       \
    *(u8  *)(p + 0x03) = 5;                     \
    *(u32 *)(p + 0x04) = (TAG);                 \
    *(u8  *)(p + 0x0B) = 0x64;                  \
    *(u8  *)(p + 0x0A) = arg0;                  \
    *(u8  *)(p + 0x09) = arg0;                  \
    *(u8  *)(p + 0x08) = arg0;                  \
    *(s16 *)(p + 0x0C) = -0x50;                 \
    *(s16 *)(p + 0x0E) = -0x10;                 \
    *(u8  *)(p + 0x10) = 0;                     \
    *(u8  *)(p + 0x11) = (VY);                  \
    *(s16 *)(p + 0x12) = (UV);                  \
    *(s16 *)(p + 0x14) = 0xA0;                  \
    *(s16 *)(p + 0x16) = 0x20;                  \
    *(u8  *)(p + 0x0B) = 0x66;

#define HEAD1_E210()                                                            \
    *(u32 *)p = (*(u32 *)p & mhi) |                                        \
        (*(u32 *)&D_800AA608[(D_800B9A02 & 0xFFFF) << 14] & mlo);          \
    q = (u32 *)D_800AA608;

#define HEADN_E210()                                                            \
    *(u32 *)p = (*(u32 *)p & mhi) |                                        \
        (*(u32 *)((s32)q + ((D_800B9A02 & 0xFFFF) << 14)) & mlo);

#define TAILL_E210(TAIL)                                                        \
    {                                                                      \
    u32 *addrw;                                                            \
    u32 v1;                                                                \
    u32 val;                                                               \
    addrw = (u32 *)((s32)q + ((D_800B9A02 & 0xFFFF) << 14));               \
    v1 = (u32)p & mlo;                                                     \
    val = *addrw;                                                          \
    TAIL;                                                                  \
    *addrw = (val & mhi) | v1;                                             \
    }

    (void)&frame_pad;

    p = D_800A5E60;

    EMIT_E210(0xE100003E, 0x4017, 0)
    mlo = 0xFFFFFF;
    mhi = 0xFF000000;
    HEAD1_E210()
    TAILL_E210(p += 0x18)
    EMIT_E210(0xE100005E, 0x4057, 0x20)
    HEADN_E210()
    TAILL_E210(D_800A5E60 = (p += 0x18))
}
