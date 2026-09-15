/* Overlay range [80142608,801426D4) from MAIN.CD member 0012.
 * SHA256(span)=332a6fa515a07a8cacc8615daefd82ffdbe45a867d4b669bd03339303de3d6d5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CA1C(void *, s32 (*)());       /* extern */
extern s32 D_8017F798;
void func_8012AD50(void *);                      /* static */
void *func_8012C1B8();                              /* static */
void *func_8012C1DC(void *);                        /* static */
void func_8012CAE4(void *);                      /* static */

void func_80142608(void *arg0) {
    void *temp_v0;
    void *var_s0;

    if (M2C_FIELD(arg0, s16 *, 0x70) != 0) {
        var_s0 = func_8012C1B8();
    } else {
        var_s0 = func_8012C1DC(M2C_FIELD(arg0, void **, 0x64));
    }
    M2C_FIELD(arg0, void **, 0x20) = var_s0;
    if (var_s0 != 0) {
        func_8001CA1C(var_s0, D_8017F798);
        M2C_FIELD(var_s0, s16 *, 0x1A) = 0x200;
        M2C_FIELD(var_s0, s16 *, 0x18) = 0x200;
        M2C_FIELD(arg0, s16 *, 0xFC) = 0x40;
        if (M2C_FIELD(arg0, s16 *, 0x70) == 0) {
            temp_v0 = M2C_FIELD(arg0, void **, 0x64);
            if (temp_v0 != 0) {
                M2C_FIELD(arg0, u16 *, 0xFE) = (u16) M2C_FIELD(temp_v0, u16 *, 0x36);
                goto block_8;
            }
            goto block_7;
        }
block_8:
        M2C_FIELD(arg0, s16 *, 0x98) = 0;
        M2C_FIELD(arg0, s32 *, 0x90) = 0;
        func_8012AD50(arg0);
        return;
    }
block_7:
    func_8012CAE4(arg0);
}
