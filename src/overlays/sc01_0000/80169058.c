/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80169058 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_80049A1C(void *a0, void *a1);
extern void func_80048EAC(void *a0, void *a1);
extern s32 func_8005C49C(void);
extern void func_80048FBC(void *a0, void *a1, void *a2);

void func_80169058(s32 a0) {
    s32 s1 = a0;
    s16 v10[4];   /* sp+0x10 SVECTOR */
    s16 v18[4];   /* sp+0x18 SVECTOR */
    s16 v20[16];  /* sp+0x20 MATRIX_L48 */
    s16 v40[16];  /* sp+0x40 MATRIX_L48 */
    register s32 v1 __asm__("$3");
    register s32 v0 __asm__("$2");
    v10[0] = *(u16 *)(s1 + 0x6);
    v10[1] = *(u16 *)(s1 + 0xA);
    v10[2] = *(u16 *)(s1 + 0xE);
    func_800D20C0(v10, v18, 1);
    func_800D23D0(v18);
    func_80049A1C(v18, (void *)(s1 + 0x38));
    v10[0] = *(u16 *)(s1 + 0x12);
    v10[1] = *(u16 *)(s1 + 0x16);
    v10[2] = *(u16 *)(s1 + 0x1A);
    func_80049A1C(v10, v40);
    if ((*(s32 *)(s1 + 0x2C) & 0x2) == 0) {
        v0 = func_8005C49C();
        v1 = (v0 & 0x7F) << 3;
        v0 = ((u32)(v0 & 0x7F00)) >> 5;
        __asm__ __volatile__("" : "=r"(v0) : "0"(v0));
        v0 = v0 + 0xC00;
    } else {
        v0 = func_8005C49C();
        v1 = ((v0 & 0x7F) << 3) + 0xE40;
        v0 = (((u32)(v0 & 0x7F00)) >> 5) + 0xE00;
    }
    v10[0] = v1;
    v10[1] = v0;
    __asm__ __volatile__("" : : "r"(v1), "r"(v0));
    v10[2] = 0;
    func_80049A1C(v10, v20);
    func_80048EAC(v40, v20);
    v10[0] = 0;
    v10[1] = 0;
    v10[2] = 0xA;
    func_80048FBC(v20, v10, v10);
    *(u16 *)(s1 + 0x12) = v10[0];
    *(u16 *)(s1 + 0x16) = v10[1];
    {
        s32 c = *(u16 *)(s1 + 0x2);
        s32 z = (u16)v10[2];
        *(s32 *)(s1 + 0x1C) = 0;
        *(u16 *)(s1 + 0x2) = c + 1;
        *(u16 *)(s1 + 0x1A) = z;
    }
}
