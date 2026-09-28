/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E30C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8018A788(void);
extern s16 D_801E2498;
extern s32 D_801E256C;
extern s32 D_801E3488;
extern s32 D_801E34A8;

void func_801E30C8(void) {
    func_8018A788();
    if (D_801E2498 == 0) {
        *(s32 *)(D_801E256C + 4) = (s32)&D_801E3488;
    } else {
        *(s32 *)(D_801E256C + 4) = (s32)&D_801E34A8;
    }
}
