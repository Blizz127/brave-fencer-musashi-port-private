/* Complete SC02 retail span [8014B944,8014BB0C).
 * Ahead hole after 4AA28; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014B944 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 arg);
extern u8 D_80078E78[];
extern s32 D_80078EA4;
extern u16 D_80078EA6;

void func_8014B944(s32 a0, s32 a1, s32 a2)
{
    u8 *base = D_80078E78;
    if (a2 != 0) {
        D_80078EA4 += a1;
        __asm__ __volatile__("" ::: "memory");
        if ((s16)D_80078EA6 >= 0xA1) {
            D_80078EA4 = 0xA00000;
        }
    } else {
        if ((func_80029178(0x1B) & 0xFF) != 0) {
            D_80078EA4 += a1;
            __asm__ __volatile__("" ::: "memory");
            if ((s16)D_80078EA6 >= 0xA1) {
                D_80078EA4 = 0xA00000;
            }
        } else {
            if ((s16)D_80078EA6 < 0x80) {
                D_80078EA4 += a1;
                __asm__ __volatile__("" ::: "memory");
                if ((s16)D_80078EA6 >= 0x81) {
                    D_80078EA4 = 0x800000;
                }
            }
        }
    }
    if (a2 != 0) {
        *(s32 *)(base + 0x60) += a1;
        if (*(s16 *)(base + 0x62) >= 0xA1) {
            *(s32 *)(base + 0x60) = 0xA00000;
        }
    } else {
        if ((func_80029178(0x1B) & 0xFF) != 0) {
            *(s32 *)(base + 0x60) += a1;
            if (*(s16 *)(base + 0x62) >= 0xA1) {
                *(s32 *)(base + 0x60) = 0xA00000;
            }
        } else {
            if (*(s16 *)(base + 0x62) < 0x80) {
                *(s32 *)(base + 0x60) += a1;
                if (*(s16 *)(base + 0x62) >= 0x81) {
                    *(s32 *)(base + 0x60) = 0x800000;
                }
            }
        }
    }
}
