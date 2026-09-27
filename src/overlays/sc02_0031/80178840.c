/* SC02 resident retail span [80178840,801788B8). Offset 0x506E8 at base 80128158.
 * SHA256(span)=3491648a8073928ebe9d7e5df2b1b1a591c9310fa18925a9d7fbdff4d071550f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80181BC4->D_801884B4; D_80181BD0->D_801884C0.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80019064();
void func_80131E00();
extern s32 D_801884B4;
extern s32 D_801884C0[];
typedef struct { u8 pad[0x5C]; u16 u5C; u8 u5E; } T;
void func_80178840(T *p) {
    u8 n;
    if ((p->u5C & 1) == 0) {
        return;
    }
    n = p->u5E;
    if (n == 0xC) {
        func_80019064(&D_801884B4);
    }
    func_80131E00(p, D_801884C0[n]);
}
