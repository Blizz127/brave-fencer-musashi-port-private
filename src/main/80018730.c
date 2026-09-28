/* Exact retail word export [80018730,80018918); verified against pinned EXE and asm. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build).
   Vendor symbol names renamed to address symbols: LzssDecodeSector, lzss_curMask, lzss_curToken, lzss_outPtr, lzss_partialCode, lzss_ringIndex, lzss_state. */
#include "psx_types.h"

/* func_80018730 - byte-exact against retail at -O2 (tools/register_match.py). */

typedef float f32;
#ifndef NULL
#define NULL ((void *)0)
#endif

/* shared typedefs (vendor src/800_shared.h) */
/* was: src/800.c */
typedef struct Ent30D80 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u8 pad04[6];
    /* 0x0A */ u16 unk0A;
    /* 0x0C */ u8 pad0C[0x34];
    /* 0x40 */ void (*unk40)(s32, s32);
    /* 0x44 */ s32 unk44;
    /* 0x48 */ u8 pad48[6];
    /* 0x4E */ u8 unk4E;
    /* 0x4F */ u8 pad4F;
    /* 0x50 */ u8 unk50;
    /* 0x51 */ u8 unk51;
} Ent30D80;

/* was: src/800.c */
typedef struct { u8  v; } W8;

/* was: src/800.c */
typedef struct Rec14 {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u16 unk0E;
    /* 0x10 */ u32 unk10;
} Rec14; /* 0x14 */

/* was: src/800.c */
typedef struct Owner4EE8 {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ Rec14 **unk14;
} Owner4EE8;

/* was: src/800.c */
typedef struct Slot {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u8 unk08[0xC];
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8 unk16[2];
    /* 0x18 */ s16 unk18;
    /* 0x1A */ u8 unk1A[0x26];
    /* 0x40 */ s32 unk40;
    /* 0x44 */ u8 unk44;
    /* 0x45 */ u8 unk45[3];
} Slot;

/* was: src/800.c */
typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    s16 unk0C;
    s16 unk0E;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
    s32 unk14;
} Rsc24;                       /* 0x18 */

/* was: src/800.c */
typedef struct {
    /* 0x00 */ u8 *unk00;
    /* 0x04 */ u8  pad04[2];
    /* 0x06 */ u8  unk06;
    /* 0x07 */ u8  unk07;
    /* 0x08 */ u8  unk08;
    /* 0x09 */ u8  pad09[3];
} A12; /* 0x0C */

/* was: src/800.c */
typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ u8  unk0A;
    /* 0x0B */ u8  unk0B;
} B12; /* 0x0C */

/* was: src/800.c */
typedef struct {
    /* 0x00 */ u8  pad00[4];
    /* 0x04 */ u8  unk04;
    /* 0x05 */ u8  pad05[11];
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u8  pad14[2];
    /* 0x16 */ s16 unk16;
    /* 0x18 */ u8  pad18[8];
} C24; /* 0x20 */

/* was: src/800.c */
typedef struct {               /* 0x18 stride; D_800A463C + k*0x18 */
    s32 unk00;
    u8  unk04[0x14];
} Ent24;

/* was: src/800.c */
typedef struct {              /* base 0x80064D49, stride 0x0C */
    u8  unk00;
    u8  pad[11];
} Elm12;

/* was: src/800.c */
typedef struct {              /* base 0x80076240, stride 0x10 */
    u16 unk00;
    u16 unk02;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
} Slot16A;

/* was: src/800.c */
typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    u8  unk0C;
    u8  unk0D;
    u8  unk0E;
    u8  unk0F;
} Slot16;                      /* 0x10 */

/* was: src/800.c */
typedef struct { s32 v; } W32;

/* was: src/800.c */
typedef struct Slot54 {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ u16 unk08;
    /* 0x0A */ s8  unk0A;
} Slot54;

/* was: src/800.c */
typedef struct { u16 f0; } H2; /* 0x2 */

/* was: src/800.c */
typedef struct {
    s32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08;
    u8  unk09;
    u8  unk0A;
    u8  unk0B;
    s32 unk0C;
} Rsc16;                      /* 0x10 */

/* was: src/800_c.c */
typedef struct { s16 v; } W16;

/* was: src/800_c.c */
typedef struct {
    u8  unk00;
    u8  unk01[11];
} Rsc12;                      /* 0x0C */


/* LZSS streaming sector decompressor (resumable coroutine state machine).
 * Decodes up to 0x800 input bytes per call out of an LZSS stream into a 0x400-byte
 * scratchpad ring (lzss_ringBuffer @ 0x1F800000) and to lzss_outPtr. lzss_state is the
 * resume point (0=idle/done, 1=fresh, 2=token loop, 3=have code low byte, 4=advance bit).
 * Returns 1 if the input sector was consumed mid-stream (resume next call), 0 at the
 * stream terminator (back-ref offset 0) or when idle. */
/* MATCHED — asm-differ score 0, full-binary SHA1 green (Phase 7, session F, 2026-06-15).
 * Five constructs below are LOAD-BEARING for the byte-for-byte match against gcc 2.7.2 -O2; a
 * future reader who "cleans them up" WILL break the match. Each is annotated inline and the
 * compiler-internal root cause is in docs/matching-cookbook.md §10 (+ §5a). All five were
 * ground-truthed against the pinned gcc-2.7.2 source (reorg.c, jump.c, local-alloc.c). */
extern u8 D_800747A0;        /* 0x800747A0 */
extern u8 D_800747A4;       /* 0x800747A4 */
extern u8 *D_800747AC;        /* 0x800747AC */
extern u32 D_800747B0;     /* 0x800747B0 */
extern u16 D_800747B4;   /* 0x800747B4 */
extern u32 D_800C7D24;         /* 0x800C7D24 */

