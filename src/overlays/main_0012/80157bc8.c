/* Overlay range [80157BC8,80157CCC) from MAIN.CD member 0012.
 * SHA256(span)=d5afe56cf6c9383367bdf5fa7f84ee916a6e99a26147a54a068d77a17fa04803.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_80146D90(void *);                      /* static */
void func_801473EC(void *);                      /* static */
void func_80147460(void *);                      /* static */
void func_80147AD4(s32, s32, s32);   /* static */
void func_80148038(void *, s32);             /* static */
void func_8014C010(void *, s32);             /* static */
s32 func_8014ED28(void *);                          /* static */
void func_801599A4(void *);                      /* static */
void func_80159B3C(void *);                      /* static */
void func_8015BE04(void *);                      /* static */
s32 func_8016158C(void *);                          /* static */
void func_80161D20(void *, u16);                 /* static */
void func_8016706C();                     /* static */
void func_801725A4(void *);                      /* static */

void func_80157BC8(void *arg0) {
    s32 temp_v0;

    func_80147AD4(0, 0, 0x10000);
    func_801473EC(arg0);
    func_80148038(arg0, 0x1A000);
    func_80147460(arg0);
    if (func_8014ED28(arg0) != 0) {
        func_80146D90(arg0);
    }
    temp_v0 = func_8016158C(arg0);
    if (temp_v0 & 5) {
        func_80161D20(arg0, M2C_FIELD(arg0, u16 *, 0x16E));
        func_8014C010(arg0, 1);
        func_8016706C(4);
        func_8016706C(5);
        func_801599A4(arg0);
        func_80159B3C(arg0);
    }
    if (temp_v0 == 0) {
        if (M2C_FIELD(arg0, s32 *, 0x34) > 0) {
            func_801599A4(arg0);
            func_80146D90(arg0);
            func_8015BE04(arg0);
            return;
        }
        func_801725A4(arg0);
    }
}
