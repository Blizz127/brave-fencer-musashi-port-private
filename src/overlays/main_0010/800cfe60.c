/* Exact retail overlay 0010 export [800CFE60,800D0214), offset 0x21068. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFE60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800AF630[];
extern void *D_80072C74;
extern int func_80019A24(void *dst, void *src, int arg2, int arg3);
typedef struct {
    s32 word0;
    s32 word4;
} CdFileLoc;
extern s16 D_800B9A08;
extern s32 D_800D34AC[];
extern CdFileLoc D_800AE830[];

s32 func_800CFE60(void) {
    extern s16 D_800B9A08;
    extern s32 D_800D34AC[];
    extern s16 D_800D34AE[];
    extern u8 D_800AF630[];
    extern CdFileLoc D_800AE830[];
    extern void *D_80072C74;
    extern s32 D_800C7C60;
    extern s32 *D_800C7C64;
    extern s32 D_800A2E20;

    extern s32 func_8002F648(void);
    extern void func_8002F620(void);
    extern s32 func_80029504(void);
    extern s32 func_80029178(s32);
    extern s32 func_8002F658(void);
    extern void func_800D00E4();
    extern s32 func_80019A24(void *, void *, s32, s32);

    register u8 *base __asm__("$20");
    register s32 mode __asm__("$19");
    s32 file;
    s32 val;
    s32 st;
    s32 cnt;
    s32 res;
    s32 *p;

    base = D_800AF630;

    file = D_800D34AC[D_800B9A08 & 0xFFFF0FFF] & 0xFFF;
    val = D_800D34AE[(D_800B9A08 & 0xFFFF0FFF) * 2];

    st = func_8002F648();
    mode = -1;
    if (st != ((*(u32 *)((u8 *)D_800D34AC + ((D_800B9A08 & 0xFFFF0FFF) << 2)) >> 12) & 0xF)) {
        mode = 0;
        if (st != 0) {
            func_8002F620();
        }
    }

    cnt = func_80029504();

    if (*(s16 *)(base + 0xA3D8) == 0x300B && *(s16 *)(base + 0xA3DE) != 0) {
        val = 8;
        file = 0x8A;
    }
    if (*(s16 *)(base + 0xA3D8) == 0x3001 && cnt < 5) {
        file = 0x37;
    }
    if (*(s16 *)(base + 0xA3D8) == 0x304E && (func_80029178(0x17) & 0xFF) != 0) {
        file = 0x129;
        val = 0x2F;
    }
    if (*(s16 *)(base + 0xA3D8) == 0x1077 && cnt >= 0x2A8) {
        file = 0x151;
        val = 0x34;
    }
    if (*(s16 *)(base + 0xA3D8) == 0x3021 && (func_80029178(0xB9) & 0xFF) != 0) {
        file = 0xC1;
        val = 0x41;
    }

    if (func_8002F658() != val || mode >= 0) {
        s32 *q = &D_800C7C60;
        __asm__("" : "=r"(q) : "0"(q));
        p = q;
        *p = val;
        D_800C7C64 = &D_800A2E20;
    } else {
        p = 0;
    }

    if (file >= 0 && D_800AE830[file].word0 != 0) {
        res = func_80019A24(&D_800AE830[file], D_80072C74, mode, p);
    } else {
        res = 1;
    }

    if (mode == 0 && (res & 1)) {
        func_800D00E4((((u32)D_800D34AC[*(s16 *)(base + 0xA3D8) & 0xFFFF0FFF]) >> 12) & 0xF);
    }
    return res;
}
