/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D418 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016EE40(s32 a0, s32 a1, s32 a2);
extern void func_8016EE40(s32 _arg0, s32 _arg1, s32 _arg2);

void func_8017D418(void) {

    extern s32 D_80181CC8(void *a0);
    ((void (*)(void *, s32))func_8016EE40)((void *)D_80181CC8, 0x1000000);
}
