/* SC02.CD FILE_031 / ov_SC02_031 retail span [80170018,80170068).
 * Offset 0x47EC0 at overlay base 80128158. SHA256(span)=ba1962a1ac766aa761fbe0a2b9a2bdbfb75f20ee9b305965e8cf033c624ccba7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80170018.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void *func_8013767C();
void func_801719A4();
void func_80171990();
void func_80170068();
extern void *D_8011F738;
typedef struct { u8 pad_0[0x198]; void *ptr; } T;
void func_80170018(T *p) {
    func_801719A4(p, 1);
    p->ptr = func_8013767C(D_8011F738);
    func_80171990(p);
    func_80170068(p);
}
