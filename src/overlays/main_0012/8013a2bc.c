/* Overlay range [8013A2BC,8013A378) from MAIN.CD member 0012.
 * SHA256(span)=f81c78471f49131a9c886c48dc7bd3abc9dab45f47e741c62d67d61f63c5ecff.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80138C30(void *);                      /* static */
extern void *D_80127524;
extern void *D_80127528;

void func_8013A2BC(void *arg0) {
    s16 *temp_v1;
    s16 var_v0;
    void *temp_v0;

    temp_v1 = M2C_FIELD(arg0, s16 **, 0x40);
    if ((temp_v1 == 0) || (M2C_FIELD(arg0, u16 *, 0x18) == 0) || (*temp_v1 == 4)) {
        if (D_80127524 == arg0) {
            temp_v0 = D_80127528;
            D_80127528 = 0;
            D_80127524 = temp_v0;
            if (temp_v0 != 0) {
                M2C_FIELD(D_80127524, s16 *, 0x1A) = 1;
                func_80138C30(D_80127524);
            }
        }
        var_v0 = 0xE;
        if (!(M2C_FIELD(arg0, s32 *, 8) & 0x8000)) {
            var_v0 = 0xD;
        }
        M2C_FIELD(arg0, s16 *, 4) = var_v0;
    }
}
