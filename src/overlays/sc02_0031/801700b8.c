/* SC02.CD FILE_031 / ov_SC02_031 retail span [801700B8,80170100).
 * Offset 0x47F60 at overlay base 80128158. SHA256(span)=2017adbe3d10f5298a8e28f5222c4e690992ba62373f9892f9c302debdcd74fa.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801700b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void *func_8013767C();
void func_801719A4();
void func_80171928();
extern void *D_8011F738;
typedef struct { u8 pad_0[0x198]; void *ptr; } T;
void func_801700B8(T *p) {
    func_801719A4(p, 1);
    p->ptr = func_8013767C(D_8011F738);
    func_80171928(p);
}
