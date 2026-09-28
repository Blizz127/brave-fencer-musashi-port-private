/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D6F0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { u8 b[8]; } Blk8;
extern s32 func_80172664(s32 *a0);
extern s32 func_80171D78(s32 a0, s32 a1);
extern s32 func_801724EC(s32 a0);
extern const Blk8 D_80194F04;
extern const Blk8 D_80194F0C;

void func_8017D6F0(s32 param_1) {
    Blk8 buf10;
    Blk8 buf18;

    buf10 = D_80194F04;
    buf18 = D_80194F0C;

    if (((s32 (*)(s32, s32))func_801724EC)(param_1, (s32)&buf18)) {
        if (func_80172664((s32 *)param_1) == 0) {
            *(u16 *)((s32)param_1 + 0xAC) = 0x40;
            *(u16 *)((s32)param_1 + 0xAA) = 0x40;
        }
    }
    if (func_80171D78(param_1, (s32)&buf10)) {
        *(u32 *)((s32)param_1 + 0x204) = 0x20;
        *(u8 *)((s32)param_1 + 0x214) += 1;
    }
}
