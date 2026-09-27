/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155B9C,80155C0C).
 * Offset 0x2DA44 at overlay base 80128158. SHA256(span)=9c8a9cde8c462b98ed65007b70456c551259d06cdfc4e02f6cfaa4021f5f6b90.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155b9c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_800D4DB4;
void func_80148038();
void func_80147460();
void func_80154274();
void func_80146CA0();
void func_80147324();
typedef struct {
    u8 pad[0x34];
    s32 unk34;
    u8 pad38[0xC];
    u32 flags;
} T;
void func_80155B9C(T *p) {
    p->flags |= 2;
    func_80148038(p, 0x30000);
    func_80147460(p);
    if (p->unk34 >= 0) {
        func_80154274(p, &D_800D4DB4);
        func_80146CA0(p);
        func_80147324(0x447);
    }
}
