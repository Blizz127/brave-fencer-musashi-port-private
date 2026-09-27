/* SC02.CD FILE_031 / ov_SC02_031 retail span [801615C4,8016163C).
 * Offset 0x3946C at overlay base 80128158. SHA256(span)=8f62fce154e0aaf783ae242ec538b27044e6bc3cd8419ab2b8c400c4f06d36ef.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801615c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8014ED28();
void func_80146D90();
s32 func_8014CC28();
s32 func_8014FA04();
typedef struct { u8 pad[0x34]; s32 u34; } T;
s32 func_801615C4(T *p, s32 a1) {
    s32 r = 0;
    if ((a1 & 1) == 0) {
        if (func_8014ED28(p)) {
            func_80146D90(p);
        }
    }
    if (p->u34 > 0) {
        r |= func_8014CC28(p);
    }
    return r | func_8014FA04(p);
}
