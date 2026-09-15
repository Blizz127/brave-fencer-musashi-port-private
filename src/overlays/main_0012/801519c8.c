/* Overlay range [801519C8,80151AE4) from MAIN.CD member 0012.
 * SHA256(span)=706e1f3160065cb0dab98bced83bbf69b469951987517d5cb884a3b6f53bed2b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80012A60(s16, s16);                        /* extern */
void func_80019064(void *);                   /* extern */
void func_80146CA0(void *);                      /* static */
void func_80147324();                     /* static */
void func_80149020(void *);                      /* static */
void func_8014ACE8(void *, s32, s32);        /* static */
void func_80151204(void *, s16);                 /* static */
void func_80154274(void *, void *);           /* static */
void func_80154A74(void *, s32);             /* static */
extern s32 *D_80062BF4;
extern s32 *D_800D5880;
extern s32 *D_800D58AC;

void func_801519C8(void *arg0) {
    void *var_a1;
    s16 temp_v0;
    u8 temp_v1;
    u8 temp_v1_2;

    func_80019064(&D_80062BF4);
    temp_v1 = M2C_FIELD(arg0, u8 *, 0xDD);
    if ((temp_v1 != 1) && (temp_v1 == 0x11)) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0xF2);
        if (temp_v0 != 0) {
            func_8014ACE8(arg0, 5, temp_v0 & 0x7FFF);
        }
    } else {
        func_80151204(arg0, M2C_FIELD(arg0, s16 *, 0xF2));
    }
    if (func_80012A60(M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), s16 *, 0x12), M2C_FIELD(arg0, s16 *, 0xF4)) >= 0x401) {
        var_a1 = &D_800D5880;
    } else {
        var_a1 = &D_800D58AC;
    }
    func_80154274(arg0, var_a1);
    func_80154A74(arg0, 0x16);
    func_80149020(arg0);
    func_80147324(0x451);
    temp_v1_2 = M2C_FIELD(arg0, u8 *, 0xDE);
    if (((u32) (temp_v1_2 - 2) < 2U) || ((temp_v1_2 & 0xFF) == 0xB)) {
        func_80146CA0(arg0);
    }
    func_80146CA0(arg0);
}
