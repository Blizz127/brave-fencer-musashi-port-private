/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162F08,80162F60).
 * Offset 0x3ADB0 at overlay base 80128158. SHA256(span)=ad96031ff1fb59723f83044bc1ac58a42e89cc148d3a72a8a34f0921385ef6c0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162f08.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80162F60();
void func_80162F80();
void func_80162FA0();
void func_80162F08(void *p, s32 a1, s32 a2, s32 a3) {
    func_80162F60(p, a1);
    func_80162F80(p, a2);
    func_80162FA0(p, a3);
}
