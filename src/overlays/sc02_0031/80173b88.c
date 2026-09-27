/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173B88,80173BC0).
 * Offset 0x4BA30 at overlay base 80128158. SHA256(span)=2f674519d2277c9d0301b8d770b04dc08b72dc81ff38bd52032a51630d83a551.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173b88.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80147060();                                  /* static */
void func_80171A1C(s32);                               /* static */
void func_80173BC0(s32);                               /* static */

void func_80173B88(s32 arg0) {
    func_80147060();
    func_80171A1C(arg0);
    func_80173BC0(arg0);
}
