/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB0D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern s32 rand(void);
extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);

void func_800CB0D8(s32 a0) {
    typedef struct { u8 pad[0x50]; s32 f50; } Struct80078E78;
    extern Struct80078E78 D_80078E78;
    extern s32 D_80078EC8;
    extern void func_801466F0(s32, s32, s32, s32, s32, s32, s32, s32);
    extern s32 func_80165A20(s32);
    register s32 v __asm__("$16");
    register Struct80078E78 *p __asm__("$19");
    s32 q;

    v = a0;
    p = &D_80078E78;
    if ((D_80078EC8 & 0x1F) == 0) {
        func_801466F0(0xE, v, 0, 0, 0, ((((rand() % 16) + 0x10) << 12) / 360), 0, 1);
        func_801466F0(0xE, v, 0, 0, 0, -((((rand() % 16) + 0x10) << 12) / 360), 0, 1);
    }
    if ((p->f50 & 0x3F) == 0) {
        if (rand() & 1) {
            q = ((((rand() % 16) + 0x10) << 12) / 360);
            func_801466F0(0xE, v, 0, 0, 0, q, 1, 1);
        } else {
            q = -((((rand() % 16) + 0x10) << 12) / 360);
            func_801466F0(0xE, v, 0, 0, 0, q, 1, 1);
        }
    }
    if (p->f50 == 0) {
        func_80165A20(v);
    }
}
