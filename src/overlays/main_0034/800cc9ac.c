/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC9AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_800B99DA;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
} Quad4_800CCAD0;
extern Quad4_800CCAD0 D_800CCAD0;

void func_800CC9AC(void *a0) {
    extern u16 D_800B99DA;
    extern Quad4_800CCAD0 D_800CCAD0;
    extern u8 D_800CCAD1;
    extern u8 D_800CCAD2;
    int col;

    col = D_800B99DA & 1;
    if (col != 0) {
        col = 0xFF;
    } else {
        col = 0xEF;
    }
    (*(u8 *)&D_800CCAD0) = col;
    D_800CCAD1 = col;
    D_800CCAD2 = col;
}
