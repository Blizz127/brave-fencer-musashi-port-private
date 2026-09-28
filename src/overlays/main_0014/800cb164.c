/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB164 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_800CAF90(void *a0);
typedef struct { s32 w[4]; } func_800CB164_Blk16;

void func_800CB164(void *a0) {
    extern u8 D_80078EC1;
    extern void func_80146C3C(void *a0);
    extern void func_800CAF90(void *a0);

    s32 src;
    s32 obj;
    s32 cnt;

    src = *(s32 *)((s32)a0 + 0x34);
    if (*(u8 *)&D_80078EC1 == 5) {
        if ((*(u32 *)((s32)a0 + 0x2C) & 0x8000) == 0) {
            cnt = *(s32 *)((s32)a0 + 0x1C);
            *(s32 *)((s32)a0 + 0x1C) = cnt + 1;
            if (cnt < 8) {
                *(u16 *)((s32)a0 + 0x28) += 0x120;
            } else {
                *(s32 *)((s32)a0 + 0x1C) = 0;
                *(u16 *)((s32)a0 + 2) = 4;
            }
            obj = *(s32 *)(src + 0x20);
            *(func_800CB164_Blk16 *)((s32)a0 + 0x38) = *(func_800CB164_Blk16 *)(obj + 0x34);
            *(func_800CB164_Blk16 *)((s32)a0 + 0x48) = *(func_800CB164_Blk16 *)(obj + 0x44);
            func_800CAF90(a0);
        } else {
            *(u16 *)((s32)a0 + 2) += 1;
        }
    } else {
        func_80146C3C(a0);
    }
}
