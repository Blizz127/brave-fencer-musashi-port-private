/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB910 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixYXZ func_80049A1C
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_80017E68(void *a0, void *a1);
extern void RotMatrixYXZ(void *a0, void *a1);
extern void func_800CBA0C(s32 param_1);

void func_800CB910(s32 param_1)
{
    u16 sp10[3];
    u16 sp18[3];

    sp10[0] = *(u16 *)(param_1 + 0x06);
    sp10[1] = *(u16 *)(param_1 + 0x0A);
    sp10[2] = *(u16 *)(param_1 + 0x0E);
    func_800D20C0(sp10, sp18, 7);
    func_800D23D0(sp18);
    func_80017E68(sp10, (void *)(param_1 + 0x38));
    RotMatrixYXZ(sp18, (void *)(param_1 + 0x38));
    *(s32 *)(param_1 + 0x30) = 0xC0;
    func_800CBA0C(param_1);
    *(u16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
}
