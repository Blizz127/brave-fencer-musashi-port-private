/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EF448 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[3]; } Blk3_801EF448;
extern char *func_8005C540(char *, const char *);
extern u32 func_801EF960(s32 a0, s32 a1);
extern void func_801EF9C8();
extern void *D_801F8314[];
extern void *D_801F1814[];
extern char *D_801F171C[];
extern s32 D_801F19A8[];
extern u16 *D_801F1780[];
extern char *D_801F173C;
extern Blk3_801EF448 D_801EDA60;

void func_801EF448(void) {
    s16 k; s16 i; s16 j;
    u8 *p;
    void **arr;
    u32 a; u32 b;
    s32 r; s32 n;
    u16 *ico;

    for (k = 0; k < 4; k++) {
        p = (u8 *)D_801F8314[k];
        arr = (void **)D_801F1814[k];
        if (p != NULL) {
            for (i = 0; i < 7; i++) {
                func_8005C540((char *)arr[i], D_801F171C[i]);
                switch (i) {
                case 0:
                    for (j = 0; j < 5; j++) {
                        if (*(s16 *)(p + 8) < D_801F19A8[j]) break;
                    }
                    if (p[0x4E] != 0) {
                        j = (*(s32 *)p == 0) ? 0x1A : 0x1C;
                    }
                    *(s32 *)arr = j + 4;
                    break;
                case 1:
                    a = p[7];
                    if (a >= 100) a = 99;
                    b = p[6];
                    if (b >= 60) b = 59;
                    func_801EF9C8((func_801EF960((u16)a, 0x18) | 0xB00000) | func_801EF960(b, 0xC), 5, (u8 *)arr[1] + 0x12, 0);
                    break;
                case 2:
                    a = *(u16 *)(p + 0x34);
                    if (a >= 1000) a = 999;
                    func_801EF9C8(func_801EF960((u16)a, 0x14), 3, (u8 *)arr[2] + 8, 1);
                    n = p[0x42];
                    if (n >= 7) n = 6;
                    ico = D_801F1780[n];
                    *(u16 *)((u8 *)arr[2] + 0x10) = *ico++;
                    *(u16 *)((u8 *)arr[2] + 0x12) = ico[0];
                    *(u16 *)((u8 *)arr[2] + 0x14) = ico[1];
                    a = p[0x39];
                    if (a >= 0x18) a = 0x17;
                    b = p[0x38];
                    if (b >= 0x3C) b = 0x3B;
                    func_801EF9C8((func_801EF960((u16)a, 0x18) | 0xB00000) | func_801EF960(b, 0xC), 5, (u8 *)arr[2] + 0x18, 0);
                    break;
                case 3:
                    a = *(u16 *)(p + 0x3C);
                    if (a >= 1000) a = 999;
                    b = *(u16 *)(p + 0x3A);
                    if (b >= 1000) b = 999;
                    r = func_801EF960((u16)a, 0x14);
                    if (r == 0) r = 0xD00000;
                    func_801EF9C8(r | (func_801EF960(b, 4) | 0xC0000), 7, (u8 *)arr[3] + 6, 1);
                    break;
                case 4:
                    a = *(u16 *)(p + 0x40);
                    if (a >= 1000) a = 999;
                    b = *(u16 *)(p + 0x3E);
                    if (b >= 1000) b = 999;
                    r = func_801EF960((u16)a, 0x14);
                    if (r == 0) r = 0xD00000;
                    func_801EF9C8(r | (func_801EF960(b, 4) | 0xC0000), 7, (u8 *)arr[4] + 6, 1);
                    break;
                case 5:
                    a = *(u32 *)(p + 0x14);
                    if (a > 99999) a = 99999;
                    func_801EF9C8(func_801EF960(a, 0xC), 5, (u8 *)arr[5] + 2, 1);
                    break;
                case 6:
                    a = *(u16 *)(p + 0xC);
                    if (a >= 0x24) a = 0x23;
                    r = func_801EF960((u16)a, 0x18);
                    if (r == 0) r = 0xD000000;
                    func_801EF9C8(r, 2, (u8 *)arr[6] + 0x10, 1);
                    break;
                }
            }
        } else {
            for (i = 0; i < 7; i++) {
                if (i == 0) {
                    *(s32 *)arr = 4;
                } else if (i == 1) {
                    func_8005C540((char *)arr[i], D_801F171C[i]);
                } else if (i == 4) {
                    func_8005C540((char *)arr[i], D_801F173C);
                } else {
                    *(Blk3_801EF448 *)arr[i] = D_801EDA60;
                }
            }
        }
    }
}
