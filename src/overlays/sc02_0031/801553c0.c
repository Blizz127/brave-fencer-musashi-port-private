/* SC02.CD FILE_031 / ov_SC02_031 retail span [801553C0,80155440).
 * Offset 0x2D268 at overlay base 80128158. SHA256(span)=4eb55e7e33dc6d4bd23194cea8e79022c94a08d035ac355eebc0fd5c5712f89e.
 * STOP pc=801553c0 (func_801553C0), CPU_BOUNDARY/REFUSED, ra=8015a1dc.
 * Callee from burned func_8015A1C8 (jal 0C0554F0).
 * Donor shape: Druthulu shared/ov/func_801553C0.h (flag 0x10000000 at +0x44 via func_80029178(0x12F); func_8001D150(*(+(0x20)+0x24), 0x15)).
 * NOT MAIN10; NOT in parked PAC0 hole 8014E934…80153C8C; later SC02 text near jr_80154C24 / shared OV body.
 */
#include "psx_types.h"

extern s32 func_80029178(s32 arg0);
extern void func_8001D150(s32 arg0, s32 arg1);

void func_801553C0(s32 arg0) {
    s32 *flags;

    flags = (s32 *)(arg0 + 0x44);
    if ((*flags & 4) != 0 || (func_80029178(0x12F) & 0xFF) != 0) {
        *flags = *flags & 0xEFFFFFFF;
    } else {
        *flags = *flags | 0x10000000;
    }
    func_8001D150(*(s32 *)(*(s32 *)(arg0 + 0x20) + 0x24), 0x15);
}
