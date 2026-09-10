/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012DB84,8012DBD0).
 * Offset 0x5A2C at overlay base 80128158. SHA256(span)=ed3d7e488c61d75b6b771c49808b96986d68d8a788f736940b500baa9dbfab2a.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8017E6C4->D_8017EF4C; D_8017E6CC->D_8017EF54.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012DB84 (main_0012.s), decoded manually from
 * raw asm (19 instructions; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): calls func_8014C978,
 * then func_8012F568(1, 0xC001, 0, 0x3E8, &D_8017EF4C, &D_8017EF54).
 * The two stack slots (0x10/0x14) are the 5th/6th call arguments,
 * and the lui/addiu pairs take the addresses of D_8017EF4C/D_8017EF54,
 * matching the (s32, s32, s32, void *, void *, void *) prototype
 * already established by func_8012D664. */

extern void func_8014C978(void);
extern u8 D_8017EF4C;
extern u8 D_8017EF54;
extern s32 func_8012F568(s32 arg0, s32 arg1, s32 arg2, void *arg3, void *arg4, void *arg5);

void func_8012DB84(void) {
    func_8014C978();
    func_8012F568(1, 0xC001, 0, (void *) 0x3E8, &D_8017EF4C, &D_8017EF54);
}
