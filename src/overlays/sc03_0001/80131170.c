/* Overlay range [80131170,801312D0) from MAIN.CD member 0012.
 * SHA256(span)=e765700fde7de8fa864febcdd07325a9bbde6923b14b63c12f643e0a7dfd2f0a.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80131170 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern void func_8012B14C(s32 a0, s32 a1);
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131A34(s32, s32);
extern s32 func_80131AC8(void *a0);
extern void func_80131B14(void);
            typedef struct { s8 c[8]; } Blk8_80131170;


// @class: loop-guard
// @stuck: none — MATCH (88 ins). Keys: duplicate the c!=0/c==0 bodies verbatim (gcc cross-jumps
//   the shared "|=4;goto tail" into L240 on its own); tail dispatch as `if (((s32(*)(s32))func_8012BCCC)(p) <= 0x8FFF)`
//   (the <= polarity makes the >0x8FFF/0x33-first block the bnez'd else=L298, fall-through = 0x32-first);
//   both AC8 tails cross-jump-merge into the shared L2AC final call. Externs aligned to the file's
//   existing decls for gate-safety: func_80131B14(void) [file line 1486], func_8012B14C/func_8012BCCC
//   canonical (s32) [DEFINE macros], ((s32(*)())func_80131AC8)() no-proto (compatible w/ later 1-arg DEFINE, 2-arg call).


void func_80131170(s32 p, s32 b, s32 c) {
    extern u8 D_8018D870[];

    func_80131B14();
    *(u8 *)(((u8 *)p) + 0xC2) = 0;
    *(u8 *)(((u8 *)p) + 0xC3) = 0;
    *(s16 *)(((u8 *)p) + 0x98) = 0;
    if (((u8 *)b) == 0) {
        b = (s32)D_8018D870;
    }
    func_8012B14C((s32)((u8 *)p), (s32)((u8 *)b));
    *(s32 *)(((u8 *)p) + 0x1C) = 0;
    if (c != 0) {
        if (((s32(*)(s32, s32))func_80131A34)((s32)((u8 *)p), c) != 0) goto tail;
        if (((s32(*)(s32, s32))func_80131A34)((s32)((u8 *)p), 0x24) != 0) goto tail;
        *(s32 *)(((u8 *)p) + 0xC4) &= ~4;
        if (((s32(*)(s32, s32))func_80131A34)((s32)((u8 *)p), 0x20) != 0) {
            *(s32 *)(((u8 *)p) + 0xC4) |= 4;
        } else {
            *(s16 *)(((u8 *)p) + 0x98) = 0;
        }
    } else {
        if (((s32(*)(s32, s32))func_80131A34)((s32)((u8 *)p), 0x24) != 0) goto tail;
        *(s32 *)(((u8 *)p) + 0xC4) &= ~4;
        if (((s32(*)(s32, s32))func_80131A34)((s32)((u8 *)p), 0x20) != 0) {
            *(s32 *)(((u8 *)p) + 0xC4) |= 4;
        } else {
            *(s16 *)(((u8 *)p) + 0x98) = 0;
        }
    }
tail:
    if (*(s16 *)(((u8 *)p) + 0x76) > 0) {
        return;
    }
    if (((s32(*)(s32))func_8012BCCC)((s32)((u8 *)p)) <= 0x8FFF) {
        if (((s32(*)())func_80131AC8)(((u8 *)p), 0x32) != 0) return;
        ((s32(*)())func_80131AC8)(((u8 *)p), 0x33);
    } else {
        if (((s32(*)())func_80131AC8)(((u8 *)p), 0x33) != 0) return;
        ((s32(*)())func_80131AC8)(((u8 *)p), 0x32);
    }
}
