/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80152500 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_801473EC(s32 *a0);
void func_80147460(s32 a0);
void func_80147A84(s32 arg0);
void func_80148038(s32 a0, s32 a1);
void func_80149020(s32 *a0);
extern void func_80159B3C(void *a0);
void func_8014C010(s32 a0, s32 a1);
extern void func_80149020(s32 *a0);
extern void func_80165718(s32 a0);
extern s32 func_801535F4(void *arg0);
extern void func_8015BF48(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_80147A84(s32 arg0);
extern void func_801473EC(s32 *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_801525F4(int);

void func_80152500(int param_1)
{
    int iVar1;
    ((int (*)(int))func_80149020)(param_1);
    if (*(int *)(param_1 + 0x1c) == 0) {
        if (*(unsigned short *)(param_1 + 0xb8) == 0x8000) {
            func_801525F4(param_1);
            ((void (*)(int))func_80159B3C)(param_1);
            goto LAB_801525d8;
        }
    } else {
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
    }
    func_80147A84(param_1);
    ((void (*)(int))func_801473EC)(param_1);
    func_80148038(param_1, 0x8000);
    func_80147460(param_1);
    iVar1 = ((int (*)(int))func_801535F4)(param_1);
    if (iVar1 == 1) goto LAB_801525a4;
    if (iVar1 < 2) return;
    if (iVar1 == 2) goto LAB_801525bc;
    return;
LAB_801525a4:
    func_801525F4(param_1);
    ((void (*)(int))func_80159B3C)(param_1);
    goto LAB_801525d0;
LAB_801525bc:
    func_801525F4(param_1);
    ((void (*)(int))func_8015BF48)(param_1);
LAB_801525d0:
    func_8014C010(param_1, 1);
LAB_801525d8:
    func_80165718(param_1);
    return;
}
