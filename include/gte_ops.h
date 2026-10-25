/* Single-opcode GTE macros for C sources.
 *
 * Each macro emits exactly one coprocessor-2 instruction (or the one-word
 * `nop` the GTE needs between loading an input register and starting an
 * operation). Mnemonics such as avsz3 come from gte_macros.inc, which the
 * assembler expands; no source file carries instruction words itself. No
 * register is pinned: the compiler chooses every general register.
 */
#ifndef GTE_OPS_H
#define GTE_OPS_H

__asm__(".include \"gte_macros.inc\"\n");

#define gte_lwc2(r, off, p) __asm__ volatile("lwc2 $" #r ", " #off "(%0)" : : "r"(p))
#define gte_swc2(r, off, p) __asm__ volatile("swc2 $" #r ", " #off "(%0)" : : "r"(p) : "memory")
#define gte_mtc2(v, r) __asm__ volatile("mtc2 %0, $" #r : : "r"(v))
#define gte_mfc2(v, r) __asm__ volatile("mfc2 %0, $" #r : "=r"(v))
#define gte_cfc2(v, r) __asm__ volatile("cfc2 %0, $" #r : "=r"(v))
#define gte_ctc2(v, r) __asm__ volatile("ctc2 %0, $" #r : : "r"(v))
#define gte_nop() __asm__ volatile("nop")

#define gte_rtps() __asm__ volatile("rtps")
#define gte_rtpt() __asm__ volatile("rtpt")
#define gte_nclip() __asm__ volatile("nclip")
#define gte_avsz3() __asm__ volatile("avsz3")
#define gte_avsz4() __asm__ volatile("avsz4")
#define gte_dpcl() __asm__ volatile("dpcl")
#define gte_dpct() __asm__ volatile("dpct")
#define gte_intpl() __asm__ volatile("intpl")
#define gte_sqr12() __asm__ volatile("sqr 1")
#define gte_sqr0() __asm__ volatile("sqr 0")
#define gte_mvmva(sf, mx, v, cv, lm) __asm__ volatile("mvmva " #sf ", " #mx ", " #v ", " #cv ", " #lm)
/* mvmva 1,0,3,3,0: rotation matrix times IR1-3 (no translation), shifted. */
#define gte_rtir12() __asm__ volatile("rtir12")
/* mvmva 1,0,0,0,0: rotation matrix times V0 plus the translation vector. */
#define gte_rtv0tr() __asm__ volatile("rtv0tr")

/* ======================================================================
 * Grouped retail GTE sequences (lead decision D2)
 *
 * Retail builds its matrix/vector GTE code from fixed instruction groups whose
 * scratch registers are always $12-$14 (t4-t6). Each gte_g_* macro below is ONE
 * asm statement that writes ONE such retail group as mnemonics (never .word),
 * pins those scratch registers and lists them as clobbers. Exception:
 * gte_g_ld_v3 and gte_g_st_sxy3 pin no general register (the $12-$14 inside their
 * swc2 are the GTE data registers SXY0-SXY2); they only keep three address
 * operands in one statement, as retail does. Per lead decision D2a, a group
 * may include contiguous retail loads/stores, packing shifts and load-delay
 * nops that only move GTE inputs/outputs, using retail's scratch registers.
 * Game control flow, object address arithmetic beyond the group's base, and
 * values used by C outside the group's output stay C. GTE commands and their
 * standalone nops use the single-opcode macros above. A group is added only
 * when a retail function
 * shows it, once, and reused. Each macro sits in its own delimited block so
 * parallel branches can merge. Written from the retail words.
 * ====================================================================== */

/* ---- gte_g_ld_rot ---- */
/* load rotation matrix: the five words at p+0 into rotation control registers 0-4 */
#define gte_g_ld_rot(p) __asm__ volatile( \
    "lw $12, 0(%0)\n\tlw $13, 4(%0)\n\tctc2 $12, $0\n\tctc2 $13, $1\n\t" \
    "lw $12, 8(%0)\n\tlw $13, 12(%0)\n\tlw $14, 16(%0)\n\t" \
    "ctc2 $12, $2\n\tctc2 $13, $3\n\tctc2 $14, $4" \
    : : "r"(p) : "$12", "$13", "$14")
/* ---- end gte_g_ld_rot ---- */

/* ---- gte_g_ld_trans ---- */
/* load translation vector: the three words at p+20 into translation control registers 5-7 */
#define gte_g_ld_trans(p) __asm__ volatile( \
    "lw $12, 20(%0)\n\tlw $13, 24(%0)\n\tctc2 $12, $5\n\tlw $14, 28(%0)\n\t" \
    "ctc2 $13, $6\n\tctc2 $14, $7" \
    : : "r"(p) : "$12", "$13", "$14")
