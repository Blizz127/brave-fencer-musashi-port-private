/* SC02 resident retail span [8016F1C4,8016F250). Offset 0x4706C at base 80128158.
 * SHA256(span)=0e36f5fa96313b0e86a8a2e89dcb60e1fcf55726661bbf7b3a331193d432d370.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_8016F1C4 shape (the two published variants differ only in the table symbol) retargeted to this member (D_8018804C table, D_800B9A08 location, D_80126B58 base); oracle MATCH 35/35.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F1C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_8018804C;
extern s32 D_80126B58;
extern s16 D_800B9A08;

s32 func_8016F1C4(void) {
    s32 *p;
    s32 cur;
    s32 loc;
    s32 v;
    s32 *base = &D_80126B58;

    p = &D_8018804C;
    cur = *p;
    if (cur != 0) {
        loc = D_800B9A08;
        p = p + 1;
        for (;;) {
            if (loc == cur) {
                return 1;
            }
            cur = *p;
            p = p + 1;
            if (cur == 0) {
                break;
            }
        }
    }
    v = base[0x7E];
    if (((v & 0x80FFFFFF) != 0) && ((v & 0x10000000) != 0)) {
        return 0;
    }
    return base[0x7E] & 0x80FFFFFF;
}
