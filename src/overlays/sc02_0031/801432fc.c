/* SC02.CD FILE_031 / ov_SC02_031 retail span [801432FC,80143390).
 * Offset 0x1B1A4 at overlay base 80128158. SHA256(span)=fbfbd14bb6f5e456f56a7f4a0988f18992a1cce001c48d236d108c7e5e788348.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801432fc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_80142DB8();
s32 func_8012C044();
void func_80142BB4();
void func_80142C9C();
s32 func_8012BF10();
void func_8012AD44();
typedef struct { u8 pad[0x100]; s16 u100; } T;
void func_801432FC(T *p) {
    if (func_80142DB8(p) == 1) {
        func_80142BB4(p, 1, 3);
    } else if (p->u100 != 0) {
        if (func_8012C044(p)) {
            func_80142BB4(p, 0, 3);
        }
    } else {
        func_80142C9C(p);
        if (func_8012BF10(p, 0x30)) {
            func_8012AD44(p, 2);
        }
    }
}
