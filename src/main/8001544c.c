/* Main-exec range [8001544C,80015498) from the SLUS executable.
 * SHA256(span)=e8771b3bc7695c76e57cb1aada32825b4a9fbfee917b949db5e7cb258023a312.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8001544C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    /* 0x00 */ u16 type;
    /* 0x02 */ u16 unk02;
    /* 0x04 */ u16 x;
    /* 0x06 */ u16 y;
    /* 0x08 */ u16 w;
    /* 0x0A */ u16 h;
    /* 0x0C */ void *data;
} DispItem_800184F0;
typedef struct {
    /* 0x00 */ s16 flag;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ DispItem_800184F0 *list;
    /* 0x08 */ u16 unk08;
    /* 0x0A */ u16 unk0A;
    /* 0x0C */ u8 unk0C;
    /* 0x0D */ u8 unk0D;
    /* 0x0E */ u16 unk0E;
} DispSlot_800184F0;
extern s16 D_800B93D8[];
extern DispSlot_800184F0 D_800B97D8[];

s16 *func_8001544C(void) {
    extern DispSlot_800184F0 D_800B97D8[];
    s16 *p;
    s16 *end;
    s16 v;
    s32 pad[2];

    p = D_800B93D8;
    end = (s16 *)D_800B97D8;
    if (p >= end) {
        return 0;
    }
    do {
        v = *p;
        if (v == 0) {
            return p;
        }
        p += 8;
    } while (p < end);
    return 0;
}
