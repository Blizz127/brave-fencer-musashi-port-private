/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154ED8,80154F9C).
 * Offset 0x2CD80 at overlay base 80128158. SHA256(span)=4bc3ebb62861f3b53d9e7a98a90b78d7194bb4a1e044ced2126e634e8b27ccb4.
 * Shape from Druthulu shared/ov donor func_80154ED8.h (h_exact bd2f9eeb); re-earned through the oracle on the retail blob:
 * 49/49 words at -O2 -G0.
 * Not MAIN10.
 */
#include "psx_types.h"

extern s16 D_80078E96;
extern u8 D_800D8D10[];
extern s16 D_80078E9E;
extern u16 D_80078EA6;
extern void func_801550FC(s32 a0);
void func_80154ED8(s32 a0, s32 a1) {
    *(s32 *)(a0 + 0xC8) = a1;
    if (D_80078E96 & 0x8000) {
        *(s32 *)(a0 + 0xC8) = a1 | 0x1000000;
        func_801550FC((s32)D_800D8D10);
        return;
    }
    if (D_80078E9E >= 0x10) {
        if (*(s16 *)&D_80078EA6 >= 0x10) {
            goto and_path;
        }
    }
    if ((*(s32 *)(a0 + 0x44) & 0xC0) != 0) {
        goto and_path;
    }
    *(s32 *)(a0 + 0xC8) = a1 | 0x1000000;
    func_801550FC(0x40000002);
    return;
and_path:
    *(s32 *)(a0 + 0xC8) = *(s32 *)(a0 + 0xC8) & 0xC0FFFFFF;
    func_801550FC(a1);
}
