/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016A05C,8016A08C).
 * Offset 0x41F04 at overlay base 80128158. SHA256(span)=de0e1e434ffc1d84c12da038cf5f0848c8f64d6bd0ea363ebd1e7adb2251eb7b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016a05c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern u8 D_80078EC0;
typedef struct { u8 pad[2]; u16 u2; } T;
void func_8016A05C(T *p) {
    if (D_80078EC0 & 0x7F) {
        p->u2 = p->u2 + 1;
    } else {
        p->u2 = 2;
    }
}
