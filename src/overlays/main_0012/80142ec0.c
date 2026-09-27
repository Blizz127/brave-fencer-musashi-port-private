/* Overlay range [80142EC0,80142F68) from MAIN.CD member 0012.
 * SHA256(span)=6b98e49ca953f27ee4f3633f778477b2f514c8f0f8828209cb6d706a5e761ce9.
 * Word export for the native seam; the body below is a
 * verified MATCH (42/42 words at 0x80142EC0, -O2). */
#include "psx_types.h"
#include "m2c_macros.h"

/* Verified byte-exact against retail by tools/match_function.py
 * (42/42 words at 0x80142EC0). Same saved-copy fix as sibling
 * func_80142DC4, plus plain array indexing (m2c's `*(D + (x * 4))`
 * double-scales the s32 stride). Types and signatures are whatever
 * reproduces the bytes; they are not evidence of the original
 * declaration. */

void func_8001CA1C(void *, s32);             /* extern */
extern s32 D_8017F9A4[];
void func_8012A828(void *, s32);                 /* static */
void *func_8012C1B8();                              /* static */
void func_8012CAE4(void *);                      /* static */
void func_80142B2C(void *);                      /* static */

void func_80142EC0(void *arg0) {
    s16 temp_v1;
    void *temp_v0;
    void *save;

    temp_v0 = func_8012C1B8();
    save = temp_v0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    if (temp_v0 == 0) {
        func_8012CAE4(arg0);
        return;
    }
    func_8001CA1C(save, 0);
    temp_v1 = ((M2C_FIELD(arg0, u16 *, 0x70) & 0xF) * 0x600) + 0xC00;
    M2C_FIELD(save, s16 *, 0x1A) = temp_v1;
    M2C_FIELD(save, s16 *, 0x18) = temp_v1;
    M2C_FIELD(arg0, s16 *, 0xFC) = 0;
    func_8012A828(arg0, D_8017F9A4[M2C_FIELD(arg0, u16 *, 0x70) & 0xF]);
    func_80142B2C(arg0);
}
