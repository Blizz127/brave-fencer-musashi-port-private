/* Overlay range [801575E4,801576A8) from MAIN.CD member 0012.
 * SHA256(span)=79b9bab8889a7f24ce10a106b00c51ce2cd5d4eb9934baa1bc477fd161f5c8c3.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146994(s32, void *, s32, s32); /* static */
void func_80146CA0(void *);                      /* static */
void func_80146E90(void *, s32);             /* static */
void func_80147300();                     /* static */
void func_80147324();                     /* static */
void func_8014B768(void *, s32);             /* static */
void func_80154274(void *, void *);           /* static */
void func_80154A74();                     /* static */
void func_80156648(void *);                      /* static */
extern s32 *D_800D4F14;
extern s32 D_8011F730;

void func_801575E4(void *arg0) {
    s8 var_v0;
    u8 temp_v0;

    func_80154A74(0x15);
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x1AB) ^ 1;
    M2C_FIELD(arg0, u8 *, 0x1AB) = temp_v0;
    if (temp_v0 != 0) {
        var_v0 = 0xA;
    } else {
        var_v0 = 0xB;
    }
    M2C_FIELD(arg0, s8 *, 0x1AA) = var_v0;
    func_80154274(arg0, &D_800D4F14);
    func_80147324(0x455);
    func_80146E90(arg0, 0);
    func_80156648(arg0);
    func_80146994(5, arg0, 0, 0);
    func_8014B768(arg0, 0x333);
    func_80147300(0x5F3);
    D_8011F730 |= 4;
    func_80146CA0(arg0);
}
