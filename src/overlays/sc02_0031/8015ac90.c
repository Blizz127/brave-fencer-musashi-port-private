/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015AC90,8015ACC4).
 * Offset 0x32B38 at overlay base 80128158. SHA256(span)=6cbaad2ee00a00cc5b6ae6192257cdaf26a1d7a18a14acdc58d6a9a1cc87331b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015ac90.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80154A74(s32, s32);                            /* static */
void func_801553C0();                                  /* static */

void func_8015AC90(s32 arg0) {
    func_801553C0();
    func_80154A74(arg0, 0x11);
}
