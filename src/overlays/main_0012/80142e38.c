/* Overlay range [80142E38,80142EC0) from MAIN.CD member 0012.
 * SHA256(span)=005da01e49cef1c53a9b03a32d07de6cd9bf7ea3f7e649f5867691e8250029c6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001CA1C(void *, s32 (*)());       /* extern */
extern s32 D_8017F7D8;
void *func_8012C1B8();                              /* static */
void func_8012CAE4(void *);                      /* static */
void func_80142B2C(void *);                      /* static */

void func_80142E38(void *arg0) {
    s16 temp_v0_2;
    void *temp_v0;

    temp_v0 = func_8012C1B8();
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    if (temp_v0 == 0) {
        func_8012CAE4(arg0);
        return;
    }
    func_8001CA1C(temp_v0, D_8017F7D8);
    temp_v0_2 = ((M2C_FIELD(arg0, u16 *, 0x70) & 0xF) * 0x600) + 0x1200;
    M2C_FIELD(temp_v0, s16 *, 0x1A) = temp_v0_2;
    M2C_FIELD(temp_v0, s16 *, 0x18) = temp_v0_2;
    M2C_FIELD(arg0, s16 *, 0xFC) = 0;
    func_80142B2C(arg0);
}
