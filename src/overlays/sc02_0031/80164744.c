/* SC02.CD FILE_031 / ov_SC02_031 retail span [80164744,801647A4).
 * Offset 0x3C5EC at overlay base 80128158. SHA256(span)=dff19edf1d1ce0c612151f525e8f8d978971458f6cee85d8fa3f562d4459be77.
 * Differs from the registry-verified MAIN member 0012 carve in exactly one
 * data reference: D_80180F84 here is D_8018180C (+0x888 member
 * data-block shift). Oracle MATCH re-earned on this file; Not MAIN10.
 */
#include "psx_types.h"
void func_80162D28();
typedef void (*CB)();
extern CB D_8018180C[];
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0x1C]; void *inner;
} T;
void func_80164744(T *p) {
    void *in = p->inner;
    D_8018180C[p->u2]();
    if (in) {
        func_80162D28(p);
    }
}
