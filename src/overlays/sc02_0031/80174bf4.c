/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174BF4,80174C60).
 * Offset 0x4CA9C at overlay base 80128158. SHA256(span)=2992e7d940db6782c54ba1e641cf756d5879e482853a706cff7688926a4a27de.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801819F8 here is D_80182280 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80182280[];
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
    D_80182280[p->idx]();
}
