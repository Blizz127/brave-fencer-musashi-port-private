/* SC02 resident retail span [8015FCC8,8015FD74). Offset 0x37B70 at base 80128158.
 * SHA256(span)=a6ee56a55c177886865c8fe2beb570e6322216183bd2a35c240356c95d1b8ac1.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
void func_8016007C();
void func_80147078();
void func_80159B70();
void func_8014BFF4();
void func_80146CA0();
extern s32 D_800AE6B0;
typedef struct {
    u16 idx;
    u8 pad2[0xBC]; u8 uBE, uBF;
    u8 padC0[0xC4]; s32 u184;
    u8 pad188[0xF]; u8 u197;
    u8 pad198[8]; u8 u1A0;
} T;
void func_8015FCC8(T *p) {
    if (D_800AE6B0 & 0x80FFFFFF) {
        func_8016007C();
        D_8018730C[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        p->u197 = 0;
        p->uBE = 0;
        p->uBF = 0;
        p->u1A0 = p->u184;
        func_8014BFF4(p, 1);
        func_80146CA0(p);
    }
}
