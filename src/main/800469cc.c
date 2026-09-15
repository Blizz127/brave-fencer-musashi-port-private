/* Exact retail word export [800469CC,80046A5C); verified against pinned EXE and asm. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_80078800;
extern s32 D_80078804;
extern s32 (*D_800A5E80)();
extern s32 D_800AE644;
extern s32 D_800C6D38;
extern s32 D_800C6D3C;
extern s32 D_800C7C94;

void func_800469CC(void) {
    void *temp_v1;

    temp_v1 = D_800C7C94 + (D_800C6D3C << 5);
    temp_v1->unk0 = 2;
    D_80078800.unk3 = (unaligned s32) M2C_ERROR(/* Unable to handle lwr; missing a corresponding lwl */);
    D_80078804 = temp_v1->unk8;
    D_800C6D3C = D_800C6D38;
    if (D_800A5E80 != 0) {
        D_800A5E80(D_800A5E80, &D_80078800);
    }
    D_800AE644 = 0;
}
