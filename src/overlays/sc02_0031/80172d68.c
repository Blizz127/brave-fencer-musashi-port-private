/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172D68,80172DAC).
 * Offset 0x4AC10 at overlay base 80128158. SHA256(span)=3d8b220ce30fe8618ff95de488b2e6f8dcbd3cf54b97b39ee53e7d64e040ee82.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172d68.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
extern s32 D_80126B58;
extern void *D_80127508;
void *func_8014C168();
void func_80172DAC();
void func_80174684();
void func_80172D68(void *p) {
    D_80127508 = func_8014C168(&D_80126B58, p);
    func_80174684(func_80172DAC);
}
