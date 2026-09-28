/* SC02 resident retail span [8013D064,8013D13C). Offset 0x14F0C at base 80128158.
 * SHA256(span)=72cfadd27d6df89df093660e47e874bd8fa8b1ba0f07e5607e9291aa00e1b0b5.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801841B0->D_801B6368; D_801841BC->D_801B6374; D_801841C8->D_801B6380; D_801841CC->D_801B6384.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D064 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801B6380;
extern s32 D_801B6368;
extern s32 D_801B6384;
extern s32 D_801B6374;
extern void func_8013D9B0();

void func_8013D064(void)
{
    if (D_801B6380 != 0) {
        if (D_801B6380 != 2) {
            if (((D_801B6380 < 3) && (D_801B6380 == 1)) &&
                (D_801B6384 = D_801B6384 + 1, 0x23a < D_801B6384)) {
                D_801B6368 = D_801B6380;
                D_801B6380 = 2;
            }
        } else {
            D_801B6368 = D_801B6368 + -1;
            if (D_801B6368 == 0) {
                D_801B6368 = D_801B6380;
                ((void (*)(s32))func_8013D9B0)(2);
                if (D_801B6374 == 0) {
                    D_801B6380 = D_801B6380 + 1;
                }
            }
        }
    }
    return;
}
