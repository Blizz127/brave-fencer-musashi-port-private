/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D07C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s16 v[4];
} Blk8_80126940_8017D07C;
extern void func_8012A568(void (*a0)(void));
extern u16 func_80148800(s32 *a0);
extern void func_8017D11C(s32 param_1, s16 *param_2);

void func_8017D07C(s32 a0) {

    extern s32 D_80126B58;
    extern s16 D_80180D74[];
    extern Blk8_80126940_8017D07C D_80126940;
    Blk8_80126940_8017D07C sp10;
    u8 t;

    if (func_80148800(&D_80126B58) & 3) {
        t = (*(u8 *)(a0 + 5) + 1) & 1;
        *(u8 *)(a0 + 5) = t;
        *(s32 *)(a0 + 0x14) = D_80180D74[t];
    }
    sp10 = D_80126940;
    func_8017D11C(a0, sp10.v);
}
