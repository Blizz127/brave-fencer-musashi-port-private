/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BE94,8015BEC4).
 * Offset 0x33D3C at overlay base 80128158. SHA256(span)=505f5faa6c942bb0acd20ff68f686ff6f90a9fb34fadf4d23899b43473efc673.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015be94.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80146CA0(s32);                               /* static */
void func_80161124();                                  /* static */

void func_8015BE94(s32 arg0) {
    func_80161124();
    func_80146CA0(arg0);
}
