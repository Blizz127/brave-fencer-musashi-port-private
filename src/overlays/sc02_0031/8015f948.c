/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F948,8015F9A4).
 * Offset 0x377F0 at overlay base 80128158. SHA256(span)=6a711df2fe1e3cb69be0986487b8f6d5d7d6dcd2bf180644c72839f2ade2db73.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f948.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80147078();
s32 func_80161104();
void func_80154150();
void func_80154A74();
void func_80146C98();
void func_8015F948(void *p) {
    func_80147078(p, 0x15);
    if (func_80161104(p)) {
        func_80154150(p, 0x22);
        func_80154A74(p, 0x1A);
        func_80146C98(p, 2);
    }
}
