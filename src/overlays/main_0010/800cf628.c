/* Exact retail overlay 0010 export [800CF628,800CF714), offset 0x20830. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CF628 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_800B9A08;
extern s32 D_80127084;
extern s32 D_80114E94;
extern s32 D_80114E98;
extern s32 func_800CFC5C(s32 arg0);
extern s32 func_800CFBF8(void);
extern s32 func_800CFD68(s32 arg0);
extern void func_80011CFC(void);
extern void func_80011D54(s32 arg0);

void func_800CF628(void) {
    s16 *cli = &D_800B9A08;
    s32 arg;

    if (func_800CFC5C(*cli) != 0) {
        if (D_80127084 != 0) {
            D_80114E94 = *cli;
            *cli = func_800CFBF8();
        tail_CFC:
            func_80011CFC();
            return;
        }
        D_80114E94 = *cli;
        if (func_800CFD68(*cli = func_800CFBF8()) != 0) {
            goto tail_CFC;
        }
        *cli = D_80114E94;
        arg = 5;
        goto tail_D54;
    }
    D_80127084 = 0;
    if (func_800CFD68(*cli) != 0) {
        arg = 6;
        goto tail_D54;
    }
    D_80114E98 = 1;
    return;
tail_D54:
    func_80011D54(arg);
}
