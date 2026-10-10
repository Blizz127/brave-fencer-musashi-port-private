/* Overlay range [8017BB34,8017BC38) from MAIN.CD member 0012.
 * SHA256(span)=69dc3b6b1522fd11b4bef4ceb5874543b0bb2f73163b7557e1db3b3ad797f01e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017BB34 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotTransSV func_8004945C
typedef struct { s16 a, b, c, d; } SV4;
typedef struct { s16 m[3][3]; s16 pad; s32 t[3]; } MTX_8017BB34;
typedef struct { s16 a, b, c, d; } SV4_8017BB34;
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern void func_80049CAC();
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void RotTransSV(s32 a0, s32 a1, void *a2);
extern void func_8004914C();
extern void func_800491AC();
extern void RotTransSV(s32, s32, void*);

s32 func_8017BB34(s32 param_1, s32 param_2)
{

    extern SV4 D_801A5694;
    extern SV4 D_801A569C;
    SV4_8017BB34 v0;             
    MTX_8017BB34 mtx;            
    SV4_8017BB34 v1;             
    SV4_8017BB34 svec;           
    SV4_8017BB34 buf1;           
    SV4_8017BB34 buf2;           

    svec = *(SV4_8017BB34 *)param_2;
    (*(SV4_8017BB34*)&D_801A5694) = svec;

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

    RotTransSV(&v1, &buf1, &buf2);
    (*(SV4_8017BB34*)&D_801A569C) = buf1;
}
