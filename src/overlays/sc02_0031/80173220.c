/* SC02 resident retail span [80173220,80173294). Offset 0x4B0C8 at base 80128158.
 * SHA256(span)=cbe51b1a180016100f5b89e7ff00dfdfb0695f96d0a7304ee10e64ce485194d4.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801818F8->D_801881E8.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80147324();
void func_80019064();
void func_80171A1C();
void func_80174650();
extern s32 D_801881E8;
typedef struct { u8 pad[0xB8]; u16 b8; } T;
void func_80173220(T *p) {
    if (p->b8 & 0x4000) {
        func_80147324(0x516);
        func_80019064(&D_801881E8);
    }
    if (p->b8 & 0x8000) {
        func_80171A1C(p);
        func_80174650(p);
    }
}
