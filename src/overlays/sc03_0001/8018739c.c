/* sc03_0001: own C written from the retail words (no upstream definition).
 * Verified byte-exact against retail by tools/verify_registry.py. Types and
 * signatures are whatever reproduces the bytes; they are not evidence of the
 * original declaration. */
#include "psx_types.h"

extern void func_8012F2E8(u8 *a0, s16 *in, s16 *out);
extern s32 func_8012CB64(s16 *v, s32 a1, s32 a2, s32 a3, s32 a4);
extern u16 D_80126B5E, D_80126B62, D_80126B66;

s32 func_8018739C(u8 *obj) {
    u8 *o = *(u8 **)(obj + 0x64);
    s16 out[4];
    s16 in[3];
    if (*(u16 *)(*(u8 **)(o + 0xCC) + 2) != 2) return 0;
    in[0] = D_80126B5E;
    in[1] = D_80126B62;
    in[2] = D_80126B66;
    func_8012F2E8(*(u8 **)(o + 0xCC), in, out);
    return func_8012CB64(out, -0xC0, 0x40, -0x60, 0);
}
