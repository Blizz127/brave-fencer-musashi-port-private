/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016EDBC,8016EDEC).
 * Offset 0x46C64 at overlay base 80128158. SHA256(span)=19d1377f66ce927d5924aeeddacceee693edf18d973038067618f0b612d989da.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016edbc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8016EE40();
extern s32 D_80126D70;
void func_8016EDBC(void *a0, void *a1, s32 a2) {
    func_8016EE40(a0, a1, a2);
    D_80126D70 = a2;
}
