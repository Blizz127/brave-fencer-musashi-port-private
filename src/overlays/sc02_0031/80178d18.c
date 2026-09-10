/* SC02.CD FILE_031 / ov_SC02_031 retail span [80178D18,80178D40).
 * Offset 0x50BC0 at overlay base 80128158. SHA256(span)=a85e4e7ba554c2b2a8f33c40dde88d7105f34692db05119791e54036e0172bac.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80185C7C->D_801A58E4.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

void func_80174714();                                  /* static */
extern s16 D_801A58E4;

void func_80178D18(void) {
    D_801A58E4 = 0;
    func_80174714();
}
