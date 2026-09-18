/* Main-exec range [8003F104,8003F144) from the SLUS executable.
 * SHA256(span)=7999745ec89d5f0c8dc85fcf8d6de079cdd6b6e1b2311f0be5bcf2d4c3f20b29.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
#include "psx_types.h"

/* Decompiled by hand from main.s, then verified byte-exact
 * against retail by tools/match_function.py. Types and signatures are
 * whatever reproduces the bytes; they are not evidence of the
 * original declaration. */

extern s32 D_800C73D8[];

/* Staged double dereference: the table word becomes a base address
 * for a byte offset. The `(s16)` casts emit the `sll`/`sra` pairs,
 * and literal `* 176` strength-reduces to exactly the retail
 * `*11`-then-`*16` shift chain. */
s32 func_8003F104(s32 arg0, s32 arg1) {
    s32 v1 = D_800C73D8[(s16)arg0];
    s32 j = (s16)arg1 * 176;

    return *(s32 *)((u8 *)v1 + j);
}
