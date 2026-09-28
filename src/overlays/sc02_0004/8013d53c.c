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
extern s32 D_80195024;
extern s32 D_80195018;
extern s32 D_80195028;
extern s32 D_80195020;
extern s32 D_80195030;
extern s32 D_80195034;
extern u8 D_80196352;
extern u8 D_801963C6;
extern u8 D_8019627A;
extern u8 D_80196334;
extern u8 D_80196258;
extern u8 D_80196279;
extern s32 D_80196338;
extern void *D_80195008;
extern void *D_80195010;
extern s32 D_80195038;
extern s32 D_80195040;

void func_8013D53C(void *arg0v) {

    extern Rec9 D_8017E60C[];
    extern Rec12 D_8017E644[];
    extern u8 D_80078EAF;
    extern u8 D_80196310;
    extern s32 D_8019502C;
    Cmd_8013D53C *arg0 = arg0v;

    extern u8 D_8017E648[];
    extern u8 D_8017E64C[];
    extern unsigned char D_80196270;
    extern s16 *D_80195014;
    extern s32 D_80195044;
    extern s32 D_80195048;
    extern s32 D_8019504C;
    s32 s0v;
    s32 t9v;
    s32 t8v;
    u8 b0, b1, b2;
    u8 pad[8];    

    if (!(D_80195038 & 1)) {
        D_80195020 = 1;
    } else {
        D_80195020 = D_80078EAF;
    }

    b0 = ((u8 *)D_8017E644)[D_80195020 * 12];
    D_80196352 = b0;
    D_801963C6 = b0;
    b1 = D_8017E648[D_80195020 * 12];
    D_8019627A = b1;
    D_80196334 = b1;
    b2 = D_8017E64C[D_80195020 * 12];
    D_80196258 = b2;
    D_80196279 = b2;

    (*(S9 *)&D_80196270) = ((S9 *)D_8017E60C)[D_80195020];
    (*(S9 *)&D_80196310) = *(S9 *)(&D_80196258 + 0x18);   

    D_80196338 = 1;
    D_80195034 = -1;
    D_80195030 = 0;
    D_8019502C = -1;
    D_80195018 = 0;
    D_80195024 = 0;
    D_80195028 = 0;

    if ((D_80195038 & 2) && (D_80195020 == 4)) {
        s0v = (*(s32 * *)&D_80195008)[18];
        t9v = (*(s32 * *)&D_80195008)[19];
        t8v = (*(s32 * *)&D_80195008)[20];
    } else {
        s32 *p = (s32 *)(D_80195020 * 12 + (s32) (*(s32 * *)&D_80195008));   
        s0v = p[0];
        t9v = p[1];
        t8v = p[2];
    }

    (*(Cmd_8013D53C * *)&D_80195014) = arg0;
    if (arg0 != 0) {
        if (D_80195040 != 0) {
            s32 *p = (s32 *)(D_80195020 * 12 + (s32) (*(s32 * *)&D_80195010));
            D_80195044 = p[0];
            D_80195048 = p[1];
            D_8019504C = p[2];
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
