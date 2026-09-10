/* SC02.CD FILE_031 / ov_SC02_031 retail span [80137D08,80137DD4).
 * Offset 0xFBB0 at overlay base 80128158. SHA256(span)=3f5cf4347c647cdcd9727b9251000f5c31c9ae1e467a6456f97f9f9f6794fddc.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8017E980 here is D_8017F208 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_80137D08 (main_0012.s), decoded manually from
 * raw asm (fully visible; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): s32 result, 0x28
 * frame. s0 = a1 (opaque forward), s1 = &D_801269F0.
 * D_800A5E60 = a0; D_80126A0A = (u16)a2;
 * func_801392FC(s1, D_80126A0E, s0). If (D_801269F4[0] == 7):
 * func_80137DD4(s1, {0x39,0xFF,0x71}-buf, s0) (third byte rides
 * the jal delay slot); else if (== 3 and (D_8017F208 & 4)):
 * func_80139680(s1, s0) (a1 set in the jal delay slot).
 * Returns the reloaded D_800A5E60 (the sole retail caller adds
 * $v0 onward, pinning the s32 return; the word is not clobbered
 * in-function). Callee decls are all-pointer views local to
 * this TU (s0/s1 never dereferenced here). */

extern u8 D_801269F0[];
extern s32 D_800A5E60;
extern u16 D_80126A0A;
extern u8 D_80126A0E;
extern s16 D_801269F4[];
extern s32 D_8017F208;
extern void func_801392FC(void *arg0, s32 arg1, void *arg2);
extern void func_80137DD4(void *arg0, void *arg1, void *arg2);
extern void func_80139680(void *arg0, void *arg1);

s32 func_80137D08(s32 arg0, void *arg1, s32 arg2) {
    void *s1v;
    u8 buf[3];

    s1v = D_801269F0;
    D_800A5E60 = arg0;
    D_80126A0A = (u16) arg2;
    func_801392FC(s1v, D_80126A0E, arg1);
    if (D_801269F4[0] == 7) {
        buf[0] = 0x39;
        buf[1] = 0xFF;
        buf[2] = 0x71;
        func_80137DD4(s1v, buf, arg1);
    } else if (D_801269F4[0] == 3) {
        if ((D_8017F208 & 4) != 0) {
            func_80139680(s1v, arg1);
        }
    }
    return D_800A5E60;
}
