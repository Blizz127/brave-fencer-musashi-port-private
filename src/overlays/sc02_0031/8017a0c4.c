/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A0C4,8017A0F4).
 * Offset 0x51F6C at overlay base 80128158. SHA256(span)=6581c2eacf0a2a4f52e3d4a137033b14402a653f40aeb0dbd701f1e2b94eaa4e.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80185364->D_801A568C.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_801A568C;
void func_80179B74(s16 *);                             /* static */

void func_8017A0C4(s32 arg0) {
    s16 sp10;

    D_801A568C = arg0;
    sp10 = 0x16;
    func_80179B74(&sp10);
}
