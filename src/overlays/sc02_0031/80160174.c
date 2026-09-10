/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160174,801601AC).
 * Offset 0x3801C at overlay base 80128158. SHA256(span)=606a46fe9b41f58f98798fecdfc341297b51af02fd91243288199500c81e07ce.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160174.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_801601AC(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_80160174(s32 arg0) {
    if (func_80161104() != 0) {
        func_801601AC(arg0);
    }
}
