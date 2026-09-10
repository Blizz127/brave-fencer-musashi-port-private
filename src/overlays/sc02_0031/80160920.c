/* SC02 resident retail span [80160920,801609B8). Offset 0x387C8 at base 80128158.
 * SHA256(span)=e8bcd2d41a6f802fa605515cf4cc37f6b6f56c6d31f122ae79e10fdbc8b21298.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180A1C->D_8018730C.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
typedef void (*CB)();
extern CB D_8018730C[];
s32 func_801487F4();
void func_80160A74();
s32 func_80161208();
void func_80154150();
void func_80146CA0();
typedef struct { u16 idx; u8 pad[0xB6]; u16 b8; } T;
void func_80160920(T *p) {
    if ((func_801487F4(p) & 8) == 0) {
        D_8018730C[p->idx](p);
        func_80160A74(p);
    } else if (func_80161208(p) == 0 && p->b8 == 0x8000) {
        func_80154150(p, 0x25);
        func_80146CA0(p);
    }
}
