/* Overlay range [8015AE2C,8015B6F4) from MAIN.CD member 0012.
 * SHA256(span)=5637dbe7984140063172568a8b0c07867971223636b7f5023e12bebc06a37aa8.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015AE2C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
void func_8012A568(void (*a0)(void));
extern void func_8012A568(void (*a0)(void));

/* func_8015AE2C (ov_SC01_077_after, 562 ins, jtbl_801D8B54) — Phase 26 crack
 * Entity main-update dispatcher: 7-case switch (0/1/2/6 shared, 3/4/5 own, no default
 * block — out-of-range falls to the after-switch join), then movement/clamp/decay tail.
 * PIN-FREE. Offset-pure (s32 arg0 + raw offsets) — ×134 template-safe.
 *
 * match_one: MATCH (562 ins). rtu_match (whole-TU): MATCH (562 ins) — see func_8015AE2C.md
 * for the two TU-side prerequisites (engine_core.h DEFINE_func_8015BEC4 extern must drop its
 * `(void)` prototype, and the def must stay K&R) plus the jtbl_carve trailing-pad-word note.
 *
 * Signature: `s32` return + K&R def are REQUIRED by the TU, byte-neutral vs void/ANSI here
 * (both verified MATCH 562): engine_core.h's thunk DEFINE_func_8015BEC4 does
 * `return func_8015AE2C();` (s32, zero-arg call) — only an unprototyped K&R def coexists
 * with that call. §41d does not bite on this body (it has early `return;`s).
 *
 * jtbl_801D8B54 = 7 entries [0,1,2,6]->0x8015AEE4  [3]->0x8015AFE0  [4]->0x8015AFF0
 * [5]->0x8015B000, bound `sltiu 7`, default(out-of-range) -> 0x8015B044 (after-switch).
 * The raw dlabel's 8th word 0x00000000 is NOT a table entry: it is the original TU's
 * intra-TU `.align 3` pad between consecutive jtbls (B34/B54/B74 chain) — the compiled
 * object emits exactly 28 B; the pad must stay in the raw post-carve data piece.
 */
