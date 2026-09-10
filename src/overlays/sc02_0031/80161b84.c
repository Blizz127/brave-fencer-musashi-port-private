/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161B84,80161BE0).
 * Offset 0x39A2C at overlay base 80128158. SHA256(span)=e24f79471aa19733ffe1d8b9140fbc22ea0638bb98513674bdeecd838cf80922.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161b84.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80149884();
void func_801599A4();
void func_801498C0();
typedef struct { u8 pad[0x44]; s32 flags; } T;
s32 func_80161B84(T *p) {
    if (p->flags & 0x100) {
        if (func_80149884()) {
            func_801599A4(p);
            func_801498C0(p);
            return 1;
        }
    }
    return 0;
}
