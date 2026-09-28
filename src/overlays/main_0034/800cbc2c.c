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
".macro ncct\n"
"    cop2op 0x11, 0x3F, lm = 1\n"
".endm\n"
".macro nclip\n"
"    cop2op 0x14, 0x06, sf = 0\n"
".endm\n"
".macro avsz3\n"
"    cop2op 0x15, 0x2D\n"
".endm\n"
);
/* func_800CBC2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800C7C74;
extern s32 func_800CC0A0(void *prim);
extern void func_800CC110(s32 ot, s32 otz, s32 shift, void *prim, u32 code);
typedef struct { s16 vx, vy, vz, pad; } SVEC2;
typedef struct {                                      
    u32 w0;       
    u32 w1;       
    u32 w2;       
    u32 w3;       
    u16 n0;       
    u16 v0;       
    u16 n1;       
    u16 v1;       
    u16 n2;       
    u16 v2;       
} FaceT3;
typedef struct {                                      
    u32 tag;      
    u32 rgb0;     
    s16 x0, y0;   
    u16 u0, cl;   
    u32 rgb1;     
    s16 x1, y1;   
    u16 u1, tp;   
    u32 rgb2;     
    s16 x2, y2;   
    u16 u2, pd;   
} GT3P;
extern u32 D_80063884;
extern u32 D_800CCA10;

GT3P *func_800CBC2C(FaceT3 *f, SVEC2 *verts, SVEC2 *norms, GT3P *prims,
                    s32 count, s32 shift, s32 ot)
{
    struct { s32 flag, opz; } g;
    GT3P *prim;

    prim = &prims[D_800C7C74];
    __asm__ volatile ( "lwc2 $6, 0( %0 )" : : "r"(  &D_80063884  ) ) ;

    for (; count != 0; count--, f++, prim += 2) {
        __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );" "lwc2 $2, 0( %1 );" "lwc2 $3, 4( %1 );" "lwc2 $4, 0( %2 );" "lwc2 $5, 4( %2 )" : : "r"(  &verts[f->v0]  ), "r"(   &verts[f->v1]  ), "r"(   &verts[f->v2]  ) ) ;
        __asm__ volatile ("nop;nop;rtpt") ;
        __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &g.flag  ) : "$12", "memory" ) ;
        if (!(g.flag & ~0x1000)) {
            __asm__ volatile ("nop;nop;nclip") ;
            __asm__ volatile ( "swc2 $24, 0( %0 )" : : "r"(  &g.opz  ) : "memory" ) ;
            if (g.opz > 0) {
                __asm__ volatile ( "swc2 $12, 8( %0 );" "swc2 $13, 20( %0 );" "swc2 $14, 32( %0 )" : : "r"(  prim  ) : "memory" ) ;
                __asm__ volatile ("nop;nop;avsz3") ;
                __asm__ volatile ( "swc2 $7, 0( %0 )" : : "r"(  &g.opz  ) : "memory" ) ;
                if (func_800CC0A0(prim) != 0) {
                    prim->rgb0 = D_800CCA10;
                    prim->rgb1 = D_800CCA10;
                    prim->rgb2 = D_800CCA10;
                } else {
                    __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );" "lwc2 $2, 0( %1 );" "lwc2 $3, 4( %1 );" "lwc2 $4, 0( %2 );" "lwc2 $5, 4( %2 )" : : "r"(  &norms[f->n0]  ), "r"(   &norms[f->n0]  ), "r"(   &norms[f->n0]  ) ) ;
                    __asm__ volatile ("nop;nop;ncct") ;
                    __asm__ volatile ( "swc2 $20, 0( %0 );" "swc2 $21, 0( %1 );" "swc2 $22, 0( %2 )" : : "r"(  &prim->rgb0  ), "r"(   &prim->rgb1  ), "r"(   &prim->rgb2  ) : "memory" ) ;
                }
                func_800CC110(ot, g.opz, shift, prim, 0x09000000);
            }
        }
    }

    return prim;
}
