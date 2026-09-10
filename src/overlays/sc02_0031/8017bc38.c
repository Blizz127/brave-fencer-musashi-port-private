/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017BC38,8017BCA0).
 * Offset 0x53AE0 at overlay base 80128158. SHA256(span)=d32dcd18c31d513e3684d7aeff313ae8821c5d09512eb56321f0523ea942e44e.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80185394->D_801A56BC.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801A56BC[10];
void func_8017BC38(void *p) {
    s32 i;
    for (i = 0; i < 10; i++) {
        if (D_801A56BC[i])
            D_801A56BC[i](p);
    }
}
