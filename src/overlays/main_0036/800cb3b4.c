/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 a0);
extern s32 func_80146CA0(void *a0);
extern s16 D_800CC134;
extern s16 D_800CC136;
extern s16 D_800CC138;
extern s32 func_8004787C(s32);
extern void func_80146E90(s32 *, s32);
extern void func_80147324(s32);
extern s32 func_80146CA0(void *);

void func_800CB3B4(void *arg0) {
    extern s32 func_8004787C(s32);
    extern void func_80146E90(s32 *, s32);
    extern void func_80147324(s32);
    extern s32 func_80146CA0(void *);
    extern s16 D_800CC134;
    extern s16 D_800CC136;
    extern s16 D_800CC138;
    extern void func_80147364(u16 a0, s32 a1);
    extern void func_801659B8(void);
    extern void func_801663A4(void *a0);
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern void func_800CB794(s32 arg0);

    void *s3;
    s32 v0;
    s32 i;
    s32 one;

    s3 = *(void **)((s32)arg0 + 0x20);

    v0 = *(s32 *)((s32)arg0 + 0x1C);
    *(s32 *)((s32)arg0 + 0x1C) = v0 + 1;
    *(s16 *)((s32)s3 + 0x18) = func_8004787C((v0 & 7) << 9) / 32 + 0x1000;

    v0 = *(s32 *)((s32)arg0 + 0x1C);
    *(s32 *)((s32)arg0 + 0x1C) = v0 + 1;
    *(s16 *)((s32)s3 + 0x1A) = func_8004787C((v0 & 7) << 9) / 64 + 0x1000;

    {
        s16 *evt;
        s16 tmp;

        evt = &D_800CC134;
        tmp = D_800CC138 + 1;
        D_800CC138 = tmp;
        D_800CC136 = tmp;
        *evt = tmp;
        if (tmp < 0xFF) {
            return;
        }

        D_800CC138 = 0xFF;
        D_800CC136 = 0xFF;
        *evt = 0xFF;
        func_801663A4(arg0);
    }

    i = 0;
    one = 1;
    do {
        func_80146A6C(0x46, arg0, 0, 0, 0, i, 0);
        func_80146A6C(0x46, arg0, 0, 0, 0, i, one);
        func_80146A6C(0x46, arg0, 0, 0, 0, i, one);
        i++;
    } while (i < 6);

    *(u32 *)((s32)s3 + 4) |= 0x80000000;
    func_800CB794((s32)arg0);
    func_80146E90((s32 *)arg0, 0x1E);
    func_80147364(4, 0x8ED);
    func_80147324(0x8EE);
    func_801659B8();
    func_80146CA0(arg0);
}
