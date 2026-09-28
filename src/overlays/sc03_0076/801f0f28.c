/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
#define strcpy func_8005C540
/* func_801F0F28 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    char c[3];
} Blk3_801F0F28;
extern char *strcpy(char *, const char *);
extern u32 func_801F1440(s32 a0, s32 a1);
extern void func_801F14A8();
extern void *D_801F9DBC[];
extern void *D_801F32BC[];
extern char *D_801F31C4[];
extern s32 D_801F3450[];
extern u16 *D_801F3228[];
extern char *D_801F31E4;
extern Blk3_801F0F28 D_801EF540;

void func_801F0F28(void) {
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
        p = (u8 *)D_801F9DBC[k];
        arr = (void **)D_801F32BC[k];
        if (p != ((void *)0) ) {
            for (i = 0; i < 7; i++) {
                strcpy((char *)arr[i], D_801F31C4[i]);
                switch (i) {
                case 0:
                    for (j = 0; j < 5; j++) {
                        if (*(s16 *)(p + 8) < D_801F3450[j]) {
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
                    func_801F14A8((func_801F1440((u16)a, 0x18) | 0xB00000) |
                                      func_801F1440(b, 0xC),
                                  5, (u8 *)arr[1] + 0x12, 0);
                    break;
                case 2:
                    a = *(u16 *)(p + 0x34);
                    if (a >= 1000) {
                        a = 999;
                    }
                    func_801F14A8(func_801F1440((u16)a, 0x14), 3, (u8 *)arr[2] + 8, 1);
                    n = p[0x42];
                    if (n >= 7) {
                        n = 6;
                    }
                    ico = D_801F3228[n];
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
                    func_801F14A8((func_801F1440((u16)a, 0x18) | 0xB00000) |
                                      func_801F1440(b, 0xC),
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
                    r = func_801F1440((u16)a, 0x14);
                    if (r == 0) {
                        r = 0xD00000;
                    }
                    func_801F14A8(r | (func_801F1440(b, 4) | 0xC0000), 7, (u8 *)arr[3] + 6, 1);
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
                    r = func_801F1440((u16)a, 0x14);
                    if (r == 0) {
                        r = 0xD00000;
                    }
                    func_801F14A8(r | (func_801F1440(b, 4) | 0xC0000), 7, (u8 *)arr[4] + 6, 1);
                    break;
                case 5:
                    a = *(u32 *)(p + 0x14);
                    if (a > 99999) {
                        a = 99999;
                    }
                    func_801F14A8(func_801F1440(a, 0xC), 5, (u8 *)arr[5] + 2, 1);
                    break;
                case 6:
                    a = *(u16 *)(p + 0xC);
                    if (a >= 0x24) {
                        a = 0x23;
                    }
                    r = func_801F1440((u16)a, 0x18);
                    if (r == 0) {
                        r = 0xD000000;
                    }
                    func_801F14A8(r, 2, (u8 *)arr[6] + 0x10, 1);
                    break;
                }
            }
        } else {
            for (i = 0; i < 7; i++) {
                if (i == 0) {
                    *(s32 *)arr = 4;
                } else if (i == 1) {
                    strcpy((char *)arr[i], D_801F31C4[i]);
                } else if (i == 4) {
                    strcpy((char *)arr[i], D_801F31E4);
                } else {
                    *(Blk3_801F0F28 *)arr[i] = D_801EF540;
                }
            }
        }
    }
}
