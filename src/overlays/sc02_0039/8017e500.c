/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E500 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_80126CAC;
extern u8 D_8019B57C[];
void func_8017E024(s32 a0);
void func_8017E25C(s32 a0);
s32 func_8017E2F4(s32 a0, s32 a1);
extern void func_8017E024(s32 a0);
extern s32 func_8017E2F4(s32 a0, s32 a1);
extern void func_8017E25C(s32 a0);
extern u16 D_80126B96;
extern s16 D_80126B98;

void func_8017E500(s32 a0)
{
    s16 t;

    if (*(u16 *)(a0 + 0xFE) < 2) {
        t = *(u16 *)(a0 + 6) - D_80126CAC;
        if (t < 0)
            t = -t;
        if (t >= 0x801) {
            *(s32 *)(*(s32 *)(a0 + 0x20) + 4) |= 0x80000000;
        } else {
            func_8017E25C(a0);
            *(s32 *)(*(s32 *)(a0 + 0x20) + 4) &= 0x7FFFFFFF;
            func_8017E024(a0);
        }
    } else if (*(s32 *)(*(s32 *)(*(s32 *)(a0 + 0x64) + 0x20) + 4) < 0) {
        *(s16 *)(a0 + 0x5C) = 0;
    } else {
        *(u16 *)(a0 + 0x5C) |= 0x4400;
        func_8017E024(a0);
        if (*(s16 *)(a0 + 0xFE) == 3 && func_8017E2F4(a0, (s32)D_8019B57C)) {
            D_80126B96 = 0x4007;
            D_80126B98 = 0x20;
        }
        *(u8 *)(a0 + 0x102) = *(u8 *)(a0 + 0x74);
    }
}
