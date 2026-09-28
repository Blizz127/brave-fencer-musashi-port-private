/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80135004 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801997C0;

s32 func_80135004(s32 arg0, s32 p1, s32 p2)
{
    extern int func_80134A74(int, s16, s16, int);
    extern s16 * D_8017F160;
    extern s16 * D_8017F15C;
    extern u8 D_8017F168;
    extern s16 *D_8017F164;
    extern u16 D_801997D0;

    register s16 *pb0 __asm__("$9");   /* D_8017F160 -> $t1 */
    register s16 *pac __asm__("$6");   /* D_8017F15C -> $a2 */
    register s16 *pb8 __asm__("$8");   /* D_8017F168 -> $t0 */
    u16 *pb4;
    u16 a, b;
    int id;
    int a1v, a2v, d94;

    pb0 = D_8017F160;
    __asm__ __volatile__("" : : "r"(pb0));

    a = ((u16 *)p2)[0]; pac = D_8017F15C; pb0[0] = a; b = ((u16 *)p1)[0]; pb8 = (*(s16 * *)&D_8017F168); pac[0] = b; pb8[0] = a - b;
    a = ((u16 *)p2)[1]; pb0[1] = a; b = ((u16 *)p1)[1]; pac[1] = b; pb8[1] = a - b;
    a = ((u16 *)p2)[2]; pb0[2] = a; b = ((u16 *)p1)[2]; pac[2] = b; pb8[2] = a - b;

    id = ((int)arg0) & 0xFFFF;
    a1v = pac[0]; a2v = pac[2]; d94 = D_801997C0;
    __asm__ __volatile__("" ::: "memory");
    D_801997D0 = 0;

    if (func_80134A74(id, a1v, a2v, d94)) {
    found:
        pb4 = (*(u16 * *)&D_8017F164);
        ((u16 *)p2)[0] = pb4[0];
        ((u16 *)p2)[1] = pb4[1];
        ((u16 *)p2)[2] = pb4[2];
        ((u16 *)p2)[3] = D_801997D0;
        return 1;
    }
    {
        register u16 *qb __asm__("$4");   /* D_8017F15C -> $a0 (reloaded) */
        register int qa0 __asm__("$5");   /* D_8017F160[0], kept in $a1 for the 2nd-call arg */
        register u16 *qa __asm__("$6");   /* D_8017F160 -> $a2 (reloaded) */
        qb = (u16 *)D_8017F15C;
        qa = (u16 *)D_8017F160;
        qa0 = qa[0];
        if (((qb[0] & 0xFF80) == (qa0 & 0xFF80)) &&
            ((qb[2] & 0xFF80) == (qa[2] & 0xFF80)))
            return 0;
        if (func_80134A74(id, (s16)qa0, (s16)qa[2], D_801997C0))
            goto found;
        return 0;
    }
}
