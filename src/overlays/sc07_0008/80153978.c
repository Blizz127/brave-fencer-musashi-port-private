/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80153978 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 unk7;
} Buf80153978;
extern s32 func_80133784(s32 a0, void *src, s32 dst);
extern s32 func_801539F8(s32 a0, void *a1);

s32 func_80153978(s32 a0, u16 *src) {
    Buf80153978 buf;
    buf.unk0 = src[0];
    buf.unk2 = src[1] + 0x1F;
    buf.unk4 = src[2];
    if (func_80133784(0, src, (s32)&buf) == 0x2000 &&
        buf.unk6 == 0 &&
        func_801539F8(a0, &buf) == 0) {
        return 0;
    }
    return 1;
}
