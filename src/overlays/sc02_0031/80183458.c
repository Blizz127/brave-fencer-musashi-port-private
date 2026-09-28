/* Complete SC02 retail span [80183458,80183808).
 * Live STOP after 832F4; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80183458 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

/* m2c compat (vendor/bfm-decomp/include/common.h). */
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))

extern void func_8012A568(void (*a0)(void));
extern s32 func_80029178(s32 a0);
extern void func_8002959C(void);
extern void func_8012BD14(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern int func_800D0CA0(int a0);
extern void func_8014B598(s32 a0, s32 a1);
extern s32 func_8014CB2C(void);
extern s32 func_8014CB58(void);
extern s32 func_8016F0AC();
extern s32 func_8016F1AC(void);
extern void func_80175414(s32 _arg0);
extern void func_80175454(void);
extern s32 func_80178B18(s32 param_1, s32 param_2);
extern s32 func_801789AC(s32 a0);
extern void func_80178D18(void);
extern void func_8017F4E8(void);
extern s32 func_80181EF0(void);
extern void func_80183A20(s32 param_1);
extern void func_80183A74(s32 param_1);
extern s32 D_801151D4;
extern s16 D_801B7990;
extern s16 D_801B7992;
extern s16 D_801B7994;
extern s16 D_801B7998;
extern s16 D_801B799A;
extern s16 D_801B799C;
extern u8 D_801888B0[];
extern u8 D_8018939C[];
extern u8 D_801893AC[];
extern u8 D_801893BC[];

void func_80183458(s32 a0) {
    u16 v;
    s32 t;

    if (((s32 (*)(s32))func_8012BD14)(a0) < 0x401 || (u32)(*(u16 *)(a0 + 0x34) - 1) < 2) {
        switch (*(u16 *)(a0 + 0x34)) {
        case 0:
            if ((func_80029178(0x8D) & 0xFF) == 0) {
                func_80178B18(a0, &D_8018939C);
                *(u16 *)(a0 + 0x34) = 2;
            } else {
                func_80178B18(a0, &D_801893AC);
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
            if (func_8014CB58() == 5) {
                func_8014B598(5, &D_801888B0);
                if (func_8016F1AC() == 0) {
                    if (*(u16 *)(a0 + 0x100) & 4) {
                        *(s32 *)(a0 + 0x1C) += 1;
                    }
                } else {
                    if ((*(u16 *)(a0 + 0x100) & 4) == 0) {
                        *(u16 *)(a0 + 0x100) |= 4;
                        *(s32 *)(a0 + 0x1C) = 0;
                        func_80175454();
                        if (func_80181EF0() == 0) {
                            func_8017F4E8();
                        }
                    }
                    if (*(u16 *)(a0 + 0x100) & 4) {
                        *(s32 *)(a0 + 0x1C) += 1;
                    }
                }
                if ((*(u16 *)(a0 + 0x100) & 2) == 0 && *(s32 *)(a0 + 0x1C) == 0x5A) {
                    *(u16 *)(a0 + 0x100) |= 2;
                    func_800D0CA0(0);
                }
                if ((*(u16 *)(a0 + 0x100) & 1) == 0) {
                    t = func_8014CB2C();
                    if ((t & 0x8000007F) == 0x80000005) {
                        v = *(u16 *)(a0 + 0x34) + 1;
                        *(s32 *)(a0 + 0x1C) = 0x20;
                        *(u16 *)(a0 + 0x100) |= 1;
                        *(u16 *)(a0 + 0x34) = v;
                    }
                }
            }
            break;
        }
        if ((func_80029178(0x8D) & 0xFF) == 0) {
            return;
        }
        /* func_80183A74(a0) written out on all three paths: cross_jump merges the
           common tail and leaves the three $a0 arg-setups filling the delay slots. */
        if (func_8014CB58() == 5) {
            func_80183A20(a0);
            func_80183A74(a0);
        } else {
            *(u8 *)(*(s32 *)(a0 + 0xCC) + 0x27) = 0xA1;
            func_80183A74(a0);
        }
    } else {
        if ((func_80029178(0x8D) & 0xFF) == 0) {
            return;
        }
        *(u8 *)(*(s32 *)(a0 + 0xCC) + 0x27) = 0xA1;
        func_80183A74(a0);
    }
    if (*(u16 *)(a0 + 0x100) & 1 && func_8012BEE8(a0) != 0) {
        func_8016F0AC();
        if (func_80181EF0() != 0) {
            D_801B7990 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x48);
            D_801B7992 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x4C);
            D_801B7994 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x50);
            D_801B7998 = (s16) M2C_FIELD(D_801151D4, s32 *, 0x3C);
            D_801B799A = (s16) M2C_FIELD(D_801151D4, s32 *, 0x40);
            D_801B799C = (s16) M2C_FIELD(D_801151D4, s32 *, 0x44);
            *(u16 *)(a0 + 2) = 3;
            *(u16 *)(a0 + 0x34) = 0;
            *(s32 *)(a0 + 0x1C) = 0x10;
            func_80178B18(a0, &D_801893BC);
            if ((func_80029178(0x11D) & 0xFF) == 0) {
                func_8002959C();
            }
        } else {
            /* NO explicit temp for the 0x100 flags here: an `u16 v = flags; ... (v &
               0xFFF8) | 0x10` spelling makes the loaded value a SECOND short-lived
               quantity, which loses $v0 to the `3` constant (andi $v0,$v1 instead of
               the target's in-place andi $v0,$v0). The direct func_8005CF28-modify-func_8005CF38 keeps
               one long quantity in $v0 and puts the 3 in $v1. */
            *(u16 *)(a0 + 0x34) = 3;
            *(u16 *)(a0 + 0x100) = (*(u16 *)(a0 + 0x100) & 0xFFF8) | 0x10;
            ((void (*)(void))func_80175414)();
        }
        *(u8 *)(*(s32 *)(a0 + 0xCC) + 0x27) = 0xA1;
        *(u8 *)(*(s32 *)(a0 + 0xD0) + 0x27) = 0xA2;
    }
}
