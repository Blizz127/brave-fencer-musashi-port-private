/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158F00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

struct Actor {
    char pad0[0x12];
    u16 timer;       /* 0x12 */
};
extern s32 D_8019547C;
extern s32 D_8017F670[];
extern int func_8005C49C(void);
extern s32 func_8013767C(s32 a0);
extern void func_80146CA0(void *a0);

void func_80158F00(int param_1) {
    int *self = (int *)param_1;
    struct Actor *act = (struct Actor *)self[0x20 / 4];
    int gate = D_8019547C;

    act->timer = (u16)((act->timer + 0x16) & 0xfff);

    if (gate == 0) {
        s32 r = func_8005C49C();
        *(s32 *)(param_1 + 0x198) = func_8013767C(D_8017F670[r % 0xb]);
        ((void (*)(int))func_80146CA0)(param_1);
    }
}
