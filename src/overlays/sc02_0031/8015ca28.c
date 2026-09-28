/* SC02 resident retail span [8015CA28,8015CB94). Offset 0x348D0 at base 80128158.
 * SHA256(span)=6d26dd7c02c5e7ae7fa6aae5b7e18b6ec0591112c4f7b13519587cfebc862cce.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801809C0->D_801872B0; D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015CA28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80149FB0(s32 a0);
extern s32 func_80161B18(void *a0);
extern s32 func_80161B84(void *a0);
extern s32 func_801496D4(void *a0);
extern u16 func_801487F4(s32 *a0);
extern s32 func_801488A8(u8 *a0);
extern void func_80148AAC(u8 *a0);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801473EC(s32 *a0);
extern void func_8014D738(void);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146C98(s32 *a0, s16 a1);
extern void func_80161240(void *a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159B70(void *a0);
extern void func_80149704(void);

void func_8015CA28(u16 *param_1) {

    extern void (*D_8018730C[])(void*);
    extern int D_801872B0;
    ((void (*)(void))func_80149FB0)();
    if (((int (*)(u16 *))func_80161B18)(param_1) != 0) return;
    if (((int (*)(u16 *))func_80161B84)(param_1) != 0) return;
    if (((int (*)(u16 *))func_801496D4)(param_1) != 0) {
        ((void (**)(u16*))D_8018730C)[*param_1](param_1);
        ((void (*)(u16 *))func_80149704)(param_1);
        return;
    }
    if ((((u32 (*)(u16 *))func_801487F4)(param_1) & 0x80) != 0 || ((int (*)(u16 *))func_801488A8)(param_1) != 0) {
        if ((((int (*)(u16 *))func_80148AAC)(param_1) & 0xff) != 0) {
            ((void (*)(u16 *, int, int, int))func_80147AD4)(param_1, 0, 0, 0);
            ((void (*)(u16 *))func_801473EC)(param_1);
        }
        if (((int (*)(u16 *))func_8014D738)(param_1) != 0) {
            ((void (*)(u16 *, void *))func_80146DB8)(param_1, &D_801872B0);
            ((void (*)(u16 *, int))func_80146E90)(param_1, 0x14);
            ((void (*)(u16 *, int))func_80146C98)(param_1, 2);
        }
        if (*(int *)(param_1 + 0xb8) != 0)
            goto do161240;
    }
    ((void (**)(u16*))D_8018730C)[*param_1](param_1);
    ((void (*)(u16 *, int))func_80147078)(param_1, 0);
    ((void (*)(u16 *))func_80159B70)(param_1);
    return;
do161240:
    ((void (*)(u16 *))func_80161240)(param_1);
}
