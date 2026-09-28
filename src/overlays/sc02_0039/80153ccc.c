/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80153CCC - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    u16 pad0;
    u16 idx;   
} S80153CCC;
extern void func_80019064(void *a0);
extern u16 D_8011F748;
extern s16 D_8011DB0C;
extern s32 D_80180EF4;
extern void (*D_80180F1C[])(void *a0);

void func_80153CCC(S80153CCC *a0) {
    ((s32 (*)(s32))func_80019064)((s32)&D_80180EF4);
    D_80180F1C[a0->idx](a0);
    D_8011DB0C = 0;
    D_8011F748 = 0;
}
