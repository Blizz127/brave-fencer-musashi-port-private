/* Overlay range [8013D53C,8013D8FC) from MAIN.CD member 0012.
 * SHA256(span)=cef3d4e62ca66287aba0150c94b3e7fb9a57c786b1f150f0e5428a754d65fb3b.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013D53C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

/* File-scope declarations from the vendor translation unit. */
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

   /* 9-byte, align-1 -> unaligned block copy */








void func_8013D53C(void *arg0v) {

    extern Rec9 D_8017ECB0[];
    extern Rec12 D_8017ECE8[];
    extern s32 D_801841D0;
    extern u8 D_80078EAF;
    extern s32 D_801841B8;
    extern u8 D_80185C0A;
    extern u8 D_80185C7E;
    extern u8 D_80185B32;
    extern u8 D_80185BEC;
    extern u8 D_80185B10;
    extern u8 D_80185B31;
    extern u8 D_80185BC8;
    extern s32 D_80185BF0;
    extern s32 D_801841CC;
    extern s32 D_801841C8;
    extern s32 D_801841C4;
    extern s32 D_801841B0;
    extern s32 D_801841BC;
    extern s32 D_801841C0;
    extern void *D_801841A0;
    extern s32 D_801841D8;
    extern void *D_801841A8;
    Cmd_8013D53C *arg0 = arg0v;

    extern u8 D_8017ECEC[];
    extern u8 D_8017ECF0[];
    extern unsigned char D_80185B28;
    extern s16 *D_801841AC;
    extern s32 D_801841DC;
    extern s32 D_801841E0;
    extern s32 D_801841E4;
    s32 s0v;
    s32 t9v;
    s32 t8v;
    u8 b0, b1, b2;
    u8 pad[8];   /* dead BLKmode local: frame 0x10 -> 0x18, zero code */

    if (!(D_801841D0 & 1)) {
        D_801841B8 = 1;
    } else {
        D_801841B8 = D_80078EAF;
    }

    b0 = ((u8 *)D_8017ECE8)[D_801841B8 * 12];
    D_80185C0A = b0;
    D_80185C7E = b0;
    b1 = D_8017ECEC[D_801841B8 * 12];
    D_80185B32 = b1;
    D_80185BEC = b1;
    b2 = D_8017ECF0[D_801841B8 * 12];
    D_80185B10 = b2;
    D_80185B31 = b2;

    (*(S9 *)&D_80185B28) = ((S9 *)D_8017ECB0)[D_801841B8];
    (*(S9 *)&D_80185BC8) = *(S9 *)(&D_80185B10 + 0x18);  /* same addr as (*(S9 *)&D_80185B28); distinct sym defeats cse, keeps %hi/%lo */

    D_80185BF0 = 1;
    D_801841CC = -1;
    D_801841C8 = 0;
    D_801841C4 = -1;
    D_801841B0 = 0;
    D_801841BC = 0;
    D_801841C0 = 0;

    if ((D_801841D0 & 2) && (D_801841B8 == 4)) {
        s0v = (*(s32 * *)&D_801841A0)[18];
        t9v = (*(s32 * *)&D_801841A0)[19];
        t8v = (*(s32 * *)&D_801841A0)[20];
    } else {
        s32 *p = (s32 *)(D_801841B8 * 12 + (s32) (*(s32 * *)&D_801841A0));  /* block-local: local-alloc ties sum into mul chain */
        s0v = p[0];
        t9v = p[1];
        t8v = p[2];
    }

    (*(Cmd_8013D53C * *)&D_801841AC) = arg0;
    if (arg0 != 0) {
        if (D_801841D8 != 0) {
            s32 *p = (s32 *)(D_801841B8 * 12 + (s32) (*(s32 * *)&D_801841A8));
            D_801841DC = p[0];
            D_801841E0 = p[1];
            D_801841E4 = p[2];
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
