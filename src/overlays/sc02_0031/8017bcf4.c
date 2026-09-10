/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017BCF4,8017BD50).
 * Offset 0x53B9C at overlay base 80128158. SHA256(span)=0e17e09a97d485729527b6b60266f4498fbfa5cd5c8baa4898e3e015fb3cfb94.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8018534C->D_801A5674; D_80185C08->D_801A5870.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_8017B0E4();
void func_8012A4BC();
extern s16 D_801A5674;
extern s16 D_801A5870;
void func_8017BCF4(void *p) {
    func_8017B0E4(p, 6);
    D_801A5674++;
    if (D_801A5674 >= 0x19) {
        func_8012A4BC();
        D_801A5870 = 0;
    }
}
