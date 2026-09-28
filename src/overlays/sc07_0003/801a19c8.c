/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A19C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80126B94;
extern s32 D_80126B58;
extern u16 D_801A6B94[];
extern u8  D_801A68FC[];
extern u8  D_801152A8[];
extern s32 D_80127078;
extern void func_8012EC04(s32 param_1, s32 param_2, s32 *param_3);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32  func_80013478(s32 a0, s32 a1);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);

s32 func_801A19C8(s32 arg0) {
    s32 buf[8];   /* 0x18(sp) - scratch handed to func_8012EC04/func_8012F14C */
    u16 out[4];   /* 0x38(sp) - the projected point both later calls func_8005CF28      */
    s32 i;
    s32 *m = &D_80126B58;   /* LEVER 3: entry-block `la`, used as m+1 == +4 */

    if (!(D_80126B94 & 0x8000)) {
        return 0;
    }

    for (i = 0; i < 2; i++) {
        u16 *o = out;       /* LEVER 2: first movable, eats threshold 29 -> 26 */
        func_8012EC04(arg0, D_801A6B94[i], buf);            /* LEVER 1 */
        func_8012F14C((s32)buf, (s32)&D_801A68FC[i * 0x10], (s32)o);
        if (func_80013478((s32)(m + 1), (s32)o) < 0x4001) {
            func_8012F568(1, 0x401C,
                *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12) & 0xFFF, 0x50,
                (s32)o, (s32)D_801152A8);
            D_80127078 = arg0;
            return 1;
        }
    }
    return 0;
}
