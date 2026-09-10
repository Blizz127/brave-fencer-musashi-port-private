/* SC02.CD FILE_031 / ov_SC02_031 retail span [801399A8,801399F0).
 * Offset 0x11850 at overlay base 80128158. SHA256(span)=8283ae1d54b2ca7f226dda9d974721f5bac38d666365860d1e88a2fcf89206a0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801399a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { s32 a; u8 pad[0x48]; } S;
extern S D_801269F0[];
S *func_801399A8(void) {
    s32 i;
    for (i = 1; i < 3; i++) {
        if (D_801269F0[i].a == 0) {
            return &D_801269F0[i];
        }
    }
    return 0;
}
