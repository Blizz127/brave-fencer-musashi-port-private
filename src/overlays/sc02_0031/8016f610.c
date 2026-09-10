/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F610,8016F648).
 * Offset 0x474B8 at overlay base 80128158. SHA256(span)=4eb3efe048c9f280e5d09e8d40e2b21a82bbd6f1a190a35d61510be2ed5bd47a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f610.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80148634(s32);                               /* static */
void func_8016F288();                                  /* static */
void func_80171928(s32);                               /* static */

void func_8016F610(s32 arg0) {
    func_8016F288();
    func_80148634(arg0);
    func_80171928(arg0);
}
