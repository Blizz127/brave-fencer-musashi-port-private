/* SC02.CD FILE_031 / ov_SC02_031 retail span [80180DB0,80180DF4).
 * Offset 0x58C58 at overlay base 80128158. SHA256(span)=ac370e4132679c7a47b6dc13e261082fc43d4f678fe7faf6f86b55b82cd1f8f1.
 * Jump-table callee from func_80180D74 via D_80188D6C; STOP pc=80180db0 ra=80180da0.
 * Donor shape: Druthulu ov_SC02_031_jr_8017AE2C func_80180DB0 (func_80181224 + func_800167B8).
 * NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text in jr_8017AE2C.
 */
#include "psx_types.h"

extern void func_80181224(void);
extern void func_800167B8(s32 arg0);

s32 func_80180DB0(u8 *arg0) {
    func_80181224();
    func_800167B8(0);
    arg0[0x15] = arg0[0x15] + 1;
    return 0;
}
