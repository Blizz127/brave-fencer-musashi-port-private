/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016D464,8016D4DC).
 * Offset 0x4530C at overlay base 80128158. SHA256(span)=1ea7898f3702a7b83904841e6e885e7902e1b476caf2342d4b44672d4a9bc2e6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016d464.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_800D22E4();
void func_8016CF04();
typedef struct { u8 pad[2]; u16 u2; u8 pad4[0x18]; s32 u1C; u8 pad20[0x14]; u16 *u34; } T;
void func_8016D464(T *p) {
    u16 *s1 = p->u34;
    func_800D22E4(p);
    func_8016CF04(p, 1);
    p->u1C = p->u1C - 1;
    if (p->u1C == -1 || s1[0] != 1) {
        p->u2 = p->u2 + 1;
    }
}
