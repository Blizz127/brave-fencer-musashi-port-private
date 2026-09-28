/* Complete SC02 state-0 body; independently matched ordinary C. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181BB4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80181EF0(void);
extern void func_80181DEC();
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012AD50(void *a0);
extern u8 D_801B7840[];

void func_80181BB4(void *a0) {
    s32 i;
    u8 *p;

    if (func_80181EF0() == 0) {
        return;
    }

    p = D_801B7840;
    for (i = 0; i < 10; i++) {
        func_80181DEC((s32)p, i);
        p += 0x18;
    }

    func_8002D4C8(0x83E, 0);
    func_8012AD50(a0);
}
