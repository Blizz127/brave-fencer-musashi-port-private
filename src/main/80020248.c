/* Main-exec range [80020248,80020598) from the SLUS executable.
 * SHA256(span)=6f975ac578355506c6becfd1a0c06f6dee0e375d34332c36cb803215b91d0b39.
 * Word export only: the native seam executes the retail instruction
 * stream itself; this is not a C match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80020248 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* GTE command mnemonics (mvmva, rtpt, ...) come from include/gte_macros.inc. */
__asm__(".include \"gte_macros.inc\"\n");

/* func_80020248 — build the per-object rotation/translation matrices for a
 * NULL-terminated list of objects.  If the list is short (< 8 entries) the two
 * output matrix arrays live in the scratchpad (0x1F800000 / 0x1F8000E0) and the
 * function returns 1; otherwise they go to the main-RAM buffers D_80074818 /
 * D_80075018 and it returns 0.
 *
 * All the GTE work is the usual libgte inline-asm block set (SetRotMatrix /
 * MulMatrix0 column loop / SetTransMatrix / RotTrans). */

typedef struct {
    /* 0x00 */ s16 m[3][3];
    /* 0x14 */ s32 t[3];
} MTX_80020248; /* 0x20 */

typedef struct {
    /* 0x0 */ u32 xy;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 rot[3];
} OBJ_80020248; /* 0xC */

extern MTX_80020248 D_80074818[];
extern MTX_80020248 D_80075018[];

extern void func_80020DA4(s32 a0, s32 a1);

#define SRM_80020248(r0) __asm__ volatile (              \
    "lw $12, 0( %0 );"                                   \
    "lw $13, 4( %0 );"                                   \
    "ctc2 $12, $0;"                                      \
    "ctc2 $13, $1;"                                      \
    "lw $12, 8( %0 );"                                   \
    "lw $13, 12( %0 );"                                  \
    "lw $14, 16( %0 );"                                  \
    "ctc2 $12, $2;"                                      \
    "ctc2 $13, $3;"                                      \
    "ctc2 $14, $4"                                       \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )

#define STM_80020248(r0) __asm__ volatile (              \
    "lw $12, 20( %0 );"                                  \
    "lw $13, 24( %0 );"                                  \
    "ctc2 $12, $5;"                                      \
    "lw $14, 28( %0 );"                                  \
    "ctc2 $13, $6;"                                      \
    "ctc2 $14, $7"                                       \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )

#define LDCLMV_80020248(r0) __asm__ volatile (           \
    "lhu $12, 0( %0 );"                                  \
    "lhu $13, 6( %0 );"                                  \
    "lhu $14, 12( %0 );"                                 \
    "mtc2 $12, $9;"                                      \
    "mtc2 $13, $10;"                                     \
    "mtc2 $14, $11"                                      \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14" )

#define RTIR_80020248() __asm__ volatile (               \
    "nop;"                                               \
    "nop;"                                               \
    "mvmva 1, 0, 3, 3, 0"                                \
    : : : "memory" )

#define STCLMV_80020248(r0) __asm__ volatile (           \
    "mfc2 $12, $9;"                                      \
    "mfc2 $13, $10;"                                     \
    "mfc2 $14, $11;"                                     \
    "sh $12, 0( %0 );"                                   \
    "sh $13, 6( %0 );"                                   \
    "sh $14, 12( %0 )"                                   \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13", "$14", "memory" )

#define LDLVL_80020248(r0) __asm__ volatile (            \
    "lhu $13, 4( %0 );"                                  \
    "lhu $12, 0( %0 );"                                  \
    "sll $13, $13, 16;"                                  \
    "or $12, $12, $13;"                                  \
    "mtc2 $12, $0;"                                      \
    "lwc2 $1, 8( %0 )"                                   \
    :                                                    \
    : "r"( r0 )                                          \
    : "$12", "$13" )

#define RT_80020248() __asm__ volatile (                 \
    "nop;"                                               \
    "nop;"                                               \
    "mvmva 1, 0, 0, 0, 0"                                \
    : : : "memory" )

#define STLVNL_80020248(r0) __asm__ volatile (           \
    "swc2 $25, 0( %0 );"                                 \
    "swc2 $26, 4( %0 );"                                 \
    "swc2 $27, 8( %0 )"                                  \
    :                                                    \
    : "r"( r0 )                                          \
    : "memory" )

s32 func_80020248(s32 *a0, OBJ_80020248 *a1, MTX_80020248 *a2, MTX_80020248 *a3, s32 a4)
{
    MTX_80020248 lm;            /* sp+0x10 */
    MTX_80020248 *rm;
    MTX_80020248 *om;
    u32 w;
    s32 n;
    s32 ret;

    ret = 0;
    n = 0;
    while (*a0++ != 0) {
        n++;
    }

    if (n >= 8) {
        rm = D_80074818;
        om = D_80075018;
    } else {
        rm = (MTX_80020248 *)0x1F800000;
        om = (MTX_80020248 *)0x1F8000E0;
        ret = 1;
    }

    while (--n != -1) {
        func_80020DA4((s32)a1->rot, (s32)&lm);

        w = a1->xy;
        lm.t[0] = w & 0xFFFF;
        lm.t[1] = w >> 16;
        lm.t[2] = a1->z;

        if (a4 == 0) {
            SRM_80020248(a2);
            LDCLMV_80020248(&lm.m[0][0]);
            RTIR_80020248();
            STCLMV_80020248(&rm->m[0][0]);
            LDCLMV_80020248(&lm.m[0][1]);
            RTIR_80020248();
            STCLMV_80020248(&rm->m[0][1]);
            LDCLMV_80020248(&lm.m[0][2]);
            RTIR_80020248();
            STCLMV_80020248(&rm->m[0][2]);
            rm++;
        }

        SRM_80020248(a3);
        LDCLMV_80020248(&lm.m[0][0]);
        RTIR_80020248();
        STCLMV_80020248(&om->m[0][0]);
        LDCLMV_80020248(&lm.m[0][1]);
        RTIR_80020248();
        STCLMV_80020248(&om->m[0][1]);
        LDCLMV_80020248(&lm.m[0][2]);
        RTIR_80020248();
        STCLMV_80020248(&om->m[0][2]);

        STM_80020248(a3);
        LDLVL_80020248(&lm.t[0]);
        RT_80020248();
        STLVNL_80020248(&om->t[0]);

        om++;
        a1++;
    }

    return ret;
}
