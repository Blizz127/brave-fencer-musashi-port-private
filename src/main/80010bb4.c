/* Exact retail word export for [80010BB4,80010C7C); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80074784;
void func_80010AE0();                     /* static */
void func_80011778();                            /* static */
void func_80011B7C();                     /* static */
void func_80015310();                            /* static */
void func_80018FC8();                            /* static */
void func_8001903C();                            /* static */
void func_8001C044();                            /* static */
void func_80029274();                            /* static */
void func_8002941C();                            /* static */
void func_80029690();                            /* static */
extern s32 *D_800AF630;
extern s16 D_801150D4;

void func_80010BB4(void) {
    M2C_FIELD(&D_800AF630, s8 *, 0xA3E0) = 0;
    M2C_FIELD(&D_800AF630, s8 *, 0xA3E1) = 1;
    M2C_FIELD(&D_800AF630, s8 *, 0xA434) = 0;
    func_8001C044();
    func_80015310();
    func_80029690();
    D_801150D4 = 0;
    D_80074784 = 0;
    func_80018FC8();
    func_8001903C();
    func_80029274();
    func_8002941C();
    func_80010AE0(0x3E0);
    func_80011B7C(0);
    func_80011778();
}
