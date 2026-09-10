/* SC02 resident retail span [80128288,801282CC). Offset 0x130 at base 80128158.
 * SHA256(span)=6d7c4dd20813e292c7011e14f7eb59e1d6172ece4f3a4da047728bbd627805af.
 * Words are the guest's own loaded image (artifacts/sc02-resident-20260910),
 * not the sc01-title-code capture: that capture is a different member and
 * makes the port refuse at 801282AC. C is the member-0012 shape with the
 * dispatch table at this member's D_80184F08; oracle MATCH 17/17.
 * Not MAIN10.
 */
#include "psx_types.h"

extern u16 D_800B99F6;
extern void (*D_80184F08[])(void);

void func_80128288(void) {
    if (D_800B99F6 < 9U) {
        D_80184F08[D_800B99F6]();
    }
}
