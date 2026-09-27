/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151ECC,80151F38).
 * Offset 0x29D74 at overlay base 80128158. SHA256(span)=ffb418d29847c259101e381e5c5157d5132c5338d6c1133121cabe20d76de51f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151ecc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
void func_80146CA0();
void func_80172630();
typedef struct { u8 pad[0x64]; s16 u64; u8 pad66[0x78]; u8 uDE; } T;
void func_80151ECC(T *p) {
    func_80149020(p);
    p->u64 += p->uDE << 6;
    p->uDE += 5;
    if (p->u64 >= 0x1556) {
        p->uDE = 0x10;
        func_80146CA0(p);
    }
    func_80172630(p);
}
