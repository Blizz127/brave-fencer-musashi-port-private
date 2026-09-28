/* Exact retail word export for [8003750C,8003775C); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8003750C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    s16 unk0C;
    s16 unk0E;
    u8  unk10;
    u8  unk11;
    u8  unk12;
    u8  unk13;
    s32 unk14;
} Rsc24;

typedef struct {
    s32 unk00;
    u8  unk04;
    u8  unk05;
    u8  unk06;
    u8  unk07;
    u8  unk08;
    u8  unk09;
    u8  unk0A;
    u8  unk0B;
    s32 unk0C;
} Rsc16;

typedef struct {
    u8  unk00;
    u8  unk01[11];
} Rsc12;

extern s32  D_8007629C;
extern u8   D_8006AEF4;
extern u8   D_80076298;
extern Rsc16 D_80076248[];    
extern Rsc12 D_80064D4A[];
extern Rsc24  D_800A4640[];
extern s16  D_800C5328[];
extern s16  D_800C532A[];

extern s32  func_8003C4F0(s32);
extern void func_800415A8(s32);
extern void func_80031A98(void);

s32 func_8003750C(void) {
    s32 i;
    s32 val;
    s32 k;
    s32 h;

    switch (D_8007629C) {
    case 0:
        if (D_8006AEF4 & 2) {
            return 0;
        }
        D_8006AEF4 |= 2;
        D_8007629C = 1;

    case 1:
        if (D_8006AEF4 & 1) {
            if (func_8003C4F0(0) == 0) {
                return 0;
            }
        }
        D_8007629C = D_8007629C + 1;

    case 2:
        for (i = 0; i < 5; i++) {
            if (D_80076248[i].unk09 == 0) {
                continue;
            }
            val = D_80076248[i].unk00;
            k = D_80076248[i].unk0A;
            if (val & 0x6000) {
                continue;
            }
            h = D_800A4640[k].unk04;
            if (h != 0 && h != D_80064D4A[val].unk00) {
                D_800C532A[D_800A4640[k].unk08 * 2] = -1;
                D_800A4640[k].unk04 = 0;
                D_800A4640[k].unk08 = 0;
            }
            if (D_800A4640[k].unk10 != 0) {
                continue;
            }
            D_800A4640[k].unk10 = 1;
            D_800C5328[D_800A4640[k].unk00 * 2] = -1;
            if (D_800A4640[i].unk02 >= 0) {
                func_800415A8(D_800A4640[i].unk02);
                D_800A4640[i].unk02 = -1;
            }
            func_80031A98();
        }
        D_8007629C = 0;
        D_80076298 = 0;
        return 1;
    default:
        return 0;
    }
}
