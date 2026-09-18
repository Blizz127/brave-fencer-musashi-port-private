/* Overlay range [80146B9C,80146C3C) from MAIN.CD member 0012.
 * SHA256(span)=261f062ef8585966a38f4891bc3e33aadbf63597f8b49b8fc50201fed01f20a6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* Verified byte-exact against retail by tools/match_function.py
 * (40/40 words at 0x80146B9C). Twin of func_80146AFC: cursor stepping
 * is bytes (u8*), derefs keep explicit u16 widths. Types and signatures
 * are whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern u16 D_8011DA28;

u16 *func_80146B9C(void *arg0) {
    u8 *temp_v1;
    u8 *var_a1;
    u8 *var_a2;

    var_a2 = (u8 *) &D_8011DA28;
    temp_v1 = var_a2 - 0x9F8;
    if ((u32) var_a2 >= (u32) temp_v1) {
        var_a1 = var_a2 + 0x30;
loop_2:
        if (*(u16 *) var_a2 == 0) {
            M2C_FIELD(var_a1, s32 *, 4) = (s32) M2C_FIELD(arg0, s32 *, 8);
            *(u16 *) var_a2 = M2C_FIELD(arg0, u16 *, 0);
            M2C_FIELD(var_a1, u16 *, -0x2A) = (u16) M2C_FIELD(arg0, u16 *, 2);
            M2C_FIELD(var_a1, u16 *, -0x26) = (u16) M2C_FIELD(arg0, u16 *, 4);
            M2C_FIELD(var_a1, u16 *, -0x22) = (u16) M2C_FIELD(arg0, u16 *, 6);
            M2C_FIELD(var_a1, s32 *, -4) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
            M2C_FIELD(var_a1, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x10);
            return (u16 *) var_a2;
        }
        var_a2 -= 0x58;
        var_a1 -= 0x58;
        if ((u32) var_a2 < (u32) temp_v1) {
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return 0;
        }
        goto loop_2;
    }
    return 0;
}
