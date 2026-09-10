/* Complete SC02 retail span [8014462C,801446A4).
 * Ahead leaf.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
#include "psx_types.h"

extern void func_8012AD80(s32 a0);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80016714(void *a0, s32 a1);
extern void func_8012C218(void *a0);

void func_8014462C(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0xCC);

    func_8012AD80((s32)a0);
    *(u16 *)(s1 + 8) = *(u16 *)(a0 + 6);
    *(u16 *)(s1 + 0xA) = *(u16 *)(a0 + 0xA);
    *(u16 *)(s1 + 0xC) = *(u16 *)(a0 + 0xE);
    if (func_80128ED8((s32)s1, (s32 *)(a0 + 0xD0))) {
        func_80016714(s1, 0x38);
        func_8012C218(a0);
    }
}
