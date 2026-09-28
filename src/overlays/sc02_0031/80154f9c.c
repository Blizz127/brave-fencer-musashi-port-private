/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154F9C,801550FC).
 * Offset 0x2CE44 at overlay base 80128158. SHA256(span)=7edb80a446de4725cb4ed27ae63a05f67fd518039e25f4daf1286646ebc00846.
 * Shape from Druthulu shared/ov donor func_80154F9C.h (h_exact 9fb7a0c8); re-earned through the oracle on the retail blob:
 * 88/88 words at -O2 -G0.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154F9C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078E78[];
extern s16 D_80078E96;
extern s16 D_80078E9E;
extern u16 D_80078EA6;
extern u8 D_800D8D10[];
extern s32 func_8016F1AC(void);
extern void func_801550FC(s32 a0);

void func_80154F9C(s32 a0) {
    u8 *base = D_80078E78;
    if (*(s32 *)(a0 + 0xC8) & 0x1000000) {
        if ((D_80078E96 & 0x8000) || D_80078E9E < 0x10 || (s16)D_80078EA6 < 0x10) {
            if (func_8016F1AC() == 0) {
                return;
            }
        }
        *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) & 0xC0FFFFFF;
        func_801550FC(*(s32 *)(a0 + 0xC8));
    } else {
        if ((D_80078E96 & 0x8000) && func_8016F1AC() == 0) {
            *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) | 0x1000000;
            func_801550FC((s32)D_800D8D10);
            return;
        }
        if (!(*(s16 *)(base + 0x26) < 0x10) && !(*(s16 *)(base + 0x2E) < 0x10)) {
            return;
        }
        if (*(s32 *)(a0 + 0x44) & 0xC0) {
            return;
        }
        if (func_8016F1AC() != 0) {
            return;
        }
        *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) | 0x1000000;
        func_801550FC(0x40000002);
    }
}
