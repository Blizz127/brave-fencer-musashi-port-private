/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80155150 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 func_8014BEF8(void);
extern void func_8001D150(s32, s32);
extern void func_8001D130(int, int);

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