extern void (*D_8018FBA8[])(void *);
extern s32 func_80161A60(s32 a0);
extern u16 func_801487F4(s32 *a0);
extern s32 func_80149FB0(s32 a0);
extern s32 func_801619A4(s32 *a0);
extern s32 func_80149C08(s32 a0);
extern void func_801577C8();
extern s32 func_8015B6F4(s32 a0);
extern s32 func_8015B7B4(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_8015B8F8(s32 *a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_801498E0(s32 *a0);
extern s32 func_80149954(s32 s0);
extern s32 func_80149A64(s32 *a0);
extern void func_800CCCC0(s32 a0);
extern int func_80155FF8(int arg, int a1);
extern s32 func_8015B858(u8 *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_80147814(s32 a0, s32 a1);
extern s32 func_800CF8B4(void);
extern s32 func_801491C4(s32 a0);
extern int func_80148AFC(void *a0);
extern s32 func_80149184(s32 a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80147A30(s32 a0, s32 a1, s32 a2);
extern s32 func_80146E98(s32 a0);
extern void func_80146D90(s32 a0);
extern void func_80147A84(s32 a0);
extern void func_801473EC(s32 *a0);
extern s32 func_80172644(u8 *a0);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801541D8(u8 *a0, s32 a1, s32 a2);
extern s32 func_8014C050(s32 a0, s32 a1);
extern void func_800CCB78(s32 a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_80161488(void *a0);
extern void func_80146CA0(void *a0);
extern s32 func_8014A674(s32 *a0);
extern void func_8014E434(void);
extern void func_8015CC40(s32 *a0);
extern s32 func_8014A69C(s32 *a0);
extern void func_8014E6A0(void);
extern void func_8015CF8C(s32 *a0);
extern s32 func_801725A4(u8 *a0);
extern s32 D_800D4E94;
extern s32 D_800D4ED4;
extern u8 D_800D4F8C[];
extern s32 D_800D4A9C;
extern s32 D_800D4B48;

void func_8015AE2C(arg0)
s32 arg0;
{
    /* [T51] scoped in from file scope: a file-scope decl of these symbols constrains every
       LATER function in this TU, which blocks a byte-true decl of a different type.
       Declaration-only move (cookbook §103); the whole-binary byte-gate is the arbiter. */
    extern u8 D_800D4BE0[];
    /* [T51] scoped in from file scope: a file-scope decl of these symbols constrains every
       LATER function in this TU, which blocks a byte-true decl of a different type.
       Declaration-only move (cookbook §103); the whole-binary byte-gate is the arbiter. */
    extern s16 D_801152A0;
    s32 flag;
    s32 r;
    s32 lim;
    s32 doit;
    s32 t;

    flag = 0;
    if ((func_80161A60(arg0) != 0) && (((s32 (*)(s32))func_801487F4)(arg0) & 0x40) && (*(s32 *)(arg0 + 0x34) >= 0)) {
        flag = 1;
        if (*(s32 *)(arg0 + 0x5C) == 0) {
            *(s32 *)(arg0 + 0x58) = 0;
            *(s32 *)(arg0 + 0x54) = 0;
            *(s32 *)(arg0 + 0x50) = 0;
        }
        *(s32 *)(arg0 + 0x5C) = 1;
    } else {
        *(s32 *)(arg0 + 0x5C) = 0;
    }
    ((void (*)(s32))func_80149FB0)(arg0);
    if (*(s32 *)(arg0 + 0x1B0) == 0) {
        switch (((s32 (*)(s32))func_801619A4)(arg0)) {
        case 0:
        case 1:
        case 2:
        case 6:
            if (*(s32 *)(arg0 + 0xB4) == (s32)&(*(s32 *)&D_800D4BE0)) {
                if (func_80149C08(arg0) != 0) {
                    D_8018FBA8[*(u16 *)arg0]((void *)arg0);
                    ((void (*)(s32))func_801577C8)(arg0);
                    return;
                }
            }
            if ((*(s32 *)(arg0 + 0xB4) != (s32)&D_800D4E94) &&
                (*(s32 *)(arg0 + 0xB4) != (s32)&D_800D4ED4) &&
                (*(s32 *)(arg0 + 0xB4) != (s32)&(*(s32 *)&D_800D4F8C))) {
                if (func_8015B6F4(arg0) == 0) {
                    ((void (*)(s32))func_8015B7B4)(arg0);
                }
            } else {
                if (*(u16 *)(arg0 + 0xB8) == 0x8000) {
                    func_80154A74(arg0, 0x22);
                    ((void (*)(s32))func_8015B8F8)(arg0);
                    *(u32 *)(arg0 + 0x44) &= ~2;
                    if (flag != 0) {
                        ((void (*)(s32, s32, s32, s32))func_80146994)(0x3B, arg0, 0, 0);
                    }
                }
            }
            break;
        case 3:
            ((void (*)(s32))func_801498E0)(arg0);
            break;
        case 4:
            ((void (*)(s32))func_80149954)(arg0);
            break;
        case 5:
            if (((s32 (*)(s32))func_80149A64)(arg0) != 0) {
                D_8018FBA8[*(u16 *)arg0]((void *)arg0);
                func_800CCCC0(arg0);
                return;
            }
            break;
        }
    }
    if (*(u32 *)(arg0 + 0x44) & 2) {
        ((void (*)(s32, s32))func_80155FF8)(arg0, *(u8 *)(arg0 + 0x1AA));
    } else {
        if ((*(s32 *)(arg0 + 0x240) == 0) && (((s32 (*)(s32))func_8015B858)(arg0) != 0)) {
            *(s32 *)(arg0 + 0x240) += 1;
        }
        if ((*(s32 *)(arg0 + 0xB4) == (s32)&(*(s32 *)&D_800D4BE0)) && (*(u16 *)(arg0 + 0xB8) & 0x8000)) {
            ((void (*)(s32))func_8015B8F8)(arg0);
        } else if ((*(s32 *)(arg0 + 0xB4) == (s32)&D_800D4A9C) ||
                   (*(s32 *)(arg0 + 0xB4) == (s32)&D_800D4B48)) {
            if (*(u16 *)(arg0 + 0xB8) & 0x8000) {
                if (*(s32 *)(arg0 + 0x34) >= 0) {
                    *(u16 *)(arg0 + 0xB8) += 1;
                }
            }
        }
    }
    if (*(u8 *)(arg0 + 0x1C6) != 0) {
        if (((s32 (*)(s32))func_801487F4)(arg0) & 0x40) {
            func_80148038(arg0, 0xFFFE6000);
        } else {
            func_80148038(arg0, 0x1A000);
        }
        lim = 0x40000;
        if ((*(s32 *)(arg0 + 0xB4) != (s32)&D_800D4E94) &&
            (*(s32 *)(arg0 + 0xB4) != (s32)&D_800D4ED4) &&
            (*(s32 *)(arg0 + 0xB4) != (s32)&(*(s32 *)&D_800D4F8C))) {
            lim = 0xC0000;
        }
        if (*(s32 *)(arg0 + 0x34) < -lim) {
            *(s32 *)(arg0 + 0x34) = -lim;
        } else if (lim < *(s32 *)(arg0 + 0x34)) {
            *(s32 *)(arg0 + 0x34) = lim;
        }
        func_80147460(arg0);
    } else {
        if (*(s32 *)(arg0 + 0x34) < 0) {
            if (((s32 (*)(s32))func_801487F4)(arg0) & 0x40) {
                func_80147814(arg0, 0xFFFF0000);
            }
            func_80147814(arg0, 0x10000);
        }
    }
    if (func_800CF8B4() != 0) {
        *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x12) = ((*(u16 *)&D_801152A0) + func_801491C4(arg0)) & 0xFFF;
    }
    if (flag == 0) {
        if ((u8)((s32 (*)(s32))func_80148AFC)(arg0)) {
            (*(u16 *)&D_801152A0) = func_80149184(arg0);
            ((void (*)(s32, s32))func_80146E90)(arg0, 4);
            if (*(s32 *)(arg0 + 0x2C) > -0x80000) {
                *(s32 *)(arg0 + 0x2C) = -0x80000;
                func_80147A30(arg0, -0x10000, 0xBA000);
            } else {
                func_80147A30(arg0, -0x1000, 0xBA000);
            }
        } else {
            if (func_80146E98(arg0) != 0) {
                func_80146D90(arg0);
            }
        }
        func_80147A84(arg0);
        ((void (*)(s32))func_801473EC)(arg0);
        if (*(u8 *)(arg0 + 0x1C6) == 0) {
            func_80148038(arg0, 0x1A000);
            func_80147460(arg0);
        }
    } else {
        ((void (*)(s32))func_80172644)(arg0);
        if ((u8)((s32 (*)(s32))func_80148AFC)(arg0)) {
            (*(u16 *)&D_801152A0) = func_80149184(arg0);
            func_80146D90(arg0);
            func_80147AD4(arg0, 0, 0, 0xFFFF4000);
            *(s32 *)(arg0 + 0x50) += *(s32 *)(arg0 + 0x10);
            *(s32 *)(arg0 + 0x54) += *(s32 *)(arg0 + 0x14);
            *(s32 *)(arg0 + 0x58) += *(s32 *)(arg0 + 0x18);
            if (*(s32 *)(arg0 + 0x50) > 0xBA000) {
                *(s32 *)(arg0 + 0x50) = 0xBA000;
            } else if (*(s32 *)(arg0 + 0x50) < -0xBA000) {
                *(s32 *)(arg0 + 0x50) = -0xBA000;
            }
            if (*(s32 *)(arg0 + 0x54) > 0xBA000) {
                *(s32 *)(arg0 + 0x54) = 0xBA000;
            } else if (*(s32 *)(arg0 + 0x54) < -0xBA000) {
                *(s32 *)(arg0 + 0x54) = -0xBA000;
            }
            if (*(s32 *)(arg0 + 0x58) > 0xBA000) {
                *(s32 *)(arg0 + 0x58) = 0xBA000;
            } else if (*(s32 *)(arg0 + 0x58) < -0xBA000) {
                *(s32 *)(arg0 + 0x58) = -0xBA000;
            }
            *(s32 *)(arg0 + 0x10) = *(s32 *)(arg0 + 0x50);
            *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x54);
            *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x58);
            ((void (*)(s32))func_801473EC)(arg0);
        } else {
            doit = 0;
            if (*(s32 *)(arg0 + 0x50) != 0) {
                doit = 1;
                if (*(s32 *)(arg0 + 0x50) >= 0) {
                    *(s32 *)(arg0 + 0x50) -= 0x8000;
                    if (*(s32 *)(arg0 + 0x50) < 0) {
                        *(s32 *)(arg0 + 0x50) = 0;
                    }
                } else {
                    *(s32 *)(arg0 + 0x50) += 0x8000;
                    if (*(s32 *)(arg0 + 0x50) >= 0) {
                        *(s32 *)(arg0 + 0x50) = 0;
                    }
                }
            }
            if (*(s32 *)(arg0 + 0x54) != 0) {
                doit = 1;
                if (*(s32 *)(arg0 + 0x54) >= 0) {
                    *(s32 *)(arg0 + 0x54) -= 0x8000;
                    if (*(s32 *)(arg0 + 0x54) < 0) {
                        *(s32 *)(arg0 + 0x54) = 0;
                    }
                } else {
                    *(s32 *)(arg0 + 0x54) += 0x8000;
                    if (*(s32 *)(arg0 + 0x54) >= 0) {
                        *(s32 *)(arg0 + 0x54) = 0;
                    }
                }
            }
            if (*(s32 *)(arg0 + 0x58) != 0) {
                doit = 1;
                if (*(s32 *)(arg0 + 0x58) >= 0) {
                    *(s32 *)(arg0 + 0x58) -= 0x8000;
                    if (*(s32 *)(arg0 + 0x58) < 0) {
                        *(s32 *)(arg0 + 0x58) = 0;
                    }
                } else {
                    *(s32 *)(arg0 + 0x58) += 0x8000;
                    if (*(s32 *)(arg0 + 0x58) >= 0) {
                        *(s32 *)(arg0 + 0x58) = 0;
                    }
                }
            }
            if (doit != 0) {
                *(s32 *)(arg0 + 0x10) = *(s32 *)(arg0 + 0x50);
                *(s32 *)(arg0 + 0x14) = *(s32 *)(arg0 + 0x54);
                *(s32 *)(arg0 + 0x18) = *(s32 *)(arg0 + 0x58);
                ((void (*)(s32))func_801473EC)(arg0);
            }
            if (!(*(u32 *)(arg0 + 0x44) & 2)) {
                ((void (*)(s32, s32, s32))func_801541D8)(arg0, 0xF, 0x12);
            }
        }
        t = func_8014C050(arg0, 0x3B);
        if (t != 0) {
            func_800CCB78(t);
        }
        if ((*(u16 *)(arg0 + 0x1C8) & 0x1F) == 0) {
            ((void (*)(s32, s32, s32, s32))func_80146994)(0x3C, arg0, 0, 0);
        }
    }
    if (*(s32 *)(arg0 + 0x1B0) != 0) {
        if (*(s32 *)(arg0 + 0x1B0) == 1) {
            func_80154A74(arg0, 0x22);
            func_80154150(arg0, 0xF);
        } else {
            ((void (*)(s32, s32))func_80154274)(arg0, *(s32 *)(arg0 + 0x1B4));
        }
    }
    r = ((s32 (*)(s32))func_80161488)(arg0);
    if (r & 5) {
        *(u32 *)(arg0 + 0x44) &= ~2;
        if (*(s32 *)(arg0 + 0xB4) == (s32)&D_800D4A9C) {
            func_80154150(arg0, 0xE);
        } else {
            func_80154150(arg0, 0x10);
        }
        ((void (*)(s32))func_80146CA0)(arg0);
    }
    if (r == 0) {
        if ((((s32 (*)(s32))func_8014A674)(arg0) != 0) && (((s32 (*)(s32))func_8014E434)(arg0) != 0)) {
            D_8018FBA8[*(u16 *)arg0]((void *)arg0);
            ((void (*)(s32))func_8015CC40)(arg0);
        } else if ((((s32 (*)(s32))func_8014A69C)(arg0) != 0) && (((s32 (*)(s32))func_8014E6A0)(arg0) != 0)) {
            D_8018FBA8[*(u16 *)arg0]((void *)arg0);
            ((void (*)(s32))func_8015CF8C)(arg0);
        } else {
            ((void (*)(s32))func_801725A4)(arg0);
        }
    }
}
