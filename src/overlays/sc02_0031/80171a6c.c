/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171A6C,80171A80).
 * Offset 0x49914 at overlay base 80128158. SHA256(span)=eba2ff8fb2bdf643c6f4b305df1cfe260fb2283700df877927842b9146fcd964.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171a6c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 pad[0x216]; u8 u216; } T;
void func_80171A6C(T *p) {
    p->u216 = p->u216 - 1;
}
