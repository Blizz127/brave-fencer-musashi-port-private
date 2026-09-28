/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D0BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct Ent_8017BFE0_8017D0BC {
    u8  pad00[2];   /* 0x00 */
    u16 f02;        /* 0x02 */
    u8  pad04[0x18];/* 0x04 */
    s32 f1c;        /* 0x1C */
    u8  pad20[0xA]; /* 0x20 */
    u16 f2a;        /* 0x2A */
    u16 f2c;        /* 0x2C */
    u8  pad2e[2];   /* 0x2E */
    s32 f30;        /* 0x30 */
} Ent_8017BFE0_8017D0BC;
extern void func_80147324(s32 arg0);
extern void func_8017D2F4(int);

void func_8017D0BC(Ent_8017BFE0_8017D0BC *param_1)
{
    s32 t;

    t = param_1->f1c;
    param_1->f1c = t + 1;
    if (t < 0x20) {
        param_1->f2a = param_1->f2a - 0x10;
    } else {
        if (param_1->f30 == 0) {
            func_80147324(param_1->f2c);
        }
        param_1->f1c = 0;
        param_1->f02 = param_1->f02 + 1;
    }
    ((void (*)(Ent_8017BFE0_8017D0BC *))func_8017D2F4)(param_1);
}
