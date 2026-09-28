/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015F448 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146DB8(s32 *a0, s32 *a1);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147324(s32 arg0);
extern void func_801473EC(s32 *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80147A84(s32 arg0);
extern void func_801484B0(s32 a0, s32 a1);
extern void func_80148534(s32 a0, s32 a1);
extern u16 func_80148800(s32 *a0);
extern s32 func_80148980(u8 *a0);
extern s32 func_801496D4(void *a0);
extern void func_80149724(void);
extern s32 func_80149884(void);
extern void func_80019064(void *a0);
extern void func_8014ED28(s32 _arg0);
extern void func_8014F1F4(void);
extern void func_8014FA04(s32 a0);
extern void func_8014FCFC(void);
extern void func_80147324(s32 a0);
extern void func_8014ED28(s32 a0);
extern void func_80147A84(int);
extern void func_80147A84(s32 a0);
extern s32 func_801496D4(void*);
extern void func_801473EC(s32*);
extern void (*D_80181798[])(void *);
extern u16  func_80148800(s32 *a0);
extern void func_80146DB8(s32*, s32*);
extern void func_8014FA04(s32);
extern void (*D_80181798[])(void*);
extern u16 func_80148800(s32*);
extern void func_80147A84(s32);
extern s32 func_801725B8(u8 *a0);
extern void func_801477E8(s32*, s32);
extern s32 func_80148980(u8*);
extern s32 func_80146A6C(s32, void*, s32, s32, s32, s32, s32);
extern void func_80146E90(s32*, s32);
extern s32 func_801725B8(u8*);
extern void func_80019064(void*);
extern void func_801484B0(s32, s32);
extern void func_80148534(s32, s32);

void func_8015F448(s32 arg0) {

    extern u8 D_80062BD0;
    extern s32 D_80181AA4;
    extern s32 D_80181AB4;
    extern s32 D_80181AC4;
    s32 sp20[2];
    s32 sp28[2];

    if (((*(u32 *)(arg0 + 0x44) & 0x100) && (func_80149884() != 0)) ||
        (((s32 (*)(s32))func_801496D4)(arg0) != 0)) {
        D_80181798[*(u16 *)arg0]((void *)arg0);
        *(u8 *)(arg0 + 0x1BE) = 0xA;
        ((void (*)(s32))func_80149724)(arg0);
        ((void (*)(s32, s32))func_801477E8)(arg0, 0);
        return;
    }

    if (*(u8 *)(arg0 + 0x245) == 0) {
        if (*(u8 *)(arg0 + 0x244) == 0) {
            if (((s32 (*)(s32))func_80148800)(arg0) & 0x10) {
                *(u8 *)(arg0 + 0x244) = 1;
                *(u8 *)(arg0 + 0x245) = 1;
            }
        } else if (((s32 (*)(s32))func_80148800)(arg0) & 0x80) {
            *(u8 *)(arg0 + 0x244) = 0;
            *(u8 *)(arg0 + 0x245) = 1;
        }
    }

    if (*(u16 *)(arg0 + 0xB8) & 0x3000) {
        if (*(u16 *)(arg0 + 0xB8) & 0x2000) {
            ((void (*)(void *, void *))func_801484B0)(sp20, sp28);
            func_80147324(0x56D);
        } else {
            ((void (*)(void *, void *))func_80148534)(sp20, sp28);
            func_80147324(0x56E);
        }
        ((void (*)(s32 *))func_80019064)(&(*(s32 *)&D_80062BD0));
        ((void (*)(s32, s32, s32, s32, s32, s32, s32))func_80146A6C)(0x25, arg0, *(s16 *)(arg0 + 6),
                      (s16)(*(u16 *)(arg0 + 0xA) - 0x14),
                      *(s16 *)(arg0 + 0xE), 0, 0);
        ((void (*)(s32, s32, s32, s32, s32, s32, s32))func_80146A6C)(0x25, arg0, *(s16 *)(arg0 + 6),
                      (s16)(*(u16 *)(arg0 + 0xA) - 0x14),
                      *(s16 *)(arg0 + 0xE), 1, 0);
    }

    if (*(u16 *)(arg0 + 0xB8) & 0x8000) {
        if (*(u8 *)(arg0 + 0x245) != 0) {
            *(u8 *)(arg0 + 0x245) = 0;
            *(u16 *)(arg0 + 0xB8) = *(u16 *)(arg0 + 0xBA);
            if (((s32 (*)(s32))func_80148980)(arg0) != 0) {
                ((void (*)(s32, s32 *))func_80146DB8)(arg0, &D_80181AA4);
            } else {
                ((void (*)(s32, s32 *))func_80146DB8)(arg0, &D_80181AB4);
            }
        }
    } else {
        *(u16 *)(arg0 + 0x246) = *(u16 *)(arg0 + 6);
        *(u16 *)(arg0 + 0x248) = *(u16 *)(arg0 + 0xA);
        *(u16 *)(arg0 + 0x24A) = *(u16 *)(arg0 + 0xE);
        func_80147A84(arg0);
        ((void (*)(s32))func_801473EC)(arg0);
        if (((s32 (*)(s32))func_8014F1F4)(arg0) != 0) {
            *(u16 *)(arg0 + 6) = *(u16 *)(arg0 + 0x246);
            *(u16 *)(arg0 + 0xA) = *(u16 *)(arg0 + 0x248);
            *(u16 *)(arg0 + 0xE) = *(u16 *)(arg0 + 0x24A);
        }
    }

    if (((s32 (*)(s32))func_8014FCFC)(arg0) == 0) {
        D_80181798[*(u16 *)arg0]((void *)arg0);
        *(u8 *)(arg0 + 0x1BE) = 0xA;
        ((void (*)(s32))func_80149724)(arg0);
        ((void (*)(s32, s32))func_801477E8)(arg0, 0xFFE80000);
        ((void (*)(s32, s32 *))func_80146DB8)(arg0, &D_80181AC4);
        ((void (*)(s32, s32))func_80146E90)(arg0, 0x10);
        return;
    }

    func_8014ED28(arg0);
    func_8014FA04(arg0);
    ((void (*)(s32))func_801725B8)(arg0);
}
