/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FAC0,8016FB10).
 * Offset 0x47968 at overlay base 80128158. SHA256(span)=6a63d3b34b8bd6567c249d5391773c6f9c429a1e3c3fa0cd3056342fbfd526b7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016fac0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801719A4();
void func_80171990();
void func_8016FB10();
typedef struct {
    u8 pad[0x20];
    u8 *inner;
    u8 pad24[0x132-0x24];
    u16 f132;
    u8 pad134[2];
    s16 f136;
} T;
void func_8016FAC0(T *p) {
    p->f136 = 2;
    p->f132 = *(u16 *)(p->inner + 0x12);
    func_801719A4(p, 2);
    func_80171990(p);
    func_8016FB10(p);
}
