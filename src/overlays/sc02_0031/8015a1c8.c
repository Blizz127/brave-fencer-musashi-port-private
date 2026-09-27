/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015A1C8,8015A1FC).
 * Offset 0x32070 at overlay base 80128158. SHA256(span)=6cbaad2ee00a00cc5b6ae6192257cdaf26a1d7a18a14acdc58d6a9a1cc87331b.
 * STOP pc=8015a1c8 (func_8015A1C8), CPU_BOUNDARY/REFUSED, ra=801599d0, jalr via D_8018730C.
 * Callee from burned func_801599A4 (jalr D_8018730C[*a0]).
 * Donor shape: Druthulu shared/ov/func_8015A1C8.h (func_801553C0 + func_80154A74(a0, 0x11)).
 * NOT MAIN10; NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text near jr_80159C84 / shared OV body.
 */
#include "psx_types.h"

extern void func_801553C0(s32 arg0);
extern void func_80154A74(s32 arg0, s32 arg1);

void func_8015A1C8(s32 arg0) {
    func_801553C0(arg0);
    func_80154A74(arg0, 0x11);
}
