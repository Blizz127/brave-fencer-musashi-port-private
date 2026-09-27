/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E778,8016E7C8).
 * Offset 0x46620 at overlay base 80128158. SHA256(span)=c1fdee1743c7112fc75f69db20cf9d875d7e36adaf9f60b46ba15766b02d1138.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e778.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8016E7C8();
typedef struct {
    u8 pad[0x12]; u16 u12;
    u8 pad14[2]; s16 u16;
} T;
void func_8016E778(T *p) {
    s16 v[4];
    u16 t;
    s32 u;
    s32 hi;
    t = p->u12;
    v[2] = t;
    v[1] = t;
    v[0] = t;
    u = p->u16;
    hi = (u << 16) | (u << 8);
    u = u | hi;
    func_8016E7C8(p, v, &u);
}
