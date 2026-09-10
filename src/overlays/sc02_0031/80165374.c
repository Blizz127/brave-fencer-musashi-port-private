/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165374,801653B8).
 * Offset 0x3D21C at overlay base 80128158. SHA256(span)=853107f21cc40343e38b221ed67b12190d33a23b5cb1c988d10a0c36ab39a7ff.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165374.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801653F4();
void func_80147078();
void func_80165580();
typedef struct {
    u8 pad_0[407];
    u8 f197;
} T;
void func_80165374(T *p) {
    func_801653F4(p);
    func_80147078(p, 23);
    p->f197 = 1;
    func_80165580(p);
}
