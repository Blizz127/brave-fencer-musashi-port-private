/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801372B0 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ApplyMatrixSV func_80048FBC
#define GsSortLine func_80051DC8
typedef struct { s16 vx, vy, vz, pad; } Svec_801372B0;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef void (*code)(unsigned short *);
extern u8 D_800B9A11;
extern u8 D_800AF630[];
extern u8 D_800A6518[];
void func_80137178(s32 a0, s32 a1);
extern void ApplyMatrixSV(void *m, Svec_801372B0 *in, Svec_801372B0 *out);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern void func_80137178(s32 x, s32 y);
extern u8  D_800B9A11;
extern u8  D_800AF630[];
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern u8  D_800A6518[];

void func_801372B0(void) {
    Svec_801372B0 in;
    Svec_801372B0 out;
    Gline_801372B0 prim;
    register u8 *mat __asm__("$23") = D_800AF630;             
    register s32 white __asm__("$19");                        
    register s16 ax __asm__("$16");                           
    register s16 ay __asm__("$17");                           
    register s16 bx __asm__("$18");                           
    register s16 by __asm__("$20");                           
    in.vz = 0;
    in.vy = 0;
    in.vx = 0;
    if (D_800B9A11 != 1) {
        mat += 0x18;                                          
        white = 0xFF;
         
        in.vx = 0x10;
        ApplyMatrixSV(mat, &in, &out);
        {
            register s16 vx __asm__("$7") = out.vx;           
            register s16 vy __asm__("$3") = out.vy;           
            prim.attr = 0;                                    
            prim.r = white; prim.g = white; prim.b = white;   
            prim.x0 = 0x78;                                   
            prim.y0 = -0x5A;                                  
            { s16 x1v = vx + 0x78; __asm__("" : "=r"(x1v) : "0"(x1v)); prim.x1 = x1v; }
            { s16 y1v = vy - 0x5A; __asm__("" : "=r"(y1v) : "0"(y1v)); prim.y1 = y1v; }
            aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        }
         
        in.vx = in.vx + 6;
        ApplyMatrixSV(mat, &in, &out);
        prim.attr = 0;
        prim.r = white; prim.g = 0; prim.b = 0;
        bx = out.vy;                                          
        ay = out.vx;                                          
        by = bx - 0x5D;                                       
        ax = ay + 0x7B;                                       
        bx = bx - 0x57;                                       
        {
        Gline_801372B0 *op = (Gline_801372B0*)&D_800A6518[(u32)aD800B9A02 * 0x14];
        __asm__("" : "=r"(op) : "0"(op));
        ay = ay + 0x75;                                       
        prim.x0 = ay; prim.y0 = by; prim.x1 = ax; prim.y1 = bx;
        aGsSortLine(&prim, op, 0);
        }
        __asm__("" : "=r"(ax) : "0"(ax));                     
        __asm__("" : "=r"(by) : "0"(by));                     
        prim.attr = 0;                                        
        prim.r = white; prim.g = 0; prim.b = 0;
        prim.x0 = ax; prim.y0 = by; prim.x1 = ay; prim.y1 = bx;
        aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
         
        in.vx = 0;
        in.vy = 0x10;
        ApplyMatrixSV(mat, &in, &out);
        {
            register s16 vx __asm__("$7") = out.vx;           
            register s16 vy __asm__("$2") = out.vy;           
            prim.x0 = 0x78;
            prim.attr = 0;
            prim.r = white; prim.g = white; prim.b = white;
            prim.y0 = -0x5A;
            { s16 x1v = vx + 0x78; __asm__("" : "=r"(x1v) : "0"(x1v)); prim.x1 = x1v; }
            { s16 y1v = vy - 0x5A; __asm__("" : "=r"(y1v) : "0"(y1v)); prim.y1 = y1v; }
            aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        }
        in.vy = in.vy + 6;
        ApplyMatrixSV(mat, &in, &out);
        aF80137030((s32)(s16)(out.vx + 0x78), (s32)(s16)(out.vy - 0x5A));
         
        in.vy = 0;
        in.vz = 0x10;
        ApplyMatrixSV(mat, &in, &out);
        {
            register s16 vx __asm__("$7") = out.vx;           
            register s16 vy __asm__("$2") = out.vy;           
            prim.x0 = 0x78;
            prim.attr = 0;
            prim.r = white; prim.g = white; prim.b = white;
            prim.y0 = -0x5A;
            { s16 x1v = vx + 0x78; __asm__("" : "=r"(x1v) : "0"(x1v)); prim.x1 = x1v; }
            { s16 y1v = vy - 0x5A; __asm__("" : "=r"(y1v) : "0"(y1v)); prim.y1 = y1v; }
            aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        }
        in.vz = in.vz + 6;
        ApplyMatrixSV(mat, &in, &out);
        func_80137178((s32)(s16)(out.vx + 0x78), (s32)(s16)(out.vy - 0x5A));
    }
    return;
}
