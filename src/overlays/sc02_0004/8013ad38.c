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
/* func_8013AD38 - byte-exact against retail at -O2 (tools/register_match.py). */
struct vec;
struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
typedef struct { s16 x, y; } Pair_8013AD38;
extern s16 D_800D45F4[];
extern u8  D_8017E3AC[];

void func_8013AD38(void *flag, s32 a1, void *out2, void *out3)
{
    extern s16 D_800D466C[];
    extern u8 D_8017E3E8[];

    u8 *tbl;
    s16 vec[4];
    s32 res[3];
    s32 i;

    tbl = D_8017E3E8;
    if (((s16)a1) < 0xC00) {
        tbl = D_8017E3AC;
    }

    for (i = 0; i < 30; i++) {
        vec[0] = D_800D45F4[2 * i]     + (((D_800D466C[2 * i]     - D_800D45F4[2 * i])     * ((s16)a1)) >> 12);
        vec[1] = D_800D45F4[2 * i + 1] + (((D_800D466C[2 * i + 1] - D_800D45F4[2 * i + 1]) * ((s16)a1)) >> 12);
        __asm__ __volatile__( "lwc2 $0, 0(%0)\n" "lwc2 $1, 4(%0)\n" : : "r"( vec ) : "memory") ;
        __asm__ __volatile__( "nop\n" "nop\n" "mvmva 1, 0, 0, 0, 0\n" : : : "memory") ;
        __asm__ __volatile__( "swc2 $25, 0(%0)\n" "swc2 $26, 4(%0)\n" "swc2 $27, 8(%0)\n" : : "r"( res ) : "memory") ;
        ((Pair_8013AD38 *)out2)[i].x = res[0];
        ((Pair_8013AD38 *)out2)[i].y = res[1];
        if (((s16 *)flag)[0] < 0) ((s8 *)out3)[2 * i]     = -tbl[2 * i];     else ((s8 *)out3)[2 * i]     = tbl[2 * i];
        if (((s16 *)flag)[1] < 0) ((s8 *)out3)[2 * i + 1] = -tbl[2 * i + 1]; else ((s8 *)out3)[2 * i + 1] = tbl[2 * i + 1];
    }
    ((Pair_8013AD38 *)out2)[i] = ((Pair_8013AD38 *)out2)[0];
    if (((s16 *)flag)[0] < 0) ((s8 *)out3)[2 * i]     = -tbl[0]; else ((s8 *)out3)[2 * i]     = tbl[0];
    if (((s16 *)flag)[1] < 0) ((s8 *)out3)[2 * i + 1] = -tbl[1]; else ((s8 *)out3)[2 * i + 1] = tbl[1];
}
