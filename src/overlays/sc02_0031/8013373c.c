/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013373C,80133784).
 * Offset 0xB5E4 at overlay base 80128158. SHA256(span)=ab4ee26cfaf101c0b674f0270d3ce47c611fd9d842a485e36a1182b93a55e0ae.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80184120->D_801A4448; D_80184124->D_801A444C.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80136BC4();
extern void *D_801A444C[];
extern void *D_801A4448;
void func_8013373C(s32 a0) {
    void *p = D_801A444C[(s16)a0];
    if (p) {
        D_801A4448 = p;
        func_80136BC4(p);
    }
}
