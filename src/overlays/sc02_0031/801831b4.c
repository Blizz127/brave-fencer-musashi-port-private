/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801831B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s32 D_801B7A84;
extern s32 D_801A64C8;
extern s32 D_801B7930;
extern s32 D_801B7948;
extern s32 D_801B794C;
extern s32 D_801B7950;
extern s32 D_801B7988;
extern s32 D_801B7AA0;
extern void func_8013B598(s32 a0, u16 *a1);
extern void func_8013C0F8(s32 a0);
extern void func_8017F53C(s32 a0);
extern void func_8017F5B4(s32 arg0, s32 arg1, s32 arg2);
extern void func_8013CB84(void);
extern void func_800D06E8(void);

void func_801831B4(void) {
    u16 sp10[3];

    sp10[0] = D_80126B5E;
    sp10[1] = D_80126B62;
    sp10[2] = D_80126B66;
    func_8013B598(0, sp10);

    switch (D_801B7A84) {
    case 0:
        {
            s32 *p;
            register s32 val __asm__("$2");

            func_8013C0F8((s32)&D_801A64C8);
            p = &D_801B7930;
            func_8017F53C((s32)p);
            val = D_801B7A84;
            __asm__ __volatile__("");
            D_801B7948 = 0;
            D_801B794C = 0;
            D_801B7950 = 0;
            *p = 0;
            D_801B7988 = 1;
            D_801B7A84 = val + 1;
        }
        break;
    case 1:
        if (D_801B7988 != 0) {
            func_8017F5B4((s32)&D_801B7AA0, (s32)&D_801A64C8, (s32)&D_801B7930);
        }
        break;
    }
    func_8013CB84();
    func_800D06E8();
}
