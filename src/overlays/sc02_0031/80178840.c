/* SC02.CD FILE_031 / ov_SC02_031 retail span [80178840,801788B8).
 * Offset 0x506E8 at overlay base 80128158. SHA256(span)=05fb262861669eaf5b94ab9676a82f18240e79351f3c8fb1a6b11968463798c8.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80181BC4->D_8018244C; D_80181BD0->D_80182458.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80019064();
void func_80131E00();
extern s32 D_8018244C;
extern s32 D_80182458[];
typedef struct { u8 pad[0x5C]; u16 u5C; u8 u5E; } T;
void func_80178840(T *p) {
    u8 n;
    if ((p->u5C & 1) == 0) {
        return;
    }
    n = p->u5E;
    if (n == 0xC) {
        func_80019064(&D_8018244C);
    }
    func_80131E00(p, D_80182458[n]);
}
