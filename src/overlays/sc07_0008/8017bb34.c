/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017BB34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s16 a, b, c, d; } SV4;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MTX_8017BB34;
typedef struct { s16 a, b, c, d; } SV4_8017BB34;
extern void func_8012A568(void (*a0)(void));
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void func_8004945C(void *a0, void *a1, void *a2);
extern SV4 D_80196554;
extern SV4 D_8019655C;

s32 func_8017BB34(s32 param_1, s32 param_2)
{
    SV4_8017BB34 v0;            /* sp+0x10 : func_80049CAC arg0 */
    MTX_8017BB34 mtx;           /* sp+0x18 : MATRIX_L48, t[] at sp+0x2c */
    SV4_8017BB34 v1;            /* sp+0x38 : func_8004945C arg0 */
    SV4_8017BB34 svec;          /* sp+0x40 */
    SV4_8017BB34 buf1;          /* sp+0x48 : func_8004945C arg1 (-> (*(SV4_8017BB34*)&D_8019655C)) */
    SV4_8017BB34 buf2;          /* sp+0x50 : func_8004945C arg2 */

    svec = *(SV4_8017BB34 *)param_2;
    (*(SV4_8017BB34*)&D_80196554) = svec;

    v0.a = -*(s16 *)(param_2 + 0xc);
    v0.b = *(u16 *)(param_2 + 8);
    v0.c = 0;
    v1.a = 0;
    v1.b = 0;
    v1.c = -*(s16 *)(param_2 + 0xa);
    ((void (*)(void *, void *))func_80049CAC)(&v0, &mtx);

    mtx.t[0] = (s32)svec.a;
    mtx.t[1] = (s32)svec.b;
    mtx.t[2] = (s32)svec.c;
    func_8004914C(&mtx);
    func_800491AC(&mtx);

    func_8004945C(&v1, &buf1, &buf2);
    (*(SV4_8017BB34*)&D_8019655C) = buf1;
}
