/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_800CB860[];
extern u8 D_800CB861;
extern u8 D_800CB862;
extern u8 D_800CB864;
extern u8 D_800CB865;
extern u8 D_800CB866;
extern s16 D_800CB5F4;
extern s16 D_800CB5F6;
extern u8 D_800D387C[];
extern void func_800233CC(void *, u16);
extern void func_801465C0(void);
extern void func_80146C3C(void);
extern void func_8001CC3C(s32, void *, s32, s32);
extern void func_8001CD9C(s32, void *);

void func_800CAFE0(s32 param_1) {
    s32 pad[2];
    s32 node;
    s32 node2;
    u32 hw;
    u32 sh;
    s32 sext;
    s32 save;

    if (*(u32 *)(param_1 + 0x2C) & 0x8000) {
        D_800CB861 = 0xA0;
        D_800CB860[0] = 0xA0;
        D_800CB862 = 0x70;
        D_800CB866 = 0;
        D_800CB865 = 0;
        D_800CB864 = 0;
        func_800233CC(D_800CB860, 0x1E);
        *(u16 *)(param_1 + 0x12) = 0x1C0;
        *(u16 *)(param_1 + 2) = 1;
        return;
    }
    hw = *(u32 *)(param_1 + 0x30);
    sh = hw >> 15;
    node = ((s32 (*)(void))func_801465C0)();
    if (node == 0) {
        ((void (*)(s32))func_80146C3C)(param_1);
        return;
    }
    sext = (s32)(sh << 16);
    func_8001CC3C(node, D_800D387C,
                  *(s16 *)((s32)&D_800CB5F4 + (sext >> 15)),
                  *(s16 *)((s32)&D_800CB5F6 + (sext >> 15)));
    *(u16 *)(node + 0x1A) = 0x2000;
    *(u16 *)(node + 0x18) = 0x2000;
    *(u8 *)(node + 0x27) = (sext >> 17) + 0x19;
    *(u32 *)(node + 4) |= 0xC0000000;
    save = *(u16 *)(param_1 + 0x30);
    *(s32 *)(param_1 + 0x20) = node;
    *(u16 *)(param_1 + 2) = 2;
    *(u32 *)(param_1 + 0x30) = save;
    node2 = ((s32 (*)(void))func_801465C0)();
    if (node2 == 0) {
        ((void (*)(s32))func_80146C3C)(param_1);
        return;
    }
    *(s32 *)(param_1 + 0x34) = node2;
    func_8001CD9C(node2, D_800CB860);
    *(u16 *)(node2 + 0x2C) = 0xC001;
    *(u32 *)(node2 + 4) |= 0xD0000000;
    *(u16 *)(node2 + 8) = *(u16 *)(param_1 + 6);
    *(u16 *)(node2 + 0xA) = *(u16 *)(param_1 + 0xA);
    *(u16 *)(node2 + 0xC) = *(u16 *)(param_1 + 0xE);
}