s32 func_80018730(u8 *src) {
    s32 count = 0x800;
    u32 ringIdx = D_800747B0;
    u8 mask = D_800747A0;
    u8 token = D_800747A4;
    u8 *out = D_800747AC;
    u16 code = D_800747B4;
    u8 *ring = (u8 *)0x1F800000;   /* scratchpad ring; original uses the literal (lui 0x1f80), not the symbol */
    u32 readIdx;
    s32 len;
    u8 b;
    u8 nb;   /* low-byte (state-3) source byte */
    u8 cb;
    u8 nh;   /* LOAD-BEARING #1 (residual A): a SEPARATE high-byte source var, NOT a reuse of `nb`.
              * `nb` is shared between the low- and high-byte paths; reusing it couples their
              * register allocation, so any high-byte reshaping shoves `nb` out of $v1. A distinct
              * `nh` decouples them. Cookbook §10/A. */
    s32 newState;
    s32 result; /* return-1 value carried in $v0 from each save predecessor (state-3/state-4) */

    /* LOAD-BEARING #2 (residual B3): NO `default:` case and NO statement after the switch. The
     * switch's own range check (`sltiu $v0,state,5; beqz $v0,<epilogue>`) is the ONLY state>=5
     * guard; the `beqz` REUSES the sltiu result ($v0==0 when state>=5) as the return-0 value by
     * threading straight to `jr ra`. An explicit `if(state>=5)return 0;`, a `default:`, or a
     * trailing `return 0;` each makes gcc emit a separate `move $v0,$zero` (+1 insn / wrong branch
     * target). Falling off the end here is deliberate (and matches the original). Cookbook §10/B3. */
    switch (D_800C7D24) {
    case 0:
        goto term_ret;
    case 1:
        ringIdx = 1;
        mask = 1;
        token = *src++;
        count--;
    case 2:
        for (;;) {
            if (token & mask) {
                b = *src++;
                ring[ringIdx] = b;
                ringIdx = (ringIdx + 1) & 0x3FF;
                count--;
                *out++ = b;
            } else {
                nb = *src++;
                count--;
                code = (code & 0xFF00) | nb;
                if (count != 0) {
                    goto have_low;
                }
                /* LOAD-BEARING #3 (residual B): `result` is set in the state-3 PREDECESSOR (here,
                 * before `goto save`), not inside the shared `save:` tail. This makes gcc emit a
                 * distinct `li $v0,1` per return site instead of cross-jumping/sinking one copy into
                 * the tail's branch delay slot (reorg.c fill_simple_delay_slots). Cookbook §10/B. */
                result = 1;
                newState = 3;
                goto save;
    have_low:
    case 3:
                nh = *src++;
                count--;
                /* LOAD-BEARING #1 (residual A), cont.: operand order `(code & 0xFF) | (nh << 8)`,
                 * NOT `(nh<<8)|(code&0xFF)`. gcc local-alloc.c combine_regs ties a commutative OR's
                 * result to the FIRST RTL operand that dies; writing `code & 0xFF` first ties the
                 * result to $v0 (the target reg) → `or $v0,$v0,$v1`. Cookbook §10/A. */
                code = (code & 0xFF) | (nh << 8);
                readIdx = code & 0x3FF;
                if (readIdx == 0) {
                    D_800C7D24 = 0;
                term_ret:
                    return 0;
                }
                len = (code >> 10) + 2;
                while (len != 0) {
                    cb = ring[readIdx];
                    readIdx = (readIdx + 1) & 0x3FF;
                    ring[ringIdx] = cb;
                    ringIdx = (ringIdx + 1) & 0x3FF;
                    *out++ = cb;
                    len--;
                }
            }
            if (count != 0) {
                goto next_bit;
            }
            result = 1;     /* state-4 save predecessor — see LOAD-BEARING #3 */
            newState = 4;
        save:
            D_800C7D24 = newState;
            D_800747B0 = ringIdx;
            D_800747A0 = mask;
            D_800747A4 = token;
            D_800747AC = out;
            D_800747B4 = code;
            return result;
    next_bit:
    case 4:
            if (mask == 0x80) {
                mask = 1;
                token = *src++;
                count--;
                if (count == 0) {
                    /* state-2 reload save. The original keeps this as a SEPARATE copy of the 6
                     * stores (not shared with `save:`). Two more load-bearing constructs: */
                    register s32 r __asm__("$2");
                    /* LOAD-BEARING #4 (residual B, state-2): an explicit $v0 local pinned early by a
                     * read-only input-asm. This forces `li $v0,1` to materialise BEFORE the stores
                     * (the target schedules the return value first; gcc otherwise, since `li $v0,1`'s
                     * only use is the shared epilogue, defers it to just before `jr ra`). Cookbook §10/B. */
                    r = 1;
                    __asm__ __volatile__("" : : "r"(r));
                    newState = 2;
                    D_800C7D24 = newState;
                    D_800747B0 = ringIdx;
                    D_800747A0 = mask;
                    D_800747A4 = token;
                    D_800747AC = out;
                    D_800747B4 = code;
                    /* LOAD-BEARING #5 (the cross-jump barrier): a zero-byte volatile asm. gcc 2.7.2
                     * -O2 jump.c find_cross_jump would otherwise MERGE this save with the identical
                     * `save:` tail (→111 insns); an ASM_INPUT node makes it bail (lose=1) so both
                     * survive (→122, the correct count). No -fno-crossjumping before gcc 3.3. Cookbook §5a. */
                    __asm__ __volatile__("" ::: "memory");
                    return r;
                }
            } else {
                mask <<= 1;
            }
        }
    }
}
