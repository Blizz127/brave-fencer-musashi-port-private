/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD0CC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014ACC0(s32, s32);
extern void func_800CD204();
extern s32 func_80163408(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80163328();
extern s32 func_801632F0();
extern u16 D_800CD690[];
extern u16 D_800CD692[];

void func_800CD0CC(s32 param_1)
{
    u16 *v1;
    s32 s1;
    s16 tmp;

    v1 = *(u16 **)(param_1 + 0x20);
    s1 = *(s32 *)(param_1 + 0x4C);
    *(u16 *)(v1 + 0x14) = D_800CD690[(*(s32 *)(param_1 + 0x1C) & 7) * 2];
    *(u16 *)(v1 + 0x15) = D_800CD692[(*(s32 *)(param_1 + 0x1C) & 7) * 2];
    (*(s32 *)(param_1 + 0x1C))++;
    tmp = *(s16 *)(s1 + 0x1C8) * 16 + 0x1000;
    *(u16 *)(v1 + 0xD) = tmp;
    *(u16 *)(v1 + 0xC) = tmp;
    func_800CD204();
    func_80163408(param_1, 0x24, 0x80, 4);
    func_80163328(param_1);
    if (func_801632F0(param_1) & 1) {
        func_8014ACC0(s1, 0xA);
    }
}
