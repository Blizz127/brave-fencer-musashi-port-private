/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801CBBDC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80178CBC(s32*, s32);
extern void func_80178CBC(s32 *a0, s32 a1);
extern short D_801CC950;

void func_801CBBDC(void *a0) {
        *(short *)((char *)a0 + 0x2) = 0xE;
        func_80178CBC(a0, &D_801CC950);
    }
