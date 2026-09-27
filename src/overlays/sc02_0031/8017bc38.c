/* SC02 resident retail span [8017BC38,8017BCA0). Offset 0x53AE0 at base 80128158.
 * SHA256(span)=7325fca391814e8ad5e6d50a47991861bbc5b2ec9d7bd50c0d144849a8baadac.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80185394->D_801B754C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801B754C[10];
void func_8017BC38(void *p) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (D_801B754C[i])
            D_801B754C[i](p);
    }
}
