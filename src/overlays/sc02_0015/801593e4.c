/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801593E4 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    u8 pad[0x12];
    u16 field12;
} S801593E4;
typedef struct {
    u8 pad[0x20];
    S801593E4 *p20;
} A801593E4;

void func_801593E4(A801593E4 *a0) {
    S801593E4 *v1 = a0->p20;
    v1->field12 = (v1->field12 + 0x16) & 0xFFF;
}
