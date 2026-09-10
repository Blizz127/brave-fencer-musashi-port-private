/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172894,801728E4).
 * Offset 0x4A73C at overlay base 80128158. SHA256(span)=49779ac693a733882149265f6464895b60ac5e71f36b165d403f1463bb381ff0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172894.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_80126B30;
void func_801728E4();
void func_80174684();
void func_80172894(S *p) {
    D_80126B30 = *p;
    func_80174684(func_801728E4);
}
