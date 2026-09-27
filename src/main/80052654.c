/* Exact retail word export for [80052654,800527C4); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80043078();                                /* static */
void func_80059234(s32);                               /* static */
void func_80059D68(s16 *);                             /* static */
void func_80059FC0(s16 *);                             /* static */
extern s16 D_800A6440;
extern s16 D_800A6442;
extern s16 D_800A6444;
extern s16 D_800A6446;
extern s16 D_800A6448;
extern s16 D_800A644A;
extern s16 D_800A644C;
extern s8 D_800A644E;
extern s8 D_800A644F;
extern s8 D_800A6450;
extern s16 D_800A6498;
extern s16 D_800A649A;
extern s16 D_800A649C;
extern s16 D_800A649E;
extern s16 D_800A64A0;
extern s16 D_800A64A2;
extern s16 D_800A64A4;
extern s16 D_800A64A6;
extern s8 D_800A64A8;
extern s8 D_800A64A9;
extern s8 D_800A64AA;
extern s16 D_800C7C88;

void func_80052654(s16 arg0, s16 arg1, u32 arg2, s8 arg3, u16 arg4) {
    s8 var_v0;

    func_80059234(-(((arg2 >> 4) & 3) == 3) & 3);
    D_800A6442 = 0;
    D_800A6440 = 0;
    D_800A644A = 0;
    D_800A6448 = 0;
    D_800A6446 = 0;
    D_800A6444 = 0;
    D_800A644C = 0;
    D_800A644E = arg3;
    D_800A644F = 0;
    D_800A6450 = 0;
    func_80059D68(&D_800A6440 - 8);
    D_800A6498 = 0;
    D_800A649A = 0;
    D_800A649C = arg0;
    D_800A649E = arg1;
    D_800A64A0 = 0;
    D_800A64A2 = 0;
    D_800A64A4 = 0;
    D_800A64A6 = 0;
    var_v0 = arg2 & 1;
    if (func_80043078() == 1) {
        D_800A64A2 = 0x18;
        D_800A64AA = 1;
        var_v0 = arg2 & 1;
    }
    D_800A64A8 = var_v0;
    D_800C7C88 = arg2 & 4;
    D_800A64A9 = (s8) arg4;
    func_80059FC0(&D_800A6498);
}
