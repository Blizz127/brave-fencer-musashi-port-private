/* SC02 resident retail span [8012DB84,8012DBD0). Offset 0x5A2C at base 80128158.
 * SHA256(span)=74373e2ad41f9dcbe5fe8dd7129eac3e589d4493ddeec019d6179b5e56637e36.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E6C4->D_80184FB4; D_8017E6CC->D_80184FBC.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012DB84 (main_0012.s), decoded manually from
 * raw asm (19 instructions; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): calls func_8014C978,
 * then func_8012F568(1, 0xC001, 0, 0x3E8, &D_80184FB4, &D_80184FBC).
 * The two stack slots (0x10/0x14) are the 5th/6th call arguments,
 * and the lui/addiu pairs take the addresses of D_80184FB4/D_80184FBC,
 * matching the (s32, s32, s32, void *, void *, void *) prototype
 * already established by func_8012D664. */

extern void func_8014C978(void);
extern u8 D_80184FB4;
extern u8 D_80184FBC;
extern s32 func_8012F568(s32 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4, void *arg5);

void func_8012DB84(void) {
    func_8014C978();
    func_8012F568(1, 0xC001, 0, (void *) 0x3E8, &D_80184FB4, &D_80184FBC);
}
