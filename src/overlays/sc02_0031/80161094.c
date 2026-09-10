/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161094,801610FC).
 * Offset 0x38F3C at overlay base 80128158. SHA256(span)=786adf0207c37f80e7c8838aaf271a494caffe0632505971dc2d8a0865e3ee8d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161094.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_801399F0();
void func_80139914();
void func_80129248();
extern u16 D_801270C0;
extern u8 D_800B9A17;
typedef struct { u8 pad[0x198]; void *u198; } T;
void func_80161094(T *p) {
    if (func_801399F0(p->u198)) {
        func_80139914(p->u198);
        p->u198 = 0;
    }
    D_801270C0 = 1;
    func_80129248(1);
    D_800B9A17 = 1;
}
