/* Overlay range [80159070,80159120) from MAIN.CD member 0012.
 * SHA256(span)=e137ebcd38701038fdcf94dc0505a8d7c5ea516e2a4d24a3ca55fa403cd0bf02.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_8013767C(void *);                       /* static */
void func_80139914(s32);                         /* static */
s16 func_801399F0(s32);                             /* static */
void func_80146CA0(void *);                      /* static */
extern s32 *D_80110C94;
extern s32 *D_80110CD4;

void func_80159070(void *arg0) {
    void *var_a0;
    s16 temp_v0_2;
    s16 temp_v1;
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(temp_v0, u16 *, 0x12) = (u16) ((M2C_FIELD(temp_v0, u16 *, 0x12) + 0x16) & 0xFFF);
    temp_v0_2 = func_801399F0(M2C_FIELD(arg0, s32 *, 0x198));
    M2C_FIELD(arg0, s16 *, 0x244) = temp_v0_2;
    if ((temp_v0_2 << 0x10) != 0) {
        func_80139914(M2C_FIELD(arg0, s32 *, 0x198));
        temp_v1 = M2C_FIELD(arg0, s16 *, 0x244);
        M2C_FIELD(arg0, s32 *, 0x198) = 0;
        if ((temp_v1 == 1) || (temp_v1 != 2)) {
            var_a0 = &D_80110C94;
        } else {
            var_a0 = &D_80110CD4;
        }
        M2C_FIELD(arg0, s32 *, 0x198) = func_8013767C(var_a0);
        func_80146CA0(arg0);
    }
}
