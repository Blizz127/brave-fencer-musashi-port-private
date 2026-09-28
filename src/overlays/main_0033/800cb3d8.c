/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3D8 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_800CB3D8(s32 arg0, s32 arg1) {
    extern void func_8012F14C(s32, s32, s32);
    extern void func_80015978(s32, s32 *);
    extern void func_80015954(s32, s32);
    extern s32 func_800CB4EC();

    struct S { s32 f[8]; };
    struct S st;
    s32 out1[2];
    u16 out2[3];
    u8 *ptr;
    s32 ret;

    ptr = *(u8 **)(arg0 + 0x20);
    func_80015978(arg0 + 4, out1);
    st = *(struct S *)*(s32 *)(ptr + 0x34);
    st.f[5] = 0;
    st.f[6] = 0;
    st.f[7] = 0;
    func_8012F14C((s32)&st, arg1, (s32)out2);
    *(u16 *)(arg0 + 6) += out2[0];
    *(u16 *)(arg0 + 0xA) += out2[1];
    *(u16 *)(arg0 + 0xE) += out2[2];
    ret = func_800CB4EC(arg0);
    func_80015954((s32)out1, arg0 + 4);
    return ret;
}
