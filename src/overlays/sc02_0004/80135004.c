/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80135004 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80194F88;
int func_80134A74(int param_1, s16 param_2, s16 param_3, int param_4);

s32 func_80135004(s32 arg0, s32 p1, s32 p2)
{
    extern int func_80134A74(int, s16, s16, int);
    extern s16 * D_8017E270;
    extern s16 * D_8017E26C;
    extern u8 D_8017E278;
    extern s16 *D_8017E274;
    extern u16 D_80194F98;

    register s16 *pb0 __asm__("$9");    
    register s16 *pac __asm__("$6");    
    register s16 *pb8 __asm__("$8");    
    u16 *pb4;
    u16 a, b;
    int id;
    int a1v, a2v, d94;

    pb0 = D_8017E270;
    __asm__ __volatile__("" : : "r"(pb0));

    a = ((u16 *)p2)[0]; pac = D_8017E26C; pb0[0] = a; b = ((u16 *)p1)[0]; pb8 = (*(s16 * *)&D_8017E278); pac[0] = b; pb8[0] = a - b;
    a = ((u16 *)p2)[1]; pb0[1] = a; b = ((u16 *)p1)[1]; pac[1] = b; pb8[1] = a - b;
    a = ((u16 *)p2)[2]; pb0[2] = a; b = ((u16 *)p1)[2]; pac[2] = b; pb8[2] = a - b;

    id = ((int)arg0) & 0xFFFF;
    a1v = pac[0]; a2v = pac[2]; d94 = D_80194F88;
    __asm__ __volatile__("" ::: "memory");
    D_80194F98 = 0;

    if (func_80134A74(id, a1v, a2v, d94)) {
    found:
        pb4 = (*(u16 * *)&D_8017E274);
        ((u16 *)p2)[0] = pb4[0];
        ((u16 *)p2)[1] = pb4[1];
        ((u16 *)p2)[2] = pb4[2];
        ((u16 *)p2)[3] = D_80194F98;
        return 1;
    }
    {
        register u16 *qb __asm__("$4");    
        register int qa0 __asm__("$5");    
        register u16 *qa __asm__("$6");    
        qb = (u16 *)D_8017E26C;
        qa = (u16 *)D_8017E270;
        qa0 = qa[0];
        if (((qb[0] & 0xFF80) == (qa0 & 0xFF80)) &&
            ((qb[2] & 0xFF80) == (qa[2] & 0xFF80)))
            return 0;
        if (func_80134A74(id, (s16)qa0, (s16)qa[2], D_80194F88))
            goto found;
        return 0;
    }
}
