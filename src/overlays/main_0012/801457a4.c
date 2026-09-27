/* Overlay range [801457A4,801458C4) from MAIN.CD member 0012.
 * SHA256(span)=4d483a9851eee2f5fd1e2aa24a54eae26379a4a8156eaf023a2f0c692cf0eea4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Body below is an UNVERIFIED draft, not an oracle match
 * claim; promotion requires tools/match_function.py MATCH. */
#include "psx_types.h"

/* m2c draft from main_0012.s: NOT verified against retail. C89-gated only;
 * promotion requires an oracle MATCH (tools/match_function.py). Types
 * and signatures are whatever the decompiler guessed; they are not
 * evidence of the original declaration. */

extern s32 D_8017E338;
void func_801458CC(s32 (*)[]);                         /* static */

void func_801457A4(s32 arg0) {
    if (arg0 < 0x201B) {
        if ((arg0 < 0x2015) && (arg0 != 0x1077)) {
            if (arg0 < 0x1078) {
                if ((arg0 != 0x1010) && (arg0 != 0x1052)) {
                    /* Duplicate return node #20. Try simplifying control flow for better match */
                    func_801458CC();
                    return;
                }
                /* Duplicate return node #18. Try simplifying control flow for better match */
                func_801458CC((s32 (*)[]) D_8017E338);
                return;
            }
            if ((arg0 != 0x1094) && (arg0 != 0x2013)) {
                /* Duplicate return node #20. Try simplifying control flow for better match */
                func_801458CC();
                return;
            }
            /* Duplicate return node #18. Try simplifying control flow for better match */
            func_801458CC((s32 (*)[]) D_8017E338);
            return;
        }
        /* Duplicate return node #18. Try simplifying control flow for better match */
        func_801458CC((s32 (*)[]) D_8017E338);
        return;
    }
    if (arg0 < 0x2081) {
        if (arg0 < 0x207A) {
            if ((arg0 < 0x205C) && (arg0 >= 0x2055)) {
                /* Duplicate return node #18. Try simplifying control flow for better match */
                func_801458CC((s32 (*)[]) D_8017E338);
                return;
            }
            /* Duplicate return node #20. Try simplifying control flow for better match */
            func_801458CC();
            return;
        }
        /* Duplicate return node #18. Try simplifying control flow for better match */
        func_801458CC((s32 (*)[]) D_8017E338);
        return;
    }
    if ((arg0 < 0x209E) && (arg0 >= 0x2097)) {
        func_801458CC((s32 (*)[]) D_8017E338);
        return;
    }
    func_801458CC();
}
