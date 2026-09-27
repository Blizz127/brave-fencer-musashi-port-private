/* SC02 resident retail span [8012E9C0,8012EA90). Offset 0x6868 at base 80128158.
 * SHA256(span)=81eb6e3b05411d858a96e28358bfb87bd270ca29af34003aff57b61b4ad99641.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_8017E6D4->D_80184FC4.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_8016AA50();
void func_8016B428();
void func_80019064();
extern s32 D_80184FC4;
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
        func_80019064(&D_80184FC4);
    }
}
