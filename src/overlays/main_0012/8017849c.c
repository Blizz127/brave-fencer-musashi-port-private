/* Overlay range [8017849C,80178608) from MAIN.CD member 0012.
 * SHA256(span)=913e8a1910c9ed46bf1eae72b40ecc38248cb07fee3ab3d6bb72bf2b0512f646.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8012A908();                                  /* static */
void func_80130D0C(u16 *);                             /* static */
void func_8013E370();                                  /* static */
void func_8017869C(u16 *);                             /* static */
void func_801787D4();                                  /* static */
extern s32 D_8011DB08;
extern u16 D_801202A0;
extern s16 D_801270C0;

void func_8017849C(void) {
    s32 var_s2;
    u16 *var_s0;
    u16 *var_s1;
    void *temp_a0;

    var_s1 = &D_801202A0;
    func_801787D4();
    var_s2 = 0;
    func_8012A908();
    var_s0 = &D_801202A0 + 0x54;
    do {
        if ((*var_s1 != 0) && ((D_801270C0 == 1) || (var_s0->unk1E & 0x1000))) {
            func_8017869C(var_s1);
            var_s0->unk-1C = (s32) var_s0->unk-50;
            var_s0->unk-18 = (s32) var_s0->unk-4C;
            var_s0->unk-14 = (s32) var_s0->unk-48;
            if ((var_s0->unk6C != 0) && (var_s0->unk6D != 0)) {
                func_80130D0C(var_s1);
            } else {
                *((*var_s1 * 4) + D_8011DB08)(var_s1);
            }
            temp_a0 = var_s0->unk-34;
            if (temp_a0 != 0) {
                temp_a0->unk8 = (s16) (var_s0->unk-4E + var_s0->unk-4);
                var_s0->unk-34->unkA = (s16) (var_s0->unk-4A + var_s0->unk-2);
                var_s0->unk-34->unkC = (s16) (var_s0->unk-46 + var_s0->unk0);
            }
        }
        var_s2 += 1;
        var_s0 += 0x10C;
        var_s1 += 0x10C;
    } while (var_s2 < 0x60);
    if (D_801270C0 == 1) {
        func_8013E370();
    }
}
