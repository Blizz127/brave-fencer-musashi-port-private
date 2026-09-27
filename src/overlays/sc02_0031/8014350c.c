/* SC02.CD FILE_031 / ov_SC02_031 retail span [8014350C,8014358C).
 * Offset 0x1B3B4 at overlay base 80128158. SHA256(span)=3b974d31f457f10532e277f289135e297738255991ddf7e812d9fd47f666a3a1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8014350c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8014358C();
void func_8012931C();
s32 func_80128ED8();
void func_801292C8();
typedef struct Inner { u8 pad[0x27]; u8 u27; } Inner;
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0x1C]; Inner *inner;
    u8 pad24[4]; u8 u28;
} T;
void func_8014350C(T *p) {
    if (p->u2 == 0) {
        func_8014358C();
        return;
    }
    func_8012931C(p);
    if (func_80128ED8(p->inner, (u8 *)p + 0x24)) {
        func_801292C8(p);
        return;
    }
    p->inner->u27 = p->u28 - 0x70;
}
