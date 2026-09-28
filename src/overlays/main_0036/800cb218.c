/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB218 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern void func_80147324(s32 a0);
extern s32 func_80146CA0(void *a0);
extern s32 D_800CC12C;
extern s32 D_800CC130;
extern s16 D_800CC134;
extern s16 D_800CC136;
extern s16 D_800CC138;
extern u16 D_800B99DA;
extern s32 D_80126B58[];
extern s32 func_8004787C(s32);
extern s32 func_80012DBC(s32, s32, s32, s32);
extern u16 func_80148800(s32 *);
extern s32 func_80146E98(s32);
extern void func_80146E90(s32 *, s32);
extern void func_80147324(s32);
extern s32 func_80146CA0(void *);
extern int rand(void);

void func_800CB218(void *arg0) {
    s32 cnt;
    s32 mode;
    void *s1;
    s16 *evt;

    cnt = D_800CC12C;
    mode = D_800CC130;
    s1 = *(void **)((s32)arg0 + 0x20);
    D_800CC12C = cnt - 1;

    switch (mode) {
    case 0:
        *(s16 *)((s32)arg0 + 0x60) = (func_8004787C((D_800B99DA & 0x3F) << 6)) / 64;
        break;
    case 1:
        *(s16 *)((s32)arg0 + 0x60) = (func_8004787C((D_800B99DA & 0x1F) << 7)) / 32;
        break;
    }

    *(s16 *)((s32)s1 + 0x14) = func_80012DBC(*(s16 *)((s32)s1 + 0x14), *(s16 *)((s32)arg0 + 0x60), 10, 1);

    if (*(s32 *)((s32)arg0 + 0x50) == 0) {
        if (func_80146E98((s32)arg0) != 0) {
            func_80146E90((s32 *)arg0, (rand() & 0x3F) + 0x20);
            D_800CC130 = rand() & 1;
        }
    }

    if (D_800CC12C < 0x80 || (func_80148800(D_80126B58) & 0x20)) {
        evt = &D_800CC134;
        *(s32 *)((s32)s1 + 0x80) = (s32)evt;
        *(u16 *)((s32)s1 + 0x2C) |= 0x80;
        D_800CC138 = 0x80;
        D_800CC136 = 0x80;
        *evt = 0x80;
        func_80146E90((s32 *)arg0, 0);
        func_80147324(0x8ED);
        func_80146CA0(arg0);
    }
}
