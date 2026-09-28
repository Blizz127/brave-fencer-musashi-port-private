/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013EA54 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80141C50(void);
extern void func_8013F244(void);
extern void func_8013FAF8(s16 a0, s16 a1);
extern void func_80137B80(void);
extern void func_8013E958(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern short D_800B9A02;
extern u8 D_801151C8[];
extern s32 D_801151D0;
extern u16 D_8011511A;
extern u16 D_8011511E;
extern unsigned short D_80115112;
extern s32 D_80115130;
extern s16 D_8011514C;
extern s16 D_800B9A08;

void func_8013EA54(void) {
    s32 sp10[2];
    if ((s16)func_80141C50() == 0) {
        D_801151D0 = *(s32 *)&D_801151C8[(u16)D_800B9A02 * 4];
        func_8013F244();
        func_8013FAF8(0, 5);
        func_80137B80();
        if (D_8011511E & 0x40) {
            if (D_8011511A == 0 && D_800B9A08 == 0x308F) {
                func_8002D4C8(0x466, 0);
            } else {
                u16 v = D_8011511A;
                if (v != 4) {
                    D_80115130 = 0;
                }
                if ((u16)(v - 1) <= 1) {
                    D_8011514C = 0;
                }
                func_8002D4C8(0x45D, 0);
                D_80115112 += 1;
            }
        } else if (D_8011511E & 0x810) {
            func_8013E958();
        }
    }
    (void)sp10;
}
