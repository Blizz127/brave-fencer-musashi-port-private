/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015D104,8015D1B8).
 * Offset 0x34FAC at overlay base 80128158. SHA256(span)=efed73b2c4d3747759e34f3ecb89b7a292bd5c0eb2a8878ba58145d076ca27d5.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
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
        D_801812A4[p->idx](p);
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
