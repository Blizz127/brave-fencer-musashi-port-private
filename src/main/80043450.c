#include "psx_types.h"

/* Decompiled by hand from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern void func_80044CE8(void);
extern s32 func_80044D38(void);
extern s32 func_80044BF4(void);

/* Semantics note, because the branch-delay slots lie to a casual reader:
 * each `bnez`-to-epilogue has `rc = 0` sunk into its delay slot, so a
 * nonzero poll result returns 0 (not ready: the caller retries), while the
 * fall-through sets `rc = 1`. The m2c draft had this inverted. The
 * `rc = 0; goto done;` taken blocks are what let the scheduler fill both
 * delay slots; without the explicit zeroing the match fails at words 13
 * and 20. Asked and answered against the extracted EXE, not the listing. */
s32 func_80043450(s32 arg) {
    s32 rc;

    if (arg == 2) {
        func_80044CE8();
        rc = 1;
        goto done;
    }
    rc = func_80044D38();
    if (rc != 0) {
        rc = 0;
        goto done;
    }
    rc = 1;
    if (arg != 1) {
        goto done;
    }
    rc = func_80044BF4();
    if (rc != 0) {
        rc = 0;
        goto done;
    }
    rc = 1;
done:
    return rc;
}

