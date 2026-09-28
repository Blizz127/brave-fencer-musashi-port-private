/* Overlay range [801343C4,80134510) from MAIN.CD member 0012.
 * SHA256(span)=ebc18f9d47195bcde796825d84405a2d336d8f97994d35c5d88eea48a7df0254.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801343C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

// @class: schedule
// @stuck: none — MATCH (83 ins, relocation-masked)



s32 func_801343C4(s32 angle, s32 p1, s32 p2)
{

    extern s32 D_80184120;
    extern s32 func_80133AB0(s16, s16, s16, s32);
    extern s16 * D_8017E910;
    extern s16 * D_8017E914;
    extern u16 D_80184130;
    extern u16 D_8018412C;

    s16 *pac;
    s16 *pb0;
    s16 *pacs, *pb0s;
    u16 *pb0u;
    int a1v, a2v, d94, b0;
    int sangle = ((s16)angle);

    pac = D_8017E910;
    d94 = D_80184120;
    pb0 = D_8017E914;
    pac[0] = ((u16 *)p1)[0];
    pac[1] = ((u16 *)p1)[1];
    pac[2] = ((u16 *)p1)[2];
    pb0[0] = ((u16 *)p2)[0];
    pb0[1] = ((u16 *)p2)[1];
    pb0[2] = ((u16 *)p2)[2];

    a1v = pac[0]; a2v = pac[2];
    __asm__ __volatile__("" ::: "memory");
    D_80184130 = 0;
    D_8018412C = 0;
    if (func_80133AB0(sangle, a1v, a2v, d94)) {
    setdst:
        pb0u = (u16 *)D_8017E914;
        ((u16 *)p2)[0] = pb0u[0];
        ((u16 *)p2)[1] = pb0u[1];
        ((u16 *)p2)[2] = pb0u[2];
        ((u16 *)p2)[3] = D_80184130;
        return 1;
    }

    pacs = D_8017E910;
    pb0s = D_8017E914;
    b0 = pb0s[0];
    if ((pacs[0] & 0xFF80) == (b0 & 0xFF80) &&
        (pacs[2] & 0xFF80) == (pb0s[2] & 0xFF80)) {
        return 0;
    }
    if (func_80133AB0(sangle, b0, pb0s[2], D_80184120)) {
        goto setdst;
    }
    return 0;
}
