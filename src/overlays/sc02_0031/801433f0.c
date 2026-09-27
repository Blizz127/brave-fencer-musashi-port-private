/* SC02.CD FILE_031 / ov_SC02_031 retail span [801433F0,80143458).
 * Offset 0x1B298 at overlay base 80128158. SHA256(span)=d6c1cc9d7250941c5da987562a94904a5ba17d709a5cd54cc49156e96101a3a8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801433f0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_80143458();
void func_8012931C();
s32 func_80128ED8();
void func_801292C8();
typedef struct {
    u8 pad[2]; u16 u2;
    u8 pad4[0x1C]; void *inner;
} T;
void func_801433F0(T *p) {
    if (p->u2 == 0) {
        func_80143458(p);
    } else {
        func_8012931C(p);
        if (func_80128ED8(p->inner, (u8 *)p + 0x24)) {
            func_801292C8(p);
        }
    }
}
