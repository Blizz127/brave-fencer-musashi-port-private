/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016FFA8,8016FFDC).
 * Offset 0x47E50 at overlay base 80128158. SHA256(span)=0bec840820af0376980dd8cc4bc8787b3fcb106766df88982f2da553fd66e510.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016ffa8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80171990();
typedef struct { u8 pad[170]; u16 a; u16 b; } T;
void func_8016FFA8(T *p) {
    p->b |= 64;
    p->a |= 64;
    func_80171990(p);
}
