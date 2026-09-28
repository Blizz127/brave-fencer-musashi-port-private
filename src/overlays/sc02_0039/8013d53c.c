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
extern s32 D_8019FA54;
extern s32 D_8019FA48;
extern s32 D_8019FA58;
extern s32 D_8019FA50;
extern s32 D_8019FA60;
extern s32 D_8019FA64;
extern u8 D_801A0D8A;
extern u8 D_801A0DFE;
extern u8 D_801A0CB2;
extern u8 D_801A0D6C;
extern u8 D_801A0C90;
extern u8 D_801A0CB1;
extern s32 D_801A0D70;
extern void *D_8019FA38;
extern void *D_8019FA40;
extern s32 D_8019FA68;
extern s32 D_8019FA70;

void func_8013D53C(void *arg0v) {

    extern Rec9 D_8017FA2C[];
    extern Rec12 D_8017FA64[];
    extern u8 D_80078EAF;
    extern u8 D_801A0D48;
    extern s32 D_8019FA5C;
    Cmd_8013D53C *arg0 = arg0v;

    extern u8 D_8017FA68[];
    extern u8 D_8017FA6C[];
    extern unsigned char D_801A0CA8;
    extern s16 *D_8019FA44;
    extern s32 D_8019FA74;
    extern s32 D_8019FA78;
    extern s32 D_8019FA7C;
    s32 s0v;
    s32 t9v;
    s32 t8v;
    u8 b0, b1, b2;
    u8 pad[8];    

    if (!(D_8019FA68 & 1)) {
        D_8019FA50 = 1;
    } else {
        D_8019FA50 = D_80078EAF;
    }

    b0 = ((u8 *)D_8017FA64)[D_8019FA50 * 12];
    D_801A0D8A = b0;
    D_801A0DFE = b0;
    b1 = D_8017FA68[D_8019FA50 * 12];
    D_801A0CB2 = b1;
    D_801A0D6C = b1;
    b2 = D_8017FA6C[D_8019FA50 * 12];
    D_801A0C90 = b2;
    D_801A0CB1 = b2;

    (*(S9 *)&D_801A0CA8) = ((S9 *)D_8017FA2C)[D_8019FA50];
    (*(S9 *)&D_801A0D48) = *(S9 *)(&D_801A0C90 + 0x18);   

    D_801A0D70 = 1;
    D_8019FA64 = -1;
    D_8019FA60 = 0;
    D_8019FA5C = -1;
    D_8019FA48 = 0;
    D_8019FA54 = 0;
    D_8019FA58 = 0;

    if ((D_8019FA68 & 2) && (D_8019FA50 == 4)) {
        s0v = (*(s32 * *)&D_8019FA38)[18];
        t9v = (*(s32 * *)&D_8019FA38)[19];
        t8v = (*(s32 * *)&D_8019FA38)[20];
    } else {
        s32 *p = (s32 *)(D_8019FA50 * 12 + (s32) (*(s32 * *)&D_8019FA38));   
        s0v = p[0];
        t9v = p[1];
        t8v = p[2];
    }

    (*(Cmd_8013D53C * *)&D_8019FA44) = arg0;
    if (arg0 != 0) {
        if (D_8019FA70 != 0) {
            s32 *p = (s32 *)(D_8019FA50 * 12 + (s32) (*(s32 * *)&D_8019FA40));
            D_8019FA74 = p[0];
            D_8019FA78 = p[1];
            D_8019FA7C = p[2];
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
