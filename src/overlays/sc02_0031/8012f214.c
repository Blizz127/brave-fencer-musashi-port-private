/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F214,8012F274).
 * Offset 0x70BC at overlay base 80128158. SHA256(span)=d540c6a437ee2771b23a3b8980f74b631ad2af0e5c8471216a64ce35db20a952.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012f214.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL of func_8012F214 (main_0012.s), decoded manually from
 * raw asm (0x60 bytes; NOT verified against retail; C89-gated
 * only, promotion requires an oracle MATCH): t = unk20 + 0x34;
 * calls 8004914C(t) (t set in the jal delay slot), 800491AC(t),
 * then 8004945C(arg1, arg2, buf) with an 8-byte stack buffer.
 * Same tail shape as func_8012F14C with the GTE-base override. */

struct obj_8012F214 {
    u8 pad[0x20];
    void *unk20;
};

extern void func_8004914C(void *arg0);
extern void func_800491AC(void *arg0);
extern void func_8004945C(void *arg0, void *arg1, void *arg2);

void func_8012F214(struct obj_8012F214 *arg0, void *arg1, void *arg2) {
    u8 *t;
    u8 buf[8];

    t = (u8 *) arg0->unk20 + 0x34;
    func_8004914C(t);
    func_800491AC(t);
    func_8004945C(arg1, arg2, buf);
}
