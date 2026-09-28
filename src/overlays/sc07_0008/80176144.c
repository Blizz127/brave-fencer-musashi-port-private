/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80176144 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 g0; s32 pad[2]; } S_AF634;
extern void func_8012A568(void (*a0)(void));

void func_80176144(s32 a0)
{
    extern S_AF634 aAF634[] __asm__("D_800AF634");
    extern S_AF634 aAF638[] __asm__("D_800AF638");
    extern u8  D_8011F7A8;
    extern s16 D_8011F7BC;
    extern s16 D_8011F7BE;
    extern s32 func_80178004();
    u32 *slot;
    u32 *p;
    s16 param_1 = (s16)a0;
    p = (u32 *)(aAF638[param_1].g0 + aAF634[param_1].g0 * 4);
    slot = (u32 *)(param_1 * 4 + (s32)&D_8011F7A8);
    slot[14] = (u32)p;
    __asm__("");
    p = (u32 *)func_80178004((s32)p,
                             (s16)((*(u16 *)&D_8011F7BC) - 0x17),
                             (s16)((*(u16 *)&D_8011F7BE) + 0x65));
    slot[16] = (u32)p - 0x14;
    p += 5;
    aAF634[param_1].g0 += ((s32)p - (s32)slot[14]) >> 2;
}
