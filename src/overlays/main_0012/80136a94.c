/* Overlay range [80136A94,80136BC4) from MAIN.CD member 0012.
 * SHA256(span)=f3c9eacddc487e8f050026251588cf66b8aa37ea4bd187f5be58544851d12954.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

void func_8004864C(s16 *, s32 *);                      /* extern */
void func_80048FBC(s32, u16 *, u16 *);                   /* extern */
extern s32 D_8017E918;
extern s16 D_801152A8;
extern s16 D_801152AA;
extern s16 D_801152AC;
extern u16 D_80126720;
extern u16 D_80126722;
extern u16 D_80126724;

void func_80136A94(s32 arg0, void *arg1, void *arg2, s32 arg3) {
    s32 sp10;

    if (arg0 != 0) {
        func_80048FBC(arg3, D_8017E918, D_8017E918);
        func_80048FBC(arg3, &D_80126720, &D_80126720);
        func_8004864C(&D_801152A8, &sp10);
        D_801152A8 = (s16) sp10;
        D_801152AA = (s16) sp14;
        D_801152AC = (s16) sp18;
    }
    arg2->unk0 = (s16) (D_8017E918->unk0 + arg1->unk48);
    arg2->unk2 = (s16) (D_8017E918->unk2 + arg1->unk4C);
    arg2->unk4 = (s16) (D_8017E918->unk4 + arg1->unk50);
    D_80126720 += arg1->unk48;
    D_80126722 += arg1->unk4C;
    D_80126724 += arg1->unk50;
}
