/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152DA8,80152E4C).
 * Offset 0x2AC50 at overlay base 80128158. SHA256(span)=7b59cff64d6fd91aa633421af0b22ee23eb999ff74da94af133d2f2bca74e517.
 * Differs from the registry-verified MAIN member 0012 carve in one data
 * reference only: the member-0012 block is 0x888 lower, so the symbol
 * moved from D_80180000..D_80180887 to +0x888. Oracle MATCH re-earned
 * against the SC02 blob; Not MAIN10.
 */
#include "psx_types.h"
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
extern s32 D_80062C14;
extern s32 D_800D5880;
extern s32 D_801809B4;
typedef struct { u8 pad[0xDE]; u8 de, df; u8 padE0[0x12]; s16 uF2; } T;
void func_80152DA8(T *p) {
    func_80019064(&D_80062C14);
    func_80151204(p, p->uF2);
    func_80149020(p);
    func_80154274(p, &D_800D5880);
    func_80147324(0x451);
    p->de = 0x10;
    p->df = 8;
    func_80146DB8(p, &D_801809B4);
    func_801477E8(p, 0xFFE40000);
    func_8014CBF8(p);
    func_801474EC(p);
    func_80146CA0(p);
}
