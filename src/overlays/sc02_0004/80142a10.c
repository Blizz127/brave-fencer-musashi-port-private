/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80142A10 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_801270C0;
extern void func_80142A80(void);

void func_80142A10(int param_1)
{

    extern void (*D_8017F3D8[])();
    if (*(s16 *)&D_801270C0 != 3) {
        D_8017F3D8[*(u16 *)(param_1 + 2)]();
        if (*(s16 *)(param_1 + 0xFC) != 0) {
            ((void (*)(int))func_80142A80)(param_1);
        }
    }
}
