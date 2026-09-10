/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172310,80172358).
 * Offset 0x4A1B8 at overlay base 80128158. SHA256(span)=b181fd5953271535c8fe3d4c60fe7f17fb28a8abbd2f56870cb2b4113abdb70d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172310.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80172358();
extern s32 D_80126B58;
typedef struct { u8 pad[6]; u16 unk6; } T;
typedef struct { u8 pad[0x12]; u16 unk12; } G;
extern G *D_80126B78;
void func_80172310(T *p) {
    func_80172358(&D_80126B58, p);
    D_80126B78->unk12 = p->unk6;
}
