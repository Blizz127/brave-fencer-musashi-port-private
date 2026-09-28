/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB358 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
void func_800CAF90(void *a0);

void func_800CB358(void *param_1) {
    extern u8 D_80078EC1;
    extern void func_80146C3C();
    extern void func_800CAF90(void *a0);
    register s32 iVar2 __asm__("$2");
    s32 cnt;

    if (*(u8 *)&D_80078EC1 != 5) goto LAB_800CB454;
    if (*(s16 *)((s32)param_1 + 0x28) > *(s16 *)((s32)param_1 + 0x2a)) {
        iVar2 = *(s32 *)((s32)param_1 + 0x1c);
        if (iVar2 < 1) goto LAB_800CB3ec;
        *(u16 *)((s32)param_1 + 0x2a) = (rand() & 0x180) + 0x400;
        iVar2 = -0xA0;
    } else {
        iVar2 = *(s32 *)((s32)param_1 + 0x1c);
        if (-1 < iVar2) goto LAB_800CB3ec;
        *(u16 *)((s32)param_1 + 0x2a) = (rand() & 0x180) + 0x700;
        iVar2 = 0xA0;
    }
    *(s32 *)((s32)param_1 + 0x1c) = iVar2;
LAB_800CB3ec:
    *(u16 *)((s32)param_1 + 0x28) = *(u16 *)((s32)param_1 + 0x28) + *(s32 *)((s32)param_1 + 0x1c);
    *(s32 *)((s32)param_1 + 0x4c) = *(s32 *)((s32)param_1 + 0x4c) + *(s16 *)((s32)param_1 + 0x12);
    *(s32 *)((s32)param_1 + 0x50) = *(s32 *)((s32)param_1 + 0x50) - 3;
    *(s32 *)((s32)param_1 + 0x54) = *(s32 *)((s32)param_1 + 0x54) + *(s16 *)((s32)param_1 + 0x1a);
    func_800CAF90(param_1);

    cnt = *(s32 *)((s32)param_1 + 0x30);
    *(s32 *)((s32)param_1 + 0x30) = cnt - 1;
    if (cnt != 0) return;
    *(u16 *)((s32)param_1 + 2) = *(u16 *)((s32)param_1 + 2) + 1;
    return;
LAB_800CB454:
    func_80146C3C(param_1);
}
