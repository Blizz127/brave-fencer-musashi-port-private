/* Overlay range [80134510,801345F8) from MAIN.CD member 0012.
 * SHA256(span)=f9735b8563f746b870b474cf5f32aca3c29173ef8c2ed660cafecf5b6a8baeb6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80134510 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    u16 f0;    
    u16 f2;    
    u16 f4;    
    s16 f6;    
} Foo_80134510;

s32 func_80134510(s32 param) {
    extern s32 func_801345F8(s32);
    extern Foo_80134510 * D_8017E910;
    extern Foo_80134510 * D_8017E914;
    extern Foo_80134510 * D_8017E918;
    extern s32 D_80184120;
    extern u16 D_80184130;

    s32 ret = 0;
    Foo_80134510 *b0 = D_8017E914;
    Foo_80134510 *ac = D_8017E910;
    u16 t0 = ((Foo_80134510 *)param)->f0;
    u16 t2, t4;

    ((Foo_80134510 *)param)->f6 = 0;
    ac->f0 = t0;
    b0->f0 = t0;
    t2 = ((Foo_80134510 *)param)->f2;
    ac->f2 = t2 - 4;
    b0->f2 = t2 + 0x2FC;
    t4 = ((Foo_80134510 *)param)->f4;
    ac->f4 = t4;
    b0->f4 = t4;

    if (func_801345F8(D_80184120) != 0) {
        s16 x;
        ((Foo_80134510 *)param)->f2 = D_8017E918->f2 - 2;
        x = D_8017E910->f6;
        if (x >= -3019) {
            if (x < -1400) {
                ret = 0x4000;
            } else {
                ret = 0x8000;
            }
        } else {
            ret = 0x2000;
        }
        D_8017E910->f6 = D_80184130;
    }
    return ret;
}
