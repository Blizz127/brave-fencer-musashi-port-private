/* SC02 resident retail span [80161034,80161094). Offset 0x38EDC at base 80128158.
 * SHA256(span)=ca03ce17e957cad8acc6a256becd7637d286aa0d8026b8bb31257cca7093f44f.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
void func_80149020();
void func_80147078();
void func_80159B70();
void func_80161034(u16 *p) {
    func_80149020(p);
    D_8018730C[p[0]](p);
    func_80147078(p, 0);
    func_80159B70(p);
}
