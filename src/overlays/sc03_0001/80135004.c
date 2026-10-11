/* Overlay range [80135004,80135168) from MAIN.CD member 0012.
 * SHA256(span)=7b03d2b8582c5890d4d34acb0a27ba1e8dff631d4c0d481053cafe8b3c9aa3a5.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80135004 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
extern u8 D_8018DA9C;
extern u8 D_8018DAA0;

            typedef struct { s8 c[8]; } Blk8_80135004;

// @class: plumbing
// @stuck: MATCH (89 ins). To BANK: retype aD8017E914_80135004 + aD8017E910_80135004 (u8 -> s16*) in sibling func_80135168's externs (src/ov_SC01_077/ov_SC01_077_a.c ~L1879); they hold pointers double-referenced across a call, so only a 4-byte/pointer decl folds %lo (u8 &-cast CSE's the address into a saved reg). Retype is byte-NEUTRAL for the sibling (verified: identical objdump bytes u8 vs s16*).




s32 func_80135004(s32 arg0, s32 p1, s32 p2)
{

    extern s32 D_801ED3B0;
    extern int func_80134A74(int, s16, s16, int);
    extern s16 * aD8017E914_80135004 __asm__("D_8018DAA0");
    extern s16 * aD8017E910_80135004 __asm__("D_8018DA9C");
    extern u8 D_8018DAA8;
    extern s16 *D_8018DAA4;
    extern u16 D_801ED3C0;

    register s16 *pb0 __asm__("$9");   /* aD8017E914_80135004 -> $t1 */
    register s16 *pac __asm__("$6");   /* aD8017E910_80135004 -> $a2 */
    register s16 *pb8 __asm__("$8");   /* D_8018DAA8 -> $t0 */
    u16 *pb4;
    u16 a, b;
    int id;
    int a1v, a2v, d94;

    pb0 = aD8017E914_80135004;
    __asm__ __volatile__("" : : "r"(pb0));

    a = ((u16 *)p2)[0]; pac = aD8017E910_80135004; pb0[0] = a; b = ((u16 *)p1)[0]; pb8 = (*(s16 * *)&D_8018DAA8); pac[0] = b; pb8[0] = a - b;
    a = ((u16 *)p2)[1]; pb0[1] = a; b = ((u16 *)p1)[1]; pac[1] = b; pb8[1] = a - b;
    a = ((u16 *)p2)[2]; pb0[2] = a; b = ((u16 *)p1)[2]; pac[2] = b; pb8[2] = a - b;

    id = ((int)arg0) & 0xFFFF;
    a1v = pac[0]; a2v = pac[2]; d94 = D_801ED3B0;
    __asm__ __volatile__("" ::: "memory");
    D_801ED3C0 = 0;

    if (func_80134A74(id, a1v, a2v, d94)) {
    found:
        pb4 = (*(u16 * *)&D_8018DAA4);
        ((u16 *)p2)[0] = pb4[0];
        ((u16 *)p2)[1] = pb4[1];
        ((u16 *)p2)[2] = pb4[2];
        ((u16 *)p2)[3] = D_801ED3C0;
        return 1;
    }
    {
        register u16 *qb __asm__("$4");   /* aD8017E910_80135004 -> $a0 (reloaded) */
        register int qa0 __asm__("$5");   /* aD8017E914_80135004[0], kept in $a1 for the 2nd-call arg */
        register u16 *qa __asm__("$6");   /* aD8017E914_80135004 -> $a2 (reloaded) */
        qb = (u16 *)aD8017E910_80135004;
        qa = (u16 *)aD8017E914_80135004;
        qa0 = qa[0];
        if (((qb[0] & 0xFF80) == (qa0 & 0xFF80)) &&
            ((qb[2] & 0xFF80) == (qa[2] & 0xFF80)))
            return 0;
        if (func_80134A74(id, (s16)qa0, (s16)qa[2], D_801ED3B0))
            goto found;
        return 0;
    }
}
