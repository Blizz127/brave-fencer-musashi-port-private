/* Overlay range [80164930,80164A74) from MAIN.CD member 0012.
 * SHA256(span)=3af959dee1dd4e8d3750c7db2a92c96942ac8502c02c0ba51e61929b26836abf.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80180F7E;
extern s32 D_80180F80;
void func_80162CCC(void *);                   /* static */
void func_80164ACC(void *);                   /* static */
extern s32 *D_8011F9D0;
extern s16 D_80180F7C;

void func_80164930(void *arg0) {
    void *var_s0;
    s16 temp_v0_2;
    s32 var_s1;
    u16 temp_v0;
    u16 temp_v0_3;
    u16 temp_v1;
    void *temp_a0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x20);
    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) {
        temp_v0 = M2C_FIELD(temp_a0, u16 *, 0x1C) + 0x100;
        M2C_FIELD(temp_a0, u16 *, 0x1C) = temp_v0;
        M2C_FIELD(temp_a0, u16 *, 0x18) = temp_v0;
        M2C_FIELD(temp_a0, u16 *, 0x12) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x12) + 0x71);
        temp_v0_2 = D_80180F80 - 8;
        D_80180F80 = (u16) temp_v0_2;
        D_80180F7E = temp_v0_2;
        D_80180F7C = temp_v0_2;
        var_s1 = 0;
        if (temp_v0_2 < -0x80) {
            var_s0 = &D_8011F9D0;
            do {
                if ((M2C_FIELD(var_s0, u16 *, 0) == 0x19) && (M2C_FIELD(var_s0, s32 *, 0x50) != 0)) {
                    func_80162CCC(var_s0);
                }
                var_s1 += 1;
                var_s0 += 0x68;
            } while (var_s1 < 0x14);
            func_80162CCC(arg0);
            return;
        }
        func_80164ACC(arg0);
        return;
    }
    temp_v0_3 = M2C_FIELD(temp_a0, u16 *, 0x1C) + 0x40;
    temp_v1 = M2C_FIELD(temp_a0, u16 *, 0x1A) - 0x200;
    M2C_FIELD(temp_a0, u16 *, 0x1A) = temp_v1;
    M2C_FIELD(temp_a0, u16 *, 0x1C) = temp_v0_3;
    M2C_FIELD(temp_a0, u16 *, 0x18) = temp_v0_3;
    if (temp_v1 & 0x8000) {
        M2C_FIELD(temp_a0, u16 *, 0x1A) = 0U;
    }
    M2C_FIELD(temp_a0, u16 *, 0x12) = (u16) (M2C_FIELD(temp_a0, u16 *, 0x12) - 0x71);
}
