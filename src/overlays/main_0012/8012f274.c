/* Overlay range [8012F274,8012F2E8) from MAIN.CD member 0012.
 * SHA256(span)=3dfc69ad580b53b6764763984806992d397abf51c95bada83ebe37a5ad49a6ce.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F274 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotTransSV func_8004945C
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void RotTransSV(s32 a0, s32 a1, void *a2);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015954(s32 a0, s32 a1);
static inline void tail_8012F274(s32 *in, s32 e) {
    s32 out[2];
    s32 flag[2];
    ((void (*)(s32 *, s32 *, s32 *))RotTransSV)(in, out, flag);
    ((void (*)(s32 *, s32))func_80015954)(out, e);
}

void func_8012F274(s32 a0, s32 a1) {
    s32 v[2];
    s32 p;
    func_80015978(a1, v);
    p = *(s32 *)(a0 + 0x20) + 0x34;
    func_8004914C((void *)p);
    func_800491AC((void *)p);
    tail_8012F274(v, a1);
}
