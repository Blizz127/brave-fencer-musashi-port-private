/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB88C - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixYXZ func_80049A1C
extern void func_800D20C0(void *a0, void *a1, s16 a2);
extern void func_800D23D0(s16 *a0);
extern void func_80017E68(void *a0, void *a1);
extern void RotMatrixYXZ(void *a0, void *a1);

void func_800CB88C(s32 param_1) {
    s16 sp[8];
    sp[0] = *(u16 *)(param_1 + 0x6);
    sp[1] = *(u16 *)(param_1 + 0xA);
    sp[2] = *(u16 *)(param_1 + 0xE);
    func_800D20C0(&sp[0], &sp[4], 7);
    func_800D23D0(&sp[4]);
    func_80017E68(&sp[0], (void *)(param_1 + 0x38));
    RotMatrixYXZ(&sp[4], (void *)(param_1 + 0x38));
    *(s32 *)(param_1 + 0x30) = 0xC0;
    func_800CB988(param_1);
    *(u16 *)(param_1 + 0x2) += 1;
}
