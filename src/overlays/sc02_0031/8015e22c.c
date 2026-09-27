/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E22C,8015E288).
 * Offset 0x360D4 at overlay base 80128158. SHA256(span)=8187bb72598a52a40ae7a4caf12fe13056a828bb5e7ffaabf1698ebc2b5e2fcc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e22c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_800D4FF4;
void func_80154274();
void func_80146994();
void func_80146CA0();
typedef struct {
    u8 pad[0x44];
    u32 flags;
    u8 pad48[0x234-0x48];
    s32 f234;
} T;
void func_8015E22C(T *p) {
    func_80154274(p, &D_800D4FF4);
    p->f234 = 0;
    func_80146994(5, p, 0xA, 0);
    p->flags |= 2;
    func_80146CA0(p);
}
