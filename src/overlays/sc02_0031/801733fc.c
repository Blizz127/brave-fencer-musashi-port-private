/* SC02.CD FILE_031 / ov_SC02_031 retail span [801733FC,80173460).
 * Offset 0x4B2A4 at overlay base 80128158. SHA256(span)=c35096dc96be6026f821fcfa787d5c4d479494c51d4782ec7797a9956608b65b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801733fc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { s16 x, y, z, pad; } S;
extern S D_80126B38;
extern s16 D_80126B40;
void func_801734BC();
void func_801733FC(void *p, S *q) {
    func_801734BC(p);
    D_80126B38 = *q;
    D_80126B38.pad = 1;
    D_80126B40 = 1;
}
