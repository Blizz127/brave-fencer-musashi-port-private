/* Overlay range [80142DC4,80142E38) from MAIN.CD member 0012.
 * SHA256(span)=1622fd6dbbb0db6692e3d9d1fa7245be827fb46f6515bfc3c611af28727666a1.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Verified byte-exact against retail by tools/match_function.py
 * (29/29 words at 0x80142DC4). The saved copy `save` is load-bearing:
 * immediate uses stay in $v0 while later uses come from $s0; and the
 * second call arg is the *address* (cast to s32), matching callee
 * func_8001CA1C which stores it as a word. Types and signatures are
 * otherwise whatever reproduces the bytes; they are not evidence of
 * the original declaration. */
#include "psx_types.h"
#include "m2c_macros.h"

void func_8001CA1C(void *, s32);                /* extern */
extern s32 D_8017F7BC;
void *func_8012C1B8();                              /* static */
void func_8012CAE4(void *);                      /* static */
void func_80142B2C(void *);                      /* static */

void func_80142DC4(void *arg0) {
    void *temp_v0;
    void *save;

    temp_v0 = func_8012C1B8();
    save = temp_v0;
    M2C_FIELD(arg0, void **, 0x20) = temp_v0;
    if (temp_v0 == 0) {
        func_8012CAE4(arg0);
        return;
    }
    func_8001CA1C(save, (s32) &D_8017F7BC);
    M2C_FIELD(save, s16 *, 0x1A) = 0x1800;
    M2C_FIELD(save, s16 *, 0x18) = 0x1800;
    M2C_FIELD(arg0, s16 *, 0xFC) = 0;
    func_80142B2C(arg0);
}
