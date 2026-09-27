/* Overlay range [801523F4,80152500) from MAIN.CD member 0012.
 * SHA256(span)=f14b083d28e24cb8428aa0e1586f7a0a2e24ddacb977db1d5aeb964600db0355.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012A60(s16, s16);                        /* extern */
void func_8001382C(s32, s32 (*)(), void *); /* extern */
void func_80019064(void *);                   /* extern */
extern s32 D_801800E4;
void func_80146CA0(void *);                      /* static */
void func_80146DB8(void *, void *);           /* static */
void func_80146E90();                     /* static */
void func_80147324();                     /* static */
void func_801477E8(void *, s32);                 /* static */
void func_80149020(void *);                      /* static */
void func_80151204(void *, s16);                 /* static */
void func_80154274(void *, void *);           /* static */
void func_80154A74(void *, s32);             /* static */
extern s32 *D_80062C04;
extern s32 *D_800D5880;
extern s32 *D_800D58AC;

void func_801523F4(void *arg0) {
    s32 sp20;
    void *var_a1;

    func_80146E90(0);
    func_80019064(&D_80062C04);
    func_80151204(arg0, M2C_FIELD(arg0, s16 *, 0xF2));
    if (func_80012A60(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12), M2C_FIELD(arg0, s16 *, 0xF4)) >= 0x401) {
        var_a1 = &D_800D5880;
    } else {
        var_a1 = &D_800D58AC;
    }
    func_80154274(arg0, var_a1);
    func_80154A74(arg0, 0x16);
    func_80149020(arg0);
    func_8001382C(((u16) M2C_FIELD(arg0, s16 *, 0xF4) - (u16) M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12)) & 0xFFF, D_801800E4, &sp20);
    func_80146DB8(arg0, &sp20);
    func_801477E8(arg0, M2C_FIELD(D_801800E4, s32 *, 0xC));
    func_80147324(0x451);
    func_80146CA0(arg0);
}
