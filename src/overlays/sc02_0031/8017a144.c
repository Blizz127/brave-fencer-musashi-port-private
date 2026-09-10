/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A144,8017A180).
 * Offset 0x51FEC at overlay base 80128158. SHA256(span)=7436ea076d087b8d08b369a014c8cb7761b780d546b619eea852e23fbc4fa3e8.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_8018538C->D_801A56B4.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_801A56B4;
void func_80179B74(s16 *);                             /* static */

void func_8017A144(s32 arg0) {
    s16 sp10;

    sp10 = 0x1B;
    func_80179B74(&sp10);
    D_801A56B4 = arg0;
}
