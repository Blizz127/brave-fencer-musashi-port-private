/* SC02.CD FILE_031 / ov_SC02_031 retail span [80139FE8,8013A0A4).
 * Offset 0x11E90 at overlay base 80128158. SHA256(span)=01458a95e2c4e7b6db59a95df31d45656ba4ec5c20f6eb3d575d051dd275155e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80139fe8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8001B22C();
void func_8001931C();
void func_80139788();
void func_80139A8C();
void func_80139B18();
typedef struct { u8 pad[4]; s16 u4; u8 pad6[2]; s32 u8; } T;
void func_80139FE8(T *p) {
    s32 v = func_8001B22C(p);
    if (v == 2 || v == 4) {
        p->u4 = 2;
    } else if (v == 0) {
        if (p->u8 & 1) {
            func_8001931C();
        } else {
            p->u8 = (p->u8 & ~0x10000) | 0x20020;
            func_80139788();
        }
        p->u4 = 2;
    } else {
        func_80139A8C(p);
        if (p->u8 & 0x20) {
            p->u4 = 2;
        }
    }
    func_80139B18(p);
}
