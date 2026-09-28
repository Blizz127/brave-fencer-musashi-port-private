/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB4AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_800CBD68;
extern u8 D_800CBD69;
extern u8 D_800CBD6A;

void func_800CB4AC(void) {
    extern u16 D_800B99DA;
    extern u8 D_800CBD68;
    extern u8 D_800CBD69;
    extern u8 D_800CBD6A;
    register u8 colA __asm__("$3");
    register u8 colB __asm__("$2");

    if (D_800B99DA & 1) {
        colA = 0xCF;
        colB = 0xFF;
    } else {
        colA = 0xBF;
        colB = 0xEF;
    }
    D_800CBD68 = colA;
    D_800CBD69 = colB;
    D_800CBD6A = colA;
}
