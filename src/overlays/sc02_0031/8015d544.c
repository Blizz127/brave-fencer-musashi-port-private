/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015D544,8015D57C).
 * Offset 0x353EC at overlay base 80128158. SHA256(span)=5547f2a945d02de356cdeb5cbb75b6498bfe68ff4ae02228965b32353e77d5c4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015d544.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8015D57C(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_8015D544(s32 arg0) {
    if (func_80161104() != 0) {
        func_8015D57C(arg0);
    }
}
