/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* GTE mnemonic macros, copied from vendor/bfm-decomp/include/gte_macros.inc (assembler-only, emit no code). */
__asm__(
".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
"    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
".endm\n"
".macro rtps\n"
"    cop2op 0x01, 0x01\n"
".endm\n"
".macro rtpt\n"
"    cop2op 0x02, 0x30\n"
".endm\n"
".macro nccs\n"
"    cop2op 0x10, 0x1B, lm = 1\n"
".endm\n"
".macro ncct\n"
"    cop2op 0x11, 0x3F, lm = 1\n"
".endm\n"
".macro nclip\n"
"    cop2op 0x14, 0x06, sf = 0\n"
".endm\n"
".macro avsz4\n"
"    cop2op 0x16, 0x2E\n"
".endm\n"
);
/* func_800CBE28 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800C7C74;
extern s32 func_800CC0A0(void *prim);
extern void func_800CC110(s32 ot, s32 otz, s32 shift, void *prim, u32 code);
typedef struct { s16 vx, vy, vz, pad; } SVEC8_800CBE28;
typedef struct {                                         
    u32 unk00;
    u32 uv0;
    u32 uv1;
    u32 uv2;
    u32 uv3;
    u16 n0, v0;       
    u16 n1, v1;       
    u16 n2, v2;       
    u16 n3, v3;       
} FaceGT4_800CBE28;
typedef struct {                                         
    u32 tag;
    u32 rgb0, xy0, uv0;    
    u32 rgb1, xy1, uv1;    
    u32 rgb2, xy2, uv2;    
    u32 rgb3, xy3, uv3;    
} PktGT4_800CBE28;
extern u32 D_80063888;
extern u32 D_800CCA14;
extern s32 func_800CC0A0(void *pkt);

PktGT4_800CBE28 *func_800CBE28(FaceGT4_800CBE28 *face, SVEC8_800CBE28 *vtx,
                               SVEC8_800CBE28 *nrm, PktGT4_800CBE28 *arg3,
                               s32 count, s32 shift, s32 ot)
{
    long flag;
    long otz;
    PktGT4_800CBE28 *pkt;

    pkt = &arg3[D_800C7C74];

    __asm__ volatile ( "lwc2 $6, 0( %0 )" : : "r"(  &D_80063888  ) ) ;

    while (count != 0) {
        __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );" "lwc2 $2, 0( %1 );" "lwc2 $3, 4( %1 );" "lwc2 $4, 0( %2 );" "lwc2 $5, 4( %2 )" : : "r"(  &vtx[face->v0]  ), "r"(   &vtx[face->v1]  ), "r"(   &vtx[face->v2]  ) ) ;
        __asm__ volatile ("nop;nop;rtpt") ;
        __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &flag  ) : "$12", "memory" ) ;
        if (!(flag & ~0x1000)) {
            __asm__ volatile ("nop;nop;nclip") ;
            __asm__ volatile ( "swc2 $24, 0( %0 )" : : "r"(  &otz  ) : "memory" ) ;
            if (otz > 0) {
                __asm__ volatile ( "swc2 $12, 8( %0 );" "swc2 $13, 20( %0 );" "swc2 $14, 32( %0 )" : : "r"(  pkt  ) : "memory" ) ;
                __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  &vtx[face->v3]  ) ) ;
                __asm__ volatile ("nop;nop;rtps") ;
                __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &flag  ) : "$12", "memory" ) ;
                if (!(flag & ~0x1000)) {
                    __asm__ volatile ( "swc2 $14, 0( %0 )" : : "r"(  &pkt->xy3  ) : "memory" ) ;
                    __asm__ volatile ("nop;nop;avsz4") ;
                    __asm__ volatile ( "swc2 $7, 0( %0 )" : : "r"(  &otz  ) : "memory" ) ;
                    if (func_800CC0A0(pkt) != 0) {
                        pkt->rgb0 = D_800CCA14;
                        pkt->rgb1 = D_800CCA14;
                        pkt->rgb2 = D_800CCA14;
                        pkt->rgb3 = D_800CCA14;
                    } else {
                        __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );" "lwc2 $2, 0( %1 );" "lwc2 $3, 4( %1 );" "lwc2 $4, 0( %2 );" "lwc2 $5, 4( %2 )" : : "r"(  &nrm[face->n0]  ), "r"(   &nrm[face->n0]  ), "r"(   &nrm[face->n0]  ) ) ;
                        __asm__ volatile ("nop;nop;ncct") ;
                        __asm__ volatile ( "swc2 $20, 0( %0 );" "swc2 $21, 0( %1 );" "swc2 $22, 0( %2 )" : : "r"(  &pkt->rgb0  ), "r"(   &pkt->rgb1  ), "r"(   &pkt->rgb2  ) : "memory" ) ;
                        __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  &nrm[face->n0]  ) ) ;
                        __asm__ volatile ("nop;nop;nccs") ;
                        __asm__ volatile ( "swc2 $22, 0( %0 )" : : "r"(  &pkt->rgb3  ) : "memory" ) ;
                    }
                    func_800CC110(ot, otz, shift, (void *)pkt, 0x0C000000);
                }
            }
        }
        count--;
        face++;
        pkt += 2;
    }
    return pkt;
}
