/* Overlay range [8012F49C,8012F568) from MAIN.CD member 0012.
 * SHA256(span)=b48f1cb83ceaedd705135e532b0fef235821a4da7fe5a1fb065b1a8c2a3b8d03.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F49C - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotTransPers func_8004955C
#define RotTransSV func_8004945C
extern s32 RotTransPers(s32, s32, s32 *, s32 *);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern u8 D_800AF648;
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern s32 RotTransPers(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void RotTransSV(s32 a0, s32 a1, void *a2);
extern void func_8004914C();
extern void func_800491AC();
extern s32 RotTransPers(s32, s32, s32*, s32*);

s32 *func_8012F49C(s32 *param_1, s32 param_2, s32 param_3) {
    extern u8 D_800AF648;
    s16 sv[4];
    s32 out[2];
    s32 sxy, p, flag;
    s32 m;
    void *pv;
    m = *(s32 *)(param_2 + 0x20) + 0x34;
    ((void (*)(s32))func_8004914C)(m);
    ((void (*)(s32))func_800491AC)(m);
    pv = (void *)sv;
    ((void (*)(s32, void *, s32 *))RotTransSV)(param_3, pv, &out[0]);
    sxy = 0;
     

    { register void *r4 __asm__("$4"); r4 = &D_800AF648; func_8004914C(r4); }
    { register void *r4 __asm__("$4"); r4 = &D_800AF648; func_800491AC(r4); }
    ((s32 (*)(void *, s32 *, s32 *, s32 *))RotTransPers)(pv, &sxy, &p, &flag);
    if (flag < 0) {
        out[0] = sxy = 0;
    } else {
        out[0] = sxy;
    }
    *param_1 = out[0];
    return param_1;
}
