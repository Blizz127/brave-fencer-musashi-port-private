/* SC02.CD FILE_031 / ov_SC02_031 retail span [801722CC,80172304).
 * Offset 0x4A174 at overlay base 80128158. SHA256(span)=2b67ef273bc550d659480cb52ee71d2b15b987111a4a4a2cf067a3992eb454f5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801722cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80172664();
typedef struct { u8 pad[0xAA]; u16 a, b; } T;
void func_801722CC(T *p) {
    if (func_80172664(p) == 0) {
        p->b = 0x40;
        p->a = 0x40;
    }
}
