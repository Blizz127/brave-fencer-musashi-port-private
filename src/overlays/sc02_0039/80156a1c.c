/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80156A1C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern unsigned char D_8011520C[];
extern unsigned short D_801813D0[];

void func_80156A1C(s32 param_1, s32 param_2)
{
    if (*(unsigned char *)(param_1 + 0xDA) == 0) {
        func_80147324(D_801813D0[D_8011520C[param_2]]);
        *(unsigned char *)(param_1 + 0xDA) = *(unsigned char *)(param_1 + 0xDA) + 1;
    }
}
