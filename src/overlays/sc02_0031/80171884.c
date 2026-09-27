/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171884,801718AC).
 * Offset 0x4972C at overlay base 80128158. SHA256(span)=b3453eb0a58105ac7b47a9158e91cfe8d187a09c02d83e15c7c50c5663a4dd12.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171884.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80171928(void *);                               /* static */
extern s32 *D_80126B58;

void func_80171884(void) {
    func_80171928(&D_80126B58);
}
