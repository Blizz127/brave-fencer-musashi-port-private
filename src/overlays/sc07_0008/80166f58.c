/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80166F58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(void *a0, s32 a1);
extern void func_80146C3C();
#define SHB(x) __asm__("" : "=r"(x) : "0"(x))

s32 func_80166F58(s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    /* [T51] scoped in from file scope: a file-scope decl of these symbols constrains every
       LATER function in this TU, which blocks a byte-true decl of a different type.
       Declaration-only move (cookbook §103); the whole-binary byte-gate is the arbiter. */
    extern s32 D_8011D030;
    extern unsigned char D_80195600[];

    register int p2 __asm__("$20");             /* $s4 */
    register int p3 __asm__("$17");             /* $s1 */
    register int t2 __asm__("$5");              /* a1 */
    register int t3 __asm__("$6");              /* a2 */
    unsigned short *puVar1;
    short iVar2;
    int eq;

    iVar2 = 0;
    puVar1 = ((unsigned short *)&D_8011D030);
    t2 = ((short)param_2); SHB(t2); p2 = t2; SHB(p2);
    t3 = ((short)param_3); SHB(t3); p3 = t3;
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
    ((void(*)(void *, int))func_80016714)(&D_80195600[((short)param_4) * 0xc4], 0xc4);
}
