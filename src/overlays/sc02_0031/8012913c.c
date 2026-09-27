/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012913C,801291C0).
 * Offset 0xFE4 at overlay base 80128158. SHA256(span)=92d1323bbc6ef0be1f915da869ea790e724d2de4797721574894ea342b37293b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012913c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

/* HAND MODEL from m2c draft of func_8012913C (main_0012.s): NOT
 * verified against retail. C89-gated only; promotion requires an
 * oracle MATCH. Allocator pattern: the void* from func_801291C0 is
 * null-checked, then initialized — a HALFWORD at +0x0 (sh, taking
 * the s16 argument) and a WORD at +0x20 (sw, taking temp_v0_2).
 * The struct declares exactly those two members. The extern
 * ?-prototypes follow the repo pipeline convention (s32 returns
 * where compared, void with word-sized params otherwise). NULL is
 * spelled 0. Body is m2c's verbatim. */

struct obj_8012913C {
    s16 unk0;
    u8 pad[0x1E];
    s32 unk20;
};

void func_8001CC3C(s32, s32, s32, s32);
s32 func_8001D074(s32, s32);
void *func_801291C0();

void *func_8012913C(s16 arg0) {
    s32 temp_v0_2;
    struct obj_8012913C *temp_v0;

    temp_v0_2 = func_8001D074(0x7E, 0x100);
    if (temp_v0_2 != 0) {
        temp_v0 = (struct obj_8012913C *) func_801291C0();
        if (temp_v0 != 0) {
            temp_v0->unk0 = arg0;
            temp_v0->unk20 = temp_v0_2;
            func_8001CC3C(temp_v0_2, 0, 0, 0);
            return temp_v0;
        }
        return 0;
    }
    return 0;
}
