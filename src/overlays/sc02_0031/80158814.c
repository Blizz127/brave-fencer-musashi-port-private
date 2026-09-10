/* SC02 resident retail span [80158814,80158880). Offset 0x306BC at base 80128158.
 * SHA256(span)=df85df34b1ede7eba5fe90626ca863c3f756f7bbe331d8bbeddd689e85979291.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80184288->D_801B6440; D_80184294->D_801B644C; D_80184298->D_801B6450.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_801B6440;
extern s32 D_801B644C;
extern s32 D_801B6450;
void func_80147084();
void func_80147098();
void func_801470AC();
void func_80147078();
void func_80158880();
typedef struct { u8 pad[0xA8]; u8 fA8; } T;
void func_80158814(T *p) {
    D_801B6440 = 0;
    D_801B644C = 1;
    D_801B6450 = 0;
    p->fA8 = 0;
    func_80147084(p);
    func_80147098(p);
    func_801470AC(p);
    func_80147078(p, 0x1A);
    func_80158880(p);
}
