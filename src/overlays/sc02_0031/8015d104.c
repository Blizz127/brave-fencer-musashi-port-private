/* SC02 resident retail span [8015D104,8015D1B8). Offset 0x34FAC at base 80128158.
 * SHA256(span)=ae126b4b0b6725f7f7b7f58b6d47c317bf577d6f107556ca11086113eac3e399.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
void func_80149FB0();
void func_8014FA04();
s32 func_8014E6A0();
void func_80147078();
void func_80159B70();
void func_801725F4();
void func_80146CA0();
typedef struct Inner { u8 pad[0x10]; s16 u10; } Inner;
typedef struct {
    u16 idx;
    u8 pad2[0x1E]; Inner *inner;
    u8 pad24[0x210]; s32 u234;
    u8 pad238[0xC]; s16 u244;
} T;
void func_8015D104(T *p) {
    func_80149FB0(p);
    func_8014FA04(p);
    if (func_8014E6A0(p) == 0) {
        D_8018730C[p->idx](p);
        func_80147078(p, 0);
        func_80159B70(p);
    } else {
        func_801725F4(p);
        p->u234 = 0xFF1D0000;
        p->inner->u10 = 0x600;
        p->u244 = p->inner->u10;
        func_80146CA0(p);
    }
}
