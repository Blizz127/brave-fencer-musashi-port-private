/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB1A0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8004787C(s32 a0);
extern s32 func_80047948(s32 a0);

void func_800CB1A0(void) {
    extern u16 D_800B99DA;
    extern s32 D_800CC580;
    extern s32 D_800CC584;
    extern s32 D_800CC588;
    extern u8 D_800CC58C;
    extern u8 D_800CC58D;
    extern u8 D_800CC58E;
    extern s32 D_800CC590;
    extern s32 D_800CC594;
    extern s32 D_800CC598;
    extern u8 D_800CC59C;
    extern u8 D_800CC59D;
    extern u8 D_800CC59E;
    extern s32 D_800CC5A0;
    extern s32 D_800CC5A4;
    extern s32 D_800CC5A8;
    extern u8 D_800CC5AC;
    extern u8 D_800CC5AD;
    extern u8 D_800CC5AE;
    u16 *p;
    s32 ff;

    p = &D_800B99DA;
    D_800CC580 = func_8004787C((p[0] & 7) << 9);
    D_800CC584 = 0;
    D_800CC588 = func_80047948((p[0] & 7) << 9);
    ff = 0xFF;
    D_800CC58C = ff;
    D_800CC58D = 0;
    D_800CC58E = 0;
    D_800CC590 = func_8004787C((p[0] & 7) << 9);
    D_800CC594 = func_80047948((p[0] & 7) << 9);
    D_800CC598 = 0;
    D_800CC59C = 0;
    D_800CC59D = 0;
    D_800CC59E = ff;
    D_800CC5A0 = 0;
    D_800CC5A4 = func_8004787C((p[0] & 7) << 9);
    D_800CC5A8 = func_80047948((p[0] & 7) << 9);
    D_800CC5AC = ff;
    D_800CC5AD = ff;
    D_800CC5AE = ff;
}
