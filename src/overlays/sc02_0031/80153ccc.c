/* SC02 resident retail span [80153CCC,80153D34). Offset 0x2BB74 at base 80128158.
 * SHA256(span)=2c69a74c710f0171cbe31410a50f7cd8195581f643f9a5af88ed67978d3bebbe.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180178->D_80186A68; D_801801A0->D_80186A90.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186A90[];
void func_80019064();
extern s32 D_80186A68;
extern s16 D_8011DB0C;
extern s16 D_8011F748;
typedef struct { u8 pad[2]; u16 idx; } T;
void func_80153CCC(T *p) {
    func_80019064(&D_80186A68);
    D_80186A90[p->idx](p);
    D_8011DB0C = 0;
    D_8011F748 = 0;
}
