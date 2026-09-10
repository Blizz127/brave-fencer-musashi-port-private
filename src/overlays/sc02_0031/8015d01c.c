/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015D01C,8015D104).
 * Offset 0x34EC4 at overlay base 80128158. SHA256(span)=86a21f94afee1705f1069d414bc2056a8d79148da63b126c8fc1d3485445219a.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180BE0 here is D_80181468 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80154274();
s32 func_80012A60();
void func_801725F4();
void func_80146CA0();
extern s32 D_800D550C;
extern s32 D_80181468;
typedef struct Inner { u8 pad[0x10]; s16 u10; u16 u12; } Inner;
typedef struct Q { u8 pad[0x20]; Inner *inner; } Q;
typedef struct {
    u8 pad[0x20]; Inner *inner;
    u8 pad24[0x14]; s32 u38;
    u8 pad3C[0x144]; Q *u180;
} T;
void func_8015D01C(T *p) {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 e;
    func_80154274(p, &D_800D550C);
    p->inner->u10 = 0;
    a = p->inner->u12;
    b = p->u180->inner->u12;
    c = (b + 0x800) & 0xFFF;
    d = func_80012A60(a, b);
    e = func_80012A60(a, c);
    if ((s16)d < (s16)e) {
        p->inner->u12 = b;
    } else {
        p->inner->u12 = c;
    }
    p->u38 = (s32)&D_80181468 | 0x40000000;
    func_801725F4(p);
    func_80146CA0(p);
}
