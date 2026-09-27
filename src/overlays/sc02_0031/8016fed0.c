/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FED0,8016FF30).
 * Offset 0x47D78 at overlay base 80128158. SHA256(span)=52651b0e1c1b44e692e2875b53e21c8ea8d007eaa431934f0aaed0ea72517c4d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fed0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80172664();
s32 func_80171CC4();
void func_80171928();
extern u8 D_8011F738;
typedef struct { u8 pad[0xAA]; u16 f; } T;
void func_8016FED0(T *p) {
    if (func_80172664(p)) {
        p->f |= 0x40;
    }
    if (func_80171CC4(p, &D_8011F738)) {
        func_80171928(p);
    }
}
