/* SC02.CD FILE_031 / ov_SC02_031 retail span [801528B0,8015294C).
 * Offset 0x2A758 at overlay base 80128158. SHA256(span)=6153313b40343e738e7a87f7444ee52c4a2d86f0169403beacf7aace3c5df614.
 * Differs from the registry-verified MAIN member 0012 carve in one data
 * reference only: the member-0012 block is 0x888 lower, so the symbol
 * moved from D_80180000..D_80180887 to +0x888. Oracle MATCH re-earned
 * against the SC02 blob; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80062C04;
extern s32 D_800D5880;
extern s32 D_80180984;
void func_80019064();
void func_80151204();
void func_80149020();
void func_80154274();
void func_80147324();
void func_80146DB8();
void func_801477E8();
void func_8014CBF8();
void func_801474EC();
void func_80146CA0();
typedef struct { u8 pad[0xDE]; u8 fDE; u8 padDF[0xF2-0xDF]; s16 fF2; } T;
void func_801528B0(T *p) {
    func_80019064(&D_80062C04);
    func_80151204(p, p->fF2);
    func_80149020(p);
    func_80154274(p, &D_800D5880);
    func_80147324(0x451);
    p->fDE = 0x10;
    func_80146DB8(p, &D_80180984);
    func_801477E8(p, 0xFFF00000);
    func_8014CBF8(p);
    func_801474EC(p);
    func_80146CA0(p);
}
