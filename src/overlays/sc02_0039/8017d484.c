/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D484 - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);
extern s32 ratan2(s32 dx, s32 dy);
extern u32 func_8017D5F4(s16 *param_1, s16 *param_2, s16 *param_3);
extern u32 func_8017D6AC(s16 *param_1, s16 *param_2, s16 *param_3);

s32 func_8017D484(u8 *param_1, s16 *param_2, s16 *param_3) {
    u32 a3;
    while (1) {
        switch (param_1[0]) {
        case 0:
            a3 = func_8017D5F4((s16 *)(param_1 + 2), (s16 *)(param_1 + 6), param_2);
            break;
        case 1:
            a3 = func_8017D6AC((s16 *)(param_1 + 2), (s16 *)(param_1 + 6), param_2);
            break;
        case 0xFF:
            a3 = 0;
            break;
        }
        if (a3 == 0) {
            switch (param_1[1]) {
            case 0:
                return ratan2(param_3[0] - *(s16 *)(param_1 + 0xA),
                              param_3[2] - *(s16 *)(param_1 + 0xC)) &
                       0xFFF;
            case 1:
                return ratan2(*(s16 *)(param_1 + 0xA) - param_3[0],
                              *(s16 *)(param_1 + 0xC) - param_3[2]) &
                       0xFFF;
            case 2:
                return 0x800;
            }
        }
        param_1 += 0xE;
    }
}
