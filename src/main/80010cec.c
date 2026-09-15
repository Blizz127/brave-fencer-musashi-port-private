/* Exact retail word export for [80010CEC,80010D60); EXE and assembly verified. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800CEDFC();                            /* extern */
void func_80011818();                     /* static */
void func_80015310();                            /* static */
void func_8001C044();                            /* static */
extern s32 *D_800AF630;

void func_80010CEC(void) {
    func_800CEDFC();
    if (M2C_FIELD(&D_800AF630, u16 *, 0xA3B6) != 0) {
        func_8001C044();
        func_80015310();
        func_80011818(3);
    }
}
