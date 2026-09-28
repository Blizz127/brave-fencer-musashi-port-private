/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB574 - byte-exact against retail at -O2 (tools/register_match.py). */
#define MulMatrix0 func_8004818C
#define RotMatrixZ func_8004A27C
#define rand func_8005C49C
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80149374(s32 a0, s32 a1);
extern void func_80146C3C(void);

void func_800CB574(void *param_1) {
    typedef struct { u32 a, b, c, d; } Blk16;
    extern void func_801465E4(void);
    extern void func_8001C810(s32 a0, s32 a1);
    extern void func_80149350(s32 a0);
    extern void func_80149374(s32 a0, s32 a1);
    extern s32 func_80017DC4(void *a0, void *a1);
    extern void RotMatrixZ(s32 a0, void *a1);
    extern void MulMatrix0(s32 a0, void *a1, s32 a2);
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern void func_80146C3C(void);
    extern void func_800CB780(s32 a0);
    extern s32 D_800CCA00;
    extern s32 D_800636C8;

    s32 src;
    s32 iVar2;
    s32 iVar3;
    s16 arr[3];
    s32 mat[8];

    src = *(s32 *)((s32)param_1 + 0x34);
    iVar2 = ((s32 (*)(void))func_801465E4)();
    *(s32 *)((s32)param_1 + 0x20) = iVar2;
    if (iVar2 != 0) {
        func_8001C810(iVar2, (s32)&D_800CCA00);
        *(u32 *)(iVar2 + 4) |= 0x50000040;
        *(s32 *)(iVar2 + 0x20) = (s32)&D_800636C8;

        arr[0] = 0;
        arr[1] = -6;
        arr[2] = (*(u16 *)((s32)param_1 + 0xE)) - 0x24;
        ((void (*)(s32, void *, void *))func_80149350)(src, arr, arr);

        iVar3 = *(s32 *)(src + 0x20);
        *(Blk16 *)((s32)param_1 + 0x38) = *(Blk16 *)(iVar3 + 0x34);
        *(Blk16 *)((s32)param_1 + 0x48) = *(Blk16 *)(iVar3 + 0x44);
        *(s32 *)((s32)param_1 + 0x4C) = arr[0];
        *(s32 *)((s32)param_1 + 0x50) = arr[1];
        *(s32 *)((s32)param_1 + 0x54) = arr[2];
        func_80149374(src, (s32)param_1 + 4);

        arr[2] = 0x1800;
        arr[1] = 0x1800;
        arr[0] = 0x1800;
        ((void (*)(void *, void *))func_80017DC4)(arr, mat);
        RotMatrixZ(rand() & 0xFFF, mat);
        MulMatrix0(*(s32 *)(src + 0x20) + 0x34, mat, iVar2 + 0x34);

        func_80146A6C(0x44, (void *)param_1,
                      *(s16 *)((s32)param_1 + 6),
                      *(s16 *)((s32)param_1 + 0xA),
                      *(s16 *)((s32)param_1 + 0xE),
                      0, 0);

        *(s32 *)((s32)param_1 + 0x30) = 0x80;
        func_800CB780((s32)param_1);
        *(u16 *)((s32)param_1 + 2) = *(u16 *)((s32)param_1 + 2) + 1;
    } else {
        ((void (*)(void *))func_80146C3C)(param_1);
    }
}
