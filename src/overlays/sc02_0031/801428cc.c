/* SC02.CD FILE_031 / ov_SC02_031 retail span [801428CC,8014292C).
 * Offset 0x1A774 at overlay base 80128158. SHA256(span)=8e94e45febc00257b0d4fbc591dc811b93b283ffabb22e2429461fb9cd358cb5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801428cc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80142DB8();
s32 func_80142D38();
void func_80142BB4();
void func_801428CC(void *p) {
    if (func_80142DB8(p) == 1) {
        func_80142BB4(p, 1, 3);
    } else if (func_80142D38(p) == 1) {
        func_80142BB4(p, 0, 3);
    }
}
