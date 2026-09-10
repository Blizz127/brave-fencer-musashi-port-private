/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161888,8016191C).
 * Offset 0x39730 at overlay base 80128158. SHA256(span)=885dd32f326b710620652994d93a4967da6abd6ddd1f24cb21d98bf5fe41e39e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161888.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8014C010();
void func_80161D20();
typedef struct { u8 pad[0x16E]; u16 u16E; } T;
s32 func_80161888(T *p, s32 a1) {
    if (a1 & 1) {
        func_8014C010(p, 1);
        func_80161D20(p, p->u16E);
        return 1;
    }
    if (a1 & 0x4000) {
        func_8014C010(p, 1);
        func_80161D20(p, p->u16E);
        return 2;
    }
    if (a1 & 0x2000) {
        func_8014C010(p, 1);
        func_80161D20(p, p->u16E);
        return 4;
    }
    return 0;
}
