/* SC02.CD member35 [801651B8,80165240): twin of main_0012 801651B8 (src/overlays/main_0012/801651b8.c); only the
 * global addresses differ. Byte-identical to the sc02_0035 retail words
 * (gcc-2.7.2 -O2, B28 inc 104 twin port). */
/* Overlay range [801651B8,80165240) from MAIN.CD member 0012.
 * SHA256(span)=387c6b9c6fd8f333e75d2585e224e32ecc0058c5a755e17bd1542811389f2492.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801651B8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80165240(void *param_1, void *param_2, void *param_3);

void func_801651B8(void * param_1)
{

    extern s32 D_801BD880;
    register s32 *puVar1 __asm__("$16");  
    register s32 iVar2 __asm__("$17");    
    register s32 p __asm__("$18");         

    p = param_1;
    ((s32 (*)(s32, s32, s32))func_80165240)(p, p + 0x2c, p + 0x50);
    iVar2 = 0;
    puVar1 = &D_801BD880;
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
