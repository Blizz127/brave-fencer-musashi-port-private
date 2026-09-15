/* Overlay range [80147DC0,80147E44) from MAIN.CD member 0012.
 * SHA256(span)=f517d4fe99ca135587e40de7db5f64d615b8d70414941bedacb8433c30fc14a9.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800123F0(void *, s16);              /* extern */
void func_80012558(void *, s16);              /* extern */
void func_800126C4(void *, s16);              /* extern */
void func_80013F3C(void *);                   /* extern */
void func_800484EC(void *, void *, s32);  /* extern */

void func_80147DC0(void *arg0, s32 arg1) {
    s32 sp20;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x20);
    func_80013F3C(&sp20);
    func_800126C4(&sp20, M2C_FIELD(temp_s0, s16 *, 0x10));
    func_80012558(&sp20, M2C_FIELD(temp_s0, s16 *, 0x12));
    func_800123F0(&sp20, M2C_FIELD(temp_s0, s16 *, 0x14));
    func_800484EC(&sp20, arg0 + 0x24, arg1);
}
