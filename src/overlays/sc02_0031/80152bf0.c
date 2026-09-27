/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152BF0,80152C40).
 * Offset 0x2AA98 at overlay base 80128158. SHA256(span)=9ce5502b292a0e8aad50b07b28f35afa5c5968850866cfb73a59c118b1cb6144.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152bf0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80062C14;
void func_80019064();
void func_80151204();
void func_80149020();
void func_80146CA0();
typedef struct { u8 pad_0[242]; s16 fF2; } T;
void func_80152BF0(T *p) {
    func_80019064(&D_80062C14);
    func_80151204(p, p->fF2);
    func_80149020(p);
    func_80146CA0(p);
}
