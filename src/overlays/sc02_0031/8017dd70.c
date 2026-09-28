/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017DD70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8014659C(void);
extern void func_8001C214(s32 a0, s32 a1);
extern void func_80149374(s32 a0, s32 a1);
extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
extern void func_80146CA0(void *a0);

void func_8017DD70(s32 a0) {

    extern s32 D_801B40E4;
    extern s16 D_801888FC;
    extern s16 D_801888FA;
    extern s16 D_801888F8;
    s32 iVar1;
    s32 iVar2;

    iVar1 = *(s32 *)(a0 + 0x4C);
    iVar2 = ((s32 (*)(void))func_8014659C)();
    *(s32 *)(a0 + 0x20) = iVar2;
    if (iVar2 != 0) {
        func_8001C214(iVar2, (s32)&D_801B40E4);
        *(u16 *)(iVar2 + 0x10) = 0x800;
        *(u16 *)(a0 + 0x60) = 0;
        func_80149374(iVar1, a0 + 4);
        func_80146DE8((s32 *)a0, 0, 0xFFC00000, 0);
        D_801888FC = 0x80;
        D_801888FA = 0x80;
        D_801888F8 = 0x80;
        func_80146CA0((void *)a0);
        if (*(s32 *)(a0 + 0x50) == 0) {
            *(u16 *)(iVar2 + 0x2c) = *(u16 *)(iVar2 + 0x2c) | 0x10;
        }
    }
}
