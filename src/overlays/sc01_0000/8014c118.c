/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014C118 - byte-exact against retail at -O2 (tools/register_match.py). */
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
    u8 pad[0x6E];
    s16 unk70;
    u8 pad2[0x9A];
} Entry8014C118;
extern u8 D_801202A0[];

s32 func_8014C118(void * a0, s32 a1, s32 a2)
{
    Entry8014C118 *p;
    s32 i;
    i = 0;
    a2 = (s16)a2;
    p = (Entry8014C118 *)D_801202A0;
    do {
        if (p->unk0 == a1) {
            if (p->unk70 == a2) {
                return (s32)p;
            }
        }
        i++;
        p++;
    } while ((u32)i < 0x60);
    return 0;
}
