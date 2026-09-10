/* SC02.CD FILE_031 / ov_SC02_031 retail span [801609B8,80160A28).
 * Offset 0x38860 at overlay base 80128158. SHA256(span)=127d5fc341566530403b6b9fa28a76c54b0430d5997aa1e28922d0424c24ea82.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
s32 func_801487F4();
void func_80160A74();
void func_80161208();
typedef struct { u16 idx; } T;
void func_801609B8(T *p) {
    if ((func_801487F4(p) & 8) == 0) {
        D_801812A4[p->idx](p);
        func_80160A74(p);
    } else {
        func_80161208(p);
    }
}
