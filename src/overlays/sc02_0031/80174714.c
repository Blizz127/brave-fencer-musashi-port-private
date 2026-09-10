/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174714,80174754).
 * Offset 0x4C5BC at overlay base 80128158. SHA256(span)=011e134f2a0104dfabcf9dbf72aaef72d3e47a7dad54798880205ac19cdfcada.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174714.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

s32 func_800CF8CC();                                /* extern */
void func_80147060(void *);                               /* static */
void func_8016F0AC();                                  /* static */
extern s32 *D_80126B58;

void func_80174714(void) {
    if (func_800CF8CC() == 0) {
        func_80147060(&D_80126B58);
        func_8016F0AC();
    }
}
