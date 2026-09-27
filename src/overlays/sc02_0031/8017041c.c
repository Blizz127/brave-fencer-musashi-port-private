/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017041C,8017044C).
 * Offset 0x482C4 at overlay base 80128158. SHA256(span)=a7085beda4cb50662313d90fdbf00e1b6831384f68651148e238cb7153e97526.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017041c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_8017044C(s32);                               /* static */
void func_80171990();                                  /* static */

void func_8017041C(s32 arg0) {
    func_80171990();
    func_8017044C(arg0);
}
