/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173BC0,80173C64).
 * Offset 0x4BA68 at overlay base 80128158. SHA256(span)=f137d66342a9f8ca52024cabf7f88fdc6e38de73d7a145a6bf313a09b5fc1ecc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173bc0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173BC0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct S80126B38 { s32 a; s32 b; } __attribute__((packed));
extern void func_8012A568(void (*a0)(void));
extern s16 D_80126B3A;
extern struct S80126B38 D_80126B38;
extern s16 D_8011F9C8;
extern s32 func_800D0EC4(void);
extern void func_8013E588(void*);
extern s32 func_80174650(s32);
extern void func_80171A34(s32 *a0, s8 a1);
extern void func_80171A1C(u8 *a0);

void func_80173BC0(u8* a0)
{
    s32 v = D_80126B3A;
    if (v != 0 && v < 0x6F && func_800D0EC4() == 0) {
        if ((*(s16 *)&D_80126B38) & 0x8000) {
            ((void (*)(void))func_8013E588)();
        } else {
            func_80174650((s32)a0);
            D_8011F9C8 = 2;
            func_80171A34(a0, 7);
            return;
        }
    }
    func_80171A1C((u8 *)a0);
}
