/* SC02 resident retail span [80174BF4,80174C60). Offset 0x4CA9C at base 80128158.
 * SHA256(span)=e25adac374471d8a77a5279883bb13ad0a13258fc9d66b3527c2ec059590c71a.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801819F8->D_801882E8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801882E8[];
typedef struct {
    u8 pad[4];
    u8 idx;
    u8 pad5[7];
    s32 unkC;
    u8 pad10[4];
    s32 unk14;
    u8 pad18[8];
    s16 unk20, unk22, unk24;
    u8 pad26[8];
    s16 unk2E, unk30, unk32;
    u8 pad34[0x20];
    s32 unk54;
} T;
void func_80174BF4(T *p) {
    p->unkC = 0x12C;
    p->unk14 = 0x12C;
    p->unk20 = 0x155;
    p->unk22 = 0x800;
    p->unk24 = 0;
    p->unk2E = 0;
    p->unk30 = -0x28;
    p->unk32 = 0;
    p->unk54 = 0;
    D_801882E8[p->idx]();
}
