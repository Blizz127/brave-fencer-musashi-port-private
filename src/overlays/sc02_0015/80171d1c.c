/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80171D1C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146D90(s32 a0);
extern void func_80146D90(int);
extern void func_80146D90(s32);
extern int func_8017250C(short *a0, short *a1);
extern s32 func_80171FFC(short *a0, short *a1, s32 a2);

s32 func_80171D1C(void * a0, void * a1, s32 a2)
{
    s32 ret;
    ret = func_80171FFC(a0, a1, a2 & 0xFF);
    if (func_8017250C(a0, a1) != 0) {
        func_80146D90((s32)a0);
    }
    return ret;
}
