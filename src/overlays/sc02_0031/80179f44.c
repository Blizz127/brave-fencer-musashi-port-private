/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179F44,80179F6C).
 * Offset 0x51DEC at overlay base 80128158. SHA256(span)=0e72e869e96edd5eb7f324a089d4dcb1e4ca557a5b7582d1036b7ba831155f4f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179f44.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80179B74(s16 *);                             /* static */

void func_80179F44(void) {
    s16 sp10;

    sp10 = 0x18;
    func_80179B74(&sp10);
}
