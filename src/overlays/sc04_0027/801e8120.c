/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E8120 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801151D0;
extern u8 D_801151C8[];
extern u8 D_800B9A15;
extern s16 D_80115126;
extern s16 D_800B9A02;
extern unsigned short D_80115112;
extern s16 D_801F2184;
extern s16 D_801F2188;
extern s32 D_801F2470;
extern s32 D_801F2474;
extern u8 D_801F2478[];
extern s32 D_801F2488;
extern s32 func_8002B0B4(s32, s32, void *);
extern void func_801E8DF4(void);
extern void func_801E915C(void);
extern s32 func_801E8274(void);
extern void func_801E88D0(void);

void func_801E8120(void) {
    u16 idx;
    u16 *p;
    u16 cnt;
    s32 ret;
    s32 frame_pad[1];

    (void)&frame_pad;

    idx = *(u16 *)&D_800B9A02;
    D_801151D0 = *(s32 *)(D_801151C8 + (idx << 2));
    if (*(s16 *)&D_801F2188 == 0) {
        D_801F2488 = func_8002B0B4(D_801F2470, D_801F2474, D_801F2478);
        if (D_80115126 == 0) {
            func_801E8DF4();
        } else {
            func_801E915C();
        }
    }
    ret = func_801E8274();
    func_801E88D0();
    if ((ret << 16) != 0) {
        p = &D_80115112;
        cnt = *p;
        D_801F2184 = ret;
        D_800B9A15 = 0;
        *p = cnt + 1;
    }
}
