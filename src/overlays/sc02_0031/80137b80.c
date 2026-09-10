/* SC02.CD FILE_031 / ov_SC02_031 retail span [80137B80,80137BD8).
 * Offset 0xFA28 at overlay base 80128158. SHA256(span)=97fdaffef510ff000e20d0803ab21dca350b397d409f860917e4dc82196cfb40.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8017E980->D_8017F208.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80137B80 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): void (void), 0x18
 * frame. D_80127548 = 0x24, then if (D_801269F0[0].w0 != 0)
 * func_80138BE0(&D_801269F0[0]) (a0 = base throughout, no a-reg
 * writes precede the jal), then D_8017F208++ (asm order: the
 * store precedes the call). Results ignored. Slot
 * view (0x4C stride, word 0) matches func_801379FC's; 38BE0 decl
 * likewise. */

struct slot_80137B80 {
    u32 w0;
    u8 pad[0x48];
};

extern struct slot_80137B80 D_801269F0[];
extern u32 D_80127548;
extern s32 D_8017F208;
extern void func_80138BE0(struct slot_80137B80 *arg0);

void func_80137B80(void) {
    D_80127548 = 0x24;
    if (D_801269F0[0].w0 != 0) {
        func_80138BE0(&D_801269F0[0]);
    }
    D_8017F208++;
}
