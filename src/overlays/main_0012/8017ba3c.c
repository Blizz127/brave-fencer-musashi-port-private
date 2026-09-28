/* Overlay range [8017BA3C,8017BB34) from MAIN.CD member 0012.
 * SHA256(span)=de7512b49dff2cc5f18fc05daf74ebd3647fb755a8a4b2906992e5a9e5fe8d51.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017BA3C - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotTransSV func_8004945C
typedef struct { s16 a, b, c, d; } SV4;
typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} MTX;
extern void func_80049CAC(s32 a0, s32 a1);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern void func_8004914C(void *);
extern void func_800491AC(void *);
extern void func_80049CAC();
extern void func_8004914C(void *a0);
extern void func_800491AC(void *a0);
extern void RotTransSV(s32 a0, s32 a1, void *a2);
extern void func_8004914C();
extern void func_800491AC();
extern void RotTransSV(s32, s32, void*);

void func_8017BA3C(s32 param_1, s32 param_2)
{

    extern SV4 D_8018536C;
    extern SV4 D_80185374;
    SV4 v0;             
    MTX mtx;            
    SV4 v1;             
    SV4 svec;           
    SV4 buf1;           
    SV4 buf2;           

    func_8012F214(param_1, param_2, (s32)&svec);
    D_8018536C = svec;

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

    ((void (*)(void *, void *, void *))RotTransSV)(&v1, &buf1, &buf2);
    D_80185374 = buf1;
}
