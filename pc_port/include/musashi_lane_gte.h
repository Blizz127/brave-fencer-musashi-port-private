/* Native-lane (host) forms of include/gte_ops.h (N-GTE).
 *
 * tools/native_lane_gen.py injects this header (clang -include) into every
 * lane compile; the PSX matching build never sees it, and include/gte_ops.h is
 * not edited. It defines GTE_OPS_H first, so a source's #include "gte_ops.h"
 * expands to nothing: none of its inline asm (nor its top-level .include of
 * gte_macros.inc) reaches the host compile. Every gte_* and gte_g_* macro here
 * performs the same register moves, commands and memory accesses as the PSX
 * macro, as calls to the lane GTE helpers (pc_port/mips_formatter.c), which
 * run the interpreter's gte_owner code paths:
 *   - LWC2 is the C word load plus lane_gte_lwc2, SWC2 is lane_gte_swc2 plus
 *     the C word store, as the interpreter does (cpu_read32 + write_data,
 *     read_data + cpu_write32); they have their own helper names only so the
 *     generator can tell them from MTC2/MFC2;
 *   - commands pass the cop2 word that include/gte_macros.inc assembles;
 *   - gte_nop() is nothing: the helpers complete synchronously;
 *   - each macro argument is evaluated once, as the asm operand was.
 * The generator audits every helper call (kind, register or command word)
 * against the function's retail COP2 words before it admits the function. */
#ifndef MUSASHI_LANE_GTE_H
#define MUSASHI_LANE_GTE_H
#define GTE_OPS_H

void lane_gte_mtc2(unsigned int value, int reg);
void lane_gte_lwc2(unsigned int value, int reg);
unsigned int lane_gte_mfc2(int reg);
unsigned int lane_gte_swc2(int reg);
void lane_gte_ctc2(unsigned int value, int reg);
unsigned int lane_gte_cfc2(int reg);
void lane_gte_cmd(unsigned int word);

/* gte_macros.inc cop2op (gbg 0): fake_op << 20 | sf << 19 | mx << 17 |
 * v << 15 | cv << 13 | lm << 10 | op, in the COP2 command encoding. */
#define LANE_GTE_OP(fake, op, sf, mx, v, cv, lm) \
    (0x4A000000u | ((unsigned int)(fake) << 20) | ((unsigned int)(sf) << 19) | \
     ((unsigned int)(mx) << 17) | ((unsigned int)(v) << 15) | \
     ((unsigned int)(cv) << 13) | ((unsigned int)(lm) << 10) | (unsigned int)(op))

/* Word and halfword access at byte offset off from b (an unsigned char *). */
#define LANE_GTE_LW(b, off) (*(const unsigned int *)((b) + (off)))
#define LANE_GTE_SW(b, off) (*(unsigned int *)((b) + (off)))
#define LANE_GTE_LHU(b, off) (*(const unsigned short *)((b) + (off)))
#define LANE_GTE_SH(b, off) (*(unsigned short *)((b) + (off)))

#define gte_lwc2(r, off, p) lane_gte_lwc2(LANE_GTE_LW((const unsigned char *)(p), off), r)
#define gte_swc2(r, off, p) (LANE_GTE_SW((unsigned char *)(p), off) = lane_gte_swc2(r))
#define gte_mtc2(v, r) lane_gte_mtc2((unsigned int)(v), r)
#define gte_mfc2(v, r) ((v) = lane_gte_mfc2(r))
#define gte_cfc2(v, r) ((v) = lane_gte_cfc2(r))
#define gte_ctc2(v, r) lane_gte_ctc2((unsigned int)(v), r)
#define gte_nop() ((void)0)

#define gte_rtps() lane_gte_cmd(LANE_GTE_OP(0x01, 0x01, 1, 0, 0, 0, 0))
#define gte_rtpt() lane_gte_cmd(LANE_GTE_OP(0x02, 0x30, 1, 0, 0, 0, 0))
#define gte_nclip() lane_gte_cmd(LANE_GTE_OP(0x14, 0x06, 0, 0, 0, 0, 0))
#define gte_avsz3() lane_gte_cmd(LANE_GTE_OP(0x15, 0x2D, 1, 0, 0, 0, 0))
#define gte_avsz4() lane_gte_cmd(LANE_GTE_OP(0x16, 0x2E, 1, 0, 0, 0, 0))
#define gte_dpcl() lane_gte_cmd(LANE_GTE_OP(0x06, 0x29, 1, 0, 0, 0, 0))
#define gte_dpct() lane_gte_cmd(LANE_GTE_OP(0x0F, 0x2A, 1, 0, 0, 0, 0))
#define gte_intpl() lane_gte_cmd(LANE_GTE_OP(0x09, 0x11, 1, 0, 0, 0, 0))
#define gte_sqr12() lane_gte_cmd(LANE_GTE_OP(0x0A, 0x28, 1, 0, 0, 0, 1))
#define gte_sqr0() lane_gte_cmd(LANE_GTE_OP(0x0A, 0x28, 0, 0, 0, 0, 1))
#define gte_mvmva(sf, mx, v, cv, lm) lane_gte_cmd(LANE_GTE_OP(0x04, 0x12, sf, mx, v, cv, lm))
/* mvmva 1,0,3,3,0 and mvmva 1,0,0,0,0 (gte_macros.inc rtir12, rtv0tr). */
#define gte_rtir12() gte_mvmva(1, 0, 3, 3, 0)
#define gte_rtv0tr() gte_mvmva(1, 0, 0, 0, 0)

