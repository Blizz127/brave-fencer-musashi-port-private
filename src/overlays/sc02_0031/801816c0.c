/* SC02 resident image [801816C0,80181868) at overlay base 0x80128158.
 * SHA256(span)=1d617a29c8be3043ecc32cbb6ed0445a08d3d61fe6ead521946cff70bd0f1482.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801816C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u16 D_80126B5E;
extern u16 D_80126B66;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80132EF4(s32 a0, s32 a1);
extern void func_80129374(s32 a0, s32 a1);
extern s32 func_801818A4(void *a0, void *a1);
extern s32 D_80188DD8;
extern u16 D_80126B96;
extern s16 D_80126B98;

void func_801816C0(s32 a0) {
    s32 counter;
    s16 diff1;
    s16 diff2;
    s32 ent;
    u16 *p96;

    counter = *(s32 *)(a0 + 0x1C) + 1;
    *(s32 *)(a0 + 0x1C) = counter;
    if ((counter & 0x20) == 0) {
        diff1 = D_80126B5E - *(u16 *)(a0 + 6);
        if (diff1 < 0) {
            diff1 = -diff1;
        }
        if (diff1 < 0x201) {
            diff2 = D_80126B66 - *(u16 *)(a0 + 0xE);
            if (diff2 < 0) {
                diff2 = -diff2;
            }
            if (diff2 < 0x281) {
                if ((counter & 0x1F) == 0) {
                    func_8002D4C8(0x5A8, ((0x7F - ((diff1 * diff1 + diff2 * diff2) * 0x50) / 0xA4000) | 0x1000) & 0xFFFF);
                }
                if ((*(u32 *)(a0 + 0x1C) & 1) != 0) {
                    ent = func_80132EF4(a0, 0x22);
                    if (ent != 0) {
                        func_80129374(ent, a0);
                        *(s16 *)(*(s32 *)(ent + 0x20) + 0x18) = 0x3000;
                        *(s16 *)(*(s32 *)(ent + 0x20) + 0x1A) = 0x3000;
                    }
                }
                if ((*(s32 *)(a0 + 0x1C) & 0x1F) > 7) {
                    ent = func_801818A4((void *)a0, &D_80188DD8);
                    if (ent != 0) {
                        p96 = &D_80126B96;
                        D_80126B98 = 0xC;
                        *p96 |= 0x4000;
                    }
                }
            }
        }
    }
}
