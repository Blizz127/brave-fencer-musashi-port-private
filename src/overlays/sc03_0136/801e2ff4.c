/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E2FF4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_801E2498;
extern s32 D_801E256C;
extern s32 D_801E3488;
extern void *D_801E34C0[];
extern void *D_801E34F4[];

void func_801E2FF4(void) {
    switch (D_801E2498) {
    case 0:
        *(s32 *)(*(s32 *)&D_801E256C + 4) = (s32)((void *)&D_801E3488);
        break;
    case 1:
        *(s32 *)(*(s32 *)&D_801E256C + 4) = (s32)D_801E34C0;
        break;
    case 2:
        *(s32 *)(*(s32 *)&D_801E256C + 4) = (s32)D_801E34F4;
        break;
    }
}
