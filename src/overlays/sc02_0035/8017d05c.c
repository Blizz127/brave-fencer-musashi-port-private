/* SC02.CD member35 [8017D05C,8017D0F4): the same code as sc01_0000 8017D024
 * (src/overlays/sc01_0000/8017d024.c) with this scene's values (D_80126954 = 500, D_8012696A = 0x600)
 * and its init callback 8017D0F4; byte-identical to the sc02_0035 retail
 * words. Source of that file: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8012A018(s32 a0, s32 a1);
extern void func_8012A094(s32 a0);
extern void func_8017D0F4(void *a0);

void func_8017D05C(void) {

    extern s32 D_80126954;
    extern s32 D_8012695C;
    extern s16 D_80126968;
    extern s16 D_8012696A;
    extern s16 D_8012696C;
    extern s16 D_80126976;
    extern s16 D_80126978;
    extern s16 D_8012697A;
    extern u8 D_80126948[];
    D_80126954 = 0x1f4;
    D_8012695C = 0x4b0;
    D_80126968 = 0x2aa;
    D_8012696A = 0x600;
    D_8012696C = 0;
    D_80126976 = 0;
    D_80126978 = 0;
    D_8012697A = 0;
    func_8012A018((s32)func_8017D0F4, 0);
    func_8012A094((s32)D_80126948);
    func_8017D0F4(D_80126948);
}
