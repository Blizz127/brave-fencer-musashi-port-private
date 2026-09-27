/* SC02 resident retail span [801654A8,80165580). Offset 0x3D350 at base 80128158.
 * SHA256(span)=94a45dfbebddf34e5cf8c96574ba577cb175c5c7e959e2ff927a281a0738b6c2.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910);
 * the C is the Druthulu shared/ov func_801654A8 shape (the two published variants differ only in the dispatch table) retargeted to this member's D_801878D4, with D_80078E78/D_80078EC1 already matching; oracle MATCH 54/54.
 * Not MAIN10.
 */
#include "psx_types.h"

extern u8 D_80078E78[];
extern u8 D_80078EC1;
extern void *D_801878D4[];
s32 func_80165658(s32 a0, s32 a1);
void func_800CAE0C(s32 a0);

void func_801654A8(s32 arg0)
{
    u8 *s1 = D_80078E78;

    if (*(u16 *)arg0 == 0x16) {
        return;
    }
    if (*(u16 *)arg0 != 0x1A) {
        if ((*(s32 *)(arg0 + 0x1F8) & 0x80FFFFFF) == 0) {
            if (func_80165658(arg0, D_80078EC1) & 0x80) {
                ((void (*)(s32))D_801878D4[D_80078EC1 & 0x7F])(arg0);
            }
        }
    }
    if (*(u16 *)arg0 == 0x16) {
        return;
    }
    if (*(u16 *)arg0 == 0x1A) {
        return;
    }
    if (s1[0x49] == 0x19) {
        func_800CAE0C(arg0);
    }
}
