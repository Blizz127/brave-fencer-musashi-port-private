/* SC02.CD FILE_031 / ov_SC02_031 retail span [801636D0,80163764).
 * Offset 0x3B578 at overlay base 80128158. SHA256(span)=d63a19729e83e0051aa618e9bb95a22c7e086cf1be55059c39ecb8afd62d17d9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801636d0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8014AD30();
extern s32 D_80115200[];
extern s32 D_80126B18[];
void func_801636D0(void *p, u32 a1) {
    u32 i;
    for (i = 0; i < 3; i++) {
        if (D_80115200[i] & 1) {
            func_8014AD30(p, &D_80126B18[i * 2], 0, (u16)(a1 & 0x7FFF));
        }
    }
}
