/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157D20,80157D74).
 * Offset 0x2FBC8 at overlay base 80128158. SHA256(span)=634c5f19a6b9f389ad5f082eb192bdb1e596d9ea624836288bedea790bb825b5.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801806BC here is D_80180F44 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
extern u16 D_80180F44[];
void func_80156648();
void func_80147078();
void func_80157D74();
void func_80157D20(void *p, s32 a1) {
    func_80156648(p);
    func_80147078(p, D_80180F44[a1]);
    func_80157D74(p);
}
