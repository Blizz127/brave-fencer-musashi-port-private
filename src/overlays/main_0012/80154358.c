/* Overlay range [80154358,80154418) from MAIN.CD member 0012.
 * SHA256(span)=0b5a31285b5648f44d6a7bfc9dbfb56c8a20203d514dc6df2bea46ef08437140.
 * Word export for the native seam; the body below is a
 * verified MATCH (48/48 words at 0x80154358, -O2). */
#include "psx_types.h"
#include "m2c_macros.h"

/* Verified byte-exact against retail by tools/match_function.py
 * (48/48 words at 0x80154358). The stack-slot call takes a leading
 * arg0 (4 args); without it every slot address shifts one register
 * down. This also proves callee func_8015444C takes >= 4 args.
 * Types and signatures are whatever reproduces the bytes; they are
 * not evidence of the original declaration. */

void func_8015444C(void *, s32 *, s32 *, s32 *);  /* static */

s32 func_80154358(void *arg0) {
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 temp_s2;
    s32 temp_s4;
    s32 temp_v0;
    u16 temp_s1;
    u16 temp_s3;
    u8 temp_s5;
    u8 temp_s6;
    u8 temp_s7;
    void *temp_v1;

    temp_s5 = M2C_FIELD(arg0, u8 *, 0xBC);
    temp_s6 = M2C_FIELD(arg0, u8 *, 0xBD);
    temp_s7 = M2C_FIELD(arg0, u8 *, 0xDC);
    sp10 = 0;
    sp14 = 0;
    sp18 = 1;
    temp_s2 = M2C_FIELD(arg0, s32 *, 0xB4);
    temp_s3 = M2C_FIELD(arg0, u16 *, 0xB8);
    temp_s1 = M2C_FIELD(arg0, u16 *, 0xBA);
    temp_s4 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s32 *, 0x20);
    func_8015444C(arg0, &sp10, &sp14, &sp18);
    temp_v1 = M2C_FIELD(arg0, void **, 0x20);
    M2C_FIELD(arg0, s32 *, 0xB4) = temp_s2;
    M2C_FIELD(arg0, u16 *, 0xB8) = temp_s3;
    M2C_FIELD(arg0, u16 *, 0xBA) = temp_s1;
    M2C_FIELD(arg0, u8 *, 0xBC) = temp_s5;
    M2C_FIELD(arg0, u8 *, 0xBD) = temp_s6;
    M2C_FIELD(arg0, u8 *, 0xDC) = temp_s7;
    temp_v0 = M2C_FIELD(temp_v1, s32 *, 0x20);
    M2C_FIELD(temp_v1, s32 *, 0x20) = temp_s4;
    return temp_v0;
}
