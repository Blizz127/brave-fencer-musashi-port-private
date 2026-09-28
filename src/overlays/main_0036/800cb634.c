/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB634 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 func_80146CA0(void *a0);
extern void func_80146E90(s32 *, s32);
extern s32 func_80146CA0(void *);
extern int rand(void);
extern void func_800CB774(void);
extern void func_8014659C(void);
extern void func_8001CA1C(void *a0, void *a1);
extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
extern void func_80146E90(s32 *a0, s32 a1);
typedef struct { s32 vx, vy, vz; } V3_800CB634;

void func_800CB634(void *a0) {

    extern V3_800CB634 D_800CBFA0[];
    void *s1;
    s32 vx;
    s32 vy;
    s32 vz;

    s1 = (void *)((s32 (*)(void))func_8014659C)();
    *(s32 *)((s32)a0 + 0x20) = (s32)s1;

    if (s1 != ((void *)0) ) {
        func_8001CA1C(s1, &D_800CBFA0[*(s32 *)((s32)a0 + 0x50)]);

        vx = ((rand() & 0x3f) - 0x20) << 15;
        vy = ((rand() & 0x3f) - 0x20) << 15;
        vz = -(((rand() & 0x1f) + 0x10) << 15);
        func_80146DE8((s32 *)a0, vx, vz, vy);

        func_80146E90((s32 *)a0, 0x40);
        func_80146CA0(a0);
    } else {
        ((void (*)(void *))func_800CB774)(a0);
    }
}
