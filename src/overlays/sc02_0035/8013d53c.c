/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013D53C - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { s32 a, b, c; } Rec12;
typedef struct { s32 a, b; s8 c; } __attribute__((packed, aligned(1))) Rec9;
typedef struct { u8 b[9]; } S9;
typedef struct {
    u16 cmd;         
    u16 pad2;        
    u16 pad4;        
    u16 pad6;        
    s16 w;           
    s16 h;           
    u16 *data;       
} Cmd_8013D53C;
extern s32 D_801BD6A4;
extern s32 D_801BD698;
extern s32 D_801BD6A8;
extern s32 D_801BD6A0;
extern s32 D_801BD6B0;
extern s32 D_801BD6B4;
extern u8 D_801BE9D2;
extern u8 D_801BEA46;
extern u8 D_801BE8FA;
extern u8 D_801BE9B4;
extern u8 D_801BE8D8;
extern u8 D_801BE8F9;
extern s32 D_801BE9B8;
extern void *D_801BD688;
extern void *D_801BD690;
extern s32 D_801BD6B8;
extern s32 D_801BD6C0;

void func_8013D53C(void *arg0v) {

    extern Rec9 D_80184E00[];
    extern Rec12 D_80184E38[];
    extern u8 D_80078EAF;
    extern u8 D_801BE990;
    extern s32 D_801BD6AC;
    Cmd_8013D53C *arg0 = arg0v;

    extern u8 D_80184E3C[];
    extern u8 D_80184E40[];
    extern unsigned char D_801BE8F0;
    extern s16 *D_801BD694;
    extern s32 D_801BD6C4;
    extern s32 D_801BD6C8;
    extern s32 D_801BD6CC;
    s32 s0v;
    s32 t9v;
    s32 t8v;
    u8 b0, b1, b2;
    u8 pad[8];    

    if (!(D_801BD6B8 & 1)) {
        D_801BD6A0 = 1;
    } else {
        D_801BD6A0 = D_80078EAF;
    }

    b0 = ((u8 *)D_80184E38)[D_801BD6A0 * 12];
    D_801BE9D2 = b0;
    D_801BEA46 = b0;
    b1 = D_80184E3C[D_801BD6A0 * 12];
    D_801BE8FA = b1;
    D_801BE9B4 = b1;
    b2 = D_80184E40[D_801BD6A0 * 12];
    D_801BE8D8 = b2;
    D_801BE8F9 = b2;

    (*(S9 *)&D_801BE8F0) = ((S9 *)D_80184E00)[D_801BD6A0];
    (*(S9 *)&D_801BE990) = *(S9 *)(&D_801BE8D8 + 0x18);   

    D_801BE9B8 = 1;
    D_801BD6B4 = -1;
    D_801BD6B0 = 0;
    D_801BD6AC = -1;
    D_801BD698 = 0;
    D_801BD6A4 = 0;
    D_801BD6A8 = 0;

    if ((D_801BD6B8 & 2) && (D_801BD6A0 == 4)) {
        s0v = (*(s32 * *)&D_801BD688)[18];
        t9v = (*(s32 * *)&D_801BD688)[19];
        t8v = (*(s32 * *)&D_801BD688)[20];
    } else {
        s32 *p = (s32 *)(D_801BD6A0 * 12 + (s32) (*(s32 * *)&D_801BD688));   
        s0v = p[0];
        t9v = p[1];
        t8v = p[2];
    }

    (*(Cmd_8013D53C * *)&D_801BD694) = arg0;
    if (arg0 != 0) {
        if (D_801BD6C0 != 0) {
            s32 *p = (s32 *)(D_801BD6A0 * 12 + (s32) (*(s32 * *)&D_801BD690));
            D_801BD6C4 = p[0];
            D_801BD6C8 = p[1];
            D_801BD6CC = p[2];
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
                    __asm__("" :: "r"(src));   
                    dst = src + n;
                    if (n > 0) {
                        do {
                            u16 px;
                            s32 r, g, b, out;
                            __asm__("" :: "r"(i));   
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
