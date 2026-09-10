/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172A2C,80172A8C).
 * Offset 0x4A8D4 at overlay base 80128158. SHA256(span)=4387f664d3f2afba3576ac15528de301901a39b9d1d1b0174ed66810fd7b9033.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172a2c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80126B30;
void func_80147060();
void func_80149350();
void func_80171A1C();
void func_80172A8C();
typedef struct {
    u8 pad[0x20];
    u8 *inner;
    u8 pad24[0x132-0x24];
    u16 f132;
    u8 pad134[2];
    s16 f136;
} T;
void func_80172A2C(T *p) {
    func_80147060(p);
    p->f136 = 2;
    p->f132 = *(u16 *)(p->inner + 0x12);
    func_80149350(p, &D_80126B30, &D_80126B30);
    func_80171A1C(p);
    func_80172A8C(p);
}
