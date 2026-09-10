/* SC02 resident retail span [80161C24,80161C98). Offset 0x39ACC at base 80128158.
 * SHA256(span)=438d481f1b636c166a16d4667b23cc6f9819a43811b2bb1f2cc9853592949590.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180E38->D_80187728.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80147324();
typedef struct { u16 a, b; } E;
extern E D_80187728[];
typedef struct { u8 pad[0xDA]; u8 uDA; } T;
void func_80161C24(T *p, u32 a1) {
    if (a1 >= 8) {
        return;
    }
    if (p->uDA) {
        func_80147324(D_80187728[a1].a);
        p->uDA = 0;
        return;
    }
    func_80147324(D_80187728[a1].b);
    p->uDA = 1;
}
