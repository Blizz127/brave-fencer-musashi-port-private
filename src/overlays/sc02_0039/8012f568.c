/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012F568 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *memcpy(void *, const void *, unsigned int);
extern s16 D_80126B98;
extern s16 D_80126B9A;
extern void *memcpy(void *, const void *, u32);
extern u8 D_80126C38;
extern u8 D_80126C40;
extern u16 D_80126B94;
extern u16 D_80126B96;

void func_8012F568(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
    memcpy(&D_80126C38, param_5, 8);
    memcpy(&D_80126C40, param_6, 8);
    __asm__ __volatile__("" ::: "memory");
    D_80126B96 = param_2;
    D_80126B9A = param_3;
    D_80126B98 = param_4;
    D_80126B94 = D_80126B94 | param_1;
}
