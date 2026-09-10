/* SC02.CD FILE_031 / ov_SC02_031 retail span [801520DC,80152194).
 * Offset 0x29F84 at overlay base 80128158. SHA256(span)=6ee7fea00bbcb7dd9033f70f5989a57ba0b8ccfd45526b8624dd015291bc0fce.
 * Differs from the registry-verified MAIN member 0012 carve in one data
 * reference only: the member-0012 block is 0x888 lower, so the symbol
 * moved from D_80180000..D_80180887 to +0x888. Oracle MATCH re-earned
 * against the SC02 blob; Not MAIN10.
 */
#include "psx_types.h"
void func_80019064();
void func_80151204();
void func_80149020();
void func_801472C8();
void func_80146DB8();
void func_801477E8();
void func_8014CBF8();
void func_801474EC();
void func_80146A6C();
void func_80147324();
void func_80146CA0();
extern s32 D_80062C04;
extern s32 D_8018093C;
typedef struct {
    u8 pad[6]; s16 a; u8 pad8[2]; s16 b; u8 padC[2]; s16 c;
    u8 pad10[0xCE]; u8 de;
    u8 padDF[0x13]; s16 uF2;
} T;
void func_801520DC(T *p) {
    func_80019064(&D_80062C04);
    func_80151204(p, p->uF2);
    func_80149020(p);
    func_801472C8(p);
    p->de = 0x10;
    func_80146DB8(p, &D_8018093C);
    func_801477E8(p, 0x40000);
    func_8014CBF8(p);
    func_801474EC(p);
    func_80146A6C(0x10, p, p->a, p->b, p->c, 0, 0);
    func_80147324(0x441);
    func_80146CA0(p);
}
