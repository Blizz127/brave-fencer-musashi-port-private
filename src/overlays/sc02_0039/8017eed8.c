/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017EED8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012B2CC(s32 a0);
extern void func_8012B2CC(s32);
extern u16 D_80126B96;
extern s16 D_80126B98;

void func_8017EED8(s32 a0in) {
    extern s32 D_8019B618[];
    extern void func_8012B2CC(s32 a0);
    extern s32 func_8017EF5C(s32 a0, s32 a1);
    extern u16 D_80126B96;
    extern s16 D_80126B98;
    register s32 param_1 __asm__("$16");
    register s32 s1 __asm__("$17");

    param_1 = a0in;
    s1 = D_8019B618[*(s16 *)(param_1 + 0x102)];
    if (s1 != 0) {
        ((void (*)(void))func_8012B2CC)();
        if (func_8017EF5C(param_1, s1) != 0) {
            D_80126B96 = *(u16 *)(s1 + 4);
            D_80126B98 = *(s16 *)(s1 + 6);
        }
    }
}
