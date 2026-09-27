/* SC02.CD FILE_031 / ov_SC02_031 retail span [801430F4,80143188).
 * Offset 0x1AF9C at overlay base 80128158. SHA256(span)=5878cad9a0f28abb422dfdf2bf4d638a8e95bac6e85e7c4bf1d9d6d22082c830.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801430f4.c (recovery=c, -O2); the span is
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
void func_801430F4(T *p) {
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
