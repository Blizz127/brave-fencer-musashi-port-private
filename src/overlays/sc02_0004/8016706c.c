/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016706C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8011D030;
extern void func_80146C3C();
extern void func_80146C3C(void);

void func_8016706C(s32 param_1)
{
    extern s32 D_8011D030;
    unsigned short *puVar1;
    short iVar2;
    iVar2 = 0;
    puVar1 = ((unsigned short *)&D_8011D030);
    do {
        if ((unsigned int)*puVar1 == ((short)param_1)) {
            ((void(*)(unsigned short *))func_80146C3C)(puVar1);
        }
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x2c;
    } while (iVar2 < 0x1e);
}
