/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801615C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146D90(s32 a0);
extern void func_8014CC28(s32 a0);
extern void func_8014ED28(s32 _arg0);
extern void func_8014FA04(s32 a0);
extern void func_8014ED28(s32 a0);
extern void func_80146D90(int);
extern void func_8014CC28(s32);
extern void func_8014FA04(s32);
extern void func_8014ED28();

s32 func_801615C4(void * arg0, s32 arg1)
{
    u32 acc;
    acc = 0;
    if (((arg1 & 1) == 0) && (((s32 (*)(void))func_8014ED28)() != 0)) {
        func_80146D90(arg0);
    }
    if (*(s32 *)((u8 *)arg0 + 0x34) > 0) {
        acc |= ((s32 (*)(s32))func_8014CC28)(arg0);
    }
    return acc | ((s32 (*)(s32))func_8014FA04)(arg0);
}
