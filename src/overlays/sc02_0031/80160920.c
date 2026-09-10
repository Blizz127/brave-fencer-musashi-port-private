/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160920,801609B8).
 * Offset 0x387C8 at overlay base 80128158. SHA256(span)=ba66d77137110b6b78ec32adb9640074b4c99928f1bfd67b9e74191bcbd016ef.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180A1C here is D_801812A4 (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_801812A4[];
s32 func_801487F4();
void func_80160A74();
s32 func_80161208();
void func_80154150();
void func_80146CA0();
typedef struct { u16 idx; u8 pad[0xB6]; u16 b8; } T;
void func_80160920(T *p) {
    if ((func_801487F4(p) & 8) == 0) {
        D_801812A4[p->idx](p);
        func_80160A74(p);
    } else if (func_80161208(p) == 0 && p->b8 == 0x8000) {
        func_80154150(p, 0x25);
        func_80146CA0(p);
    }
}
