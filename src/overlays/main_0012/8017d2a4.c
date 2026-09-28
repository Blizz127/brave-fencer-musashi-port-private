/* Overlay range [8017D2A4,8017D730) from MAIN.CD member 0012.
 * SHA256(span)=3cb0717623fdf54b4e8b403bed0d3496e112741aab6a4507f8397de4eca0eeca.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017D2A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* func_8017D2A4 -- ov_MAIN_012 / ov_MAIN_012_jr_801789AC (291 ins, jr/jump-table exemplar)
 *
 * Every declaration is BLOCK-scoped so nothing constrains the rest of the TU.  The two symbols the
 * TU already declares at file scope are declared here with the IDENTICAL type so the block-scope
 * copy cannot conflict:
 *   D_8011511A  -> u16              (ov_MAIN_012_jr_801789AC.c:920)
 *   D_80115118  -> unsigned short   (ov_MAIN_012_jr_801789AC.c:937)
 *   func_8002D4C8 -> void(s32,s32)  (ov_MAIN_012_jr_801789AC.c:168)
 *
 * Idioms that were load-bearing (all byte-proven against the target):
 *   - cookbook §161a: the jump table jtbl_8018406C is indexed from ZERO and its first entry is the
 *     merge/epilogue label 0x8017D6FC, so `case 0: break;` is REQUIRED.  Without it gcc-2.7.2 picks
 *     minval = 1, emits `addiu $v1,$v1,-1` and every table slot shifts.
 *   - the four sites where the target emits `lui/addiu` (the ADDRESS of D_8011512C in a register)
 *     instead of the gas macro form need a real pointer local.  They must be SEPARATE, block-scoped
 *     pointers: one shared `s16 *` for all of them makes gcc merge the live ranges and hand every
 *     site the callee-saved $s0, where the target uses $a0 inside the switch arms.
 *   - cookbook §30 / §135-2: in `case 3` the target hoists the `lh` of D_8011512C ABOVE the fixed
 *     `sh $zero, D_801150D4`.  A bare `*q` deref is non-/s, so sched.c true_dependence keeps the
 *     edge and the load stays put; the COMPONENT_REF form `((struct { s16 h; } *)q)->h` sets
 *     MEM_IN_STRUCT_P unconditionally (/s + varying vs non-/s + fixed) and the edge is dropped.
 *   - D_8011512C is s16: the `lhu` sites are gcc's own build_range_check rewriting
 *     `x == 0xB || x == 0xC` into unsigned-short domain; they do NOT need a u16 declaration.
 *   - D_801150D4's 1..4 test does NOT fold on its own (u16 gives `andi 0xffff; beqz; sltiu 5`), so
 *     the range form `(u32)(D_801150D4 - 1) < 4` is written out explicitly.
 */
void func_8017D2A4(void) {
    extern s32 D_80185AEC;
    extern s32 D_80185AD4;
    extern u8 D_80185ADC[];
    extern u8 D_80185ADD;
    extern u8 D_80185AE0[];
    extern u8 D_80185AE4[];
    extern u8 D_80185AE5;
    extern s32 D_80185AF0[];
    extern s16 D_8011512C;
    extern unsigned short D_80115118;
    extern u16 D_8011511A;
    extern u16 D_801150D4;
    extern s32 D_801826D8;
    extern s32 D_80182638;
    extern void func_80029774(s32 a0);
    extern void func_8002D4C8(s32 a0, s32 a1);
    extern s32 func_8002AF48(s32 a0);
    extern s32 func_8002AF60(void);
    extern void func_8017D730(void);

    s32 ret;
    s16 i;
    s16 *p;

    ret = 0;
    if (D_80185AEC != 0) {
        if (D_80185AEC == 1) {
            p = &D_8011512C;
            if (*p == 3) {
                if (D_80185ADD == 8) {
                    func_80029774(0);
                    *p = 4;
                    D_80115118 = 0x4B;
                    D_801150D4 = 0;
                    D_801826D8 = 0xF;
                    func_8002D4C8(0xB3B, 0);
                } else {
                    *p = 0;
                }
            } else {
                if (D_80185ADD == 6) {
                    *p = 7;
                    D_80115118 = 0x4B;
                    D_801826D8 = 0x18;
                } else {
                    *p = 0;
                }
            }
        } else {
            if ((D_80185AD4 & 3) == 1) {
                D_8011512C = 0xB;
                D_801826D8 = 0x12;
            } else {
                D_8011512C = 0xC;
                D_801826D8 = 0x1C;
            }
            D_80115118 = 0x4B;
        }
        D_80185AD4 = 0;
        D_80185AE5 = 0xFF;
    }

    if (D_8011512C == 0xB || D_8011512C == 0xC) {
        return;
    }
    if (D_80185ADD == D_80185AE5) {
        return;
    }

    for (i = 0; i < 8; i++) {
        D_80185AE4[i] = D_80185ADC[i];
    }

    switch (D_80185ADD) {
    case 0:
        break;
    case 1:
        ret = 0xA;
        D_8011512C = 0;
        D_8011511A = 0;
        break;
    case 2:
        ret = 0xB;
        D_801150D4 = 0;
        D_8011512C = 0;
        D_8011511A = 0;
        break;
    case 3: {
        s16 *q = &D_8011512C;
        D_801150D4 = 0;
        if (((struct { s16 h; } *)q)->h != 0xC) {
            ret = 0x11;
            *q = 5;
        }
        break;
    }
    case 4:
        D_801150D4 = 0;
        D_8011512C = 8;
        ret = 0xB;
        break;
    case 5:
        D_8011512C = 8;
        ret = 0x10;
        break;
    case 6: {
        s16 *q = &D_8011512C;
        D_801150D4 = 0;
        if ((*q != 6) && (*q != 7) && (*q != 0xB)) {
            ret = 0xD;
            *q = 1;
        }
        for (i = 0; i < 4; i++) {
            D_80185AF0[i] = 0;
        }
        D_8011511A = 1;
        func_8017D730();
        break;
    }
    case 7:
        ret = 0xA;
        break;
    case 8: {
        s16 *q;
        if ((D_8011512C != 0xB) && (D_8011512C != 3) && (D_8011512C != 4)) {
            ret = 0xD;
        }
        for (i = 0; i < 4; i++) {
            if (D_80185AE0[i] == 1) {
                D_80185AF0[i] = func_8002AF48(i);
            } else {
                D_80185AF0[i] = 0;
            }
        }
        q = &D_8011512C;
        if (*q == 0) {
            *q = 1;
            if ((u32)(D_801150D4 - 1) < 4) {
                D_8011511A = D_801150D4;
            } else {
                D_8011511A = (func_8002AF60() & 3) + 1;
            }
            if ((D_80185AF0[0] == 0) && (D_80185AF0[1] == 0) && (D_80185AF0[2] == 0) &&
                (D_80185AF0[3] == 0)) {
                D_801150D4 = 0;
                D_8011511A = 1;
            }
        }
        func_8017D730();
        break;
    }
    }

    if (ret != 0) {
        D_80182638 = ret;
    }
}
