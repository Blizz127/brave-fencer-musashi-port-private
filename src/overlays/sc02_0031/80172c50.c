/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172C50,80172CA0).
 * Offset 0x4AAF8 at overlay base 80128158. SHA256(span)=08eeed6b49538162ba1611a029b5343d00b7dc317ff3c12de1362da6697767e9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172c50.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 b[8]; } S;
extern S D_80126B30;
void func_80172CA0();
void func_80174684();
void func_80172C50(S *p) {
    D_80126B30 = *p;
    func_80174684(func_80172CA0);
}
