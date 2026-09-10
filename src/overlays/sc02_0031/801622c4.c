/* SC02.CD FILE_031 / ov_SC02_031 retail span [801622C4,80162330).
 * Offset 0x3A16C at overlay base 80128158. SHA256(span)=997ede9c8d45abaa2f04c77470682fd1ce220c6c1c7fb18c307a51fcdedf1e40.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801842A0->D_801A45C8.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80029124();
void func_800291C8();
void func_80016714();
extern void *D_801A45C8[3];
void func_801622C4(void) {
    s32 i;
    func_80029124(0x141, 1);
    func_800291C8(8, 0);
    for (i = 0; i < 3; i++) {
        func_80016714(D_801A45C8[i], 0x38);
    }
}
