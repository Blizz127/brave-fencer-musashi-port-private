/* Overlay range [8012D098,8012D38C) from MAIN.CD member 0012.
 * SHA256(span)=44ff3a5d0b53f8c2cc8cff4bab8afb3031e51c4c0902d08e4468f10a7824e799.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8012D3B4(void *, void *, s32); /* static */
void func_8012F214(void *, u16 *, void *);    /* static */
extern s32 *D_80000004;

void func_8012D098(void *arg0, s32 arg1) {
    u16 sp54;
    u16 sp52;
    u16 sp50;
    s32 sp48;
    s32 sp40;
    s32 sp38;
    s32 sp30;
    s32 sp28;
    s32 sp20;
    s32 sp18;
    s32 sp10;
    s32 temp_v1;
    s32 var_s7;

    var_s7 = arg1;
    if ((arg0 != 0) && (M2C_FIELD(arg0, u16 *, 0) != 0)) {
        if (var_s7 == 0) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x58);
            if (temp_v1 != 0) {
                var_s7 = (temp_v1 & 0x0FFFFFFF) | (s32) &D_80000004;
                goto block_5;
            }
        } else {
block_5:
            sp50 = *(s32 *) var_s7;
            sp52 = *(s32 *) var_s7;
            sp54 = *(s32 *) var_s7;
            func_8012F214(arg0, &sp50, &sp10);
            sp50 = *(s32 *) var_s7;
            sp52 = *(s32 *) var_s7;
            sp54 = *(s32 *) var_s7;
            func_8012F214(arg0, &sp50, &sp18);
            sp50 = *(s32 *) var_s7;
            sp52 = *(s32 *) var_s7;
            sp54 = *(s32 *) var_s7;
            func_8012F214(arg0, &sp50, &sp20);
            sp50 = *(s32 *) var_s7;
            sp52 = *(s32 *) var_s7;
            sp54 = *(s32 *) var_s7;
            func_8012F214(arg0, &sp50, &sp28);
            sp50 = *(s32 *) var_s7;
            sp52 = *(s32 *) var_s7;
            sp54 = *(s32 *) var_s7;
            func_8012F214(arg0, &sp50, &sp30);
            sp50 = *(s32 *) var_s7;
            sp52 = *(s32 *) var_s7;
            sp54 = *(s32 *) var_s7;
            func_8012F214(arg0, &sp50, &sp38);
            sp50 = *(s32 *) var_s7;
            sp52 = *(s32 *) var_s7;
            sp54 = *(s32 *) var_s7;
            func_8012F214(arg0, &sp50, &sp40);
            sp50 = *(s32 *) var_s7;
            sp52 = *(s32 *) var_s7;
            sp54 = *(s32 *) var_s7;
            func_8012F214(arg0, &sp50, &sp48);
            func_8012D3B4(&sp10, &sp18, 0xFFFFFF);
            func_8012D3B4(&sp18, &sp28, 0xFFFFFF);
            func_8012D3B4(&sp28, &sp20, 0xFFFFFF);
            func_8012D3B4(&sp20, &sp10, 0xFFFFFF);
            func_8012D3B4(&sp30, &sp38, 0xFFFFFF);
            func_8012D3B4(&sp38, &sp48, 0xFFFFFF);
            func_8012D3B4(&sp48, &sp40, 0xFFFFFF);
            func_8012D3B4(&sp40, &sp30, 0xFFFFFF);
            func_8012D3B4(&sp10, &sp30, 0xFFFFFF);
            func_8012D3B4(&sp18, &sp38, 0xFFFFFF);
            func_8012D3B4(&sp20, &sp40, 0xFFFFFF);
            func_8012D3B4(&sp28, &sp48, 0xFFFFFF);
        }
    }
}
