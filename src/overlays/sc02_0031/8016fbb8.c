/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FBB8,8016FC24).
 * Offset 0x47A60 at overlay base 80128158. SHA256(span)=be5c64121bcc4a92ac5a850139ecd66048486036d38266c00abb5b185924cd63.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fbb8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801719A4();
void func_80171B44();
void func_80171990();
void func_8016FC24();
typedef struct Inner { u8 pad[0x12]; u16 unk12; } Inner;
typedef struct {
    u8 pad[0x20]; Inner *inner;
    u8 pad24[0x10E]; u16 f132; u8 pad134[2]; s16 f136;
} T;
void func_8016FBB8(T *p) {
    p->f136 = 2;
    p->f132 = p->inner->unk12;
    p->inner->unk12 = (p->inner->unk12 + 0x800) & 0xFFF;
    func_801719A4(p, 1);
    func_80171B44(p);
    func_80171990(p);
    func_8016FC24(p);
}
