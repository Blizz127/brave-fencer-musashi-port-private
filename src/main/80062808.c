/* Main-exec range [80062808,80062870) from the SLUS executable.
 * SHA256(span)=66e895b6d0d6ccf524d91264f49085ec54719c78dbe8e53c90bd4a7c90ba9c09.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 *D_80062870;
extern s32 *D_8006287C;
extern s32 D_80074764;
void func_8005CE28();                                  /* static */
void func_8005CF08();                                  /* static */
void func_8005CF18();                                  /* static */

void func_80062808(void) {
    s32 *var_t2;
    s32 temp_v1;
    void *var_v0;

    D_80074764 = (s32) saved_reg_ra;
    func_8005CF08();
    var_v0 = (void *(*)())0xB0()->unk18;
    var_t2 = &D_80062870;
    do {
        temp_v1 = *var_t2;
        var_t2 += 4;
        var_v0 += 4;
        var_v0->unk6C = temp_v1;
    } while (var_t2 != &D_8006287C);
    func_8005CE28();
    func_8005CF18();
}
