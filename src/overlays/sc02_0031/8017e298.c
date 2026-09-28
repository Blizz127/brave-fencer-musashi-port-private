/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E298 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct obj {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s32 unk8;
};
extern void func_8012A568(void (*a0)(void));
extern s32 func_80146E98(s32 a0);
extern void func_80162CCC(void);

void func_8017E298(s32 arg0) {
    s32 tbl;
    s32 obj;
    u16 t1;
    u16 t2;

    tbl = *(s32 *)(arg0 + 0x4C);
    obj = *(s32 *)(arg0 + 0x20);
    if (func_80146E98(arg0) != 0) {
        t1 = *(u16 *)(obj + 0x1C) + 0x400;
        *(s16 *)(obj + 0x1C) = t1;
        *(s16 *)(obj + 0x18) = t1;
        if ((s16)t1 >= 0x7001) {
            *(s16 *)(obj + 0x1C) = 0x7000;
            *(s16 *)(obj + 0x18) = 0x7000;
        }
        t2 = *(u16 *)(obj + 0x1A) + 0x100;
        *(s16 *)(obj + 0x1A) = t2;
        if ((s16)t2 >= 0x7001) {
            *(s16 *)(obj + 0x1A) = 0x7000;
        }
    }
    if (*(u16 *)tbl != 0x16) {
        ((void (*)(s32))func_80162CCC)(arg0);
    }
}
