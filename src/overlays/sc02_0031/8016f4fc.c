/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F4FC,8016F540).
 * Offset 0x473A4 at overlay base 80128158. SHA256(span)=f2d7a539db47d39ac00cd0486020421c6d67084f5bc6a394a471040d9f3f539c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f4fc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern void *D_8011F738;
void func_801719A4();
void func_800D1724();
void func_80171928();
void func_8016F4FC(void *p) {
    func_801719A4(p, 1);
    func_800D1724(D_8011F738);
    func_80171928(p);
}
