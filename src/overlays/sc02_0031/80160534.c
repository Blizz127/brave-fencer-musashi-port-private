/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160534 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8  D_80078EC0;
extern u8  D_80078EBF;
extern void (*D_8018730C[])(void *);
extern void func_80149020(s32 *a0);
extern void func_80149034(s32 *a0);
extern u16  func_80148800(s32 *a0);
extern s32  func_80149B54(s32 *a0);
extern void func_80149BAC(s32 *a0);
extern s32  func_80149AA8(s32 *a0);
extern void func_80149AD4(s32 *a0);
extern s32  func_80146E98(s32 a0);
extern u16  func_801487F4(s32 *a0);
extern void func_8015E9B8(s32 *a0);
extern void func_80159B70(void *a0);
extern s32  func_800CF8B4();
extern s32  func_801491C4(s32 a0);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801473EC(s32 *a0);
extern void func_8014D738(void);
extern void func_8015C714(void *a0);
extern s32  func_80161208();
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015F00C(s32 *a0);

void func_80160534(u8 *p) {

    extern s16 D_801152A0;
    func_80149020((s32 *)p);
    func_80149034((s32 *)p);
    if ((D_80078EC0 & 0x7F) != 0 && (func_80148800((s32 *)p) & 0x90) != 0) {
        if (D_80078EBF == 0x80) {
            D_8018730C[*(u16 *)p](p);
            func_80147078((s32 *)p, 0x13);
            func_8015F00C((s32 *)p);
            return;
        }
        if (func_80149B54((s32 *)p) != 0) {
            D_8018730C[*(u16 *)p](p);
            func_80149BAC((s32 *)p);
            return;
        }
    }
    if (func_80149AA8((s32 *)p) != 0) {
        D_8018730C[*(u16 *)p](p);
        func_80149AD4((s32 *)p);
        return;
    }
    if (func_80146E98((s32)p) != 0) {
        if ((func_801487F4((s32 *)p) & 8) != 0) {
            D_8018730C[*(u16 *)p](p);
            func_80147078((s32 *)p, 0x11);
            func_8015E9B8((s32 *)p);
        } else {
            D_8018730C[*(u16 *)p](p);
            func_80147078((s32 *)p, 0);
            func_80159B70(p);
        }
        return;
    }
    if (func_800CF8B4() != 0) {
        *(u16 *)(*(s32 *)(p + 0x20) + 0x12) =
            ((*(u16 *)&D_801152A0) + func_801491C4((s32)p)) & 0xFFF;
    }
    func_80147AD4((s32)p, *(s32 *)(p + 0x234), *(s32 *)(p + 0x238),
                  *(s32 *)(p + 0x23C));
    func_801473EC((s32 *)p);
    if (((s32 (*)(s32 *))func_8014D738)((s32 *)p) != 0) {
        D_8018730C[*(u16 *)p](p);
        func_80147078((s32 *)p, 9);
        func_8015C714(p);
    } else {
        ((s32 (*)(void *))func_80161208)(p);
    }
}
