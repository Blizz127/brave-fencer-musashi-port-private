/* Overlay range [8012C0EC,8012C194) from MAIN.CD member 0012.
 * SHA256(span)=82cc2ccbce6e3f1ba28d2f581e360ac6bcc0645ad2bc55eb6c5d3878b5e8d05c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s32 func_80013478(s32, void *);                  /* extern */
void func_8012C218(void *);                      /* static */
extern s32 *D_80126CAC;
extern s32 (*D_801274D4)(void *);
extern s32 D_801274E0;

s32 func_8012C0EC(void *arg0) {
    s32 var_v0;
    s32 var_v0_2;
    void *temp_v1;

    if (D_801274D4 == 0) {
        var_v0_2 = func_80013478(arg0 + 4, &D_80126CAC) >= D_801274E0;
    } else {
        var_v0_2 = D_801274D4(arg0);
    }
    var_v0 = 0;
    if (var_v0_2 != 0) {
        temp_v1 = M2C_FIELD(arg0, void **, 0x68);
        if ((temp_v1 != 0) && (M2C_FIELD(arg0, s16 *, 0x72) & 0x8000)) {
            M2C_FIELD(temp_v1, u16 *, 0xA) = (u16) (M2C_FIELD(temp_v1, u16 *, 0xA) & 0x7FFF);
        }
        func_8012C218(arg0);
        var_v0 = 1;
    }
    return var_v0;
}
