/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015309C - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80146CA0(void *a0);
void func_8014CC28(s32 a0);
void func_8014E934(s32 _arg0);
s32 func_8014F3E8(s32 param_1);
extern void func_8014E934(s32 a0);
extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_801530E4(s32 a0);

void func_8015309C(s32 a0) {
    func_8014E934(a0);
    func_8014CC28(a0);
    func_8014F3E8(a0);
    func_801530E4(a0);
    func_80146CA0((void *)a0);
}
