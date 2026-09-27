/* Main-exec range [800623A4,80062434) from the SLUS executable.
 * SHA256(span)=2372f8cb4d4e13d5bf986b58693028b91b6c12ba5b0a3294b313453dd199d51e.
 * Word export for the native seam (m2c produced no draft). */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8005CF08();                            /* static */
void func_8005CF18();                            /* static */
void func_8005CF48();                     /* static */
void func_8006252C();                            /* static */
void func_800626B8(s32, s32, s32, s32); /* static */
void func_800626F0();                            /* static */
void func_80062768();                            /* static */
extern s32 func_80072A24;

void func_800623A4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80062768();
    func_8005CF08();
    func_800626F0();
    func_8005CF18();
    func_8005CF48(0);
    func_8006252C();
    func_800626B8(arg0, arg1, arg2, arg3);
    func_80072A24 = 1;
}
