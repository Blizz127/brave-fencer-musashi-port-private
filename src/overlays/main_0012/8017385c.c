/* Overlay range [8017385C,801738D4) from MAIN.CD member 0012.
 * SHA256(span)=bf9e9540620440af595eece571b60db5887b74797e9429ab9232337ff8f6b8ca.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80171A1C(void *);                      /* static */
void func_80174650(void *);                      /* static */
extern s16 D_80126B30;

void func_8017385C(void *arg0) {
    u16 var_v0;
    u16 var_v1;

    if ((D_80126B30 == 0) || (D_80126B30 != 1)) {
        var_v0 = M2C_FIELD(arg0, u16 *, 0xAC) | 0x80;
        var_v1 = M2C_FIELD(arg0, u16 *, 0xAA) | 0x80;
    } else {
        var_v0 = M2C_FIELD(arg0, u16 *, 0xAC) | 0x10;
        var_v1 = M2C_FIELD(arg0, u16 *, 0xAA) | 0x10;
    }
    M2C_FIELD(arg0, u16 *, 0xAC) = var_v0;
    M2C_FIELD(arg0, u16 *, 0xAA) = var_v1;
    func_80171A1C(arg0);
    func_80174650(arg0);
}
