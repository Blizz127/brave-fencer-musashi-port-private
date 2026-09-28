/* Overlay range [801299C8,80129C40) from MAIN.CD member 0012.
 * SHA256(span)=a41196705608562ebd96fc4afeec4ec154b3612a796800ec00366e8304195692.
 * Word export for the native seam (m2c produced no draft). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801299C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

// @class: schedule
// @stuck: none — MATCH (158 ins, match_one relocation-masked)
//
// Levers that landed it (2 iterations, 56 mismatched -> MATCH):
//  1. §43 K&R s16-param definition: `void f(a0,a1,a2) s16 a0; s16 a1; u8 *a2;` reproduces the
//     in-place `sll $a0,$a0,16` zero-test on the arg reg + the raw-$a1 copy (`addu $a3,$a1,$zero`)
//     stashed in the jtbl branch delay slot and RE-extended per use in the case body.
//  2. §18 array-of-struct %lo-fold: three sibling extern arrays D_801840B8/1/2[] (a 4-row x 3-comp
//     RGB gradient table, stride 4) give `lui $at,%hi(sym); addu $at,$at,idx4; sb $v0,%lo(sym)($at)`
//     for the indexed case and plain `lui/sb %lo(sym+k)` for the constant-index case.
//  3. Switch CASE-ORDER = source order: the jump table dispatches case 1 to the FIRST emitted block,
//     so `case 1:` must be written before `case 0/2:` and `case 3/4:`.
//  4. THE residual (56 -> 0): the case-1 body must be written ROW-MAJOR (BE0[0],BE1[0],BE2[0],
//     BE0[4],BE1[4],BE2[4],...), i.e. the natural table fill. gcc-2.7.2's sched pass then REORDERS
//     the stores itself (BE0,BE1,BE5,BE8,BE4,BEC,BE9,BED,BE2,BE6,BEA,BEE) because the three arrays
//     are distinct declarations => provably non-aliasing. Writing the source in the target's STORE
//     order is the trap: it pins the b*255 / r*143 CSEs at their late store sites instead of letting
//     them hoist into $a0/$v1 at rows 0/1, and mis-schedules the D_80185B10 load.
//  5. Shift signedness: `u32` component locals give `srl` for r*5>>3 and g*25>>1; an explicit
//     `(s32)(x * 255) >> 4` gives `sra` for the *255 / *143 / *45 terms (mixed within one block).

extern u8 D_80185C0A;
extern u8 D_80185B32;
extern u8 D_80185B10;
extern u8 D_801840B8[];
extern u8 D_801840B9[];
extern u8 D_801840BA[];

void func_801299C8(arg0, arg1, arg2)
s16 arg0;
s16 arg1;
u8 *arg2;
{
    u32 r;
    u32 g;
    u32 b;
    s32 i;

    if (arg0 != 0) {
        switch (arg1) {
        case 1:
            r = D_80185C0A;
            g = D_80185B32;
            b = D_80185B10;
            D_801840B8[0] = r * 5 >> 3;
            D_801840B9[0] = g << 3;
            D_801840BA[0] = (s32)(b * 255) >> 4;
            D_801840B8[4] = (s32)(r * 143) >> 4;
            D_801840B9[4] = g * 25 >> 1;
            D_801840BA[4] = (s32)(b * 255) >> 4;
            D_801840B8[8] = (s32)(r * 255) >> 4;
            D_801840B9[8] = (s32)(g * 255) >> 4;
            D_801840BA[8] = (s32)(b * 255) >> 4;
            D_801840B8[12] = (s32)(r * 143) >> 4;
            D_801840B9[12] = (s32)(g * 255) >> 4;
            D_801840BA[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_801840B8[i] = arg2[0x44] * D_80185C0A >> 4;
            D_801840B9[i] = arg2[0x45] * D_80185B32 >> 4;
            D_801840BA[i] = arg2[0x46] * D_80185B10 >> 4;
            i = (arg1 + 1) * 4;
            D_801840B8[i] = arg2[0x47] * D_80185C0A >> 4;
            D_801840B9[i] = arg2[0x48] * D_80185B32 >> 4;
            D_801840BA[i] = arg2[0x49] * D_80185B10 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_80185C0A << 3;
            arg2[0x21] = D_80185B32 << 3;
            arg2[0x22] = D_80185B10 << 3;
            break;
        }
    }
}
