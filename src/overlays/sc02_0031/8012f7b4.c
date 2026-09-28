/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F7B4,8012F828).
 * Offset 0x765C at overlay base 80128158. SHA256(span)=9f91acef129877d32d6a36a57a0e5f88c5a16001d9af3cccf96f2e904637c1ac.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012f7b4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F7B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012BEE8(s32);
extern s32 func_80131A34(s32, s32);
extern void func_80131CA8(int a0, int a1);

void func_8012F7B4(s32 a0) {
    if (*(s32 *)(a0 + 0xB4) & 4) {
        func_8012BEE8(a0);
        if (*(s32 *)(a0 + 0x1C) == 1) {
            if (func_80131A34(a0, 8) == 0) {
                func_80131A34(a0, 0x20);
            }
        }
    }
    func_80131CA8(a0, 7);
}
