/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155344,80155394).
 * Offset 0x2D1EC at overlay base 80128158. SHA256(span)=fd431a96f40df7bdffcd48ecb08d018c7c90f48e94cc52a629782aa3fd85f82d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155344.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_800DE2A4;
typedef struct { u8 pad[0x44]; s32 flags; } T;
void func_80155344(T *p) {
    s32 *s = &D_800DE2A4;
    while (*s) {
        *s = *s | 0x1000000;
        s++;
    }
    p->flags &= 0xCFFFFFFF;
}
