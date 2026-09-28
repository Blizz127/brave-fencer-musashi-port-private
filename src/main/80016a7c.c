/* Main-exec range [80016A7C,80016B60) from the SLUS executable.
 * SHA256(span)=fb5252e0389d12c04386428083cf2aaa07d52c93a570dc9017b8820dfc67d88e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80016A7C - byte-exact against retail at -O2 (tools/register_match.py). */
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
} SV_80016A7C;
typedef struct {
    SV_80016A7C v[2];  /* 0x00 */
    u32 rgb0;          /* 0x10 */
    u32 rgb1;          /* 0x14 */
    u32 attr;          /* 0x18 */
} Src_80016A7C;
typedef struct {
    u32 tag;   /* 0x00 */
    u32 rgb0;  /* 0x04 */
    u32 xy0;   /* 0x08 */
    u32 rgb1;  /* 0x0C */
    u32 xy1;   /* 0x10 */
} LineG2_80016A7C;
extern void *func_80010A08(s32 size);
extern void func_80058EB0(void *p);
extern void func_80017E8C(s32 arg0);
extern s32 func_8004958C(void *v0, void *v1, void *v2,
                          s32 *sxy0, s32 *sxy1, s32 *sxy2,
                          s32 *p, s32 *flag);
extern void func_80018094(void *p, s32 otz, u32 flags);

void func_80016A7C(Src_80016A7C *arg0, s32 arg1)
{
    LineG2_80016A7C *p;
    s32 opz;
    s32 flag;
    s32 otz;

    p = (LineG2_80016A7C *)func_80010A08(0x14);
    p->rgb0 = arg0->rgb0;
    p->rgb1 = arg0->rgb1;
    func_80058EB0(p);

    if (arg1 != 0) {
        func_80017E8C(arg1);
        otz = func_8004958C(&arg0->v[0], &arg0->v[1], &arg0->v[1],
                             (s32 *)&p->xy0, (s32 *)&p->xy1, (s32 *)&p->xy1,
                             &opz, &flag);
    } else {
        p->xy0 = arg0->v[0].xy;
        p->xy1 = arg0->v[1].xy;
        __asm__ volatile("");
        otz = arg0->v[0].z;
        flag = 0;
    }

    if ((flag & ~0x1000) == 0) {
        func_80018094(p, otz, arg0->attr);
    }
}
