/* Overlay range [80160410,80160534) from MAIN.CD member 0012.
 * SHA256(span)=cb06c5e3858c11786009f6f794504f8a8e8f8205d0b70583061d335322fa761c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8001382C(s16, s32 *, void *);       /* extern */
void func_80013E94(void *, s32 *);               /* extern */
void func_80019064(void *);                   /* extern */
void func_80146A6C(s32, void *, s16, s16, s32, s32, s32); /* static */
void func_80146CA0(void *);                      /* static */
void func_80146DB8(void *, void *);           /* static */
void func_80146E90(void *, s32);             /* static */
void func_80147324();                     /* static */
void func_80149020(void *);                      /* static */
s16 func_80149184(void *);                          /* static */
void func_801553A8(void *);                      /* static */
extern s32 *D_80062BD0;
extern s16 D_801152A0;

void func_80160410(void *arg0) {
    s32 sp60;
    s32 sp30;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s16 temp_s1;
    s32 temp_v0;

    func_80019064(&D_80062BD0);
    func_80149020(arg0);
    temp_s1 = M2C_FIELD(arg0, u16 *, 0x42) - M2C_FIELD(M2C_FIELD(arg0, void **, 0x20), u16 *, 0x12);
    func_80013E94(arg0 + 0xE8, &sp60);
    temp_v0 = sp60 | 0x80000000;
    sp60 = temp_v0;
    func_80146A6C(6, arg0, M2C_FIELD(arg0, s16 *, 0xE0), M2C_FIELD(arg0, s16 *, 0xE2), (s32) M2C_FIELD(arg0, s16 *, 0xE4), temp_v0, 0);
    func_80147324(0x43D);
    sp20 = 0;
    sp24 = 0;
    sp28 = 0xFFFA0000;
    func_8001382C(temp_s1, &sp20, &sp30);
    func_80146DB8(arg0, &sp30);
    sp20 = 0;
    sp24 = 0;
    sp28 = 0x8000;
    func_8001382C(temp_s1, &sp20, arg0 + 0x234);
    func_80146E90(arg0, 8);
    func_801553A8(arg0);
    D_801152A0 = func_80149184(arg0);
    func_80146CA0(arg0);
}
