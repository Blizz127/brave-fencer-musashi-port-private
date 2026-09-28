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
