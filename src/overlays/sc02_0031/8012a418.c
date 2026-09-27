/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A418,8012A464).
 * Offset 0x22C0 at overlay base 80128158. SHA256(span)=e00698062425188e27910bc9f2de60580fb9a39f4d87fd17754cb3760851d55f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a418.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u32 w[41]; } T;
extern T *D_801151D4;
extern T D_80114EE8;
void func_8012A418(void) { D_80114EE8 = *D_801151D4; }
