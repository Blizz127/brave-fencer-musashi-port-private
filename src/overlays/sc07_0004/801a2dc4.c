/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A2DC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_8019FF8A;
extern s16 D_801F8714;
extern void func_8016AA50(s32 a0, s32 a1);
extern void func_8016B3F4(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_801A2DC4(s32 arg0) {
    s32 var;
    register s16 cae __asm__("$2");
    register u16 c76 __asm__("$2");
    register u16 t5c __asm__("$2");
    register u16 dv __asm__("$3");

    var = arg0;
    cae = -1;
    *(s16 *)(var + 0xAE) = cae;
    c76 = 0x800;
    *(u16 *)(var + 0x76) = c76;
    t5c = *(volatile u16 *)(var + 0x5C);
    *(u8 *)(var + 0xC1) = 0;
    dv = D_8019FF8A;
    *(u16 *)(var + 0x5E) = 0;
    t5c = t5c & 0xFFFE;
    dv = dv | 0x400;
    *(u16 *)(var + 0x5C) = t5c;
    D_8019FF8A = dv;
    func_8016AA50(arg0, 0x27A);

    if (D_801F8714 != 0) {
        D_801F8714 -= 0x27A;
        if (D_801F8714 < 0) {
            D_801F8714 = 0;
        }
    }

    *(u16 *)(arg0 + 0x7C) = *(u16 *)(arg0 + 6);
    *(u16 *)(arg0 + 0x7E) = *(u16 *)(arg0 + 0xA) + *(u16 *)(arg0 + 0x52);
    *(u16 *)(arg0 + 0x80) = *(u16 *)(arg0 + 0xE);
    func_8016B3F4(arg0);
    func_8002D4C8(0xB4C, 0);
}
