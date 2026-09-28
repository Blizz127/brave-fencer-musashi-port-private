/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155150,801552F4).
 * Offset 0x2CFF8 at overlay base 80128158. SHA256(span)=8c483e020b14e2fe42f0d1477c9416178a6b22c7ac60906e2cd9d7e5d794c5c6.
 * Shape from Druthulu shared/ov donor func_80155150.h (h_exact 109982dd);
 * re-earned through the oracle on the retail blob: 105/105 words -O2 -G0.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155150 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8001D150(s32, s32);
extern void func_8001D130(int, int);
extern u8 func_8014BEF8(void);

void func_80155150(int param_1) {
    int iVar1;
    unsigned int uVar2;
    func_8001D150(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x19);
    func_8001D150(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x18);
    func_8001D150(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x16);
    func_8001D150(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x15);
    uVar2 = *(unsigned int *)(param_1 + 0x44);
    if ((uVar2 & 0x400) != 0) {
        return;
    }
    if ((uVar2 & 0x20000) == 0) {
        if ((uVar2 & 0x20000000) != 0) {
            func_8001D130(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x19);
        } else {
            iVar1 = ((int (*)(int))func_8014BEF8)(param_1);
            if (iVar1 != 0) {
                func_8001D150(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x19);
                func_8001D130(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x18);
                goto LAB_80155260;
            }
            func_8001D150(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x19);
        }
        func_8001D150(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x18);
    }
LAB_80155260:
    if ((*(unsigned int *)(param_1 + 0x44) & 0x10000000) != 0) {
        func_8001D130(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x16);
        goto LAB_801552CC;
    }
    func_8001D150(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x16);
    func_8001D130(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x15);
    if ((*(unsigned int *)(param_1 + 0x44) & 4) == 0) {
        return;
    }
LAB_801552CC:
    func_8001D150(*(int *)(*(int *)(param_1 + 0x20) + 0x24), 0x15);
    return;
}
