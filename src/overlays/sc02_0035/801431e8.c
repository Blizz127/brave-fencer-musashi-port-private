/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801431E8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern s32 func_8012E504(s32 a0, s32 a1);
extern void *memcpy(void *, const void *, u32);
extern u8 D_801BD6E8;
void func_80142B2C(void *arg0);
extern void func_80142B2C(void *arg0);
extern int func_8001CA88(int, void *);
extern void func_800233CC(void *, unsigned short);
extern u8 D_801BCD7C;
extern u8 D_801BD6EC;

void func_801431E8(s32 param_1) {
    u8 buf[8];
    s32 iVar5;
    u16 uVar2;
    s16 sVar4;

    register s32 d __asm__("$16");
    memcpy(buf, &D_801BCD7C, 4);
    iVar5 = ((s32 (*)(void))func_8012C1B8)();
    *(s32 *)(param_1 + 0x20) = iVar5;
    d = iVar5;
    if (iVar5 == 0) {
        ((void (*)(s32))func_8012CAE4)(param_1);
    } else {
        ((void (*)(s32, void *))func_8001CA88)(d, &D_801BD6E8);
        uVar2 = *(u16 *)(param_1 + 0x70);
        *(s16 *)(d + 0x76) = -0x10;
        sVar4 = (uVar2 & 0xf) * 0x600 + 0xc00;
        *(s16 *)(d + 0x1a) = sVar4;
        *(s16 *)(d + 0x18) = sVar4;
        *(u32 *)(d + 4) = *(u32 *)(d + 4) | 0x50000000;
        if (func_8012E504(param_1, 0x33) == 0) {
            *(s16 *)(param_1 + 0xfc) = 1;
            func_800233CC(&D_801BD6E8, 0x10);
            memcpy(&D_801BD6EC, buf, 4);
        } else {
            *(s16 *)(param_1 + 0xfc) = 0;
        }
        ((void (*)(s32))func_80142B2C)(param_1);
    }
}
