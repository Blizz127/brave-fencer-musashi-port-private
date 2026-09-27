/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F7D4,8016F804).
 * Offset 0x4767C at overlay base 80128158. SHA256(span)=6f885361506ea07ff26d3d17505072ed66232023eb9ed97713fdbaf1c9cbbda0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f7d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8016F804(s32);                               /* static */
void func_80171990();                                  /* static */

void func_8016F7D4(s32 arg0) {
    func_80171990();
    func_8016F804(arg0);
}
