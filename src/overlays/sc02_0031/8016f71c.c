/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F71C,8016F764).
 * Offset 0x475C4 at overlay base 80128158. SHA256(span)=fbcf63603c710ec4119d4e7fbc4431f842731a0b969a1e3b0010efbddd887bfc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f71c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8011F738;
void func_801719A4();
void func_80171990();
void func_8016F764();
typedef struct {
    u8 pad_0[512];
    void * ptr;
} T;
void func_8016F71C(T *p) {
    func_801719A4(p, 1);
    p->ptr = D_8011F738;
    func_80171990(p);
    func_8016F764(p);
}
