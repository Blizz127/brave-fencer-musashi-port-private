/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F648,8016F680).
 * Offset 0x474F0 at overlay base 80128158. SHA256(span)=d32c7945398b34865138d881bb92601015bf2024b25b62f7f06ae71c9878737e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f648.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80148634(s32);                               /* static */
void func_8016F264();                                  /* static */
void func_80171928(s32);                               /* static */

void func_8016F648(s32 arg0) {
    func_8016F264();
    func_80148634(arg0);
    func_80171928(arg0);
}
