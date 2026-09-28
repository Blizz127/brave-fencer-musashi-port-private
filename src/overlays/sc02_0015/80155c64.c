/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80155C64 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80146D90(s32 a0);
extern void func_80147460(s32 a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern void func_8014CC28(s32 a0);
extern void func_8014ED28(s32 _arg0);
extern void func_8014FA04(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_8015BF48(s32 *a0);
extern void func_8014ED28();
extern int func_80155FF8(int arg, int a1);
extern s32 D_800D4DF4;

void func_80155C64(s32 a0) {
    s32 flags;
    *(s32 *)(a0 + 0x44) |= 2;
    func_80148038(a0, 0x30000);
    func_80147460(a0);
    if (((s32 (*)(s32))func_8014ED28)(a0) != 0) {
        func_80146D90(a0);
    }
    if ((*(s32 *)(a0 + 0x34) > 0) && (((s32 (*)(s32))func_8014CC28)(a0) != 0)) {
        func_801599A4((void *)a0);
        func_80159B3C((void *)a0);
        func_8014C010(a0, 1);
        return;
    }
    flags = ((s32 (*)(s32))func_8014FA04)(a0);
    if (flags & 0x4000) {
        func_801599A4((void *)a0);
        func_8014C010(a0, 1);
        ((void (*)(void *))func_8015BF48)((void *)a0);
        return;
    }
    if (flags & 0x2000) {
        func_80154274((s32 *)a0, (s32)&D_800D4DF4);
        func_80146CA0((void *)a0);
        func_8014C010(a0, 1);
        return;
    }
    ((void (*)(s32, s32))func_80155FF8)(a0, *(u8 *)(a0 + 0x1AA));
}
