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
/* func_800CB900 - byte-exact against retail at -O2 (tools/register_match.py). */
#define RotMatrixZ func_8004A27C


void func_800CB900(void *arg0, void *trns, void *vsrc, void *dsrc, void *oncep, void *twicep, s16 *angp) {
    extern u16 D_800B99DA;
    struct {
        s16 o1[4];
        s16 o2[4];
        s16 o3[4];
        u16 q28, q2A, q2C, q2E, q30, q32;
        u32 w34, w38, w3C, w40;
        u8 b44;
        char z45[3];
        s16 v48[4];
        s16 v50[4];
        s16 v58[4];
        s32 mat[8];
    } L;
    u32 w3c;
    u16 t;

    func_80013F3C(L.mat);
    RotMatrixZ(*angp, L.mat);

    L.mat[5] = *(s16 *)trns;
    L.mat[6] = *((s16 *)trns + 1);
    L.mat[7] = 0;
    func_8004914C(L.mat);
    func_800491AC(L.mat);

    __asm__ __volatile__("" : : "r"(twicep));

    L.w40 = 0x50000000;
    L.w34 = *(u32 *)oncep;
    L.w38 = *(u32 *)twicep;

    w3c = *(u32 *)twicep;
    L.v48[0] = *(u16 *)vsrc;
    L.v48[1] = *((u16 *)vsrc + 1);
    L.v48[2] = 0;
    L.v50[0] = *(u16 *)vsrc - *(u16 *)dsrc;
    L.v50[1] = *((u16 *)dsrc + 1);
    L.v50[2] = 0;
    L.v58[0] = *(u16 *)vsrc + *(u16 *)dsrc;
    L.v58[1] = *((u16 *)dsrc + 1);
    L.w3C = w3c;
    w3c = (u32)L.o1;
    L.v58[2] = 0;





    __asm__ __volatile__("lwc2 $0, 0(%0)\n" "lwc2 $1, 4(%0)\n" : : "r"( L.v48 ) : "memory") ;
    __asm__ __volatile__("nop\n" "nop\n" "mvmva 1, 0, 0, 0, 0\n" : : : "memory") ;
    __asm__ __volatile__("mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n" "sh $12, 0(%0)\n" "sh $13, 2(%0)\n" "sh $14, 4(%0)\n" : : "r"( (u16 *)w3c ) : "$12", "$13", "$14", "memory") ;
    __asm__ __volatile__("lwc2 $0, 0(%0)\n" "lwc2 $1, 4(%0)\n" : : "r"( L.v50 ) : "memory") ;
    __asm__ __volatile__("nop\n" "nop\n" "mvmva 1, 0, 0, 0, 0\n" : : : "memory") ;
    __asm__ __volatile__("mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n" "sh $12, 0(%0)\n" "sh $13, 2(%0)\n" "sh $14, 4(%0)\n" : : "r"( L.o2 ) : "$12", "$13", "$14", "memory") ;
    __asm__ __volatile__("lwc2 $0, 0(%0)\n" "lwc2 $1, 4(%0)\n" : : "r"( L.v58 ) : "memory") ;
    __asm__ __volatile__("nop\n" "nop\n" "mvmva 1, 0, 0, 0, 0\n" : : : "memory") ;
    __asm__ __volatile__("mfc2 $12, $9\n" "mfc2 $13, $10\n" "mfc2 $14, $11\n" "sh $12, 0(%0)\n" "sh $13, 2(%0)\n" "sh $14, 4(%0)\n" : : "r"( L.o3 ) : "$12", "$13", "$14", "memory") ;

    __asm__ __volatile__("" : : "r"(twicep));

    L.q2A = 0x13F;
    L.q2E = 0x100;
    L.q32 = 0x17F;
    L.b44 = 0x19;
    L.o1[2] = 1;
    t = (D_800B99DA << 2) & 0x3F;
    L.q28 = t | 0x680;
    L.q2C = t + 0x6BF;
    L.q30 = L.q2C;
    func_800174DC();
}
