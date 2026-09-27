/* Overlay range [8016C2C4,8016C374) from MAIN.CD member 0012.
 * SHA256(span)=abf92bad51f64de026212d584ae769bf6b0819723c1e0f1e966102cd743a06e1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80015954(u16 *, void *);               /* extern */
extern s32 D_801847B4;
void func_80146C3C(void *);                      /* static */
void func_80149350(s32, u16 *, u16 *);           /* static */
s32 func_8016C374(void *, void *, void *, s32 (*)()); /* static */
extern s32 *D_801847FC;
extern s32 *D_80184804;

void func_8016C2C4(void *arg0) {
    u16 sp14;
    u16 sp12;
    u16 sp10;
    u16 temp_v0;
    u16 temp_v1;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x20);
    sp10 = M2C_FIELD(arg0, u16 *, 0x12);
    sp12 = M2C_FIELD(arg0, u16 *, 0x16);
    sp14 = M2C_FIELD(arg0, u16 *, 0x1A);
    func_80149350(M2C_FIELD(arg0, s32 *, 0x34), &sp10, &sp10);
    func_80015954(&sp10, arg0 + 4);
    temp_v1 = M2C_FIELD(arg0, u16 *, 0x10) + 0x10;
    M2C_FIELD(arg0, u16 *, 0x10) = temp_v1;
    temp_v0 = M2C_FIELD(temp_s0, u16 *, 0x1A) + temp_v1;
    M2C_FIELD(temp_s0, u16 *, 0x1A) = temp_v0;
    M2C_FIELD(temp_s0, u16 *, 0x18) = temp_v0;
    if (func_8016C374(arg0, &D_801847FC, &D_80184804, D_801847B4) == 0) {
        func_80146C3C(arg0);
    }
}
