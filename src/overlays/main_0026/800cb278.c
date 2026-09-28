/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB278 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98();
extern void func_80146578(void);
extern void func_8001CD9C(int a0, void *a1);
extern void func_800233CC(void *, unsigned short);
extern void func_80146CA0(void *a0);
extern void func_80162CCC(void);
extern u8 D_800CBBD8;
extern u8 D_800CBBD9;
extern u8 D_800CBBDA;
extern u8 D_800CBBDB;
extern u8 D_800CBBDC;
extern u8 D_800CBBDD;
extern u8 D_800CBBDE;
extern u8 D_800CBBDF;

void func_800CB278(s32 param_1)
{
    register s32 p1    __asm__("$17");   
    register s32 iVar1 __asm__("$16");   
    register s32 base  __asm__("$18");   
    register s32 ivar3 __asm__("$19");   

    p1 = param_1;
    base = (s32)&D_800CBBD8;
    if (((s32 (*)(void))func_80146E98)() == 0) {
        return;
    }
    *(s32 *)(p1 + 0x20) = (iVar1 = ((s32 (*)(void))func_80146578)());
    ivar3 = iVar1;
    if (iVar1 != 0) {
        func_8001CD9C(iVar1, (void *)base);
        func_800233CC((void *)base, 0x80);
        *(s16 *)(iVar1 + 0x18) = 0;
        *(s16 *)(iVar1 + 0x1a) = 0;
        *(s16 *)(p1 + 0x60) = 0;
        D_800CBBDB = 0;
        D_800CBBDF = 0;
        if (*(s32 *)(p1 + 0x50) == 0) {
            *(u8 *)base = 0xFF;
            D_800CBBD9 = 0xFF;
            D_800CBBDA = 0xFF;
            D_800CBBDC = 0;
            D_800CBBDD = 0;
            D_800CBBDE = 0xFF;
            *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x50000000;
        } else {
            *(u8 *)base = 0;
            D_800CBBDA = 0xC0;
            D_800CBBD9 = 0;
            D_800CBBDC = 0;
            D_800CBBDD = 0;
            D_800CBBDE = 0x80;
            *(u32 *)(ivar3 + 4) = *(u32 *)(ivar3 + 4) | 0x50000000;
        }
        func_80146CA0((void *)p1);
    } else {
        ((void (*)(s32))func_80162CCC)(p1);
    }
}
