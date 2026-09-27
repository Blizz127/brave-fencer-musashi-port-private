/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170784,801707D4).
 * Offset 0x4862C at overlay base 80128158. SHA256(span)=d39054d3df36fdbdc98aed071e079c42bddc6b96f702afd23c0b6deae32daadc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170784.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8011F738;
void func_801719A4();
void func_80171990();
void func_801707D4();
void func_80170784(void *p) {
    func_801719A4(p, 1);
    D_8011F738();
    func_80171990(p);
    func_801707D4(p);
}
