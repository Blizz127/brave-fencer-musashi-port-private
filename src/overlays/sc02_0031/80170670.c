/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170670,801706AC).
 * Offset 0x48518 at overlay base 80128158. SHA256(span)=f1233c5070c566fc20f9193f231155cfca78b4c4c9193b4c3d893da84a25dc91.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170670.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8012A568(s32);                               /* static */
void func_80171928(s32);                               /* static */
extern s32 D_8011F738;

void func_80170670(s32 arg0) {
    func_8012A568(D_8011F738);
    func_80171928(arg0);
}
