/* SC02 resident retail span [8017B8E8,8017B940). Offset 0x53790 at base 80128158.
 * SHA256(span)=c70271f0aefe57b9c25576a0702f058eb9c77fd21ddfc9478b4ac7f7fc9b3e01.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801853BC->D_801B7574; D_801853C4->D_801B757C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_801B757C;
extern S D_801B7574;
void func_8017B8E8(S *p) {
    D_801B757C = p[0];
    D_801B7574 = p[1];
}
