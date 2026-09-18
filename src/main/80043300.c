#include "psx_types.h"

/* Decompiled by hand from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 func_80043450(s32);
extern s32 func_8004359C(s32);
extern s32 func_800435B4(s32);
extern s32 func_8004654C(s32);
extern s32 func_80046564(s32);
extern s32 func_8005C604(const char *);
extern void func_80043398(void);
extern void func_800433C0(void);
extern void func_800433E8(void);
extern char D_800735FC[];

/* Two structural notes, both load-bearing. The back-edge `goto` keeps gcc
 * from recognising the retry as a loop, so the `== 1` and `!= -1` constants
 * stay per-iteration immediates instead of being hoisted into saved registers
 * (which would grow the frame to 0x20). The convergent `return rc` keeps the
 * success block falling through from the `bne`, with `return 1` compiled as a
 * jump into the shared epilogue rather than a reordered out-of-line block. */
s32 func_80043300(void) {
    s32 count = 4;
    s32 ret;
    s32 rc;

retry:
    ret = func_80043450(1);
    count -= 1;
    if (ret == 1) {
        func_8004359C((s32)func_80043398);
        func_800435B4((s32)func_800433C0);
        func_8004654C((s32)func_800433E8);
        func_80046564(0);
        rc = 1;
    } else {
        if (count != -1) {
            goto retry;
        }
        func_8005C604(D_800735FC);
        rc = 0;
    }
    return rc;
}

