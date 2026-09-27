/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172E94,80172ED4).
 * Offset 0x4AD3C at overlay base 80128158. SHA256(span)=60fcbf7ade855824a06e4b98d90939e13964b8c194e7a92d22b834ecb8c47202.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172e94.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8017303C(void *);                               /* static */
void func_80174650(void *);                               /* static */
extern s32 *D_800D5A34;
extern s16 D_80126B30;
extern s32 *D_80126B58;

void func_80172E94(void) {
    func_8017303C(&D_800D5A34);
    D_80126B30 = 0;
    func_80174650(&D_80126B58);
}
