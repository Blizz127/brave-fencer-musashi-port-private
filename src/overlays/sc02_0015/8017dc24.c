/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* GTE mnemonic macros, copied from vendor/bfm-decomp/include/gte_macros.inc (assembler-only, emit no code). */
__asm__(
".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
"    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
".endm\n"
".macro rtpt\n"
"    cop2op 0x02, 0x30\n"
".endm\n"
);
/* func_8017DC24 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef void (*code)(unsigned short *);
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_8012EF34(s32 a0, s32 a1);
extern void func_80017D98(void *a0);
extern void func_8001739C(void *a0);
typedef struct {
    s16 x;       
    s16 y;       
    s16 c;       
    s16 pad;     
} Vtx_8017DC24;
typedef struct {
    Vtx_8017DC24 v[3];               
    u8 r0, g0, b0, code;             
    u8 r1, g1, b1, pad1;             
    u8 r2, g2, b2, pad2;             
    u32 color;                       
} Prim_8017DC24;
typedef struct {
    u16 x;       
    u16 y;       
    u16 z;       
} Pos_8017DC24;
typedef struct {
    u16 vx;      
    u16 vy;      
    u16 vz;      
    u16 pad;     
} Sxy_8017DC24;
typedef struct {
    s16 m[3][3];                     
    s32 t[3];                        
} Mtx_8017DC24;
extern u16 D_80181D9C[];
extern s16 D_80181DA0;
extern u16 D_80181DA4[];
extern s16 D_80181DA8;
extern u16 D_80181DAC[];
extern s16 D_80181DB0;

void func_8017DC24(s32 arg0)
{
    Prim_8017DC24 prim;              
    Pos_8017DC24 wpos;               
    Pos_8017DC24 spos;               
    Sxy_8017DC24 sxy[4];             
    Mtx_8017DC24 mtx;                
    s32 otz;                         
    s32 flag;                        
    s32 t;

    func_80015978(arg0 + 4, (s32 *)&wpos);
    if ((func_8012EF34((s32)&wpos, (s32)&spos) & ~0x1000) == 0) {
        __asm__ volatile ( "mfc2 $12, $19;" "nop;" "sra $12, $12, 2;" "sw $12, 0( %0 )" : : "r"(  &otz  ) : "$12", "memory" ) ;
        D_80181DA0 = spos.z;
        D_80181DA8 = spos.z;
        D_80181DB0 = spos.z;
        func_80017D98(&mtx);
         
        mtx.t[2] = 0;
        mtx.t[1] = 0;
        mtx.t[0] = 0;
        __asm__ volatile ( "lw $12, 0( %0 );" "lw $13, 4( %0 );" "ctc2 $12, $0;" "ctc2 $13, $1;" "lw $12, 8( %0 );" "lw $13, 12( %0 );" "lw $14, 16( %0 );" "ctc2 $12, $2;" "ctc2 $13, $3;" "ctc2 $14, $4" : : "r"(  &mtx  ) : "$12", "$13", "$14" ) ;
        __asm__ volatile ( "lw $12, 20( %0 );" "lw $13, 24( %0 );" "ctc2 $12, $5;" "lw $14, 28( %0 );" "ctc2 $13, $6;" "ctc2 $14, $7" : : "r"(  &mtx  ) : "$12", "$13", "$14" ) ;
        __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );" "lwc2 $2, 0( %1 );" "lwc2 $3, 4( %1 );" "lwc2 $4, 0( %2 );" "lwc2 $5, 4( %2 )" : : "r"(  D_80181D9C  ), "r"(   D_80181DA4  ), "r"(   D_80181DAC  ) ) ;
        __asm__ volatile ("nop;nop;rtpt") ;
        __asm__ volatile ( "swc2 $12, 0( %0 );" "swc2 $13, 0( %1 );" "swc2 $14, 0( %2 )" : : "r"(  &sxy[0]  ), "r"(   &sxy[1]  ), "r"(   &sxy[2]  ) : "memory" ) ;
        __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &flag  ) : "$12", "memory" ) ;
        if (flag >= 0) {
            prim.b0 = 0xC0;
            prim.g0 = 0xC0;
            prim.r0 = 0xC0;
            prim.b1 = 0x40;
            prim.g1 = 0x20;
            prim.r1 = 0x20;
            prim.b2 = 0x40;
            prim.g2 = 0x20;
            prim.r2 = 0x20;
            prim.color = 0x50000000;
            prim.v[0].x = sxy[0].vx + spos.x;
            prim.v[0].y = sxy[0].vy + spos.y;
            prim.v[1].x = sxy[1].vx + spos.x;
            prim.v[1].y = sxy[1].vy + spos.y;
            prim.v[2].x = sxy[2].vx + spos.x;
            prim.v[2].y = sxy[2].vy + spos.y;
            prim.v[0].c = otz;
            func_8001739C(&prim);
            t = sxy[1].vy;
            prim.v[1].y = spos.y - t;
            func_8001739C(&prim);
            t = sxy[2].vx;
            prim.v[2].x = spos.x - t;
            func_8001739C(&prim);
            prim.v[1].y = sxy[1].vy + spos.y;
            func_8001739C(&prim);
        }
    }
}
