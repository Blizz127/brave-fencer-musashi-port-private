/* SC02 resident image [8012A328,8012A418) at overlay base 0x80128158.
 * SHA256(span)=f2b6d56a500b4a422709470398fcb81a3f0b056297a4ff6cb8895ef507021207.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A328 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
        u8 pad[0x154];
        u16 f154;
        s16 f156;
        u16 f158;
    } Obj_80126B58;
extern s32 func_80012F74(s32, s32, s32, s32);

void func_8012A328(void)
{
    extern s8 D_801152C0;
    extern s16 D_801152C2;
    extern s16 D_80126940;
    extern s16 D_80126942;
    extern s16 D_80126944;
    extern s32 D_80126B58;
    extern s16 D_80127080;
    extern s16 D_80126CAE;
    Obj_80126B58 *p = (Obj_80126B58 *)&D_80126B58;
    s16 *q;
    s32 a, b;
    if (*(u8 *)&D_801152C0 != 0) {
        a = D_80127080; b = D_80126CAE;
        if (D_801152C2 < ((a - b) < 0 ? (b - a) : (a - b))) {
            q = &D_80126942;
            *q = func_80012F74(*q, p->f156, 4, 1);
        } else {
            q = &D_80126942;
            *q = func_80012F74(*q, D_80127080, 4, 1);
        }
    } else {
        s16 *r = &D_80126942;
        *r = func_80012F74(*r, D_80126CAE, 4, 1);
    }
    D_80126940 = p->f154;
    D_80126944 = p->f158;
}
