/* SC02 resident retail span [80142A10,80142A80). Offset 0x1A8B8 at base 80128158.
 * SHA256(span)=98ea06f3e8034aff057074c2cafa499f8b2d5d49da87cf0dda6222cab74248b3.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017FA7C->D_8018636C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018636C[];
extern s16 D_801270C0;
void func_80142A80();
typedef struct { u16 a, idx; u8 pad[0xF8]; s16 unkFC; } T;
void func_80142A10(T *p) {
    if (D_801270C0 != 3) {
        D_8018636C[p->idx]();
        if (p->unkFC)
            func_80142A80(p);
    }
}
