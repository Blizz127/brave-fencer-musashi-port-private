/* Main-exec range [8001E378,8001E668) from the SLUS executable. */
/* func_8001E378 - clean-room C from the retail disassembly; byte-exact against
 * retail at -O2 (gcc-2.7.2-psx). Builds an object's world matrix:
 * RotMatrix(angles) * diag(scale), translation = position, then pre-multiplied
 * by the camera matrix at D_800AF648 and set as the GTE rotation/translation. */
#include "psx_types.h"

/* GTE command mnemonics (mvmva, ...) come from include/gte_macros.inc. */
__asm__(".include \"gte_macros.inc\"\n");

/* PsyQ inline_c.h GTE macros (the strict lane maps the names to host helpers). */
#define gte_SetRotMatrix(r0) __asm__ volatile (                   \
    "lw $12, 0( %0 );" "lw $13, 4( %0 );"                         \
    "ctc2 $12, $0;" "ctc2 $13, $1;"                               \
    "lw $12, 8( %0 );" "lw $13, 12( %0 );" "lw $14, 16( %0 );"    \
    "ctc2 $12, $2;" "ctc2 $13, $3;" "ctc2 $14, $4"                \
    : : "r"( r0 ) : "$12", "$13", "$14" )
#define gte_SetTransMatrix(r0) __asm__ volatile (                 \
    "lw $12, 20( %0 );" "lw $13, 24( %0 );"                       \
    "ctc2 $12, $5;" "lw $14, 28( %0 );"                           \
    "ctc2 $13, $6;" "ctc2 $14, $7"                                \
    : : "r"( r0 ) : "$12", "$13", "$14" )
#define gte_ldclmv(r0) __asm__ volatile (                         \
    "lhu $12, 0( %0 );" "lhu $13, 6( %0 );" "lhu $14, 12( %0 );"  \
    "mtc2 $12, $9;" "mtc2 $13, $10;" "mtc2 $14, $11"              \
    : : "r"( r0 ) : "$12", "$13", "$14" )
#define gte_rtir() __asm__ volatile ("nop;nop;mvmva 1, 0, 3, 3, 0")
#define gte_stclmv(r0) __asm__ volatile (                         \
    "mfc2 $12, $9;" "mfc2 $13, $10;" "mfc2 $14, $11;"             \
    "sh $12, 0( %0 );" "sh $13, 6( %0 );" "sh $14, 12( %0 )"      \
    : : "r"( r0 ) : "$12", "$13", "$14", "memory" )
#define gte_ldlv0(r0) __asm__ volatile (                          \
    "lhu $13, 4( %0 );" "lhu $12, 0( %0 );"                       \
    "sll $13, $13, 16;" "or $12, $12, $13;"                       \
    "mtc2 $12, $0;" "lwc2 $1, 8( %0 )"                            \
    : : "r"( r0 ) : "$12", "$13" )
#define gte_rt() __asm__ volatile ("nop;nop;mvmva 1, 0, 0, 0, 0")
#define gte_stlvnl(r0) __asm__ volatile (                         \
    "swc2 $25, 0( %0 );" "swc2 $26, 4( %0 );" "swc2 $27, 8( %0 )" \
    : : "r"( r0 ) : "memory" )

typedef struct { s16 m[3][3]; s32 t[3]; } MATRIX_8001E378;

extern u8 D_800AF648[];
extern void func_8004978C(s16 *a0, void *a1);

void func_8001E378(s32 arg0)
{
    s16 sc[16];
    MATRIX_8001E378 m;
    u8 *g;

    func_8004978C((s16 *)(arg0 + 0x10), &m);
    sc[0] = *(u16 *)(arg0 + 0x18);
    sc[1] = 0;
    sc[2] = 0;
    sc[3] = 0;
    sc[4] = *(u16 *)(arg0 + 0x1A);
    sc[5] = 0;
    sc[6] = 0;
    sc[7] = 0;
    sc[8] = *(u16 *)(arg0 + 0x1C);
    g = D_800AF648;

    gte_SetRotMatrix(&m);
    gte_ldclmv(sc);
    gte_rtir();
    gte_stclmv(&m.m[0][0]);
    gte_ldclmv(&sc[1]);
    gte_rtir();
    gte_stclmv(&m.m[0][1]);
    gte_ldclmv(&sc[2]);
    gte_rtir();
    gte_stclmv(&m.m[0][2]);

    m.t[0] = *(s16 *)(arg0 + 8);
    m.t[1] = *(s16 *)(arg0 + 0xA);
    m.t[2] = *(s16 *)(arg0 + 0xC);

    gte_SetRotMatrix(g);
    gte_ldclmv(&m.m[0][0]);
    gte_rtir();
    gte_stclmv(&m.m[0][0]);
    gte_ldclmv(&m.m[0][1]);
    gte_rtir();
    gte_stclmv(&m.m[0][1]);
    gte_ldclmv(&m.m[0][2]);
    gte_rtir();
    gte_stclmv(&m.m[0][2]);
    gte_SetTransMatrix(g);

    gte_ldlv0(m.t);
    gte_rt();
    gte_stlvnl(m.t);
    gte_SetRotMatrix(&m);
    gte_SetTransMatrix(&m);
}
