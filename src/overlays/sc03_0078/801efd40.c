/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFD40 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_801EFD40(void *a0) {
    extern s32 func_8018727C(void *a0, void *a1);
    extern u8 D_801EFE9C[];
    extern u8 D_801C3FC8[];
    extern void func_8012A828(s32 a0, void *a1);
    extern void func_8012E8E0(s32 a0, s32 a1);
    extern u8 D_801EFE94[];
    extern void (*D_801EFF1C[])(void);
    extern s32 func_80178B18(s32 a0, s32 a1);

    s32 s0 = (s32)a0;

    if (func_8018727C(a0, D_801EFE9C)) {
        *(u16 *)(s0 + 2) = 1;
        func_8012A828(s0, D_801C3FC8);
        func_8012E8E0(s0, (s32)D_801EFE94);
        *(u16 *)(s0 + 0x34) = 0;
        func_80178B18(s0, (s32)D_801EFF1C);
    }
}
