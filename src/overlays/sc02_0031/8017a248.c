/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A248,8017A270).
 * Offset 0x520F0 at overlay base 80128158. SHA256(span)=cf721b14aeac360d4d6b8cbc2d1aaa79fda38719639ac608436e27844204700e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017a248.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80179B74(s16 *);                             /* static */

void func_8017A248(void) {
    s16 sp10;

    sp10 = 0x22;
    func_80179B74(&sp10);
}
