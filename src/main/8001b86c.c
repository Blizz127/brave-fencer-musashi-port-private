/* Main-exec range [8001B86C,8001BA84) from the SLUS executable.
 * SHA256(span)=697162ec0f03063c386121faa74f13ff6f024344a9e03ede07fcdb236fcce6ea.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_800747FC;
void func_8001BA84();                                  /* static */
s32 func_8001BADC(s32, s32);                          /* static */
void func_8001BB60();                                  /* static */
void func_80059BFC(s32, s32, u16);                       /* static */
void func_80059FC0(void *);                            /* static */
extern s32 D_80074800;
extern s32 D_80074804;
extern s32 D_8007480C;
extern s32 *D_8007BA70;
extern void *D_800A5E60;
extern s32 *D_800A651C;
extern s32 *D_800A6528;
extern s32 *D_800A6610;
extern s32 *D_800AF630;
extern u16 D_800B9A02;

s32 func_8001B86C(void) {
    s32 temp_v0;
    s32 var_v0;

    switch (D_800747FC) {                           /* irregular */
    case 0:
        *(&D_800A651C + (D_800B9A02 * 0x14)) = (D_800B9A02 << 0xE) + &D_800A6610;
        *(&D_800A6528 + (D_800B9A02 * 0x14)) = (D_800B9A02 << 0xE) + (&D_800A6610 + 4);
        D_800A5E60 = (D_800B9A02 * 0x13880) + &D_8007BA70;
        func_80059BFC(*(&D_800A651C + (D_800B9A02 * 0x14)), 2, D_800B9A02);
        func_8001BA84();
        D_80074800 = 0x80;
        D_800747FC = (s32) (D_800747FC + 1);
        return 0;
    case 1:
        D_80074804 = D_800747FC;
        D_800747FC = 2;
        return 0;
    case 2:
        func_80059FC0(&D_800AF630 + 0x160);
        func_80059BFC(*(&D_800A651C + (D_800B9A02 * 0x14)), 2);
        func_8001BB60();
        D_800747FC = (s32) (D_800747FC + 1);
        /* fallthrough */
    case 3:
        temp_v0 = D_80074804 < 2;
        D_80074804 += 1;
        if (temp_v0 == 0) {
            D_80074804 = 1;
            var_v0 = 1;
            if (func_8001BADC(D_8007480C, 1) == 0) {
                D_8007480C += 1;
                return 0;
            }
            /* Duplicate return node #12. Try simplifying control flow for better match */
            return var_v0;
        }
        func_8001BADC(D_8007480C, 0);
        var_v0 = 0;
        return var_v0;
    default:
        return 0;
    }
}
