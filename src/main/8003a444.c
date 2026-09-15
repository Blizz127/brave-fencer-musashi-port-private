/* Native retail instruction export [8003A444,8003A53C).
 * Verified against asm/main.s and the extracted EXE. No C match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8006B0E4;
extern s32 D_8006B0E8;
extern s32 D_8006B0EC;
extern s32 D_8006B0F0;
extern s32 D_8006B0F4;
extern s32 D_8006B0FC;
extern s32 D_8006B102;
extern s32 D_8006B104;
extern s32 D_8006B108;
extern s32 D_8006B10C;
extern s32 D_8006B110;
extern s32 D_8006B142;
extern s32 D_8006B544;
extern s32 D_8006B568;
extern s32 D_8006B5A8;
extern s32 D_8006B5AC;
extern s32 D_8006B5B0;
extern s32 D_8006B5B4;
void func_8003A53C();                                 /* static */
void func_8003A5B8(s32);                               /* static */
void func_8003AF04(s32, s32, s32);                         /* static */
void func_80042580();                                  /* static */
extern s16 D_8006B100;

void func_8003A444(s32 arg0) {
    s32 (*var_v0)();
    s32 var_v1;

    func_80042580();
    func_8003A5B8(arg0);
    if (arg0 == 0) {
        var_v1 = 0x17;
        var_v0 = D_8006B142;
        do {
            *var_v0 = 0xC000;
            var_v1 -= 1;
            var_v0 -= 2;
        } while (var_v1 >= 0);
    }
    func_8003A53C(0xC000);
    D_8006B0EC = 0;
    D_8006B0F0 = 0;
    D_8006B0FC = 0;
    D_8006B100 = 0;
    D_8006B102 = 0;
    D_8006B104 = 0;
    D_8006B108 = 0;
    D_8006B0F4 = (s32) D_8006B5B4;
    func_8003AF04(0xD1, D_8006B5B4, 0);
    D_8006B5A8 = 0;
    D_8006B5AC = 0;
    D_8006B5B0 = 0;
    D_8006B0E8 = 0;
    D_8006B568 = 0;
    D_8006B0E4 = 0;
    D_8006B110 = 0;
    D_8006B10C = 0;
    D_8006B544 = 0;
}
