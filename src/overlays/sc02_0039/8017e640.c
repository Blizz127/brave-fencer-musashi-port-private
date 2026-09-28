/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017E640 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 rand(void);
extern int rand(void);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_8012BEE8(s32 a0);
extern void func_8017E794(void *a0);
extern u8 D_8019B594[];
extern u8 D_8019B595[];

void func_8017E640(void *a0) {
    s32 v1;
    u8 a1;
    u8 t;

    if (*(s16 *)((s32)a0 + 0x70) == 0) {
        func_8017E794(a0);
    }

    if (func_8012BEE8((s32)a0)) {
        v1 = D_8019B594[*(s16 *)((s32)a0 + 0xFE) * 2];
        if (v1 == 0xFF) {
            *(s16 *)((s32)a0 + 0xFE) = 0;
        }

        a1 = D_8019B594[*(s16 *)((s32)a0 + 0xFE) * 2];

        if (a1 & 4) {
            t = rand() & 1;
            if (t) {
                a1 = t | 0x40;
            } else {
                a1 = t | 0x80;
            }
        }

        v1 = D_8019B595[*(s16 *)((s32)a0 + 0xFE) * 2];
        *(s32 *)((s32)a0 + 0x1C) = v1;

        if ((u16)(*(u16 *)((s32)a0 + 0x100) + 0xFF) < 0x1FF) {
            if (*(s32 *)((s32)a0 + 0xE0) < 0x150) {
                func_8012C658(0x1A9, a1, (s32)a0);
            }
        }

        *(u16 *)((s32)a0 + 0xFE) = *(u16 *)((s32)a0 + 0xFE) + 1;
    }
}
