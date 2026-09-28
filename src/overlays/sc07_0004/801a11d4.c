/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A11D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_801830D8(s32 a0);
extern void func_8013C9C4(void *a0);
extern s32 D_80186F44;
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern s32 D_801EEAC8;
extern s16 D_801F8714;
extern void func_8012B200(u8 *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern void func_801A4328(s32 a0);
extern void func_8017F418(void);

void func_801A11D4(s32 arg0) {
    switch (*(u16 *)(arg0 + 0x34)) {
    case 0:
        *(u16 *)(arg0 + 0xA) -= 8;
        if (*(s32 *)(arg0 + 0x94) == 0x1A) {
            *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        }
        break;
    case 1:
        *(u16 *)(arg0 + 0xA) -= (0x1F - *(s32 *)(arg0 + 0x94)) * 2;
        if (*(s32 *)(arg0 + 0x94) == 0x1E) {
            *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
            func_8002D4C8(0xBA6, 0);
        }
        break;
    case 2:
        if (*(s32 *)(arg0 + 0x94) == 0x28) {
            *(u16 *)(arg0 + 0x98) = 0;
        }
        if (*(s16 *)(arg0 + 0xA) < -0x200) {
            *(s16 *)(arg0 + 0xA) = *(s16 *)(arg0 + 0xA) + 0x18;
            if (*(s16 *)(arg0 + 0xA) < -0x200) {
                break;
            }
        }
        *(s16 *)(arg0 + 0xA) = -0x200;
        *(u16 *)(arg0 + 0x52) = 0;
        func_801830D8(arg0);
        func_8013C9C4(&D_80186F44);
        *(s32 *)(arg0 + 0x1C) = 0x40;
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        func_8002D4C8(0xABC, 0);
        break;
    case 3:
        if (func_8012BEE8(arg0) == 0) {
            break;
        }
        *(u16 *)(arg0 + 0x98) = 1;
        *(u16 *)(arg0 + 0x34) = *(u16 *)(arg0 + 0x34) + 1;
        break;
    case 4:
        if (*(s16 *)(arg0 + 0xA) >= -0x23F) {
            *(s16 *)(arg0 + 0xA) = *(s16 *)(arg0 + 0xA) - 4;
        }
        if (*(s16 *)(arg0 + 0x98) != 0) {
            break;
        }
        if (*(s16 *)(arg0 + 0xA) >= -0x23F) {
            break;
        }
        *(s16 *)(arg0 + 0xA) = -0x240;
        func_8012A828(arg0, &D_801EEAC8);
        *(s32 *)(arg0 + 0x1C) = (s16)(D_801F8714 / 79) + 0x18;
        func_8012B200((u8 *)arg0);
        func_8012AD44((s32 *)arg0, 1);
        *(u16 *)(arg0 + 0x108) = 0;
        func_801A4328(0);
        func_8017F418();
        *(u16 *)(arg0 + 0x5C) |= 0x2000;
        break;
    }
}
