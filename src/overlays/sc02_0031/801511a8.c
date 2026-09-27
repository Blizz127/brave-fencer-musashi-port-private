/* SC02.CD FILE_031 / ov_SC02_031 retail span [801511A8,801511C4).
 * Offset 0x29050 at overlay base 80128158. SHA256(span)=88a5f51c9e9ff26f0b86b67107761973b4db13fc5fb509acf6903ccf0e601471.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801511a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 pad[0x3C]; u16 f3c, f3e, f40, f42; } T;
void func_801511A8(T *p) {
    p->f3e = 0;
    p->f40 = 0;
    p->f42 = 0;
    p->f3c &= 0xFFFE;
}
