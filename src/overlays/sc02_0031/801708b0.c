/* SC02.CD FILE_031 / ov_SC02_031 retail span [801708B0,80170928).
 * Offset 0x48758 at overlay base 80128158. SHA256(span)=4806d9c5010fb51228f2a2a7f15594524ffa8acfe9f83ccffccff087ac84adbe.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801708b0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern void *D_8011F738;
void func_801484B0();
void func_80149350();
void *func_8014C168();
void func_80171928();
typedef struct { s16 x, y, z; } S;
void func_801708B0(void *p) {
    S a;
    S b;
    u8 *q;
    func_801484B0(&a, &b);
    func_80149350(p, &a, &a);
    q = func_8014C168(p, D_8011F738);
    *(u16 *)(q + 6) = a.x;
    *(u16 *)(q + 10) = a.y;
    *(u16 *)(q + 14) = a.z;
    func_80171928(p);
}
