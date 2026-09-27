/* Overlay range [80130438,80130514) from MAIN.CD member 0012.
 * SHA256(span)=83869e61aa4e3ffd33e0a04063a742322c2871953e89f872c5d10a2adf3962ec.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8002D4C8(s32, s32);            /* extern */
void func_800CB0E8(void *);                      /* extern */
s32 func_80131A34(void *, s32);                 /* static */
void func_80131B14();                            /* static */
s32 func_80131CA8(void *, s32);                 /* static */
void func_80131E00(void *, s32);             /* static */
void func_80143CD4(void *);                      /* static */
extern void *D_80126B78;

void func_80130438(void *arg0) {
    s32 var_s1;

    var_s1 = 0;
    M2C_FIELD(arg0, s8 *, 0xC1) = 6;
    if (M2C_FIELD(arg0, s32 *, 0xB4) & 0x40) {
        var_s1 = 1;
        func_80131B14();
        M2C_FIELD(arg0, s32 *, 0x1C) = 0x78;
        func_80143CD4(arg0);
        func_8002D4C8(0x47B, 0);
        func_8002D4C8(0x478, 0);
        func_800CB0E8(arg0);
        if (func_80131A34(arg0, 0x14) == 0) {
            M2C_FIELD(arg0, s16 *, 0x98) = 0;
        }
    }
    if (func_80131CA8(arg0, 0x12) != 0) {
        var_s1 = 1;
    }
    if (var_s1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x5E) = 2;
        M2C_FIELD(arg0, s16 *, 0x60) = 1;
        M2C_FIELD(arg0, u16 *, 0x62) = (u16) M2C_FIELD(D_80126B78, u16 *, 0x12);
        func_80131E00(arg0, 1);
    }
}
