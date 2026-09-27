/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152C40,80152C80).
 * Offset 0x2AAE8 at overlay base 80128158. SHA256(span)=a1217cbefb42b4e904a1c4bdc337c8496d1f843ea8e98d81522c13fdddc8c668.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152c40.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80149020();                                  /* static */
void func_80152C80(s32);                               /* static */
void func_80159B3C(s32);                               /* static */
void func_80165718(s32);                               /* static */

void func_80152C40(s32 arg0) {
    func_80149020();
    func_80152C80(arg0);
    func_80159B3C(arg0);
    func_80165718(arg0);
}
