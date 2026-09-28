/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80158F00 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
struct Actor;
struct Actor {
    char pad0[0x12];
    u16 timer;        
};
extern void func_80146CA0(void *a0);
extern s32 rand(void);
extern s32 D_8019FB2C;
extern int D_8019FB2C;
extern s32 D_8018146C[];
extern int rand(void);
extern s32 func_8013767C(s32 a0);

void func_80158F00(int param_1) {
    int *self = (int *)param_1;
    struct Actor *act = (struct Actor *)self[0x20 / 4];
    int gate = D_8019FB2C;

    act->timer = (u16)((act->timer + 0x16) & 0xfff);

    if (gate == 0) {
        s32 r = rand();
        *(s32 *)(param_1 + 0x198) = func_8013767C(D_8018146C[r % 0xb]);
        ((void (*)(int))func_80146CA0)(param_1);
    }
}
