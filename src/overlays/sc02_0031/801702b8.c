/* SC02.CD FILE_031 / ov_SC02_031 retail span [801702B8,801702FC).
 * Offset 0x48160 at overlay base 80128158. SHA256(span)=31b47dbe83dacaf8cb4e715ecd5fb5aaf2d2b1c56cc1ac29e5b9371295566293.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801702b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80171AB0();
void func_80171928();
extern u8 D_8011F738;
void func_801702B8(void *p) {
    if ((s16)func_80171AB0(p, &D_8011F738) == 0) {
        func_80171928(p);
    }
}
