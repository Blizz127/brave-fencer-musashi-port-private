/* SC02 resident retail span [801609B8,80160A28). Offset 0x38860 at base 80128158.
 * SHA256(span)=59cbcb8247fbfad10a3ed46d2fbb6a39752b44f0c88fa15165dc924a4222e7c0.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
s32 func_801487F4();
void func_80160A74();
void func_80161208();
typedef struct { u16 idx; } T;
void func_801609B8(T *p) {
    if ((func_801487F4(p) & 8) == 0) {
        D_8018730C[p->idx](p);
        func_80160A74(p);
    } else {
        func_80161208(p);
    }
}
