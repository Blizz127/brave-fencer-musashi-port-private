/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157880,801578C0).
 * Offset 0x2F728 at overlay base 80128158. SHA256(span)=2bf1cd8e90bc64dc4b71a77bad32c33a843786cab07b279ebfad4d3ca881fdf4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157880.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8014D3E0(s32);                               /* static */
void func_8014ED28();                                  /* static */
void func_8014FA04(s32);                               /* static */
void func_801578C0(s32);                               /* static */

void func_80157880(s32 arg0) {
    func_8014ED28();
    func_8014D3E0(arg0);
    func_8014FA04(arg0);
    func_801578C0(arg0);
}
