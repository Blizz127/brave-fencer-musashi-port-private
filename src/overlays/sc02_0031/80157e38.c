/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157E38,80157EA4).
 * Offset 0x2FCE0 at overlay base 80128158. SHA256(span)=c2e6df33c8bbcfe1980fab40f62d6bd840710fbdb9daec72be10c59b4e19f61b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157e38.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_800D4F14;
void func_80154274();
void func_80154A74();
void func_80146994();
void func_80147324();
void func_80146CA0();
typedef struct {
    u8 pad[0x1AA];
    u8 f1AA;
    u8 pad1AB[0x244-0x1AB];
    s16 f244;
} T;
void func_80157E38(T *p) {
    p->f1AA = 0xD;
    func_80154274(p, &D_800D4F14);
    func_80154A74(p, 0x15);
    func_80146994(5, p, 0, 0);
    func_80147324(0x455);
    p->f244 = 0;
    func_80146CA0(p);
}
