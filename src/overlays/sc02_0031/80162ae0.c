/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162AE0,80162AF4).
 * Offset 0x3A988 at overlay base 80128158. SHA256(span)=e3db16dd7ea2c2cad4a6904fa6b3698ae230357f75033df90e90975311d0393f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162ae0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 pad; u8 u1; } T;
void func_80162AE0(T *p) {
    p->u1 = p->u1 - 1;
}
