/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80139954 - byte-exact against retail at -O2 (tools/register_match.py). */
extern int D_801269F0;
extern s16 D_801269F4;
extern void func_8013A8B0(s32 *a0);
extern u16 D_80126A08;
extern s32 D_801269F0;
extern s32 *D_80126A30;

void func_80139954(void) {
    u16 v = D_80126A08;
    D_801269F4 = 0;
    D_801269F0 = 0;
    if (v != 0) {
        if (D_80126A30 != 0) {
            func_8013A8B0(D_80126A30);
        }
    }
}
