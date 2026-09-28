/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80181C2C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
typedef struct { u8 c[4]; } W4;
extern s32 func_80181EF0(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012AD44(void *a0, s16 a1);
extern void func_80181DEC();
extern void func_80181E88(void *a0);
extern u8 D_801B7840[];
extern s32 func_8005C49C(void);

void func_80181C2C(void *a0) {
    s32 i;
    s32 off;
    u8 *p;
    s32 w;

    if (func_80181EF0() == 0) {
        func_8002D4C8(4, 0x83E);
        func_8012AD44(a0, 0);
        return;
    }

    i = 0;
    off = 0;
    do {
        p = D_801B7840 + off;
        if (*(s32 *)(p + 8) == 0) {
            if (*(s32 *)(p + 0x14) == 0) {
                if (*(s32 *)(p + 0x10) != 0) {
                    *(u16 *)p += 0x10;
                    *(u16 *)(p + 2) += 0x20;
                    if (*(s32 *)(p + 0xC) == 0) {
                        *(u16 *)(p + 4) += 0x10;
                        *(u16 *)(p + 6) += 0x20;
                    } else {
                        (*(s32 *)(p + 0xC))--;
                    }
                    (*(s32 *)(p + 0x10))--;
                } else {
                    *(u16 *)(p + 4) += 0x10;
                    w = *(u16 *)(p + 6) + 0x20;
                    *(u16 *)(p + 6) = w;
                    if (*(s16 *)(p + 2) < (s16)w) {
                        *(s32 *)(p + 0x14) = 2;
                        *(W4 *)(p + 4) = *(W4 *)p;
                        goto next;
                    }
                }
            } else {
                *(u16 *)(p + 4) = *(u16 *)(p + 4) + (func_8005C49C() & 3);
                *(u16 *)(p + 6) = *(u16 *)(p + 6) - (func_8005C49C() & 7);
                if (--*(s32 *)(p + 0x14) == 0) {
                    func_80181DEC(p, i);
                    goto next;
                }
            }
            func_80181E88(p);
        } else {
            (*(s32 *)(p + 8))--;
        }
    next:
        i++;
        off += 0x18;
    } while (i < 10);
}
