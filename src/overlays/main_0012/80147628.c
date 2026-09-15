/* Overlay range [80147628,80147718) from MAIN.CD member 0012.
 * SHA256(span)=41748af6c54cda984fdcb89e811c35f0bc21dbddbc92def0650654d23bf738da.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"
#include "m2c_macros.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_800123F0(void *, s16);                 /* extern */
void func_80012558(void *, s16);                 /* extern */
void func_800126C4(void *, s16);                 /* extern */
void func_80013F3C(void *);                      /* extern */

void func_80147628(void *arg0) {
    s16 var_a1;
    s16 var_a1_2;
    s16 var_a1_3;
    void *temp_s1;
    void *temp_s2;

    temp_s2 = M2C_FIELD(arg0, void **, 0x20);
    temp_s1 = temp_s2 + 0x34;
    func_80013F3C(temp_s1);
    func_80012558(temp_s1, M2C_FIELD(arg0, s16 *, 0x102));
    func_800126C4(temp_s1, M2C_FIELD(arg0, s16 *, 0x100));
    func_800123F0(temp_s1, M2C_FIELD(arg0, s16 *, 0x104));
    if (M2C_FIELD(arg0, u16 *, 0x136) & 2) {
        var_a1 = M2C_FIELD(arg0, s16 *, 0x132);
    } else {
        var_a1 = M2C_FIELD(temp_s2, s16 *, 0x12);
    }
    func_80012558(temp_s1, var_a1);
    if (M2C_FIELD(arg0, u16 *, 0x136) & 1) {
        var_a1_2 = M2C_FIELD(arg0, s16 *, 0x130);
    } else {
        var_a1_2 = M2C_FIELD(temp_s2, s16 *, 0x10);
    }
    func_800126C4(temp_s2 + 0x34, var_a1_2);
    if (M2C_FIELD(arg0, u16 *, 0x136) & 4) {
        var_a1_3 = M2C_FIELD(arg0, s16 *, 0x134);
    } else {
        var_a1_3 = M2C_FIELD(temp_s2, s16 *, 0x14);
    }
    func_800123F0(temp_s2 + 0x34, var_a1_3);
}
