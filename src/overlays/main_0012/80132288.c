/* Overlay range [80132288,8013240C) from MAIN.CD member 0012.
 * SHA256(span)=48248273db7c6e298b2f0886afb9cd0f06a341f4f8cd66284da34241b43ad073.
 * Word export for the native seam; the body below is a
 * verified MATCH (97/97 words at 0x80132288, -O2). */
#include "psx_types.h"
#include "m2c_macros.h"

/* Verified byte-exact against retail by tools/match_function.py
 * (97/97 words at 0x80132288). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */

void func_8005C324(void *, void *, s32);         /* extern */
void func_801325B8(void *, void *, s32, s32, s32); /* static */

void func_80132288(void *arg0, void *arg1, void *arg2) {
    u32 var_a0;
    u32 var_a0_2;
    u32 var_a1;
    u32 var_a1_2;
    void *sz;
    void *temp_v1;
    void *temp_v1_2;

    M2C_FIELD(arg0, void **, 0) = arg1;
    M2C_FIELD(arg0, s16 *, 4) = 0;
    M2C_FIELD(arg0, s16 *, 6) = 0;
    M2C_FIELD(arg0, void **, 8) = arg2;
    sz = M2C_FIELD(M2C_FIELD(arg1, void **, 0), void **, 0);
    if (M2C_FIELD(sz, s32 *, 4) == 1) {
        var_a1 = M2C_FIELD(sz, u32 *, 0xC);
    } else {
        var_a1 = (u32) (sz + ((((u32) M2C_FIELD(sz, u32 *, 0xC) >> 2) * 4) + 0xC));
    }
    sz = arg2;
    if (M2C_FIELD(arg2, s32 *, 4) == 1) {
        var_a0 = M2C_FIELD(arg2, u32 *, 0xC);
    } else {
        var_a0 = (u32) (arg2 + ((((u32) M2C_FIELD(arg2, u32 *, 0xC) >> 2) * 4) + 0xC));
    }
    func_8005C324((void *) var_a0, (void *) var_a1, M2C_FIELD(sz, s32 *, 0x10) * 8);
    temp_v1 = M2C_FIELD(arg1, void **, 0);
    if (M2C_FIELD(temp_v1, s32 *, 8) != 0) {
        sz = M2C_FIELD(temp_v1, void **, 0);
        if (M2C_FIELD(sz, s32 *, 4) == 1) {
            var_a1_2 = M2C_FIELD(sz, u32 *, 0x14);
        } else {
            var_a1_2 = (u32) (sz + ((((u32) M2C_FIELD(sz, u32 *, 0x14) >> 2) * 4) + 0xC));
        }
        sz = arg2;
        if (M2C_FIELD(arg2, s32 *, 4) == 1) {
            var_a0_2 = M2C_FIELD(arg2, u32 *, 0x14);
        } else {
            var_a0_2 = (u32) (arg2 + ((((u32) M2C_FIELD(arg2, u32 *, 0x14) >> 2) * 4) + 0xC));
        }
        func_8005C324((void *) var_a0_2, (void *) var_a1_2, M2C_FIELD(sz, s32 *, 0x18) * 8);
    }
    if (M2C_FIELD(arg1, s16 *, 6) < 0) {
        temp_v1_2 = M2C_FIELD(arg1, void **, 0);
        func_801325B8(arg2, M2C_FIELD(temp_v1_2, void **, 0), M2C_FIELD(temp_v1_2, s32 *, 4), M2C_FIELD(temp_v1_2, s32 *, 8), 0x1000);
    }
}
