/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80166F58 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern s32 D_8011D030;
extern void func_80146C3C();

s32 func_80166F58(s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
     


    extern s32 D_8011D030;
    extern unsigned char D_8019FCB0[];

    register int p2 __asm__("$20");              
    register int p3 __asm__("$17");              
    register int t2 __asm__("$5");               
    register int t3 __asm__("$6");               
    unsigned short *puVar1;
    short iVar2;
    int eq;

    iVar2 = 0;
    puVar1 = ((unsigned short *)&D_8011D030);
    t2 = ((short)param_2); __asm__("" : "=r"( t2 ) : "0"( t2 )) ; p2 = t2; __asm__("" : "=r"( p2 ) : "0"( p2 )) ;
    t3 = ((short)param_3); __asm__("" : "=r"( t3 ) : "0"( t3 )) ; p3 = t3;
    eq = (p2 == p3);
    do {
        if ((puVar1 != ((unsigned short *)param_1)) &&
            ((unsigned int)*puVar1 == p2 || (unsigned int)*puVar1 == p3) &&
            (!eq ||
             *(int *)(puVar1 + 0x16) == *(int *)(((unsigned short *)param_1) + 0x16))) {
            ((void(*)(unsigned short *))func_80146C3C)(puVar1);
        }
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 0x2c;
    } while (iVar2 < 0x1e);
    ((void(*)(void *, int))func_80016714)(&D_8019FCB0[((short)param_4) * 0xc4], 0xc4);
}
