/* SC02 resident retail span [801578C0,8015795C). Offset 0x2F768 at base 80128158.
 * SHA256(span)=516dfd1c5013a382a29909fa1df76d27a8b1fa559492500c24ca76aa3eecb4de.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018066C->D_80186F5C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_800D5128;
extern s32 D_80186F5C;
void func_80156648();
void func_80154274();
void func_80154A74();
void func_80147324();
void func_80146DB8();
void func_80146994();
void func_80146CA0();
void func_801725A4();
typedef struct { u8 pad[0x1AA]; u8 f1AA; } T;
void func_801578C0(T *p) {
    func_80156648(p);
    p->f1AA = 9;
    func_80154274(p, &D_800D5128);
    func_80154A74(p, 0x15);
    func_80147324(0xC20);
    func_80146DB8(p, &D_80186F5C);
    func_80146994(4, p, 7, 0);
    func_80146994(5, p, 9, 0);
    func_80146CA0(p);
    func_801725A4(p);
}
