/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013B7AC,8013B7F4).
 * Offset 0x13654 at overlay base 80128158. SHA256(span)=cb5d40e39405d61e2cedf9bbaba3bb13814aebec5d7f5aaece60cdf9a07e6a5c.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80185B58->D_801A57C0.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef struct { s32 a; u8 pad[24]; } S;
extern S D_801A57C0[];
void func_8013B7AC(s32 a0) {
    D_801A57C0[a0].a = 0;
}
