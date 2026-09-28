/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E024 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixZ func_8004A27C
extern s32 D_80126B58;
extern u8 D_80126B5C;
struct Mtx_8017E024  { s16 m[3][3]; s32 t[3]; };
struct SVec_8017E024 { s16 vx, vy, vz, pad; };
struct Vec_8017E024  { s32 vx, vy, vz, pad; };
extern void RotMatrixZ(s32 a0, void *a1);
extern void func_8012F0BC(s32 *a0, s32 *a1, s32 *a2);
extern void func_8012F1A4(s32 *a0, s32 a1, s32 *a2);
extern void func_80132784(s32 a0, s32 a1, u32 a2);
extern u8  D_80126B5C;
extern s32 D_80126B60;
extern s32 D_80126B64;
extern u8  D_8019F93C[];
extern s16 D_8019B584;

void func_8017E024(s32 a0)
{
     



    struct Vec_8017E024  unused;    
    struct SVec_8017E024 sv;        
    struct Vec_8017E024  vin;       
    struct Vec_8017E024  vout;      
    struct Vec_8017E024  res;       
    struct Mtx_8017E024  m;         
    s32 flag;                       
    s32 *g;
    s32 owner;

     

    m = *(struct Mtx_8017E024 *)(*(s32 *)(*(s32 *)(a0 + 0x64) + 0x20) + 0x34);
    g = &D_80126B58;

    if (*(u16 *)(a0 + 0xFE) < 2) {
         


        sv = *(struct SVec_8017E024 *)D_8019F93C;
        RotMatrixZ(*(s16 *)(a0 + 0x100), &m);
        __asm__ __volatile__ ( "lw $12, 0( %0 );" "lw $13, 4( %0 );" "ctc2 $12, $0;" "ctc2 $13, $1;" "lw $12, 8( %0 );" "lw $13, 12( %0 );" "lw $14, 16( %0 );" "ctc2 $12, $2;" "ctc2 $13, $3;" "ctc2 $14, $4" : : "r"(  &m  ) : "$12", "$13", "$14" ) ;
        __asm__ __volatile__ ( "lw $12, 20( %0 );" "lw $13, 24( %0 );" "ctc2 $12, $5;" "lw $14, 28( %0 );" "ctc2 $13, $6;" "ctc2 $14, $7" : : "r"(  &m  ) : "$12", "$13", "$14" ) ;
        __asm__ __volatile__ ( "lwc2 $0, 0( %0 );" "lwc2 $1, 4( %0 )" : : "r"(  &sv  ) ) ;
        __asm__ __volatile__ ("nop;nop;.word 0x4A480012") ;
        __asm__ __volatile__ ( "swc2 $25, 0( %0 );" "swc2 $26, 4( %0 );" "swc2 $27, 8( %0 )" : : "r"(  &vout  ) : "memory" ) ;
        __asm__ __volatile__ ( "cfc2 $12, $31;" "nop;" "sw $12, 0( %0 )" : : "r"(  &flag  ) : "$12", "memory" ) ;
        *(s16 *)(a0 + 0x6) = vout.vx;
        *(s16 *)(a0 + 0xA) = vout.vy;
        *(s16 *)(a0 + 0xE) = vout.vz;
    } else {
        if (*(u8 *)(a0 + 0x74)) {
            vin.vx = *(s32 *)&D_80126B5C;    
            vin.vy = D_80126B60;
            vin.vz = D_80126B64;
            func_8012F0BC((s32 *)(*(s32 *)(a0 + 0x20) + 0x34), (s32 *)&vin, (s32 *)&res);
            if (*(u8 *)(a0 + 0x102) == 0) {
                owner = *(s32 *)(a0 + 0x64);
                *(s32 *)(owner + 0xE0) += res.vx >> 2;
            }
        }
        func_80132784(a0, *(s32 *)(a0 + 0x64), 0);
        if (*(u8 *)(a0 + 0x74)) {
            res.vy = (D_8019B584 - 1) << 16;
            func_8012F1A4((s32 *)(*(s32 *)(a0 + 0x20) + 0x34), (s32)&res, (s32 *)&vout);
            g[1] = vout.vx;
            g[2] = vout.vy;
            g[3] = vout.vz;
        }
    }
}
