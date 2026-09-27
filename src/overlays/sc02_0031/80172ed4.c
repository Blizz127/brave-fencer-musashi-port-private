/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172ED4,80172EFC).
 * Offset 0x4AD7C at overlay base 80128158. SHA256(span)=e3d11cc90b74ad01f2d52989185141931d81b7a3ee5d1bdd242c10d7e4da1eeb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172ed4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8017303C(void *);                               /* static */
extern s32 *D_800D59EC;

void func_80172ED4(void) {
    func_8017303C(&D_800D59EC);
}
