/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173220,80173294).
 * Offset 0x4B0C8 at overlay base 80128158. SHA256(span)=a5bb1f238a3020563c5226970246dfc07f0525b3d6c2bfd6cfd38c7f670a16f5.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_801818F8 here is D_80182180 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80147324();
void func_80019064();
void func_80171A1C();
void func_80174650();
extern s32 D_80182180;
typedef struct { u8 pad[0xB8]; u16 b8; } T;
void func_80173220(T *p) {
    if (p->b8 & 0x4000) {
        func_80147324(0x516);
        func_80019064(&D_80182180);
    }
    if (p->b8 & 0x8000) {
        func_80171A1C(p);
        func_80174650(p);
    }
}
