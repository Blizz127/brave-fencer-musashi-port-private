/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142A10,80142A80).
 * Offset 0x1A8B8 at overlay base 80128158. SHA256(span)=f9b6b944a34aa0f689a07b0c1df039012e609e76dd54103636de74b7bf8a73a6.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8017FA7C here is D_80180304 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80180304[];
extern s16 D_801270C0;
void func_80142A80();
typedef struct { u16 a, idx; u8 pad[0xF8]; s16 unkFC; } T;
void func_80142A10(T *p) {
    if (D_801270C0 != 3) {
        D_80180304[p->idx]();
        if (p->unkFC)
            func_80142A80(p);
    }
}
