/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016634C,801663A4).
 * Offset 0x3E1F4 at overlay base 80128158. SHA256(span)=f2b153c6509d8ae7dcf86ffb27d5b0895bb69785df869fa3a4df516afef3c7db.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016634c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80146A6C();
void func_8016634C(s16 *p) {
    func_80146A6C(3, p, p[3], (s16)((u16)p[5] - 0x10), p[7], 0x0EEEFFF8, 0x6800B000);
}
