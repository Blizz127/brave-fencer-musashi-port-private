/* SC02.CD FILE_031 / ov_SC02_031 retail span [80137614,8013767C).
 * Offset 0xF4BC at overlay base 80128158. SHA256(span)=ef25364f7b72a5f475f6e8fc0e54889e7b3dcfa85df778425bb032deaff504ed.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80137614.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void *func_801399A8();
void func_801377B4();
typedef struct { u8 pad[0x1C]; s16 f; } S;
void *func_80137614(void *p, s16 a1, s32 a2) {
    S *s = func_801399A8(p);
    if (s) {
        func_801377B4(p, a2 & 0xD8, s);
        s->f = a1;
    }
    return s;
}
