/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171C64,80171CC4).
 * Offset 0x49B0C at overlay base 80128158. SHA256(span)=77cb302c17b62939a06ba55cc0e631d23151f012cc6fa6bc7f026f287c0a88c1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171c64.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80171EC8();
void func_80146D90();
typedef struct { u8 pad[0x20C]; u8 c; } T;
s32 func_80171C64(T *p, u32 a1) {
    u8 v;
    func_80171EC8(p);
    v = p->c;
    p->c = v + 1;
    if (v == (u8)a1) {
        func_80146D90(p);
        return 1;
    }
    return 0;
}
