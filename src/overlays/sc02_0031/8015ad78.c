/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015AD78,8015ADB0).
 * Offset 0x32C20 at overlay base 80128158. SHA256(span)=8d09596bbdb49fd6e9096da5c756ce443ce87842f0e3402dbcff9096b5a4df3f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015ad78.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8015ADB0(s32);                               /* static */
s32 func_80161104();                                /* static */

void func_8015AD78(s32 arg0) {
    if (func_80161104() != 0) {
        func_8015ADB0(arg0);
    }
}
