/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013373C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801BD608;
extern s32 D_801BD60C[];
extern void func_80136BC4(s32 a0);
extern void func_80136BC4(s32);

void func_8013373C(s16 arg0) {
    s32 temp = D_801BD60C[arg0];
    if (temp != 0) {
        D_801BD608 = temp;
        func_80136BC4(temp);
    }
}
