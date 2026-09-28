/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB470 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern u8 D_800CBBD8;
extern u8 D_800CBBD9;
extern u8 D_800CBBDA;
extern u8 D_800CBBDC;
extern u8 D_800CBBDD;
extern u8 D_800CBBDE;
extern void func_800CB5F4();

void func_800CB470(void *arg0) {
    extern void func_800CB5F4();
    extern s32 func_80012F74(s32 a0, s32 a1, s32 a2, s32 a3);
    extern void func_80146CA0(void *a0);
    extern u8 D_800CBBD8;
    extern u8 D_800CBBD9;
    extern u8 D_800CBBDA;
    extern u8 D_800CBBDC;
    extern u8 D_800CBBDD;
    extern u8 D_800CBBDE;

    s32 base;
    void *s1;
    s16 w;

    s1 = *(void **)((u8 *)arg0 + 0x20);
    func_800CB5F4(arg0);
    base = (s32)&D_800CBBD8;
    *(u8 *)base = func_80012F74(*(u8 *)base, 0, 10, 1);
    D_800CBBD9 = func_80012F74(D_800CBBD9, 0, 10, 1);
    D_800CBBDA = func_80012F74(D_800CBBDA, 0, 10, 1);
    D_800CBBDC = func_80012F74(D_800CBBDC, 0, 10, 1);
    D_800CBBDD = func_80012F74(D_800CBBDD, 0, 10, 1);
    D_800CBBDE = func_80012F74(D_800CBBDE, 0, 10, 1);
    if (*(s32 *)((u8 *)arg0 + 0x50) != 0) {
        w = *(u16 *)((u8 *)s1 + 0x1e) + 0x20;
        *(u16 *)((u8 *)s1 + 0x1e) = w;
        if ((s16)w >= 0x1001) {
            *(u16 *)((u8 *)s1 + 0x1e) = 0x1000;
        }
    }
    if (*(s32 *)base == 0 && *(s32 *)&D_800CBBDC == 0) {
        func_80146CA0(arg0);
    }
}
