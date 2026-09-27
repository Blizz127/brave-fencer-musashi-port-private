/* SC02.CD FILE_031 / ov_SC02_031 retail span [801596D4,801596F0).
 * Offset 0x3157C at overlay base 80128158. SHA256(span)=0039a44c6adb1b45f8fd98846be375bd7418f703283f17800bdb5b7125efd47a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801596d4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
typedef struct { u8 pad[0x15]; u8 unk15; u8 pad16[0x12]; s32 unk28; } T;
s32 func_801596D4(T *p) {
    p->unk28 = 0x10;
    p->unk15++;
    return 0;
}
