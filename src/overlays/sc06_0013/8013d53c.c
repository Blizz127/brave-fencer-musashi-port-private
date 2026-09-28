/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D53C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { s32 a, b, c; } Rec12;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;
typedef struct { u8 b[9]; } S9;
typedef struct {
    u16 cmd;        /* 0x0 */
    u16 pad2;       /* 0x2 */
    u16 pad4;       /* 0x4 */
    u16 pad6;       /* 0x6 */
    s16 w;          /* 0x8 */
    s16 h;          /* 0xA */
    u16 *data;      /* 0xC */
} Cmd_8013D53C;
extern s32 D_80199870;
extern s32 D_80199858;
extern u8 D_8019AB92;
extern u8 D_8019AC06;
extern u8 D_8019AABA;
extern u8 D_8019AB74;
extern u8 D_8019AA98;
extern u8 D_8019AAB9;
extern s32 D_8019AB78;
extern s32 D_8019986C;
extern s32 D_80199868;
extern s32 D_80199850;
extern s32 D_8019985C;
extern s32 D_80199860;
extern void *D_80199840;
extern s32 D_80199878;
extern void *D_80199848;

void func_8013D53C(void *arg0v) {

    extern Rec9 D_8017F4FC[];
    extern Rec12 D_8017F534[];
    extern u8 D_80078EAF;
    extern u8 D_8019AB50;
    extern s32 D_80199864;
    Cmd_8013D53C *arg0 = arg0v;

    extern u8 D_8017F538[];
    extern u8 D_8017F53C[];
    extern unsigned char D_8019AAB0;
    extern s16 *D_8019984C;
    extern s32 D_8019987C;
    extern s32 D_80199880;
    extern s32 D_80199884;
    s32 s0v;
    s32 t9v;
    s32 t8v;
    u8 b0, b1, b2;
    u8 pad[8];   /* dead BLKmode local: frame 0x10 -> 0x18, zero code */

    if (!(D_80199870 & 1)) {
        D_80199858 = 1;
    } else {
        D_80199858 = D_80078EAF;
    }

    b0 = ((u8 *)D_8017F534)[D_80199858 * 12];
    D_8019AB92 = b0;
    D_8019AC06 = b0;
    b1 = D_8017F538[D_80199858 * 12];
    D_8019AABA = b1;
    D_8019AB74 = b1;
    b2 = D_8017F53C[D_80199858 * 12];
    D_8019AA98 = b2;
    D_8019AAB9 = b2;

    (*(S9 *)&D_8019AAB0) = ((S9 *)D_8017F4FC)[D_80199858];
    (*(S9 *)&D_8019AB50) = *(S9 *)(&D_8019AA98 + 0x18);  /* same addr as (*(S9 *)&D_8019AAB0); distinct sym defeats cse, keeps %hi/%lo */

    D_8019AB78 = 1;
    D_8019986C = -1;
    D_80199868 = 0;
    D_80199864 = -1;
    D_80199850 = 0;
    D_8019985C = 0;
    D_80199860 = 0;

    if ((D_80199870 & 2) && (D_80199858 == 4)) {
        s0v = (*(s32 * *)&D_80199840)[18];
        t9v = (*(s32 * *)&D_80199840)[19];
        t8v = (*(s32 * *)&D_80199840)[20];
    } else {
        s32 *p = (s32 *)(D_80199858 * 12 + (s32) (*(s32 * *)&D_80199840));  /* block-local: local-alloc ties sum into mul chain */
        s0v = p[0];
        t9v = p[1];
        t8v = p[2];
    }

    (*(Cmd_8013D53C * *)&D_8019984C) = arg0;
    if (arg0 != 0) {
        if (D_80199878 != 0) {
            s32 *p = (s32 *)(D_80199858 * 12 + (s32) (*(s32 * *)&D_80199848));
            D_8019987C = p[0];
            D_80199880 = p[1];
            D_80199884 = p[2];
        } else {
            while ((arg0->cmd & 0xFFFF) != 0xFF) {
                if ((arg0->cmd & 0xFFFF) == 9) {
                    s32 n;
                    s32 i;
                    u16 *src;
                    u16 *dst;
                    n = arg0->w * arg0->h;
                    i = 0;
                    src = arg0->data;
                    __asm__("" :: "r"(src));  /* +2 refs on src (depth-2): keeps src above i, below the mfhi temp */
                    dst = src + n;
                    if (n > 0) {
                        do {
                            u16 px;
                            s32 r, g, b, out;
                            __asm__("" :: "r"(i));  /* +3 refs on i (depth-3): lifts i over dst in the $t2 race */
                            px = *src;
                            r = ((px & 0x1F) * s0v) / 2560;
                            g = (((px & 0x3E0) * t9v) / 2560) & 0x3E0;
                            b = (((px & 0x7C00) * t8v) / 2560) & 0x7C00;
                            out = r | g | b | (px & 0x8000);
                            if (out == 0 && px != 0) {
                                out = 0x8000;
                            }
                            *dst = out;
                            dst++;
                            i++;
                            src++;
                        } while (i < n);
                    }
                }
                arg0++;
            }
        }
    }
}
