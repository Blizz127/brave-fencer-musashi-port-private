/* Overlay range [8012F40C,8012F49C) from MAIN.CD member 0012.
 * SHA256(span)=97b3c4ff071d2c74b0b56b067efac4a96692735a2c711ea7ad9a37810a1eb6e7.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F40C - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotTransPers func_8004955C
extern s32 RotTransPers(s32, s32, s32 *, s32 *);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern u8 D_800AF648;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 RotTransPers(s32 a0, s32 a1, s32 *a2, s32 *a3);
void *param_2;
extern void func_8004914C();
extern void func_800491AC();
extern s32 RotTransPers(s32, s32, s32*, s32*);

s32 *func_8012F40C(s32 *param_1, s32 param_2) {
    extern u8 D_800AF648;
    s32 sxy, p, flag;
    sxy = 0;
    { register void *r4 __asm__("$4"); r4 = &D_800AF648; func_8004914C(r4); }
    { register void *r4 __asm__("$4"); r4 = &D_800AF648; func_800491AC(r4); }
    ((s32 (*)(s32, s32 *, s32 *, s32 *))RotTransPers)(param_2, &sxy, &p, &flag);
    if (flag < 0) {
        *param_1 = sxy = 0;
    } else {
        *param_1 = sxy;
    }
    return param_1;
}
