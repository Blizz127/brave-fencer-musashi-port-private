/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016EDEC,8016EE40).
 * Offset 0x46C94 at overlay base 80128158. SHA256(span)=524d6c33ec17862e26089348f5c4be6fcfb27fbd4c79dc633d144d54166c6812.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016edec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8016EE94();
void func_801599A4();
void func_80159B3C();
extern u16 D_80126B58;
void func_8016EDEC(void *p) {
    u16 *s = &D_80126B58;
    func_8016EE94(p);
    if ((u16)(*s - 25) < 2) {
        return;
    }
    func_801599A4(s);
    func_80159B3C(s);
}
