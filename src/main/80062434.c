/* Main-exec range [80062434,800624C4) from the SLUS executable.
 * SHA256(span)=a8bd09d9aa043a47c5b81c06e04f915577e13b805b006e13ae76cd50ea61754c.
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
void func_80062688(s32, s32, s32, s32); /* static */
void func_800626F0();                            /* static */
void func_80062768();                            /* static */
extern s32 func_80072A24;

void func_80062434(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80062768();
    func_8005CF08();
    func_800626F0();
    func_8005CF18();
    func_8005CF48(0);
    func_8006252C();
    func_80062688(arg0, arg1, arg2, arg3);
    func_80072A24 = 1;
}
