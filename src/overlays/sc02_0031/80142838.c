/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142838,801428CC).
 * Offset 0x1A6E0 at overlay base 80128158. SHA256(span)=9d3c6136b708c87887f31f2c63de6b4c5e8eb42884913f61e2ddb5f54d9411ee.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142838.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80142DB8();
s32 func_8012C0EC();
void func_80142BB4();
void func_80142C9C();
s32 func_8012BF10();
void func_8012AD44();
typedef struct { u8 pad[0x100]; s16 u100; } T;
void func_80142838(T *p) {
    if (func_80142DB8(p) == 1) {
        func_80142BB4(p, 1, 3);
    } else if (p->u100 != 0) {
        if (func_8012C0EC(p)) {
            func_80142BB4(p, 0, 3);
        }
    } else {
        func_80142C9C(p);
        if (func_8012BF10(p, 0x30)) {
            func_8012AD44(p, 2);
        }
    }
}
