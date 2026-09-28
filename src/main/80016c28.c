/* Main-exec range [80016C28,80016D78) from the SLUS executable.
 * SHA256(span)=727fed1e591b96d9f10ba28d018778862873fc59fdbdebaae7e62ab3587c433f.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80016C28 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif
/* GTE instruction macros (vendor/bfm-decomp/include/gte_macros.inc) for GNU as. */
__asm__(
    ".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
    "    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
    ".endm\n"
    ".macro rtps\n"
    "    cop2op 0x01, 0x01\n"
    ".endm\n"
    ".macro rtpt\n"
    "    cop2op 0x02, 0x30\n"
    ".endm\n"
    ".macro avsz4\n"
    "    cop2op 0x16, 0x2E\n"
    ".endm\n"
    ".macro op sf\n"
    "    cop2op 0x17, 0x0C, sf = \\sf\n"
    ".endm\n"
);

typedef struct {
    s16 vx, vy, vz, pad;
} SV_80016C28;
typedef struct {
    SV_80016C28 v[4]; /* 0x00 */
    u32 rgb0;          /* 0x20 */
    u32 rgb1;          /* 0x24 */
    u32 rgb2;          /* 0x28 */
    u32 rgb3;          /* 0x2C */
    u32 flags;         /* 0x30 */
} Src_80016C28;
typedef struct {
    u32 tag;    /* 0x00 */
    u32 rgb0;   /* 0x04 */
    u32 xy0;    /* 0x08 */
    u32 rgb1;   /* 0x0C */
    u32 xy1;    /* 0x10 */
    u32 rgb2;   /* 0x14 */
    u32 xy2;    /* 0x18 */
    u32 rgb3;   /* 0x1C */
    u32 xy3;    /* 0x20 */
    u32 term;   /* 0x24 */
} LineG4_80016C28;
extern void *func_80010A08(s32);
extern void func_80058F24(LineG4_80016C28 *p);
extern void func_80017E8C(s32 arg0);
extern void func_80018094(void *p, s32 otz, u32 flags);
#define gte_ldv0(r0) __asm__ volatile (          \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 )"                           \
    :                                            \
    : "r"( r0 ) )
#define gte_ldv3(r0, r1, r2) __asm__ volatile (  \
    "lwc2 $0, 0( %0 );"                          \
    "lwc2 $1, 4( %0 );"                          \
    "lwc2 $2, 0( %1 );"                          \
    "lwc2 $3, 4( %1 );"                          \
    "lwc2 $4, 0( %2 );"                          \
    "lwc2 $5, 4( %2 )"                           \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 ) )
#define gte_rtps() __asm__ volatile ("nop;nop;rtps")
#define gte_rtpt() __asm__ volatile ("nop;nop;rtpt")
#define gte_avsz4() __asm__ volatile ("nop;nop;avsz4")
#define gte_stsxy(r0) __asm__ volatile (         \
    "swc2 $14, 0( %0 )"                          \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stsxy3(r0, r1, r2) __asm__ volatile ( \
    "swc2 $12, 0( %0 );"                         \
    "swc2 $13, 0( %1 );"                         \
    "swc2 $14, 0( %2 )"                          \
    :                                            \
    : "r"( r0 ), "r"( r1 ), "r"( r2 )            \
    : "memory" )
#define gte_stotz(r0) __asm__ volatile (         \
    "swc2 $7, 0( %0 )"                           \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
#define gte_stflg(r0) __asm__ volatile (         \
    "cfc2 $12, $31;"                             \
    "nop;"                                       \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )

void func_80016C28(Src_80016C28 *arg0, s32 arg1)
{
    LineG4_80016C28 *p;
    s32 flag;
    s32 flag2;
    s32 otz;

    p = (LineG4_80016C28 *)func_80010A08(0x28);
    func_80058F24(p);
    p->rgb0 = arg0->rgb0;
    p->rgb1 = arg0->rgb1;
    p->rgb2 = arg0->rgb2;
    p->rgb3 = arg0->rgb3;
    func_80017E8C(arg1);

    gte_ldv3(&arg0->v[0], &arg0->v[1], &arg0->v[2]);
    gte_rtpt();
    gte_stflg(&flag);
    gte_stsxy3(&p->xy0, &p->xy1, &p->xy2);
    gte_ldv0(&arg0->v[3]);
    gte_rtps();
    gte_stflg(&flag2);
    flag |= flag2;
    gte_stsxy(&p->xy3);
    gte_avsz4();
    gte_stotz(&otz);

    if ((flag & ~0x1000) == 0) {
        func_80018094(p, otz, arg0->flags);
    }
}
