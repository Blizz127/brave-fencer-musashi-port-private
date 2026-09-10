/* SC02.CD FILE_031 / ov_SC02_031 retail span [80175114,80175150).
 * Offset 0x4CFBC at overlay base 80128158. SHA256(span)=f8efb19c2f015b8b89b3983e33c6192686f21223cdbc74f0e4b6febe89a92f66.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80175114.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80147078();
void func_80175184();
typedef struct {
    u8 pad_0[2];
    s16 f2;
} T;
void func_80175114(T *p) {
    func_80147078(p, 8);
    p->f2 = 1;
    func_80175184(p);
}
