/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151D60,80151DB0).
 * Offset 0x29C08 at overlay base 80128158. SHA256(span)=d06665e2a0dc0ed8f78271a5b46ac30f2b18c6e6594308145088a80dd3840090.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151d60.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_8014E934();
void func_8014CC28();
void func_8014F3E8();
void func_80151DB0();
void func_80146CA0();
typedef struct {
    u8 pad_0[222];
    u8 fDE;
} T;
void func_80151D60(T *p) {
    func_8014E934(p);
    func_8014CC28(p);
    func_8014F3E8(p);
    func_80151DB0(p);
    p->fDE = 32;
    func_80146CA0(p);
}
