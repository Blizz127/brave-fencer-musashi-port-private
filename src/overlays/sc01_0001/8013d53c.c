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
extern s32 D_801EC788;
extern s32 D_801EC770;
extern u8 D_801F3152;
extern u8 D_801F31C6;
extern u8 D_801F307A;
extern u8 D_801F3134;
extern u8 D_801F3058;
extern u8 D_801F3079;
extern s32 D_801F3138;
extern s32 D_801EC784;
extern s32 D_801EC780;
extern s32 D_801EC768;
extern s32 D_801EC774;
extern s32 D_801EC778;
extern void *D_801EC758;
extern s32 D_801EC790;
extern void *D_801EC760;

void func_8013D53C(void *arg0v) {

    extern Rec9 D_80184188[];
    extern Rec12 D_801841C0[];
    extern u8 D_80078EAF;
    extern u8 D_801F3110;
    extern s32 D_801EC77C;
    Cmd_8013D53C *arg0 = arg0v;

    extern u8 D_801841C4[];
    extern u8 D_801841C8[];
    extern unsigned char D_801F3070;
    extern s16 *D_801EC764;
    extern s32 D_801EC794;
    extern s32 D_801EC798;
    extern s32 D_801EC79C;
    s32 s0v;
    s32 t9v;
    s32 t8v;
    u8 b0, b1, b2;
    u8 pad[8];   /* dead BLKmode local: frame 0x10 -> 0x18, zero code */

    if (!(D_801EC788 & 1)) {
        D_801EC770 = 1;
    } else {
        D_801EC770 = D_80078EAF;
    }

    b0 = ((u8 *)D_801841C0)[D_801EC770 * 12];
    D_801F3152 = b0;
    D_801F31C6 = b0;
    b1 = D_801841C4[D_801EC770 * 12];
    D_801F307A = b1;
    D_801F3134 = b1;
    b2 = D_801841C8[D_801EC770 * 12];
    D_801F3058 = b2;
    D_801F3079 = b2;

    (*(S9 *)&D_801F3070) = ((S9 *)D_80184188)[D_801EC770];
    (*(S9 *)&D_801F3110) = *(S9 *)(&D_801F3058 + 0x18);  /* same addr as (*(S9 *)&D_801F3070); distinct sym defeats cse, keeps %hi/%lo */

    D_801F3138 = 1;
    D_801EC784 = -1;
    D_801EC780 = 0;
    D_801EC77C = -1;
    D_801EC768 = 0;
    D_801EC774 = 0;
    D_801EC778 = 0;

    if ((D_801EC788 & 2) && (D_801EC770 == 4)) {
        s0v = (*(s32 * *)&D_801EC758)[18];
        t9v = (*(s32 * *)&D_801EC758)[19];
        t8v = (*(s32 * *)&D_801EC758)[20];
    } else {
        s32 *p = (s32 *)(D_801EC770 * 12 + (s32) (*(s32 * *)&D_801EC758));  /* block-local: local-alloc ties sum into mul chain */
        s0v = p[0];
        t9v = p[1];
        t8v = p[2];
    }

    (*(Cmd_8013D53C * *)&D_801EC764) = arg0;
    if (arg0 != 0) {
        if (D_801EC790 != 0) {
            s32 *p = (s32 *)(D_801EC770 * 12 + (s32) (*(s32 * *)&D_801EC760));
            D_801EC794 = p[0];
            D_801EC798 = p[1];
            D_801EC79C = p[2];
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
