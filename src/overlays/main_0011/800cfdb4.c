/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFDB4 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800AF630[];
extern u8 D_80078E78[];
const char D_800CEE30[] = "(DISELECT)";

void func_800CFDB4(void) {
    typedef struct { s32 m; } S70;
    typedef struct { s32 pad00[8]; s32 f20; } SW20;
    typedef struct { s32 pad00[8]; u16 f20; } SH20;
    typedef struct { u8 pad00[0x1A]; u16 f1A; } SP18;
    extern s32 D_800D4C88;
    extern s32 D_800D4C8C;
    extern u16 D_800D4C84;
    extern u16 D_800D4C9C;
    extern u8 D_800D4B64[];
    extern S70 D_800D4B70[];
    extern S70 D_800D4B74[];
    extern s32 D_800D3344;
    extern s16 D_800D334A;
    extern u8 D_800D31F8[];
    extern s32 func_800D0828(s32);
    extern void func_800D0858(void);
    extern void func_800152F4(s32);
    extern void func_800167B8(s32);
    extern void func_800CFCBC(void);
    extern u16 func_80014B10(s32);
    extern void func_80029514(s32);
    extern void func_80011928(s32);
    extern void func_8001534C(int, void *, int, int, int, int);

    register u8 *v0 = D_800AF630;
    SP18 *sp18 = (SP18 *)D_80078E78;
    u8 sp1C;

    sp1C = func_800D0828(((SW20 *)(D_800D4B70[D_800D4C88 * 5].m + D_800D4C8C * 36))->f20);
    func_800D0858();
    func_800152F4(0x11);
    if (D_800D4C9C & 0x820) {
        func_800167B8(4);
        *(u16 *)&v0[0xA3D8] = ((SH20 *)(D_800D4B70[D_800D4C88 * 5].m + D_800D4C8C * 36))->f20;
        *(u16 *)&v0[0xA3DA] = *(s16 *)&v0[0xA3D8] & -0x1000;
        if (sp1C != 0) {
            func_800CFCBC();
            if (func_80014B10(0) & 0x10) {
                func_80029514(D_800D3344);
                sp18->f1A = D_800D334A;
            }
            func_80011928(2);
        }
    }
    if (D_800D4C9C & 0x40) {
        func_80011928(1);
    }
    if (D_800D4C9C & 0x5000) {
        D_800D4C84 = (D_800D4C84 + 1) & 1;
    }
    if (*(s16 *)&D_800D4C84 == 0) {
        if (D_800D4C9C & 0x2000) {
            D_800D4C88++;
            if (D_800D4C88 >= 0xCU) {
                D_800D4C88 = 0;
            }
            D_800D4C8C = 0;
        }
        if (D_800D4C9C & 0x8000) {
            D_800D4C88--;
            if (D_800D4C88 < 0) {
                D_800D4C88 = 0xB;
            }
            D_800D4C8C = 0;
        }
        func_8001534C(0xC, &D_800D4B64[D_800D4C88 * 20], 0xA4, 0x46, 0x44, 0);
        func_8001534C(0xD, (void *)(D_800D4B70[D_800D4C88 * 5].m + D_800D4C8C * 36), 0xA4, 0x52, 0x44, 0);
        if (sp1C == 0) {
            func_8001534C(0x11, (void *)D_800CEE30, 0xA4, 0x5E, 0x44, 0);
        }
    }
    if (*(s16 *)&D_800D4C84 == 1) {
        if (D_800D4C9C & 0x2000) {
            D_800D4C8C++;
            if (D_800D4C8C >= D_800D4B74[D_800D4C88 * 5].m) {
                D_800D4C8C = 0;
            }
        }
        if (D_800D4C9C & 0x8000) {
            D_800D4C8C--;
            if (D_800D4C8C < 0) {
                D_800D4C8C = D_800D4B74[D_800D4C88 * 5].m - 1;
            }
        }
        func_8001534C(0xC, &D_800D4B64[D_800D4C88 * 20], 0xA4, 0x46, 0x44, 0);
        func_8001534C(0xD, (void *)(D_800D4B70[D_800D4C88 * 5].m + D_800D4C8C * 36), 0xA4, 0x52, 0x44, 0);
        if (sp1C == 0) {
            func_8001534C(0x11, (void *)D_800CEE30, 0xA4, 0x5E, 0x44, 0);
        }
    }
    func_8001534C(1, D_800D31F8, 0x68, (s16)(*(s16 *)&D_800D4C84 * 12 + 0x46), 0, 0);
}
