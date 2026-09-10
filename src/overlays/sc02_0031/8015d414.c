/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015D414,8015D480).
 * Offset 0x352BC at overlay base 80128158. SHA256(span)=8d0441874f597d5dbfe87c3cd2bd075cac6605cc09217292c93aff0d34b9c5f7.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8017FD30 here is D_801805B8 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_801553C0();
void func_80154A74();
extern s32 D_801805B8;
typedef struct Inner { u8 pad[0x10]; s16 u10; } Inner;
typedef struct {
    u8 pad[0xA]; s16 unkA;
    u8 padC[0x14]; Inner *inner;
    u8 pad24[0x14]; void *p38;
    u8 pad3C[0xFC]; s16 u138, u13A, u13C, u13E;
    u8 pad140[0x7D]; u8 u1BD;
} T;
void func_8015D414(T *p) {
    p->u1BD = 8;
    p->p38 = &D_801805B8;
    p->u138 = 0;
    p->u13A = 0;
    p->u13C = 0;
    p->u13E = 0;
    p->unkA += 0x48;
    p->inner->u10 = 0;
    func_801553C0(p);
    func_80154A74(p, 0x11);
}
