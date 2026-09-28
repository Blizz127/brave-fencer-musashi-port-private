/* Complete SC02 retail span [80182CF4,801832D0).
 * Gap after 82C60 cluster through 832D0 leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182CF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016F0AC();
extern void func_8012A568(void (*a0)(void));
extern s32 func_80178B18(s32 param_1, s32 param_2);
extern s32 func_80029178(s32 a0);
extern void func_801746DC(void);
extern void func_8012BD14(s32 a0);
extern s32 func_801789AC(s32 a0);
extern void func_80178D18(void);
extern s32 func_8014CB58(void);
extern void func_8014B598(s32 a0, s32 a1);
extern s32 func_8014CB2C(void);
extern s32 func_8016F1AC(void);
extern void func_80175454(void);
extern int func_800D0CA0(int a0);
extern void func_80183044(s32 a0);
extern void func_80183098(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012E544(s32 a0);
extern void func_8002959C(void);
extern u8 D_80189028[];
extern u8 D_80189038[];
extern u8 D_801888B0[];

void func_80182CF4(s32 a0) {
    u16 v;
    s32 t;

    if ((func_80029178(0x9C) & 0xFF) != 0) {
        *(u16 *)(a0 + 2) = 2;
        *(u8 *)(*(s32 *)(a0 + 0xCC) + 0x27) = 0x80;
        *(u8 *)(*(s32 *)(a0 + 0xD0) + 0x27) = 0x81;
        return;
    }
    if (((s32 (*)(s32))func_8012BD14)(a0) < 0x401 || (u32)(*(u16 *)(a0 + 0x34) - 1) < 2) {
        switch (*(u16 *)(a0 + 0x34)) {
        case 0:
            if ((func_80029178(0x8A) & 0xFF) == 0) {
                func_801746DC();
                func_80178B18(a0, &D_80189028);
                *(u16 *)(a0 + 0x34) = 2;
            } else {
                func_801746DC();
                func_80178B18(a0, &D_80189038);
                *(u16 *)(a0 + 0x34) += 1;
            }
            break;
        case 1:
            if (func_801789AC(a0) == 1) {
                ((void (*)(s32))func_80178D18)(a0);
                *(u16 *)(a0 + 0x34) = 3;
            }
            break;
        case 2:
            if (func_801789AC(a0) == 1) {
                ((void (*)(s32))func_80178D18)(a0);
                *(u16 *)(a0 + 0x34) = 4;
            }
            break;
        case 3:
            if ((*(u16 *)(a0 + 0xFE) & 1) == 0 && func_8014CB58() == 2) {
                func_8014B598(2, &D_801888B0);
                t = func_8014CB2C();
                if (func_8016F1AC() == 0) {
                    if (*(u16 *)(a0 + 0xFE) & 8) {
                        *(s32 *)(a0 + 0x1C) += 1;
                    }
                } else {
                    if ((*(u16 *)(a0 + 0xFE) & 8) == 0) {
                        *(u16 *)(a0 + 0xFE) |= 8;
                        *(s32 *)(a0 + 0x1C) = 0;
                        func_80175454();
                    }
                    if (*(u16 *)(a0 + 0xFE) & 8) {
                        *(s32 *)(a0 + 0x1C) += 1;
                    }
                }
                if ((*(u16 *)(a0 + 0xFE) & 4) == 0 && *(s32 *)(a0 + 0x1C) == 0x5A) {
                    *(u16 *)(a0 + 0xFE) |= 4;
                    func_800D0CA0(0);
                }
                if ((t & 0x8000007F) == 0x80000002) {
                    v = *(u16 *)(a0 + 0x34) + 1;
                    *(s32 *)(a0 + 0x1C) = 0x3C;
                    *(u16 *)(a0 + 0xFE) |= 1;
                    *(u16 *)(a0 + 0x34) = v;
                }
            }
            break;
        }
        if ((func_80029178(0x8A) & 0xFF) == 0) {
            return;
        }
        /* func_80183098(a0) written out on all three paths: gcc cross-jumps the common
           tail but leaves the three $a0 arg-setups, which then fill the three branch
           delay slots. */
        if (func_8014CB58() == 2) {
            func_80183044(a0);
            func_80183098(a0);
        } else {
            *(u8 *)(*(s32 *)(a0 + 0xCC) + 0x27) = 0x80;
            func_80183098(a0);
        }
    } else {
        if ((func_80029178(0x8A) & 0xFF) == 0) {
            return;
        }
        *(u8 *)(*(s32 *)(a0 + 0xCC) + 0x27) = 0x80;
        func_80183098(a0);
    }
    if (*(u16 *)(a0 + 0xFE) & 1 && func_8012BEE8(a0) != 0) {
        func_8016F0AC();
        *(u16 *)(func_8012E544(0x13B) + 0xFC) = 1;
        *(u16 *)(a0 + 0xFE) &= ~1;
        func_8002959C();
    }
}
