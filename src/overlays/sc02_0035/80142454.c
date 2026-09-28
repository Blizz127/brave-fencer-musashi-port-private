/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80142454 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012C51C(void *a0, s32 a1);
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;

void func_80142454(s32 a0) {
    s32 s0 = a0;
    u16 *s1 = &D_80126B5E;
    s32 ret;
    s16 st[10];
    st[3] = 0x13;
    st[0] = *s1;
    st[1] = D_80126B62;
    st[2] = D_80126B66;
    st[4] = 1;
    st[5] = 0;
    st[7] = 0;
    *(s32 *)&st[8] = 0;
    ret = ((s32 (*)(void *, s32))func_8012C51C)(st, 0);
    if (ret != 0) {
        *(s16 *)(ret + 0x52) = s0;
        *(s32 *)(ret + 0x64) = (s32)s1 - 6;
    }
}
