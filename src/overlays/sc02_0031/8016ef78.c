/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016EF78,8016EFA8).
 * Offset 0x46E20 at overlay base 80128158. SHA256(span)=4d566ca109d04e990eb5850cf9ad039e1d3760b26874531c6c708cc8b8c0dcd5.
 * STOP pc=8016ef78 (func_8016EF78), CPU_BOUNDARY/REFUSED, ra=8016ee50.
 * Callee from burned func_8016EE40 (jal 0C05BBDE).
 * Donor shape: Druthulu shared/ov/func_8016EF78.h (func_8016EFC8(a0) + func_801726D0(&D_80126B58)).
 * NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text near jr_8017AE2C / shared OV body.
 */
#include "psx_types.h"

extern s32 func_8016EFC8(s32 a0);
extern void func_801726D0(void *a0);
extern u16 D_80126B58;

void func_8016EF78(s32 a0) {
    func_8016EFC8(a0);
    func_801726D0(&D_80126B58);
}
