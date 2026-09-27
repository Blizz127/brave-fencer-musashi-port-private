/* SC02.CD FILE_031 / ov_SC02_031 retail span [801599E0,80159A18).
 * Offset 0x31888 at overlay base 80128158. SHA256(span)=179c8f31a716f557e876339b8ae09069a5a32d5324a0669272d271853f47453e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801599e0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80159A20();
typedef struct { u8 pad[0x4D]; u8 unk4D; } T;
void func_801599E0(T *p) {
    func_80159A20(p);
    p->unk4D++;
}
