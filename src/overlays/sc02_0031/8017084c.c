/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017084C,801708B0).
 * Offset 0x486F4 at overlay base 80128158. SHA256(span)=63343b1d88a5f276ffb74fcdc77b5f1539c9a52ccde6e66f9d1674c870acdff6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017084c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_800D5DA8;
void func_801719A4();
void func_8014706C();
void func_80154274();
void func_8016BADC();
void func_80171990();
void func_801708B0();
void func_8017084C(void *p) {
    func_801719A4(p, 1);
    func_8014706C(p);
    func_80154274(p, &D_800D5DA8);
    func_8016BADC(p, -0x40, 0x40);
    func_80171990(p);
    func_801708B0(p);
}
