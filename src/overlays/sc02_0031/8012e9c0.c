/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E9C0,8012EA90).
 * Offset 0x6868 at overlay base 80128158. SHA256(span)=8602cd27f031824fe3b3f54f09ea4ebb74e3a4128f5cd3453246f706d1994008.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_8017E6D4 here is D_8017EF5C (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_8016AA50();
void func_8016B428();
void func_80019064();
extern s32 D_8017EF5C;
typedef struct Q { u8 pad[0x30]; s16 u30; } Q;
typedef struct {
    u8 pad[6]; u16 u6;
    u8 pad8[2]; u16 uA;
    u8 padC[2]; u16 uE;
    u8 pad10[0x4E]; u8 u5E;
    u8 pad5F; s16 u60;
    u8 pad62[0x16]; Q *u78;
    s16 u7C, u7E, u80, u82;
} T;
void func_8012E9C0(T *p) {
    s32 a1;
    if (p->u60 == 0) {
        return;
    }
    if (p->u5E == 0x1D) {
        p->u82 = 0;
        p->u7C = p->u6;
        p->u7E = p->uA;
        p->u80 = p->uE;
    }
    if (p->u78) {
        a1 = (p->u60 * p->u78->u30) >> 12;
        if (a1 <= 0) {
            a1 = 1;
        }
    } else {
        a1 = p->u60;
    }
    func_8016AA50(p, a1);
    if (p->u82 & 1) {
        func_8016B428(p);
        func_80019064(&D_8017EF5C);
    }
}
