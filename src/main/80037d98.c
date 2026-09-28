/* Exact retail word export for [80037D98,80037EA0); EXE-verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80037D98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 *D_800762B0;
extern u8 D_800A4EFE[];
extern s32 D_80073140[][1];  

extern u8 D_800C6DE0[];
extern u8 D_800C6DE4[];
extern u8 D_800C6DEC[];
extern u8 D_800C6DEE[];
extern u8 D_800C6E2A[];
extern u8 D_800C6E2B[];
extern u8 D_800C6E2C[];
extern u8 D_800C6E2D[];
extern u8 D_800C6E2E[];

extern u8 D_800B9EC8[];
extern u8 D_800B9ED2[];
extern u8 D_800B9ED3[];

extern s32 D_80079A68;
extern void func_8003D424(s32 *);

void func_80037D98(void) {
    s32 i;
    s32 offset;
    s32 val;
    s32 *table;

    D_800762B0 = D_800A4EFE;

    i = 0;
    table = (s32 *)D_80073140;
    offset = 0;
    while (i < 0x10) {
        val = *table;
        table++;
        i++;
        D_800C6E2A[offset] = 0;
        D_800C6E2B[offset] = 0;
        D_800C6E2C[offset] = 0;
        D_800C6E2D[offset] = 0;
        *(s16 *)&D_800C6DEC[offset] = 0;
        *(s16 *)&D_800C6DEE[offset] = 0;
        *(s32 *)&D_800C6DE4[offset] = 0;
        D_800C6E2E[offset] = 0;
        *(s32 *)&D_800C6DE0[offset] = val;
        offset += 0x60;
    }

    i = 0;
    offset = 0;
    for (; i < 2; i++) {
        D_800B9ED3[offset] = 0;
        D_800B9ED2[offset] = 0;
        *(s16 *)&D_800B9EC8[offset] = i;
        offset += 0x1FC;
    }

    func_8003D424(&D_80079A68);
}
