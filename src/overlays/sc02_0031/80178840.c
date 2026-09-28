/* SC02 resident retail span [80178840,801788B8). Offset 0x506E8 at base 80128158.
 * SHA256(span)=3491648a8073928ebe9d7e5df2b1b1a591c9310fa18925a9d7fbdff4d071550f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181BC4->D_801884B4; D_80181BD0->D_801884C0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178840 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80131E00 {
    char pad[0xB0];
    s32 field_B0;
};
extern void func_8012A568(void (*a0)(void));
extern void func_80019064(void *a0);
extern void func_80131E00(struct S80131E00 *a0, s32 a1);

void func_80178840(int param_1) {

    extern int D_801884B4;
    extern int D_801884C0[];
    register int p __asm__("$16");
    register int s1byte __asm__("$17");
    p = param_1;
    if ((*(unsigned short *)(p + 0x5c) & 1) != 0) {
        s1byte = *(unsigned char *)(p + 0x5e);
        if (s1byte == 0xc) {
            ((void (*)(int))func_80019064)((int)&D_801884B4);
        }
        ((void (*)(int, int))func_80131E00)(p, D_801884C0[s1byte]);
    }
}
