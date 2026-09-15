/* Exact retail word export for [8004D16C,8004D20C); EXE/asm verified. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_8004D1D4;
extern s32 *D_8004D20C;
extern s32 D_80074754;
void func_8005CE28();                                  /* static */
void func_8005CF08();                                  /* static */
void func_8005CF18();                                  /* static */

void func_8004D16C(void) {
    s32 *var_t2;
    s32 temp_v1;
    void *var_v0;

    D_80074754 = (s32) saved_reg_ra;
    func_8005CF08();
    var_v0 = (void *(*)())0xB0()->unk18;
    var_t2 = &D_8004D1D4;
    do {
        temp_v1 = *var_t2;
        var_t2 += 4;
        var_v0 += 4;
        var_v0->unk-4 = temp_v1;
    } while (var_t2 != &D_8004D20C);
    func_8005CE28();
    func_8005CF18();
}