/* Grouped retail sequences (lead decision D2): the same loads, register moves
 * and stores as the gte_ops.h group, in the group's order. */

/* load rotation matrix: the five words at p+0 into rotation control registers 0-4 */
#define gte_g_ld_rot(p) do { \
    const unsigned char *lane_gte_p = (const unsigned char *)(p); \
    lane_gte_ctc2(LANE_GTE_LW(lane_gte_p, 0), 0); \
    lane_gte_ctc2(LANE_GTE_LW(lane_gte_p, 4), 1); \
    lane_gte_ctc2(LANE_GTE_LW(lane_gte_p, 8), 2); \
    lane_gte_ctc2(LANE_GTE_LW(lane_gte_p, 12), 3); \
    lane_gte_ctc2(LANE_GTE_LW(lane_gte_p, 16), 4); \
} while (0)

/* load translation vector: the three words at p+20 into translation control registers 5-7 */
#define gte_g_ld_trans(p) do { \
    const unsigned char *lane_gte_p = (const unsigned char *)(p); \
    lane_gte_ctc2(LANE_GTE_LW(lane_gte_p, 20), 5); \
    lane_gte_ctc2(LANE_GTE_LW(lane_gte_p, 24), 6); \
    lane_gte_ctc2(LANE_GTE_LW(lane_gte_p, 28), 7); \
} while (0)

/* load matrix column: halfwords at p+0, p+6, p+12 (zero-extended, lhu) into IR1-IR3 */
#define gte_g_ld_col(p) do { \
    const unsigned char *lane_gte_p = (const unsigned char *)(p); \
    lane_gte_mtc2(LANE_GTE_LHU(lane_gte_p, 0), 9); \
    lane_gte_mtc2(LANE_GTE_LHU(lane_gte_p, 6), 10); \
    lane_gte_mtc2(LANE_GTE_LHU(lane_gte_p, 12), 11); \
} while (0)

/* store matrix column: IR1-IR3 into the halfwords at p+0, p+6, p+12 */
#define gte_g_st_col(p) do { \
    unsigned char *lane_gte_p = (unsigned char *)(p); \
    unsigned int lane_gte_1 = lane_gte_mfc2(9); \
    unsigned int lane_gte_2 = lane_gte_mfc2(10); \
    unsigned int lane_gte_3 = lane_gte_mfc2(11); \
    LANE_GTE_SH(lane_gte_p, 0) = (unsigned short)lane_gte_1; \
    LANE_GTE_SH(lane_gte_p, 6) = (unsigned short)lane_gte_2; \
    LANE_GTE_SH(lane_gte_p, 12) = (unsigned short)lane_gte_3; \
} while (0)

/* load three vertices: the (VXY, VZ) word pairs at a, b, c into V0, V1, V2 */
#define gte_g_ld_v3(a, b, c) do { \
    const unsigned char *lane_gte_a = (const unsigned char *)(a); \
    const unsigned char *lane_gte_b = (const unsigned char *)(b); \
    const unsigned char *lane_gte_c = (const unsigned char *)(c); \
    lane_gte_lwc2(LANE_GTE_LW(lane_gte_a, 0), 0); \
    lane_gte_lwc2(LANE_GTE_LW(lane_gte_a, 4), 1); \
    lane_gte_lwc2(LANE_GTE_LW(lane_gte_b, 0), 2); \
    lane_gte_lwc2(LANE_GTE_LW(lane_gte_b, 4), 3); \
    lane_gte_lwc2(LANE_GTE_LW(lane_gte_c, 0), 4); \
    lane_gte_lwc2(LANE_GTE_LW(lane_gte_c, 4), 5); \
} while (0)

/* load long vector 0: low halfwords of the words at p+0 and p+4 packed into VXY0, the word at p+8 into VZ0 */
#define gte_g_ld_lv0(p) do { \
    const unsigned char *lane_gte_p = (const unsigned char *)(p); \
    lane_gte_mtc2((unsigned int)LANE_GTE_LHU(lane_gte_p, 0) | \
                  ((unsigned int)LANE_GTE_LHU(lane_gte_p, 4) << 16), 0); \
    lane_gte_lwc2(LANE_GTE_LW(lane_gte_p, 8), 1); \
} while (0)

/* store screen XY FIFO: SXY0, SXY1, SXY2 to the words at a, b, c */
#define gte_g_st_sxy3(a, b, c) do { \
    unsigned char *lane_gte_a = (unsigned char *)(a); \
    unsigned char *lane_gte_b = (unsigned char *)(b); \
    unsigned char *lane_gte_c = (unsigned char *)(c); \
    LANE_GTE_SW(lane_gte_a, 0) = lane_gte_swc2(12); \
    LANE_GTE_SW(lane_gte_b, 0) = lane_gte_swc2(13); \
    LANE_GTE_SW(lane_gte_c, 0) = lane_gte_swc2(14); \
} while (0)

/* store GTE FLAG: cfc2 $31, word store at p */
#define gte_g_st_flag(p) do { \
    unsigned char *lane_gte_p = (unsigned char *)(p); \
    LANE_GTE_SW(lane_gte_p, 0) = lane_gte_cfc2(31); \
} while (0)

/* store SZ3 >> 2: mfc2 $19, arithmetic shift right 2, word store at p */
#define gte_g_st_sz3_sra2(p) do { \
    unsigned char *lane_gte_p = (unsigned char *)(p); \
    LANE_GTE_SW(lane_gte_p, 0) = (unsigned int)((int)lane_gte_mfc2(19) >> 2); \
} while (0)

#endif
