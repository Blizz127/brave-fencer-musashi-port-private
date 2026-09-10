/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015B8F8,8015B950).
 * Offset 0x337A0 at overlay base 80128158. SHA256(span)=14e4f16788957fc1996316229c8df6d1a8361e4ac4260a64ceecfba95e402c85.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015b8f8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
void func_801542DC();
void func_80154150();
extern s32 D_800D4A9C;
extern s32 D_800D4B48;
typedef struct { u8 pad[0x23C]; void *p23c; u8 pad240[4]; u8 u244; } T;
void func_8015B8F8(T *p) {
    if (p->p23c == &D_800D4A9C || p->p23c == &D_800D4B48) {
        func_801542DC(p, p->p23c, p->u244);
    } else {
        func_80154150(p, 0xF);
    }
}
