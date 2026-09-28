/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801651B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80165240(void *param_1, void *param_2, void *param_3);
extern s32 D_80195200;

void func_801651B8(void * param_1)
{
    register s32 *puVar1 __asm__("$16");  
    register s32 iVar2 __asm__("$17");    
    register s32 p __asm__("$18");         

    p = param_1;
    ((s32 (*)(s32, s32, s32))func_80165240)(p, p + 0x2c, p + 0x50);
    iVar2 = 0;
    puVar1 = &D_80195200;
    do {
        if (puVar1[3] != 0) {
            s32 a0v = p;
            __asm__ __volatile__("" : "=r"(a0v) : "0"(a0v));
            ((s32 (*)(s32, s32, s32))func_80165240)(a0v, (s32)puVar1, (s32)(puVar1 + 2));
            puVar1[3] = puVar1[3] + -1;
        }
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 4;
    } while (iVar2 < 8);
}
