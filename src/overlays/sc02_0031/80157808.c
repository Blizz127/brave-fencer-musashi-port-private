/* SC02 resident retail span [80157808,80157880). Offset 0x2F6B0 at base 80128158.
 * SHA256(span)=f0a2606eb8638a02e85293c76ec3eeea67ee714c54bf1e7ba19e3aed8956508b.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8018068C->D_80186F7C; D_80184280->D_801B6438.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_80186F7C[];
extern s32 D_801B6438;
void func_801599A4();
void func_80159B3C();
void func_80157808(u16 *p) {
    D_80186F7C[p[1]]();
    if (--D_801B6438 == -1) {
        func_801599A4(p);
        func_80159B3C(p);
    }
}
