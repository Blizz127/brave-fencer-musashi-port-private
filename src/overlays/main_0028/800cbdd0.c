/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBDD0 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_800CB8A0(void *a0);
typedef struct { s32 w[4]; } Struct16;
extern void func_800CB8A0();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_800CBDD0(s32 a0) {
    s32 s1;
    s32 v0;
    s32 var1C;

    s1 = *(s32 *)(a0 + 0x34);
    v0 = *(s32 *)(s1 + 0x20);
    *(Struct16 *)(a0 + 0x38) = *(Struct16 *)(v0 + 0x34);
    *(Struct16 *)(a0 + 0x48) = *(Struct16 *)(v0 + 0x44);
    func_800CB8A0(a0);
    var1C = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = var1C;
    if (var1C == -1) {
        func_80146A6C(0x35, (void *)s1, 0, 0, 0, 0x8000, 0);
        *(s32 *)(a0 + 0x1C) = 0x18;
    }
}
