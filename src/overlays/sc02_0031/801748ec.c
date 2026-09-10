/* SC02.CD FILE_031 / ov_SC02_031 retail span [801748EC,8017496C).
 * Offset 0x4C794 at overlay base 80128158. SHA256(span)=33d5913d106bf6079410b1f5ed0054bae46083ad01c6dd6a5ba61c8ec878e939.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801748ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8017496C();
void func_8012A018();
extern s32 D_80126954, D_80126950, D_8012695C;
extern s16 D_80126968, D_8012696A, D_8012696C, D_80126976, D_80126978, D_8012697A;
void func_801748EC(void) {
    D_80126954 = 0x1F4;
    D_80126950 = 0x1F4;
    D_8012695C = 0x384;
    D_80126968 = 0x1C7;
    D_8012696A = 0x600;
    D_8012696C = 0;
    D_80126976 = 0;
    D_80126978 = 0;
    D_8012697A = 0;
    func_8012A018(func_8017496C, 0);
}
