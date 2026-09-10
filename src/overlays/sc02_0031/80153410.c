/* SC02.CD FILE_031 / ov_SC02_031 retail span [80153410,80153490).
 * Offset 0x2B2B8 at overlay base 80128158. SHA256(span)=4e9b5b2aaef2d28b4c75d01bafefcf656a3452d943d26ba9aafd9c23094baa17.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80153410.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80149020();
void func_80148038();
void func_80147460();
void func_801470B4();
void func_8015369C();
void func_80146CA0();
typedef struct {
    u8 pad[0xA]; s16 uA;
    u8 padC[0xD2]; u8 uDE;
} T;
void func_80153410(T *p) {
    func_80149020(p);
    func_80148038(p, 0x18000);
    func_80147460(p);
    if (p->uA >= 0x201 || p->uDE-- == 0) {
        func_801470B4(p);
        func_8015369C(p);
        func_80146CA0(p);
    }
}
