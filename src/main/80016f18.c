/* Main-exec range [80016F18,80017168) from the SLUS executable.
 * SHA256(span)=d0628823a42bc48e59b6c9585eb7c8ffa958c1523bf3b529676ed644b13ed0ff.
 * Word export for the native seam; the body below is kept
 * byte-identical (wrap only, no rewrite). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80016F18 - byte-exact against retail at -O2 (tools/register_match.py). */
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
#define gte_stflg(r0) __asm__ volatile (         \
    "cfc2 $12, $31;"                             \
    "nop;"                                       \
    "sw $12, 0( %0 )"                            \
    :                                            \
    : "r"( r0 )                                  \
    : "$12", "memory" )
#define gte_stotz(r0) __asm__ volatile (         \
    "swc2 $7, 0( %0 )"                           \
    :                                            \
    : "r"( r0 )                                  \
    : "memory" )
typedef struct {
    /* 0x0 */ u32 xy;
    /* 0x4 */ s16 z;
    /* 0x6 */ s16 pad;
} V16F18;
typedef union {
    u32 w;
    u16 h[2];
} UV16F18;
typedef struct {
    /* 0x00 */ V16F18   v[4];
    /* 0x20 */ UV16F18  uv[4];
    /* 0x30 */ u32      rgbc;
    /* 0x34 */ u32      attr;
    /* 0x38 */ u8       clut;
} S16F18;
typedef struct {
    /* 0x00 */ u32 tag;
    /* 0x04 */ u32 rgbc;
    /* 0x08 */ u32 xy0;
    /* 0x0C */ u8  u0;
    /* 0x0D */ u8  v0;
    /* 0x0E */ u16 clut;
    /* 0x10 */ u32 xy1;
    /* 0x14 */ u8  u1;
    /* 0x15 */ u8  v1;
    /* 0x16 */ u16 tpage;
    /* 0x18 */ u32 xy2;
    /* 0x1C */ u8  u2;
    /* 0x1D */ u8  v2;
    /* 0x1E */ u16 pad0;
    /* 0x20 */ u32 xy3;
    /* 0x24 */ u8  u3;
    /* 0x25 */ u8  v3;
    /* 0x26 */ u16 pad1;
} FT4_16F18;
extern void *func_80010A08(s32);
extern void func_80058DD4(FT4_16F18 *);
extern void func_80017E8C(s32);
extern s32 func_80058B40(s32, s32, s32, s32);
extern s32 func_80058B7C(s32, s32);
extern void func_80018194(void *, s32, u32);

void func_80016F18(S16F18 *arg0, s32 arg1, s32 arg2)
{
    s32 flag;
    s32 flag2;
    s32 otz;
    FT4_16F18 *p;
    u32 t;
    u32 c;

    p = (FT4_16F18 *)func_80010A08(0x28);
    p->rgbc = arg0->rgbc;
    func_80058DD4(p);

    if (arg1 != 0) {
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
    } else {
        p->xy0 = arg0->v[0].xy;
        p->xy1 = arg0->v[1].xy;
        p->xy2 = arg0->v[2].xy;
        p->xy3 = arg0->v[3].xy;
        flag = 0;
        otz = arg0->v[0].z;
    }

    t = arg0->uv[0].w;
    p->u0 = t;
    p->v0 = t >> 16;
    t = arg0->uv[1].w;
    p->u1 = t;
    p->v1 = t >> 16;
    t = arg0->uv[2].w;
    p->u2 = t;
    p->v2 = t >> 16;
    t = arg0->uv[3].w;
    p->u3 = t;
    p->v3 = t >> 16;

    if (arg2 != 0) {
        p->tpage = func_80058B40(2, (arg0->attr >> 28) & 3,
                            (arg0->uv[0].h[0] >> 2) & 0x3FC0, 0);
    } else {
        p->tpage = func_80058B40(0, (arg0->attr >> 28) & 3,
                            (arg0->uv[0].h[0] >> 2) & 0x3FC0,
                            arg0->uv[0].h[1] & 0xFF00);
    }

    c = arg0->clut;
    p->clut = func_80058B7C(c < 0xE0 ? 0x160 : 0x100, c | 0x100);

    if ((flag & ~0x1000) == 0) {
        func_80018194((void *)p, otz, (u32)arg0->attr);
    }
}
