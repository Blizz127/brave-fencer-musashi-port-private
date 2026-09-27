/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160F70,80160FE0).
 * Offset 0x38E18 at overlay base 80128158. SHA256(span)=b2226e4c2b244f0d1bb8599a77c3bd02e2ec638c507c0cb7bcc0ebb4b526221d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160f70.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80146E98();
void func_800D0F4C();
void func_8014BB24();
void func_8014BD24();
void *func_8013767C();
void func_80146CA0();
extern s32 D_80110EC0;
typedef struct { u8 pad[0x198]; void *p198; } T;
void func_80160F70(T *p) {
    if (func_80146E98(p)) {
        func_800D0F4C(0xA);
        func_8014BB24(p, 0x96, 0);
        func_8014BD24(p, 0x96);
        p->p198 = func_8013767C(&D_80110EC0);
        func_80146CA0(p);
    }
}
