/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB484 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 rand(void);
extern void func_80146CA0(void *a0);
extern u16 D_800B99DA;
extern s32 func_800CB6D4(s32 a0);
extern void func_800CB684(s32 a0, s32 a1);
extern void func_80146E90(s32 *a0, s32 a1);

void func_800CB484(s32 *a0) {
    u16 *p = *(u16 **)((u8 *)a0 + 0x20);
    if (*(s32 *)((u8 *)a0 + 0x54) != 0) {
        if (D_800B99DA & 1) {
            p[0x15] = 0x100;
        } else {
            p[0x15] = 0x120;
        }
    }
    if (func_800CB6D4((s32)a0) != 0) {
        s16 v = *(u16 *)((u8 *)a0 + 0x18);
        *(u16 *)((u8 *)a0 + 0x18) = v + 1;
        if (v >= 4) {
            func_800CB684((s32)a0, 0x200);
            func_80146CA0(a0);
            return;
        }
        if (*(s32 *)((u8 *)a0 + 0x54) != 0 && (rand() & 3) == 0) {
            func_80146E90(a0, 0x20);
            *(u16 *)((u8 *)a0 + 2) = 3;
        } else {
            func_800CB684((s32)a0, 0x80);
        }
    }
}
