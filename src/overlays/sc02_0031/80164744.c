/* SC02 resident retail span [80164744,801647A4). Offset 0x3C5EC at base 80128158.
 * SHA256(span)=47f9f72f2dbf2e4ceddfea2520c3335e7592c64ac119bf816410a050ea6e8ff1.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910).
 * Member-0012 C shape retargeted to this member: D_80180F84->D_80187874.
 * Oracle MATCH re-earned against the resident image; Not MAIN10.
 */
#include "psx_types.h"
void func_80162D28();
typedef void (*CB)();
extern CB D_80187874[];
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0x1C]; void *inner;
} T;
void func_80164744(T *p) {
    void *in = p->inner;
    D_80187874[p->u2]();
    if (in) {
        func_80162D28(p);
    }
}
