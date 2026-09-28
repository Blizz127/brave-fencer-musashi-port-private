/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CDBA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
#define RotMatrixYXZ func_80049A1C
#define rand func_8005C49C
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_80146C3C(void *a0);
extern s32 rand(void);
extern void RotMatrixYXZ(void *a0, void *a1);
extern void ApplyMatrixSV(void *a0, void *a1, void *a2);
extern void func_800D23D0(void*);
extern void func_800D20C0(void*, void*, s32);
extern void func_800CDDA8();

void func_800CDBA8(s32 param_1) {
    u16 sp20[4];
    u16 sp28[4];
    s16 sp30[4];
    s32 sp38[8];
    s16 s4;
    s32 s0;
    s32 a0;
    s32 v1;

    v1 = *(s32 *)(param_1 + 0x34);
    if (*(s32 *)(param_1 + 0x2C) == 0) {
        s4 = 0;
        sp20[0] = *(u16 *)(v1 + 6);
        sp20[1] = *(u16 *)(v1 + 0xA) - 0x28;
        sp20[2] = *(u16 *)(v1 + 0xE);
        do {
            s0 = rand();
            sp28[0] = ((s0 & 0x7F) << 3) - 0x40;
            sp28[1] = ((u32)(s0 & 0x7F00)) >> 3;
            sp28[2] = 0;
            RotMatrixYXZ(sp28, sp38);
            sp28[1] = 0;
            sp28[0] = 0;
            sp28[2] = 0x240;
            ApplyMatrixSV(sp38, sp28, sp28);
            sp30[0] = sp20[0] + ((s16)sp28[0] >> 4);
            sp30[1] = sp20[1] + ((s16)sp28[1] >> 4);
            sp30[2] = sp20[2] + ((s16)sp28[2] >> 4);
            a0 = func_80146A6C(0x39, (void *)param_1, sp30[0], sp30[1], sp30[2],
                               (s0 & 0xFFF) | 0x1000, 0);
            if (a0 == 0) {
                break;
            }
            *(s32 *)(a0 + 0x10) = (s16)sp28[0] << 11;
            *(s32 *)(a0 + 0x14) = (s16)sp28[1] << 11;
            s4 = s4 + 1;
            *(s32 *)(a0 + 0x18) = (s16)sp28[2] << 11;
        } while (s4 < 0x12);
        func_80146C3C((void *)param_1);
    } else {
        func_80015978(param_1 + 4, (s32 *)sp20);
        ((void (*)(void *, void *, s16))func_800D20C0)(sp20, sp30, 1);
        ((void (*)(s16 *))func_800D23D0)(sp30);
        RotMatrixYXZ(sp30, (void *)(param_1 + 0x38));
        *(s32 *)(param_1 + 0x1C) = 0x18;
        *(u16 *)(param_1 + 2) += 1;
        func_800CDDA8(param_1);
    }
}
