/* SC02.CD FILE_031 / ov_SC02_031 retail span [80143390,801433F0).
 * Offset 0x1B238 at overlay base 80128158. SHA256(span)=60b521039d31de79168f8ac6115d3e48e5e9b9751026635694332766aca7b4a5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80143390.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80142DB8();
s32 func_80142D38();
void func_80142BB4();
void func_80143390(void *p) {
    if (func_80142DB8(p) == 1) {
        func_80142BB4(p, 1, 3);
    } else if (func_80142D38(p) == 1) {
        func_80142BB4(p, 0, 3);
    }
}
