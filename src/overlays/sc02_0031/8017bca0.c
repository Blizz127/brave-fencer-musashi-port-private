/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017BCA0,8017BCF4).
 * Offset 0x53B48 at overlay base 80128158. SHA256(span)=b30d560c43092b9e9f8dbe98372549274f85a777707e0b21db57e02980b629c7.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8018534C->D_801A5674; D_80185C08->D_801A5870.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_8017B0E4();
extern s16 D_801A5674;
extern s16 D_801A5870;
void func_8017BCA0(void *p) {
    func_8017B0E4(p, 0xC);
    D_801A5674 = D_801A5674 + 1;
    if (D_801A5674 >= 0x1F) {
        D_801A5870 = 2;
    }
}
