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

extern s32 D_80195308;

s32 func_80135004(s32 arg0, s32 p1, s32 p2)
{
    extern int func_80134A74(int, s16, s16, int);
    extern s16 * D_8017D894;
    extern s16 * D_8017D890;
    extern u8 D_8017D89C;
    extern s16 *D_8017D898;
    extern u16 D_80195318;

    register s16 *pb0 __asm__("$9");   /* D_8017D894 -> $t1 */
    register s16 *pac __asm__("$6");   /* D_8017D890 -> $a2 */
    register s16 *pb8 __asm__("$8");   /* D_8017D89C -> $t0 */
    u16 *pb4;
    u16 a, b;
    int id;
    int a1v, a2v, d94;

    pb0 = D_8017D894;
    __asm__ __volatile__("" : : "r"(pb0));

    a = ((u16 *)p2)[0]; pac = D_8017D890; pb0[0] = a; b = ((u16 *)p1)[0]; pb8 = (*(s16 * *)&D_8017D89C); pac[0] = b; pb8[0] = a - b;
    a = ((u16 *)p2)[1]; pb0[1] = a; b = ((u16 *)p1)[1]; pac[1] = b; pb8[1] = a - b;
    a = ((u16 *)p2)[2]; pb0[2] = a; b = ((u16 *)p1)[2]; pac[2] = b; pb8[2] = a - b;

    id = ((int)arg0) & 0xFFFF;
    a1v = pac[0]; a2v = pac[2]; d94 = D_80195308;
    __asm__ __volatile__("" ::: "memory");
    D_80195318 = 0;

    if (func_80134A74(id, a1v, a2v, d94)) {
    found:
        pb4 = (*(u16 * *)&D_8017D898);
        ((u16 *)p2)[0] = pb4[0];
        ((u16 *)p2)[1] = pb4[1];
        ((u16 *)p2)[2] = pb4[2];
        ((u16 *)p2)[3] = D_80195318;
        return 1;
    }
    {
        register u16 *qb __asm__("$4");   /* D_8017D890 -> $a0 (reloaded) */
        register int qa0 __asm__("$5");   /* D_8017D894[0], kept in $a1 for the 2nd-call arg */
        register u16 *qa __asm__("$6");   /* D_8017D894 -> $a2 (reloaded) */
        qb = (u16 *)D_8017D890;
        qa = (u16 *)D_8017D894;
        qa0 = qa[0];
        if (((qb[0] & 0xFF80) == (qa0 & 0xFF80)) &&
            ((qb[2] & 0xFF80) == (qa[2] & 0xFF80)))
            return 0;
        if (func_80134A74(id, (s16)qa0, (s16)qa[2], D_80195308))
            goto found;
        return 0;
    }
}
