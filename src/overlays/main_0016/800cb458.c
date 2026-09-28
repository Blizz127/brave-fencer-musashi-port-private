/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB458 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146A6C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
void func_800CAF84();
extern void func_800CAF84();

void func_800CB458(s32 arg0) {
    extern void func_800CAF84(void);
    extern s32 func_80146A6C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    typedef struct { s32 w[4]; } Struct16;
    register s32 keep_a0 __asm__("$4");
    s32 s0 = arg0;
    s32 s1;
    s32 v0;
    s32 id;

    keep_a0 = arg0;
    s1 = *(s32 *)(s0 + 0x34);
    v0 = *(s32 *)(s1 + 0x20);

    *(Struct16 *)(s0 + 0x38) = *(Struct16 *)(v0 + 0x34);
    *(Struct16 *)(s0 + 0x48) = *(Struct16 *)(v0 + 0x44);
    __asm__ __volatile__("" :: "r"(keep_a0));

    func_800CAF84();

    if ((*(s32 *)(s0 + 0x1C) -= 1) == -1) {
        id = 0x4B;
        func_80146A6C(id, s1, 0, 0, 0, 0x8000, 0);
        *(s32 *)(s0 + 0x1C) = 0x18;
    }
}
