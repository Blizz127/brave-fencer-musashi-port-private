/* SC02.CD member35 [80158F00,80158FA4): twin of main_0012 80158F00 (src/overlays/main_0012/80158f00.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [80158F00,80158FA4) from MAIN.CD member 0012.
 * SHA256(span)=e7ffd0059d4b96ceba056464a699b4e19d80847969872df5b150a4ea6671f6e2.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80158F00 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
struct Actor;
struct Actor {
    char pad0[0x12];
    u16 timer;        
};
extern s32 func_8013767C(s32 a0);
extern s32 rand(void);
extern void func_80146CA0(void *a0);
extern int rand(void);

void func_80158F00(int param_1) {

    extern s32 D_801BD77C;
    extern s32 D_80186840[];
    int *self = (int *)param_1;
    struct Actor *act = (struct Actor *)self[0x20 / 4];
    int gate = D_801BD77C;

    act->timer = (u16)((act->timer + 0x16) & 0xfff);

    if (gate == 0) {
        s32 r = rand();
        *(s32 *)(param_1 + 0x198) = func_8013767C(D_80186840[r % 0xb]);
        ((void (*)(int))func_80146CA0)(param_1);
    }
}
