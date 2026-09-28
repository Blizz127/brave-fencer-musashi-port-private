/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB4D8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
void func_800CAF90(void *a0);
typedef struct { s32 w[4]; } func_800CB4D8_Blk16;
extern void func_800CAF90(void *a0);
extern void func_80146C3C(void *a0);
extern u8 D_80078EC1;

void func_800CB4D8(void *a0) {
    s32 s1;
    s32 src;

    s1 = *(s32 *)((s32)a0 + 0x34);
    src = *(s32 *)(s1 + 0x20);
    *(func_800CB4D8_Blk16 *)((s32)a0 + 0x38) = *(func_800CB4D8_Blk16 *)(src + 0x34);
    *(func_800CB4D8_Blk16 *)((s32)a0 + 0x48) = *(func_800CB4D8_Blk16 *)(src + 0x44);
    func_800CAF90(a0);

    if (D_80078EC1 == 5) {
        if (--*(s32 *)((s32)a0 + 0x1C) == -1) {
            func_80146A6C(0xA, (void *)s1, 0, 0, 0, 0x8000, 0);
            *(s32 *)((s32)a0 + 0x1C) = 0x18;
        }
    } else {
        func_80146C3C(a0);
    }
}
