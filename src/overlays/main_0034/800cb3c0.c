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
".macro nclip\n"
"    cop2op 0x14, 0x06, sf = 0\n"
".endm\n"
".macro avsz4\n"
"    cop2op 0x16, 0x2E\n"
".endm\n"
);
/* func_800CB3C0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_800C7C74;
extern s32 func_800CC0A0(void *prim);
extern void func_800CC110(s32 ot, s32 otz, s32 shift, void *prim, u32 code);
typedef struct { s16 vx, vy, vz, pad; } SVEC8_800CB3C0;
typedef struct {           
      u32 unk00;
      u32 rgb;
      u16 n0;
      u16 v0;
      u16 v1;
      u16 v2;
      u16 v3;
      u16 pad12;
} FaceF4_800CB3C0;
typedef struct {           
      u32 tag;
      u32 rgb0;
      u32 xy0;
      u32 xy1;
      u32 xy2;
      u32 xy3;
} PktF4_800CB3C0;
extern u32 D_800CC9FC;

PktF4_800CB3C0 *func_800CB3C0(FaceF4_800CB3C0 *face, SVEC8_800CB3C0 *vtx,
                              SVEC8_800CB3C0 *nrm, PktF4_800CB3C0 *prims,
                              s32 count, s32 shift, s32 ot)
{
    struct { s32 flag, opz; } g;
    PktF4_800CB3C0 *pkt;

    pkt = &prims[D_800C7C74];

    for (; count != 0; count--, face++, pkt += 2) {
        __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 );" "lwc2 $2, 0( %1 );" "lwc2 $3, 4( %1 );" "lwc2 $4, 0( %2 );" "lwc2 $5, 4( %2 )" : : "r"(  &vtx[face->v0]  ), "r"(   &vtx[face->v1]  ), "r"(   &vtx[face->v2]  ) ) ;
        __asm__ volatile ("nop;nop;rtpt") ;
        __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &g.flag  ) : "$12", "memory" ) ;
        if (!(g.flag & ~0x1000)) {
            __asm__ volatile ("nop;nop;nclip") ;
            __asm__ volatile ( "swc2 $24, 0( %0 )" : : "r"(  &g.opz  ) : "memory" ) ;
            if (g.opz > 0) {
                __asm__ volatile ( "swc2 $12, 8( %0 );" "swc2 $13, 12( %0 );" "swc2 $14, 16( %0 )" : : "r"(  pkt  ) : "memory" ) ;
                __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  &vtx[face->v3]  ) ) ;
                __asm__ volatile ("nop;nop;rtps") ;
                __asm__ volatile ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &g.flag  ) : "$12", "memory" ) ;
                if (!(g.flag & ~0x1000)) {
                    __asm__ volatile ( "swc2 $14, 0( %0 )" : : "r"(  &pkt->xy3  ) : "memory" ) ;
                    __asm__ volatile ("nop;nop;avsz4") ;
                    __asm__ volatile ( "swc2 $7, 0( %0 )" : : "r"(  &g.opz  ) : "memory" ) ;
                    if (func_800CC0A0(pkt) != 0) {
                        pkt->rgb0 = D_800CC9FC;
                    } else {
                        __asm__ volatile ( "lwc2 $6, 0( %0 )" : : "r"(  &face->rgb  ) ) ;
                        __asm__ volatile ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  &nrm[face->n0]  ) ) ;
                        __asm__ volatile ("nop;nop;nccs") ;
                        __asm__ volatile ( "swc2 $22, 0( %0 )" : : "r"(  &pkt->rgb0  ) : "memory" ) ;
                    }
                    func_800CC110(ot, g.opz, shift, pkt, 0x05000000);
                }
            }
        }
    }

    return pkt;
}
