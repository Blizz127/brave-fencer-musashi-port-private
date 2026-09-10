/* SC02.CD FILE_031 / ov_SC02_031 retail span [801623B8,80162414).
 * Offset 0x3A260 at overlay base 80128158. SHA256(span)=f8363491cf915bd3ba4c28297e16736d4bc29e185f5ab28fccb03daa30eb4731.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801623b8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_800D0C48();
void func_800167B8();
typedef struct { u8 pad[0x15]; u8 u15; u8 pad16[0x12]; s32 u28; } T;
s32 func_801623B8(T *p) {
    p->u28 = p->u28 - 1;
    if (p->u28 == -1) {
        func_800D0C48(1);
        func_800167B8(4);
        p->u15 = p->u15 + 1;
    }
    return 0;
}
