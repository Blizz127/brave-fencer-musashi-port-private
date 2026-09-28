/* Main-exec range [80017168,80017254) from the SLUS executable.
 * SHA256(span)=025a4f7595ab79e7ecbcd80c5dc488d786ab778cb29aa6410ef8774a625a6902.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80017168 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u32 xy;   /* 0x0: vx (lo16) | vy (hi16) */
    s16 z;    /* 0x4 */
    s16 pad;  /* 0x6 */
} SVec_80017168;
typedef struct {
    SVec_80017168 v[3];  /* 0x00 */
    u32 rgbc;            /* 0x18 */
    u32 attr;            /* 0x1C */
} Src_80017168;
typedef struct {
    u32 tag;    /* 0x00 */
    u32 rgbc0;  /* 0x04 */
    u32 xy0;    /* 0x08 */
    u32 xy1;    /* 0x0C */
    u32 xy2;    /* 0x10 */
} F3_80017168;
extern void *func_80010A08(s32 size);
extern void func_80058D70(F3_80017168 *p);
extern void func_80017E8C(s32 arg0);
extern s32 func_8004958C(void *v0, void *v1, void *v2,
                          s32 *sxy0, s32 *sxy1, s32 *sxy2,
                          s32 *p, s32 *flag);
extern void func_80018094(void *p, s32 otz, u32 flags);

void func_80017168(Src_80017168 *arg0, s32 arg1)
{
    F3_80017168 *p;
    s32 flag;
    s32 otzp;
    s32 otz;

    p = (F3_80017168 *)func_80010A08(0x14);
    p->rgbc0 = arg0->rgbc;
    func_80058D70(p);

    if (arg1 != 0) {
        func_80017E8C(arg1);
        otz = func_8004958C(&arg0->v[0], &arg0->v[1], &arg0->v[2],
                             (s32 *)&p->xy0, (s32 *)&p->xy1, (s32 *)&p->xy2,
                             &otzp, &flag);
    } else {
        p->xy0 = arg0->v[0].xy;
        p->xy1 = arg0->v[1].xy;
        p->xy2 = arg0->v[2].xy;
        __asm__ volatile("");
        otz = arg0->v[0].z;
        flag = 0;
    }

    if ((flag & ~0x1000) == 0) {
        func_80018094(p, otz, arg0->attr);
    }
}
