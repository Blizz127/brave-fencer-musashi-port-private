/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A0A98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A3B08(s32 a0);
extern void func_801A3180(s32 a0, s32 a1);
extern void func_801A3B18(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern u16 D_8019FF8A;
extern void func_8012A828(s32 a0, void *a1);
extern s32 D_801EEAC8;
extern s16 D_801F8714;
extern void func_8012B200(u8 *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_801A4328(s32 a0);
extern void func_8017F418(void);
extern void func_801A36A8(s32 a0);
extern s32 func_8012B8A4(s16 *a0);
extern void func_801A3624(s32 a0, u16 *a1, s32 a2);

void func_801A0A98(s32 arg0)
{
    s32 v0;
    s32 v1;

    switch (*(u16 *)(arg0 + 0x34)) {
    case 0:
        if (*(s16 *)(arg0 + 0x98) != 0) {
            break;
        }
        *(s32 *)(arg0 + 0x1C) = 0x100;
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        func_801A3B08(arg0);
        break;
    case 1:
        func_801A3180(arg0, 0x280);
        if (*(s32 *)(arg0 + 0x1C) < 0xF0) {
            func_801A3B18(arg0);
        }
        if (func_8012BEE8(arg0) == 0) {
            break;
        }
        v1 = *(u16 *)(arg0 + 0x34) + 1;
        D_8019FF8A |= 0x100;
        *(u16 *)(arg0 + 0x34) = v1;
        break;
    case 2:
        if (D_8019FF8A & 2) {
            break;
        }
        func_8012A828(arg0, &D_801EEAC8);
        *(s32 *)(arg0 + 0x1C) = (s16)(D_801F8714 / 79) + 0x18;
        func_8012B200((u8 *)arg0);
        func_8012AD44((s32 *)arg0, 1);
        func_801A4328(0);
        func_8017F418();
        v0 = D_8019FF8A & 0xFF7F;
        v1 = *(u16 *)(arg0 + 0x5C) | 0x2000;
        D_8019FF8A = v0;
        *(u16 *)(arg0 + 0x5C) = v1;
        break;
    }
    func_801A36A8(arg0);
    v0 = func_8012B8A4((s16 *)arg0);
    *(s16 *)(arg0 + 0xFE) = v0;
    func_801A3624((s16)v0, (u16 *)(*(s32 *)(arg0 + 0x20) + 0x12), 0x40);
}
