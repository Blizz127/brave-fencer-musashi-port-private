/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80174824 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8016EDEC(s32 _arg0, s32 _arg1, s32 _arg2);
extern s32 func_80174888(void *a0);

void func_80174824(void) {
    ((void (*)(void *, s32))func_8016EDEC)((void *)func_80174888, 0x1000000);
}
