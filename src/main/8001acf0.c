/* Exact retail word export for [8001ACF0,8001AE90); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001ACF0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* Vendor names mapped to address-named symbols for the link-by-address harness. */
#define resLoad_lastId D_800A654C
#define resLoad_loadedFileIdx D_800747F8
#define resourceIdMap D_80063138

extern s32 D_800747F0;
extern s32 D_800747F4;
extern s32 D_800747E4;
extern s32 D_800747E8;
extern s32 D_800C6D2C;
extern s32 D_800AE6E4;
extern s32 D_800BA318;
extern s32 D_800A6550;
extern s32 D_800BA1B4;
extern s32 D_800AE640;
extern s32 D_800A6430;
extern s32 resLoad_lastId;
extern s32 resLoad_loadedFileIdx;
extern u8 resourceIdMap[];
extern u8 D_8006313C;
extern void func_8002D4C8(int arg0, int arg1);

s32 func_8001ACF0(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, s32 arg4) {
    D_800747F0 = arg0;

    switch (arg0) {
    case 0: {
        s32 tmp;
        D_800C6D2C = arg1;
        D_800AE6E4 = (s32)arg2;
        D_800BA318 = arg3;
        D_800A6550 = arg4;
        tmp = *arg2;
        D_800BA1B4 = 1;
        D_800747F4 = tmp;
        break;
    }

    case 1: {
        s16 v;
        D_800BA1B4 = 2;
        if (arg1 == resLoad_lastId) {
            return 1;
        }
        if (*(s16 *)(resourceIdMap + arg1 * 6) == resLoad_loadedFileIdx) {
            v = *(s16 *)(&D_8006313C + arg1 * 6);
            if (v != 0) {
                func_8002D4C8((u16)v, 0);
                resLoad_lastId = arg1;
            }
            return 1;
        }
        D_800AE640 = arg1;
        D_800747F4 = arg1;
        break;
    }

    case 2: {
        s32 tmp;
        D_800AE6E4 = (s32)arg2;
        tmp = *arg2;
        D_800BA1B4 = 4;
        D_800747F4 = tmp;
        break;
    }

    case 3:
        D_800A6430 = arg1;
        D_800AE6E4 = (s32)arg2;
        D_800747F4 = arg1;
        D_800BA1B4 = 5;
        D_800747E4 = 0;
        D_800747E8 = 1;
        break;
    }
    return 0;
}
