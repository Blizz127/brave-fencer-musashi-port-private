/* Overlay range [80151780,80151878) from MAIN.CD member 0012.
 * SHA256(span)=5c2af7d11d57be248a5efd1a4109dbb27e80b77eff05b8e59dc48eaa8c9b9170.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

s16 func_80029D3C(s16);                             /* extern */
void func_80151878(void *);                            /* static */
void func_80153B58(void *);                            /* static */
void func_801725CC();                                  /* static */
extern s32 D_801151FC;
extern s16 D_8011DB1A;
extern s32 D_80127518;

void func_80151780(void *arg0) {
    u8 temp_v1;
    void *temp_s1;

    temp_v1 = arg0->unkDD;
    temp_s1 = arg0->unk1F0;
    if ((temp_v1 != 0) && (temp_v1 < 0x21U)) {
        if (((temp_v1 * 4) + temp_s1)->unk-4 != 0) {
            func_801725CC();
            if (D_8011DB1A != 0x3E8) {
                D_8011DB1A = func_80029D3C(D_8011DB1A);
            }
            ((arg0->unkDD * 4) + temp_s1)->unk-4(arg0);
            D_801151FC = D_80127518;
        } else {
            func_80151878(arg0);
        }
    } else {
        temp_s1->unk8(arg0);
    }
    if (arg0->unkF0 & 0x200) {
        func_80153B58(arg0);
    }
}
