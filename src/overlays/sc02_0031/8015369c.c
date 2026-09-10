/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015369C,801536DC).
 * Offset 0x2B544 at overlay base 80128158. SHA256(span)=75b5105e205aa9d49e2ddff5ec15f0418db0e520405a484910aee493b2cd0f69.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015369c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8011DB28;
void func_8015369C(u8 *p) {
    if (D_8011DB28)
        D_8011DB28(p + 0xA0);
    p[0xDE] = 0x5A;
}
