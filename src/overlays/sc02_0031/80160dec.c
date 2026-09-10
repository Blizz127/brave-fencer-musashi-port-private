/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160DEC,80160E3C).
 * Offset 0x38C94 at overlay base 80128158. SHA256(span)=efbfdbd2a1e7053691cb247ee1f3f851436e7e93cea1c37de1af5595982c8c01.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160dec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801553C0();
void func_80154A74();
typedef struct Inner { u8 pad[0x10]; s16 unk10; } Inner;
typedef struct {
    u8 pad[0x20];
    Inner *inner;
    u8 pad24[0x20];
    u32 flags;
    u8 pad48[0x1AC-0x48];
    s32 f1AC;
} T;
void func_80160DEC(T *p) {
    p->f1AC = 0;
    p->inner->unk10 = 0;
    func_801553C0(p);
    p->flags &= -0x181;
    func_80154A74(p, 0x11);
}
