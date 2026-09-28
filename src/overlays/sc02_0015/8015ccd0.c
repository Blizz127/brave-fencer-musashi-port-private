/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015CCD0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_80154150(s32 a0, s32 a1);
extern s32 func_801725E0(u8 *a0);

s32 func_8015CCD0(s32 param_1)
{
    func_80154150(param_1, 0x14);
    *(s16 *)(param_1 + 0xB8) = 0;
    func_801725E0((u8 *)param_1);
    *(s32 *)(param_1 + 0x234) = 0xF;
    func_80147324(0x6A7);
    func_80146CA0((void *)param_1);
}
