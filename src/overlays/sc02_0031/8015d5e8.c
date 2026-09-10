/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015D5E8,8015D738).
 * Offset 0x35490 at overlay base 80128158. SHA256(span)=9efe104c238d6205c5e9908a87a7268e2bf5196a76729d15eea74d0a545183f1.
 * Same shape as the registry-verified MAIN member 0012 carve with only the
 * listed data references retargeted for this member: D_80180C60->D_801814E8.
 * Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
s32 func_80161B18();
s32 func_80161B84();
void func_80154A74();
s32 func_80161208();
void func_80154150();
void func_80146CA0();
void func_80149374();
extern s8 D_801814E8[];
typedef struct Inner { u8 pad[0xC]; u16 c, e, ten; } Inner;
typedef struct {
    u8 pad[6]; s16 u6; u8 pad8[2]; s16 uA; u8 padC[2]; s16 uE;
    u8 pad10[0x68]; Inner *p78;
} U;
typedef struct {
    u8 pad[0xB8]; u16 b8;
    u8 padBA[0xBE]; U *u178;
    u8 pad17C[0xB8]; s32 u234;
} T;
void func_8015D5E8(T *p) {
    U *q;
    s32 i;
    if (func_80161B18(p)) {
        return;
    }
    if (func_80161B84(p)) {
        return;
    }
    if (p->b8 & 0x4000) {
        func_80154A74(p, 0x17);
    }
    if (func_80161208(p)) {
        return;
    }
    if (p->b8 == 0x8000) {
        p->u234 -= 3;
        func_80154150(p, 0x1A);
        func_80146CA0(p);
        return;
    }
    q = p->u178;
    if (q == 0) {
        return;
    }
    i = p->u234;
    p->u234 = i + 1;
    q->u6 = D_801814E8[i] + q->p78->c;
    i = p->u234;
    p->u234 = i + 1;
    q->uA = D_801814E8[i] + q->p78->e;
    i = p->u234;
    p->u234 = i + 1;
    q->uE = D_801814E8[i] + q->p78->ten;
    func_80149374(p, (u8 *)q + 4);
}
