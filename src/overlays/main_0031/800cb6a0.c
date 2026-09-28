/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* GTE mnemonic macros, copied from vendor/bfm-decomp/include/gte_macros.inc (assembler-only, emit no code). */
__asm__(
".macro cop2op fake_op, op, gbg = 0, sf = 1, mx = 0, v = 0, cv = 0, lm = 0\n"
"    cop2 \\fake_op << 20 | \\gbg << 20 | \\sf << 19 | \\mx << 17 | \\v << 15 | \\cv << 13 | \\lm << 10 | \\op\n"
".endm\n"
".macro mvmva sf, mx, v, cv, lm\n"
"    cop2op 0x04, 0x12, sf = \\sf, mx = \\mx, v = \\v, cv = \\cv, lm = \\lm\n"
".endm\n"
);
/* func_800CB6A0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80017DC4(void *a0, void *a1);
extern void func_80016ED4(void *a0);
extern u16 D_800CBFFC[];
extern u16 D_800CBFF8[];

void func_800CB6A0(void *a0, void *a1, void *a2, s32 a3) {
    s16 mat[4][4];
    u16 vin[3];
    u16 vec[4][4];
    u16 tc[8];
    u8 tail[10];
    register u16 *o0 __asm__("$4");
    u16 *tp;
    s32 idx;
    u16 w;

    idx = a3;
    tp = (u16 *)D_800CBFFC + idx * 4;
    func_80017DC4(a2, mat);
    o0 = &vec[0][0];

    vin[2] = 0;
    vin[0] = *(u16 *)((u8 *)a1 + 0) - 0x30;
    vin[1] = *(u16 *)((u8 *)a1 + 2) - 0x20;
    __asm__ __volatile__( "lw $12, 0(%0)\n" "lw $13, 4(%0)\n" "ctc2 $12, $0\n" "ctc2 $13, $1\n" "lw $12, 8(%0)\n" "lw $13, 12(%0)\n" "lw $14, 16(%0)\n" "ctc2 $12, $2\n" "ctc2 $13, $3\n" "ctc2 $14, $4\n" : : "r"( mat ) : "$12", "$13", "$14", "memory") ;
    __asm__ __volatile__( "lwc2 $0, 0(%0)\n" "lwc2 $1, 4(%0)\n" : : "r"( vin ) : "memory") ;
    __asm__ __volatile__( "nop\n" "nop\n" "mvmva 1, 0, 0, 3, 0\n" : : : "memory") ;
    __asm__ __volatile__( "mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n" "sh $12, 0(%0)\n" "sh $13, 2(%0)\n" "sh $14, 4(%0)\n" : : "r"( o0 ) : "$12", "$13", "$14", "memory") ;

    vin[0] = *(u16 *)((u8 *)a1 + 0) + 0x30;
    vin[1] = *(u16 *)((u8 *)a1 + 2) - 0x20;
    __asm__ __volatile__( "lw $12, 0(%0)\n" "lw $13, 4(%0)\n" "ctc2 $12, $0\n" "ctc2 $13, $1\n" "lw $12, 8(%0)\n" "lw $13, 12(%0)\n" "lw $14, 16(%0)\n" "ctc2 $12, $2\n" "ctc2 $13, $3\n" "ctc2 $14, $4\n" : : "r"( mat ) : "$12", "$13", "$14", "memory") ;
    __asm__ __volatile__( "lwc2 $0, 0(%0)\n" "lwc2 $1, 4(%0)\n" : : "r"( vin ) : "memory") ;
    __asm__ __volatile__( "nop\n" "nop\n" "mvmva 1, 0, 0, 3, 0\n" : : : "memory") ;
    __asm__ __volatile__( "mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n" "sh $12, 0(%0)\n" "sh $13, 2(%0)\n" "sh $14, 4(%0)\n" : : "r"( vec[1] ) : "$12", "$13", "$14", "memory") ;

    vin[0] = *(u16 *)((u8 *)a1 + 0) - 0x30;
    vin[1] = *(u16 *)((u8 *)a1 + 2) + 0x20;
    __asm__ __volatile__( "lw $12, 0(%0)\n" "lw $13, 4(%0)\n" "ctc2 $12, $0\n" "ctc2 $13, $1\n" "lw $12, 8(%0)\n" "lw $13, 12(%0)\n" "lw $14, 16(%0)\n" "ctc2 $12, $2\n" "ctc2 $13, $3\n" "ctc2 $14, $4\n" : : "r"( mat ) : "$12", "$13", "$14", "memory") ;
    __asm__ __volatile__( "lwc2 $0, 0(%0)\n" "lwc2 $1, 4(%0)\n" : : "r"( vin ) : "memory") ;
    __asm__ __volatile__( "nop\n" "nop\n" "mvmva 1, 0, 0, 3, 0\n" : : : "memory") ;
    __asm__ __volatile__( "mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n" "sh $12, 0(%0)\n" "sh $13, 2(%0)\n" "sh $14, 4(%0)\n" : : "r"( vec[2] ) : "$12", "$13", "$14", "memory") ;

    vin[0] = *(u16 *)((u8 *)a1 + 0) + 0x30;
    vin[1] = *(u16 *)((u8 *)a1 + 2) + 0x20;
    __asm__ __volatile__( "lw $12, 0(%0)\n" "lw $13, 4(%0)\n" "ctc2 $12, $0\n" "ctc2 $13, $1\n" "lw $12, 8(%0)\n" "lw $13, 12(%0)\n" "lw $14, 16(%0)\n" "ctc2 $12, $2\n" "ctc2 $13, $3\n" "ctc2 $14, $4\n" : : "r"( mat ) : "$12", "$13", "$14", "memory") ;
    __asm__ __volatile__( "lwc2 $0, 0(%0)\n" "lwc2 $1, 4(%0)\n" : : "r"( vin ) : "memory") ;
    __asm__ __volatile__( "nop\n" "nop\n" "mvmva 1, 0, 0, 3, 0\n" : : : "memory") ;
    __asm__ __volatile__( "mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n" "sh $12, 0(%0)\n" "sh $13, 2(%0)\n" "sh $14, 4(%0)\n" : : "r"( vec[3] ) : "$12", "$13", "$14", "memory") ;

    tc[0] = tp[0];
    tc[1] = tp[1];
    tc[2] = tp[2];
    tc[3] = tp[1];
    tc[4] = tp[0];
    tc[5] = tp[3];
    tc[6] = tp[2];
    tc[7] = tp[3];

    w = *(u16 *)((u8 *)D_800CBFF8 + idx * 2);
    tail[2] = 0x80;
    tail[1] = 0x80;
    tail[0] = 0x80;
    *(u32 *)(tail + 4) = 0x40000000;
    tail[8] = w;
    func_80016ED4(o0);
}
