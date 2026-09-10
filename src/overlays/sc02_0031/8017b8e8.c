/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017B8E8,8017B940).
 * Offset 0x53790 at overlay base 80128158. SHA256(span)=b9c264bb3101f53689249e331e26077061ae042b9ba60b40a150cbdcb9424edc.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_801853BC->D_801A56E4; D_801853C4->D_801A56EC.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_801A56EC;
extern S D_801A56E4;
void func_8017B8E8(S *p) {
    D_801A56EC = p[0];
    D_801A56E4 = p[1];
}
