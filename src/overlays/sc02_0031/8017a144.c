/* SC02 resident retail span [8017A144,8017A180). Offset 0x51FEC at base 80128158.
 * SHA256(span)=424027e85f83dcefe2628edce21c40875555ecc7016c3f80a91a9c5c7096d165.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018538C->D_801B7544.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"

extern s32 D_801B7544;
void func_80179B74(s16 *);                             /* static */

void func_8017A144(s32 arg0) {
    s16 sp10;

    sp10 = 0x1B;
    func_80179B74(&sp10);
    D_801B7544 = arg0;
}
