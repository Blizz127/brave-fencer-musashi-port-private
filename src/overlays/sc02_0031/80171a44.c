/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171A44,80171A58).
 * Offset 0x498EC at overlay base 80128158. SHA256(span)=644201adf9e62ea5c692e8b48283d884789be91789b01e92f76fab9ca3dbb982.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171a44.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 pad[0x214]; u8 u214, u215, u216; } T;
void func_80171A44(T *p) {
    p->u216 = 0;
    p->u215 = p->u215 + 1;
}
