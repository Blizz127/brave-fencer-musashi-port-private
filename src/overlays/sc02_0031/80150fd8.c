/* SC02.CD FILE_031 / ov_SC02_031 retail span [80150FD8,80151014).
 * Offset 0x28E80 at overlay base 80128158. SHA256(span)=aeca55e70b6fc087bed8d9da9f0bca9ecafcdebc2fd3e09146e3be7efcb9825a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80150fd8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"

void func_80146994(s32, s32, s32, s32);                      /* static */
extern u16 D_800B99DA;

void func_80150FD8(s32 arg0) {
    if (D_800B99DA & 7) {
        func_80146994(0x34, arg0, 0, 0);
    }
}
