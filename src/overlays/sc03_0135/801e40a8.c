/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
#define strcpy func_8005C540
/* func_801E40A8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    char c[3];
} Blk3_801E40A8;
extern char *strcpy(char *, const char *);
extern u32 func_801E45C0(s32 a0, s32 a1);
extern void func_801E4628(val, n, dst, flag);
extern void *D_801EAC58[];
extern void *D_801E6424[];
extern char *D_801E632C[];
extern s32 D_801E65B8[];
extern u16 *D_801E6390[];
extern char *D_801E634C;
extern Blk3_801E40A8 D_801E26C0;

void func_801E40A8(void) {
    s16 k;
    s16 i;
    s16 j;
    u8 *p;
    void **arr;
    u32 a;
    u32 b;
    s32 r;
    s32 n;
    u16 *ico;

    for (k = 0; k < 4; k++) {
        p = (u8 *)D_801EAC58[k];
        arr = (void **)D_801E6424[k];
        if (p != ((void *)0) ) {
            for (i = 0; i < 7; i++) {
                strcpy((char *)arr[i], D_801E632C[i]);
                switch (i) {
                case 0:
                    for (j = 0; j < 5; j++) {
                        if (*(s16 *)(p + 8) < D_801E65B8[j]) {
                            break;
                        }
                    }
                    if (p[0x4E] != 0) {
                        j = (*(s32 *)p == 0) ? 0x1A : 0x1C;
                    }
                    *(s32 *)arr = j + 4;
                    break;
                case 1:
                    a = p[7];
                    if (a >= 100) {
                        a = 99;
                    }
                    b = p[6];
                    if (b >= 60) {
                        b = 59;
                    }
                    ((void (*)(unsigned int, short, unsigned short *, short))func_801E4628)((func_801E45C0((u16)a, 0x18) | 0xB00000) |
                                      func_801E45C0(b, 0xC),
                                  5, (u8 *)arr[1] + 0x12, 0);
                    break;
                case 2:
                    a = *(u16 *)(p + 0x34);
                    if (a >= 1000) {
                        a = 999;
                    }
                    ((void (*)(unsigned int, short, unsigned short *, short))func_801E4628)(func_801E45C0((u16)a, 0x14), 3, (u8 *)arr[2] + 8, 1);
                    n = p[0x42];
                    if (n >= 7) {
                        n = 6;
                    }
                    ico = D_801E6390[n];
                    *(u16 *)((u8 *)arr[2] + 0x10) = *ico++;
                    *(u16 *)((u8 *)arr[2] + 0x12) = ico[0];
                    *(u16 *)((u8 *)arr[2] + 0x14) = ico[1];
                    a = p[0x39];
                    if (a >= 0x18) {
                        a = 0x17;
                    }
                    b = p[0x38];
                    if (b >= 0x3C) {
                        b = 0x3B;
                    }
                    ((void (*)(unsigned int, short, unsigned short *, short))func_801E4628)((func_801E45C0((u16)a, 0x18) | 0xB00000) |
                                      func_801E45C0(b, 0xC),
                                  5, (u8 *)arr[2] + 0x18, 0);
                    break;
                case 3:
                    a = *(u16 *)(p + 0x3C);
                    if (a >= 1000) {
                        a = 999;
                    }
                    b = *(u16 *)(p + 0x3A);
                    if (b >= 1000) {
                        b = 999;
                    }
                    r = func_801E45C0((u16)a, 0x14);
                    if (r == 0) {
                        r = 0xD00000;
                    }
                    ((void (*)(unsigned int, short, unsigned short *, short))func_801E4628)(r | (func_801E45C0(b, 4) | 0xC0000), 7, (u8 *)arr[3] + 6, 1);
                    break;
                case 4:
                    a = *(u16 *)(p + 0x40);
                    if (a >= 1000) {
                        a = 999;
                    }
                    b = *(u16 *)(p + 0x3E);
                    if (b >= 1000) {
                        b = 999;
                    }
                    r = func_801E45C0((u16)a, 0x14);
                    if (r == 0) {
                        r = 0xD00000;
                    }
                    ((void (*)(unsigned int, short, unsigned short *, short))func_801E4628)(r | (func_801E45C0(b, 4) | 0xC0000), 7, (u8 *)arr[4] + 6, 1);
                    break;
                case 5:
                    a = *(u32 *)(p + 0x14);
                    if (a > 99999) {
                        a = 99999;
                    }
                    ((void (*)(unsigned int, short, unsigned short *, short))func_801E4628)(func_801E45C0(a, 0xC), 5, (u8 *)arr[5] + 2, 1);
                    break;
                case 6:
                    a = *(u16 *)(p + 0xC);
                    if (a >= 0x24) {
                        a = 0x23;
                    }
                    r = func_801E45C0((u16)a, 0x18);
                    if (r == 0) {
                        r = 0xD000000;
                    }
                    ((void (*)(unsigned int, short, unsigned short *, short))func_801E4628)(r, 2, (u8 *)arr[6] + 0x10, 1);
                    break;
                }
            }
        } else {
            for (i = 0; i < 7; i++) {
                if (i == 0) {
                    *(s32 *)arr = 4;
                } else if (i == 1) {
                    strcpy((char *)arr[i], D_801E632C[i]);
                } else if (i == 4) {
                    strcpy((char *)arr[i], D_801E634C);
                } else {
                    *(Blk3_801E40A8 *)arr[i] = D_801E26C0;
                }
            }
        }
    }
}
