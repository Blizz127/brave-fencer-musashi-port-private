/* Overlay range [8015B7B4,8015B858) from MAIN.CD member 0012.
 * SHA256(span)=abbde394e5a3048589168883bbd47d3b3c8cd1139af5b8ce9aa6825858262c17.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146994(s32, void *, s32, s32); /* static */
void func_80147300();                     /* static */
void func_80147324();                     /* static */
s32 func_80149B54();                                /* static */
void func_80154274(void *, void *, u8);       /* static */
void func_80154A74(void *, s32);             /* static */
void func_80156648(void *);                      /* static */
extern s32 *D_800D4F8C;

s32 func_8015B7B4(void *arg0) {
    s32 var_v0;
    u8 temp_a2;

    var_v0 = 0;
    if (func_80149B54() != 0) {
        func_80156648(arg0);
        M2C_FIELD(arg0, s8 *, 0x1AA) = 0xC;
        temp_a2 = M2C_FIELD(arg0, u8 *, 0xBC);
        M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
        M2C_FIELD(arg0, s32 *, 0x23C) = (s32) M2C_FIELD(arg0, s32 *, 0xB4);
        M2C_FIELD(arg0, u8 *, 0x244) = temp_a2;
        func_80154274(arg0, &D_800D4F8C, temp_a2);
        func_80154A74(arg0, 0x22);
        M2C_FIELD(arg0, s8 *, 0xDA) = 0;
        func_80146994(5, arg0, 5, 0);
        func_80147324(0x455);
        func_80147300(0x5F3);
        var_v0 = 1;
    }
    return var_v0;
}
