/* SC02 resident retail span [80128940,80128998). Offset 0x7E8 at base 80128158.
 * SHA256(span)=cc0025330b2ec847e55d555a6a7f1b6b91924cd1ae44d3de2292ff4e18614e48.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80182D1C->D_801B5128.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_8001ABBC();
typedef struct { s32 a; void *b; } S;
extern S D_800C7C60;
extern s32 D_800A2E20;
extern void *D_801B5128;
extern s32 D_800AF560;
void func_80128940(void) {
    D_800C7C60.a = 94;
    D_800C7C60.b = &D_800A2E20;
    func_8001ABBC(0, 0, &D_800AF560, D_801B5128, &D_800C7C60);
}
