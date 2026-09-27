/* SC02.CD FILE_031 / ov_SC02_031 retail span [801691B8,80169228).
 * Offset 0x41060 at overlay base 80128158. SHA256(span)=9b49efa6992051207a970c67412ad4e26eeb75c7e034389f40de62615cfeee75.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801691b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80169228();
void func_800D22E4();
void func_80146C3C();
typedef struct { u8 pad[0x14]; s32 u14; u8 pad18[4]; s32 u1c; } T;
void func_801691B8(T *p) {
    if (p->u1c < 10) {
        func_80169228();
        func_800D22E4(p);
        p->u14 += 0x10000;
        p->u1c++;
    } else {
        func_80146C3C(p);
    }
}
