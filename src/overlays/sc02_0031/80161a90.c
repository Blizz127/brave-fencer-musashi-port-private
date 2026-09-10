/* SC02 resident retail span [80161A90,80161B18). Offset 0x39938 at base 80128158.
 * SHA256(span)=6447d02f5b4ebe5a4a0a33455f61433fa69ffeb0996a2502f8d32e3e8a6d1eb0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_80161A90 shape (h_exact 7604e5da) whose data D_80078E78/D_80078EC0 already match this member; oracle MATCH 34/34.
 * Not MAIN10.
 */
#include "psx_types.h"

extern u8 D_80078E78[];
extern u8 D_80078EC0;
void func_8014AC10(s32 a0);

void func_80161A90(s32 a0)
{
    u8 *p = D_80078E78;
    s32 t;
    if (*(s16 *)(a0 + 0x1C8) == 0) {
        t = 0;
    } else {
        t = ((D_80078EC0 & 0x7F) == 6);
    }
    if (t != 0) {
        *(u16 *)(a0 + 0x1C8) -= 1;
    }
    if ((p[0x48] & 0x7F) == 6) {
        if (*(s16 *)(a0 + 0x1C8) == 0) {
            func_8014AC10(0x3B);
        }
    }
}
