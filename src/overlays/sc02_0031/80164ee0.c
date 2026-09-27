/* SC02 resident retail span [80164EE0,80164F44). Offset 0x3CD88 at base 80128158.
 * SHA256(span)=21f02329f57a805473fc5e634b8d3b8f8bb2d242bb674a88703f803092fecb11.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_801843A4->D_801B655C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80165124();
void func_80146CA0();
extern s32 D_801B655C;
typedef struct {
    u8 pad[0x2C]; s16 u2c, u2e;
    u8 pad30[0x30]; s16 u60, u62;
    u8 pad64[2]; s16 u66;
} T;
void func_80164EE0(T *p) {
    s32 i;
    for (i = 0x70; i >= 0; i -= 0x10) {
        *(s32 *)((u8 *)&D_801B655C + i) = 0;
    }
    p->u2e = 0x4000;
    p->u2c = 0x4000;
    p->u60 = 0;
    p->u62 = 0;
    func_80165124(p);
    p->u66 = 0;
    func_80146CA0(p);
}
