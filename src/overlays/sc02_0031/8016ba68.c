/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016BA68,8016BADC).
 * Offset 0x43910 at overlay base 80128158. SHA256(span)=050edd37b2ec140946270e740cd93d58c0fb56307b8b4fe7b3e111c810591707.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016ba68.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
#include "psx_types.h"
s32 func_8014C050();
void func_80146C3C();
void func_80146A6C();
extern s32 D_80126B58;
typedef struct { u8 pad[0x7C]; s16 a, b, c; } T;
void func_8016BA68(T *p, s32 a1) {
    s32 v = func_8014C050(&D_80126B58, 0x56);
    if (v) {
        func_80146C3C(v);
    }
    func_80146A6C(0x56, p, p->a, p->b, p->c, a1, 0);
}
