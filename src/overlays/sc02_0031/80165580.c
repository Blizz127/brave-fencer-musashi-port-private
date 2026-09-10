/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165580,801655E4).
 * Offset 0x3D428 at overlay base 80128158. SHA256(span)=745f0cb828a8948fcd6168299f2ccd0deaf31e9f11420551cb6cab9347e9dacf.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180FE4 here is D_8018186C (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018186C[];
extern u8 D_80078EC5;
extern u8 D_80078EC1;
void func_80165B28();
void func_80165580(void *p) {
    if (D_80078EC5 & 0x80)
        func_80165B28(p);
    else
        D_8018186C[D_80078EC1 & 0x7F]();
}
