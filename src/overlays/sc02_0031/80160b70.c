/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160B70,80160BB4).
 * Offset 0x38A18 at overlay base 80128158. SHA256(span)=e8d5374d0eb3f284d8c304d876a02c346a6549c0c14af0763872c50cb418fab2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160b70.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80161104();
void func_80160BB4();
typedef struct { u8 pad[0x1AC]; s32 f; } T;
void func_80160B70(T *p) {
    if (func_80161104(p)) {
        func_80160BB4(p);
    } else {
        p->f = 0;
    }
}
