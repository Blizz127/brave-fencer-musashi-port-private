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
extern s32 D_8018F0FC;
extern s32 D_8018F0F0;
extern s32 D_8018F100;
extern s32 D_8018F0F8;
extern s32 D_8018F108;
extern s32 D_8018F10C;
extern u8 D_8019062A;
extern u8 D_8019069E;
extern u8 D_80190552;
extern u8 D_8019060C;
extern u8 D_80190530;
extern u8 D_80190551;
extern s32 D_80190610;
extern void *D_8018F0E0;
extern void *D_8018F0E8;
extern s32 D_8018F110;
extern s32 D_8018F118;

void func_8013D53C(void *arg0v) {

    extern Rec9 D_8017EB74[];
    extern Rec12 D_8017EBAC[];
    extern u8 D_80078EAF;
    extern u8 D_801905E8;
    extern s32 D_8018F104;
    Cmd_8013D53C *arg0 = arg0v;

    extern u8 D_8017EBB0[];
    extern u8 D_8017EBB4[];
    extern unsigned char D_80190548;
    extern s16 *D_8018F0EC;
    extern s32 D_8018F11C;
    extern s32 D_8018F120;
    extern s32 D_8018F124;
    s32 s0v;
    s32 t9v;
    s32 t8v;
    u8 b0, b1, b2;
    u8 pad[8];    

    if (!(D_8018F110 & 1)) {
        D_8018F0F8 = 1;
    } else {
        D_8018F0F8 = D_80078EAF;
    }

    b0 = ((u8 *)D_8017EBAC)[D_8018F0F8 * 12];
    D_8019062A = b0;
    D_8019069E = b0;
    b1 = D_8017EBB0[D_8018F0F8 * 12];
    D_80190552 = b1;
    D_8019060C = b1;
    b2 = D_8017EBB4[D_8018F0F8 * 12];
    D_80190530 = b2;
    D_80190551 = b2;

    (*(S9 *)&D_80190548) = ((S9 *)D_8017EB74)[D_8018F0F8];
    (*(S9 *)&D_801905E8) = *(S9 *)(&D_80190530 + 0x18);   

    D_80190610 = 1;
    D_8018F10C = -1;
    D_8018F108 = 0;
    D_8018F104 = -1;
    D_8018F0F0 = 0;
    D_8018F0FC = 0;
    D_8018F100 = 0;

    if ((D_8018F110 & 2) && (D_8018F0F8 == 4)) {
        s0v = (*(s32 * *)&D_8018F0E0)[18];
        t9v = (*(s32 * *)&D_8018F0E0)[19];
        t8v = (*(s32 * *)&D_8018F0E0)[20];
    } else {
        s32 *p = (s32 *)(D_8018F0F8 * 12 + (s32) (*(s32 * *)&D_8018F0E0));   
        s0v = p[0];
        t9v = p[1];
        t8v = p[2];
    }

    (*(Cmd_8013D53C * *)&D_8018F0EC) = arg0;
    if (arg0 != 0) {
        if (D_8018F118 != 0) {
            s32 *p = (s32 *)(D_8018F0F8 * 12 + (s32) (*(s32 * *)&D_8018F0E8));
            D_8018F11C = p[0];
            D_8018F120 = p[1];
            D_8018F124 = p[2];
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
