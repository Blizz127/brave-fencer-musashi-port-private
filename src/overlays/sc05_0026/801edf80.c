/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EDF80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801EDF80(void)
{
    extern s16 D_800B9A02;
    extern void (*D_801F8010)(void);
    extern u8 D_801151C8[];
    extern s32 D_801151D0;
    extern s16 D_80115126;
    extern s32 D_801F82F8;
    extern s32 D_801F82FC;
    extern u8 D_801F8300[];
    extern s32 D_801F8310;
    extern s16 D_801F800C;
    extern u8 D_800B9A15;
    extern unsigned short D_80115112;
    extern s32 func_8002B0B4(s32, s32, void *);
    extern void func_801EEC54(void);
    extern void func_801EEFBC(void);
    extern s32 func_801EE0D4();
    extern void func_801EE730(void);

    u16 idx;
    u16 *p;
    u16 cnt;
    s32 ret;
    s32 frame_pad[1];

    (void)&frame_pad;

    idx = *(u16 *)&D_800B9A02;
    D_801151D0 = *(s32 *)(D_801151C8 + (idx << 2));
    if (*(s16 *)&D_801F8010 == 0) {
        D_801F8310 = func_8002B0B4(D_801F82F8, D_801F82FC, D_801F8300);
        if (D_80115126 == 0) {
            func_801EEC54();
        } else {
            func_801EEFBC();
        }
    }
    ret = func_801EE0D4();
    func_801EE730();
    if ((ret << 16) != 0) {
        p = &D_80115112;
        cnt = *p;
        D_801F800C = ret;
        D_800B9A15 = 0;
        *p = cnt + 1;
    }
}
