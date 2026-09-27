/* SC02.CD FILE_031 / ov_SC02_031 retail span [801426D4,80142740).
 * Offset 0x1A57C at overlay base 80128158. SHA256(span)=34a5c8ea3e686cf00f774692f28eb5d525da2f08df76f3272200a8da5261a25d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801426d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8012AD50();
typedef struct Inner { u8 pad[0x18]; u16 u18, u1A; } Inner;
typedef struct {
    u8 pad[0x1C]; s32 u1C;
    Inner *inner;
    u8 pad24[0xD8]; s16 uFC;
} T;
void func_801426D4(T *p) {
    Inner *in = p->inner;
    if (p->uFC) {
        p->uFC = p->uFC - 0x10;
        in->u18 = in->u18 + 0x800;
        in->u1A = in->u1A + 0x800;
    } else {
        p->u1C = 0xC;
        func_8012AD50(p);
        in->u1A = 0x1800;
        in->u18 = 0x1800;
    }
}
