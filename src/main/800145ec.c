/* Exact retail word export for [800145EC,800146B0); EXE and assembly verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80062A3E;
extern s32 D_80062A40;
void func_80014774();                                  /* static */
void func_800147B8();                                  /* static */
void func_800525DC(u16, u16, s32, s32, s32);             /* static */
void func_80053178(s32, u16, s32, s32);                      /* static */
void func_80053218();                                  /* static */
void func_80059234();                                 /* static */
extern s32 *D_80062A3C;
extern u16 D_800AF7BC;
extern u16 D_800AF7BE;
extern u16 D_800AF7C0;

void func_800145EC(s32 arg0) {
    s32 temp_v0;
    u16 temp_a0;
    u16 temp_a1;
    u16 temp_v0_2;
    u16 var_a1;

    temp_v0 = (arg0 & 0xFFFF) * 6;
    temp_a0 = *(&D_80062A3C + temp_v0);
    D_800AF7BC = temp_a0;
    temp_a1 = *(D_80062A3E + temp_v0);
    D_800AF7BE = temp_a1;
    temp_v0_2 = *(D_80062A40 + temp_v0);
    D_800AF7C0 = temp_v0_2;
    func_800525DC(temp_a0, temp_a1, temp_v0_2 | 4, 0, 0);
    var_a1 = D_800AF7BE;
    if (var_a1 == 0x1E0) {
        var_a1 = 0;
    }
    func_80053178(0, var_a1, 0, 0);
    func_80059234(1);
    func_80053218();
    func_80014774();
    func_800147B8();
}
