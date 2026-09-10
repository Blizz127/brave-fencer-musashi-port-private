/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B178,8012B1B4).
 * Offset 0x3020 at overlay base 80128158. SHA256(span)=b4be00ab25ae72b3410ba31c0c045dca272bdff706146ae02b92ec9192ed22f8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b178.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_800484EC();
typedef struct { u8 pad[0x20]; u8 *inner; } T;
void func_8012B178(T *p, s32 a1) {
    s32 tmp[4];
    tmp[2] = a1;
    tmp[1] = 0;
    tmp[0] = 0;
    func_800484EC(p->inner + 0x34, tmp, (u8 *)p + 0x10);
}
