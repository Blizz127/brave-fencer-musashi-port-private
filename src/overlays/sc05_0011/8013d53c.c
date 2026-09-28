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
extern s32 D_8019BE48;
extern s32 D_8019BE30;
extern u8 D_8019D16A;
extern u8 D_8019D1DE;
extern u8 D_8019D092;
extern u8 D_8019D14C;
extern u8 D_8019D070;
extern u8 D_8019D091;
extern s32 D_8019D150;
extern s32 D_8019BE44;
extern s32 D_8019BE40;
extern s32 D_8019BE28;
extern s32 D_8019BE34;
extern s32 D_8019BE38;
extern void *D_8019BE18;
extern s32 D_8019BE50;
extern void *D_8019BE20;

void func_8013D53C(void *arg0v) {

    extern Rec9 D_8017E648[];
    extern Rec12 D_8017E680[];
    extern u8 D_80078EAF;
    extern u8 D_8019D128;
    extern s32 D_8019BE3C;
    Cmd_8013D53C *arg0 = arg0v;

    extern u8 D_8017E684[];
    extern u8 D_8017E688[];
    extern unsigned char D_8019D088;
    extern s16 *D_8019BE24;
    extern s32 D_8019BE54;
    extern s32 D_8019BE58;
    extern s32 D_8019BE5C;
    s32 s0v;
    s32 t9v;
    s32 t8v;
    u8 b0, b1, b2;
    u8 pad[8];   /* dead BLKmode local: frame 0x10 -> 0x18, zero code */

    if (!(D_8019BE48 & 1)) {
        D_8019BE30 = 1;
    } else {
        D_8019BE30 = D_80078EAF;
    }

    b0 = ((u8 *)D_8017E680)[D_8019BE30 * 12];
    D_8019D16A = b0;
    D_8019D1DE = b0;
    b1 = D_8017E684[D_8019BE30 * 12];
    D_8019D092 = b1;
    D_8019D14C = b1;
    b2 = D_8017E688[D_8019BE30 * 12];
    D_8019D070 = b2;
    D_8019D091 = b2;

    (*(S9 *)&D_8019D088) = ((S9 *)D_8017E648)[D_8019BE30];
    (*(S9 *)&D_8019D128) = *(S9 *)(&D_8019D070 + 0x18);  /* same addr as (*(S9 *)&D_8019D088); distinct sym defeats cse, keeps %hi/%lo */

    D_8019D150 = 1;
    D_8019BE44 = -1;
    D_8019BE40 = 0;
    D_8019BE3C = -1;
    D_8019BE28 = 0;
    D_8019BE34 = 0;
    D_8019BE38 = 0;

    if ((D_8019BE48 & 2) && (D_8019BE30 == 4)) {
        s0v = (*(s32 * *)&D_8019BE18)[18];
        t9v = (*(s32 * *)&D_8019BE18)[19];
        t8v = (*(s32 * *)&D_8019BE18)[20];
    } else {
        s32 *p = (s32 *)(D_8019BE30 * 12 + (s32) (*(s32 * *)&D_8019BE18));  /* block-local: local-alloc ties sum into mul chain */
        s0v = p[0];
        t9v = p[1];
        t8v = p[2];
    }

    (*(Cmd_8013D53C * *)&D_8019BE24) = arg0;
    if (arg0 != 0) {
        if (D_8019BE50 != 0) {
            s32 *p = (s32 *)(D_8019BE30 * 12 + (s32) (*(s32 * *)&D_8019BE20));
            D_8019BE54 = p[0];
            D_8019BE58 = p[1];
            D_8019BE5C = p[2];
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
