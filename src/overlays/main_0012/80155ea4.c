/* Overlay range [80155EA4,80155F58) from MAIN.CD member 0012.
 * SHA256(span)=e639e627b03218498465f23d588917c41a73db07da4910bf8367f82c74d8eb0e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_801473EC(void *);                      /* static */
void func_80147AD4(s32, s32, s32);   /* static */
void func_8014C010(void *, s32);             /* static */
void func_80155FF8(void *, u8);                  /* static */
void func_801599A4(void *);                      /* static */
void func_80159B3C(void *);                      /* static */
void func_80161208(void *);                      /* static */
extern u16 D_800B99DA;

void func_80155EA4(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x44) = (s32) (M2C_FIELD(arg0, s32 *, 0x44) | 2);
    func_80147AD4(0, 0, 0x8000);
    func_801473EC(arg0);
    if (!(D_800B99DA & 3)) {
        func_8014C010(arg0, 2);
    }
    func_80155FF8(arg0, M2C_FIELD(arg0, u8 *, 0x1AA));
    if ((M2C_FIELD(arg0, s32 *, 0x2C) >= 0) || (M2C_FIELD(arg0, u8 *, 0x1C0) != 0)) {
        func_801599A4(arg0);
        func_80159B3C(arg0);
        return;
    }
    func_80161208(arg0);
}
