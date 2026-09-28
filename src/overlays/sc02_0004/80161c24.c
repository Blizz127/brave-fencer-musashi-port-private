/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161C24 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_80147324();

void func_80161C24(int param_1, int param_2)
{

    extern unsigned short D_80180794[];
    extern unsigned short D_80180796[];

    if ((unsigned int)param_2 < 8) {
        if (*(u8 *)(param_1 + 0xDA) != 0) {
            func_80147324(D_80180794[(unsigned int)param_2 * 2]);
            *(u8 *)(param_1 + 0xDA) = 0;
        } else {
            func_80147324(D_80180796[(unsigned int)param_2 * 2]);
            *(u8 *)(param_1 + 0xDA) = 1;
        }
    }
}
