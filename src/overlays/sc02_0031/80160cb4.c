/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160CB4,80160D10).
 * Offset 0x38B5C at overlay base 80128158. SHA256(span)=01c3d36dfbf5c70cb366ff25ea256f6bf70ca475e9a4d8037676a8b8f667f5bc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160cb4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80161208();
void func_80154150();
void func_80154A74();
void func_80146CA0();
typedef struct { u8 pad[0xB8]; u16 f; } T;
void func_80160CB4(T *p) {
    if (func_80161208(p) == 0 && p->f == 0x8000) {
        func_80154150(p, 0x27);
        func_80154A74(p, 0x1F);
        func_80146CA0(p);
    }
}
