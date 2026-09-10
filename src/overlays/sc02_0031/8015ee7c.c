/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015EE7C,8015EEE0).
 * Offset 0x36D24 at overlay base 80128158. SHA256(span)=4c5b04ee38b8eee12805a7f5995fd7585b7229a5b6c5af248b231e5009f27603.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A00 here is D_80181288 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_800D4C48;
extern s32 D_80181288;
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
    func_80146DB8(p, &D_80181288);
    func_801477E8(p, 0xFFF40000);
    func_80146CA0(p);
}
