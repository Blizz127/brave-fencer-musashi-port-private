/* SC02 resident retail span [8015EE7C,8015EEE0). Offset 0x36D24 at base 80128158.
 * SHA256(span)=e9fbc92effec2d3a0048b8a56dde126a3624cdc11dd1399612c3f3d0b92ddd0f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A00->D_801872F0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_800D4C48;
extern s32 D_801872F0;
void func_8014CBF8();
void func_801474EC();
void func_80154274();
void func_80146DB8();
void func_801477E8();
void func_80146CA0();
void func_8015EE7C(void *p) {
    func_8014CBF8(p);
    func_801474EC(p);
    func_80154274(p, &D_800D4C48);
    func_80146DB8(p, &D_801872F0);
    func_801477E8(p, 0xFFF40000);
    func_80146CA0(p);
}
