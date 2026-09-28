/* Exact retail word export for [8003775C,800377D8); EXE and assembly verified. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8003775C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

typedef struct { u8 v; } W8_;
extern W8_ D_80076242_ __asm__("D_80076242");

extern u8  D_8006AEF4;
extern s32 func_8003C4F0(s32);
extern void func_800373D0(void);

int func_8003775C(void) {
    u32 t;

    if (D_80076242_.v != 0) {
        if (func_8003C4F0(0) == 0) {
            return 0;
        }
        D_80076242_.v = 0;
        t = D_8006AEF4;
    } else {
        t = D_8006AEF4;
    }
    D_8006AEF4 = t & 0xFC;
    func_800373D0();
    return 1;
}
