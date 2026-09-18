/* Overlay range [801505FC,801506A4) from MAIN.CD member 0012.
 * SHA256(span)=4d4082974a3e2797ed3d963da182e74eeb684b2bbab29aab1248dff25a92781f.
 * Word export for the native seam; the body below is a
 * verified MATCH (42/42 words at 0x801505FC, -O2). */
#include "psx_types.h"
#include "m2c_macros.h"

/* Verified byte-exact against retail by tools/match_function.py
 * (42/42 words at 0x801505FC). The loop limit is cursor-derived
 * (`temp_v1 = var_s0 + 0x6480`, not absolute) and saved across the
 * loop body (`s2save`), since the scratch regs die in it. Types and
 * signatures are whatever reproduces the bytes; they are not evidence
 * of the original declaration. */

s32 func_8014C278(s32, void *, s32);         /* static */
void func_801506A4(s32, void *);              /* static */
extern s32 *D_801202A0;

s32 func_801505FC(s32 arg0) {
    void *var_s0;
    void *temp_v1;
    void *s2save;

    var_s0 = &D_801202A0;
    temp_v1 = var_s0 + 0x6480;
    if ((u32) var_s0 < (u32) temp_v1) {
        s2save = temp_v1;
loop_2:
        if ((M2C_FIELD(var_s0, u16 *, 0) != 0) && (M2C_FIELD(var_s0, u16 *, 0x5C) & 0x100) && (func_8014C278(arg0, var_s0, 0x30) != 0)) {
            func_801506A4(arg0, var_s0);
            return 1;
        }
        var_s0 += 0x10C;
        if ((u32) var_s0 >= (u32) s2save) {
            goto block_7;
        }
        goto loop_2;
    }
block_7:
    return 0;
}
