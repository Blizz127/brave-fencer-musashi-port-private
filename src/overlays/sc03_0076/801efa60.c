/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFA60 - byte-exact against retail at -O2 (tools/register_match.py). */
extern unsigned short D_80115112;
extern u16 D_80115112;

void func_801EFA60(void)
{
    extern s16 D_800B9A02;
    extern u8 D_801151C8[];
    extern s32 D_801151D0;
    extern s16 D_80115126;
    extern s32 D_801F9DA0;
    extern s32 D_801F9DA4;
    extern u8 D_801F9DA8[];
    extern s32 D_801F9DB8;
    extern s16 D_801F9AB8;
    extern s16 D_801F9AB4;
    extern u8 D_800B9A15;
    extern unsigned short D_80115112;
    extern s32 func_8002B0B4(s32, s32, void *);
    extern void func_801F0734(void);
    extern void func_801F0A9C(void);
    extern s32 func_801EFBB4(void);
    extern void func_801F0210(void);

    u16 idx;
    u16 *p;
    u16 cnt;
    s32 ret;
    s32 frame_pad[1];

    (void)&frame_pad;

    idx = *(u16 *)&D_800B9A02;
    D_801151D0 = *(s32 *)(D_801151C8 + (idx << 2));
    if (*(s16 *)&D_801F9AB8 == 0) {
        D_801F9DB8 = func_8002B0B4(D_801F9DA0, D_801F9DA4, D_801F9DA8);
        if (D_80115126 == 0) {
            func_801F0734();
        } else {
            func_801F0A9C();
        }
    }
    ret = func_801EFBB4();
    func_801F0210();
    if ((ret << 16) != 0) {
        p = &D_80115112;
        cnt = *p;
        D_801F9AB4 = ret;
        D_800B9A15 = 0;
        *p = cnt + 1;
    }
}