/* ---- end gte_g_ld_trans ---- */

/* ---- gte_g_ld_col ---- */
/* load matrix column: halfwords at p+0, p+6, p+12 into IR1-IR3 */
#define gte_g_ld_col(p) __asm__ volatile( \
    "lhu $12, 0(%0)\n\tlhu $13, 6(%0)\n\tlhu $14, 12(%0)\n\t" \
    "mtc2 $12, $9\n\tmtc2 $13, $10\n\tmtc2 $14, $11" \
    : : "r"(p) : "$12", "$13", "$14")
/* ---- end gte_g_ld_col ---- */

/* ---- gte_g_st_col ---- */
/* store matrix column: IR1-IR3 into the halfwords at p+0, p+6, p+12 */
#define gte_g_st_col(p) __asm__ volatile( \
    "mfc2 $12, $9\n\tmfc2 $13, $10\n\tmfc2 $14, $11\n\t" \
    "sh $12, 0(%0)\n\tsh $13, 6(%0)\n\tsh $14, 12(%0)" \
    : : "r"(p) : "$12", "$13", "$14", "memory")
/* ---- end gte_g_st_col ---- */

/* ---- gte_g_ld_v3 ---- */
/* load three vertices: the (VXY, VZ) word pairs at a, b, c into V0, V1, V2 (no general register pinned) */
#define gte_g_ld_v3(a, b, c) __asm__ volatile( \
    "lwc2 $0, 0(%0)\n\tlwc2 $1, 4(%0)\n\tlwc2 $2, 0(%1)\n\tlwc2 $3, 4(%1)\n\t" \
    "lwc2 $4, 0(%2)\n\tlwc2 $5, 4(%2)" \
    : : "r"(a), "r"(b), "r"(c))
/* ---- end gte_g_ld_v3 ---- */

/* ---- gte_g_ld_lv0 ---- */
/* load long vector 0: low halfwords of the words at p+0 and p+4 packed into VXY0, the word at p+8 into VZ0 */
#define gte_g_ld_lv0(p) __asm__ volatile( \
    "lhu $13, 4(%0)\n\tlhu $12, 0(%0)\n\tsll $13, $13, 16\n\tor $12, $12, $13\n\t" \
    "mtc2 $12, $0\n\tlwc2 $1, 8(%0)" \
    : : "r"(p) : "$12", "$13")
/* ---- end gte_g_ld_lv0 ---- */

/* ---- gte_g_ld_bv0 ---- */
/* load byte vector 0: (u16)(s8)p[0] | (s8)p[1] << 16 into VXY0, (s8)p[2] into VZ0 */
#define gte_g_ld_bv0(p) __asm__ volatile( \
    "lb $13, 1(%0)\n\tlb $12, 0(%0)\n\tsll $13, $13, 16\n\tsll $12, $12, 16\n\tsrl $12, $12, 16\n\t" \
    "or $12, $12, $13\n\tlb $13, 2(%0)\n\tmtc2 $12, $0\n\tmtc2 $13, $1" \
    : : "r"(p) : "$12", "$13")
/* ---- end gte_g_ld_bv0 ---- */

/* ---- gte_g_st_sxy3 ---- */
/* store screen XY FIFO: SXY0, SXY1, SXY2 to the words at a, b, c (no general register pinned) */
#define gte_g_st_sxy3(a, b, c) __asm__ volatile( \
    "swc2 $12, 0(%0)\n\tswc2 $13, 0(%1)\n\tswc2 $14, 0(%2)" \
    : : "r"(a), "r"(b), "r"(c) : "memory")
/* ---- end gte_g_st_sxy3 ---- */

/* ---- gte_g_st_flag ---- */
/* store GTE FLAG: cfc2 $31 into $12, one load-delay nop, word store at p */
#define gte_g_st_flag(p) __asm__ volatile( \
    "cfc2 $12, $31\n\tnop\n\tsw $12, 0(%0)" \
    : : "r"(p) : "$12", "memory")
/* ---- end gte_g_st_flag ---- */

/* ---- gte_g_st_sz3_sra2 ---- */
/* store SZ3 >> 2: mfc2 $19 into $12, one load-delay nop, arithmetic shift right 2, word store at p */
#define gte_g_st_sz3_sra2(p) __asm__ volatile( \
    "mfc2 $12, $19\n\tnop\n\tsra $12, $12, 2\n\tsw $12, 0(%0)" \
    : : "r"(p) : "$12", "memory")
/* ---- end gte_g_st_sz3_sra2 ---- */

#endif
