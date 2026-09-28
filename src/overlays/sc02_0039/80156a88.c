/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80156A88 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 arg0);
extern s32 func_8014CA14(s32 a0, s32 a1);
extern s32 func_8014CA88(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern s32 D_801151E0[];
extern s32 D_801150E0[];

void func_80156A88(s32 a0, s32 a1) {
    s32 v1 = *(s32 *)(a1 + 0xC);
    s32 s3 = v1 & 0xF0FFFFFF;
    s32 s5, s4;
    s32 *s0;
    s32 *s1;
    u32 s2;
    if (v1 == 0x80000000) {
        return;
    }
    s2 = 0;
    s5 = v1 & 0x1000000;
    s4 = v1 & 0x2000000;
    s0 = D_801150E0;
    s1 = D_801151E0;
    do {
        if (*s1 & 1) {
            if (s5 != 0) {
                func_80147324(s3 & 0xFFFF);
            } else if (s4 != 0) {
                func_8014CA88((s32 *)*s0, s3);
            } else {
                func_8014CA14(*s0, s3);
            }
        }
        s0++;
        s2++;
        s1++;
    } while (s2 < 3);
}
