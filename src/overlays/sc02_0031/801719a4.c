/* SC02 resident retail span [801719A4,80171A04). Offset 0x4984C at base 80128158.
 * SHA256(span)=1e4261792af44e9d627aa8a2e58189312129372bb0bc8f28d2da50eee4326344.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_801719A4 shape (h_exact 7890648e); its data D_8011F738 already matches this member; oracle MATCH 24/24.
 * Not MAIN10.
 */
#include "psx_types.h"

extern void *D_8011F738;

void func_801719A4(int a0, int a1)
{
    u32 i;
    s32 off;

    for (i = 0; i < (u32)a1; i++) {
        off = i * 4;
        *(s32 *)((s32)&D_8011F738 + off) =
            *(s32 *)(((*(u8 *)(a0 + 0x214) + i) << 2) + *(s32 *)(a0 + 0x1FC));
    }
    *(u8 *)(a0 + 0x214) += i;
}
