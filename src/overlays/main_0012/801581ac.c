/* Overlay range [801581AC,8015824C) from MAIN.CD member 0012.
 * SHA256(span)=4675c3cd996cd4ca155017122b8ae87b4ff6bfba2e5b095b56b73a88010b1a2a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801473EC(void *);                      /* static */
void func_80147460(void *);                      /* static */
void func_80147AD4(void *, s32, s32, s32); /* static */
void func_80148038();                     /* static */
void func_80155FF8(void *, u8);                  /* static */
void func_801599A4(void *);                      /* static */
void func_80159B3C(void *);                      /* static */
s32 func_80161418(void *);                          /* static */

void func_801581AC(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
    func_80148038(0x10000);
    func_80147460(arg0);
    func_80147AD4(arg0, 0, 0, 0);
    func_801473EC(arg0);
    if (func_80161418(arg0) == 0) {
        if (M2C_FIELD(arg0, u16 *, 0xB8) == 0x8000) {
            func_801599A4(arg0);
            func_80159B3C(arg0);
            return;
        }
        func_80155FF8(arg0, M2C_FIELD(arg0, u8 *, 0x1AA));
    }
}
