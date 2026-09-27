/* Exact retail word export for [800373D0,800374CC); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80065438[];
void func_8002D7FC(void *, s32);              /* static */
void func_8002FDE8(u16, void *);                 /* static */
extern s32 *D_80076248;
extern s32 *D_80076250;
extern s32 *D_80076251;
extern s32 *D_80076298;
extern s32 *D_800A4E88;
extern s32 *D_800BA320;

void func_800373D0(void) {
    s32 *var_s0;
    s32 temp_a1;
    s32 var_s1;

    var_s0 = &D_80076248;
    var_s1 = 0;
    do {
        if ((*(&D_80076251 + var_s1) != 0) && (*(&D_80076250 + var_s1) != 0)) {
            temp_a1 = *var_s0;
            if (temp_a1 & 0x3000) {
                M2C_FIELD(&D_800A4E88, s16 *, 0) = (s16) (temp_a1 & 0xFFF);
                M2C_FIELD(&D_800A4E88, u16 *, 6) = (u16) (M2C_FIELD(&D_800A4E88, u16 *, 6) | 0x20);
                func_8002D7FC(&D_800BA320, temp_a1);
                if (!(*var_s0 & 0x1000)) {
                    func_8002FDE8(*(D_80065438 + (M2C_FIELD(&D_800A4E88, s16 *, 0) * 2)), &D_800BA320 + 0x7000);
                }
            }
        }
        var_s0 += 0x10;
        var_s1 += 0x10;
    } while ((s32) var_s0 < (s32) &D_80076298);
}
