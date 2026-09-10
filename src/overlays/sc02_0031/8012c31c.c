/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012C31C,8012C354).
 * Offset 0x41C4 at overlay base 80128158. SHA256(span)=27fd6b363299ddfcb53527f6455306a523512e572bde01b4e9ae480f10f5042c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012c31c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern u8 D_80120194[];
typedef struct { u16 id; u8 pad[0x10A]; } S;
S *func_8012C31C(void) {
    S *start = (S *)D_80120194;
    S *s = (S *)(D_80120194 + 0x6480);
    while (s != start) {
        if (s->id == 0) {
            return s;
        }
        s--;
    }
    return 0;
}
