/* SC02.CD FILE_031 / ov_SC02_031 retail span [801598BC,801598E0).
 * Offset 0x31764 at overlay base 80128158. SHA256(span)=c32052f384fdfbe837f759d580e00d34f7b158a3b9b771e2d2d5f61348e2a9ae.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801598bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

s32 func_800167F0();                               /* extern */

s32 func_801598BC(void) {
    return (func_800167F0(4) & 0xFFFF) != 0;
}
