/* Overlay range [80131B14,80131C78) from MAIN.CD member 0012.
 * SHA256(span)=deb23fd6ef32d8f7ef618b5c4b2db8e894bca565db420bcab76d01f7ac459021.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80019064(s32 (*)());               /* extern */
void func_8002A520(void *);                      /* extern */
void func_8002A790(void *);                      /* extern */
extern s32 D_8017E840;
void func_8012B23C(void *);                      /* static */
void func_8012B2CC(void *);                      /* static */
void func_8016AA50(void *, s32, s32);            /* static */
void func_8016B428(void *);                      /* static */

void func_80131B14(void *arg0, s32 arg1, s32 arg2) {
    s32 var_a1;
    s32 var_a2;
    u8 temp_s1;
    void *temp_v0;
    void *temp_v0_2;

    var_a1 = arg1;
    var_a2 = arg2;
    temp_s1 = M2C_FIELD(arg0, u8 *, 0x5E);
    if (M2C_FIELD(arg0, s16 *, 0x60) != 0) {
        if (temp_s1 == 0x1D) {
            M2C_FIELD(arg0, u16 *, 0x82) = 0U;
            M2C_FIELD(arg0, u16 *, 0x7C) = (u16) M2C_FIELD(arg0, u16 *, 6);
            M2C_FIELD(arg0, u16 *, 0x7E) = (u16) M2C_FIELD(arg0, u16 *, 0xA);
            M2C_FIELD(arg0, u16 *, 0x80) = (u16) M2C_FIELD(arg0, u16 *, 0xE);
        }
        temp_v0 = M2C_FIELD(arg0, void **, 0x78);
        if (temp_v0 != 0) {
            var_a2 = M2C_FIELD(arg0, s16 *, 0x60) * M2C_FIELD(temp_v0, s16 *, 0x30);
            var_a1 = var_a2 >> 0xC;
            if (var_a1 <= 0) {
                var_a1 = 1;
            }
        }
        M2C_FIELD(arg0, u16 *, 0x76) = (u16) (M2C_FIELD(arg0, u16 *, 0x76) - var_a1);
        func_8016AA50(arg0, var_a1, var_a2);
        if (M2C_FIELD(arg0, u16 *, 0x82) & 1) {
            func_8016B428(arg0);
            func_80019064(D_8017E840);
        }
    }
    M2C_FIELD(arg0, u16 *, 0x5C) = (u16) (M2C_FIELD(arg0, u16 *, 0x5C) & 0xFFFE);
    if (temp_s1 != 0x1D) {
        if (M2C_FIELD(arg0, u8 *, 0xC8) != 0) {
            func_8002A520(arg0);
        }
        if (M2C_FIELD(arg0, u8 *, 0xC9) != 0) {
            func_8002A790(arg0);
        }
    }
    if ((s16) M2C_FIELD(arg0, u16 *, 0x76) <= 0) {
        M2C_FIELD(arg0, u16 *, 0x5C) = 0U;
    }
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12) = (s16) ((M2C_FIELD(arg0, u16 *, 0x62) + 0x800) & 0xFFF);
    temp_v0_2 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(temp_v0_2, s16 *, 0x14) = 0;
    M2C_FIELD(temp_v0_2, s16 *, 0x10) = 0;
    func_8012B2CC(arg0);
    func_8012B23C(arg0);
}
