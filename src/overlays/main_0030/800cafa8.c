/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAFA8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAFA8(void *a0) {
    extern u8 D_800CB51C;
    extern u8 D_800CB51D;
    extern u8 D_800CB51E;
    extern u8 D_800CB520;
    extern u8 D_800CB521;
    extern u8 D_800CB522;
    extern u8 D_800CB464[];
    extern u8 D_800CB470[];
    extern void func_800CB158(void *);
    extern void func_80146AB4(s32, void *, s32, s32, s32, s32, s32);
    extern s32 func_801465C0(void);
    extern void func_8001CC3C(void *, void *, s32, s32);
    extern void func_80128EA8(void *, void *, void *);
    extern void func_80146C3C(void *);
    extern void func_8001CD9C(void *, void *);

    volatile s32 pad[6];
    s32 ent;
    s16 i;

    ent = *(s32 *)((s32)a0 + 0x20);
    if (*(s32 *)((s32)a0 + 0x2C) & 0x8000) {
        D_800CB51E = 0;
        D_800CB51D = 0;
        D_800CB51C = 0;
        D_800CB522 = 0;
        D_800CB521 = 0;
        D_800CB520 = 0;
        func_800CB158(a0);
        for (i = 0; i < 4; i++) {
            func_80146AB4(0x37, a0, 0, 0, 0, (i << 16) >> 6, 0);
        }
        *(s16 *)((s32)a0 + 0x16) = -0x38;
        *(s16 *)((s32)a0 + 2) = 1;
    } else {
        if (ent == 0) {
            ent = func_801465C0();
            if (ent == 0) {
                func_80146C3C(a0);
                return;
            }
            func_8001CC3C(ent, D_800CB464, 0, 0);
            *(u16 *)(ent + 0x18) = 0x6000;
            *(u16 *)(ent + 0x1A) = 0x6000;
            *(u8 *)(ent + 0x27) = 0x19;
            *(u8 *)(ent + 0x26) = 0;
            *(u8 *)(ent + 0x25) = 0;
            *(u8 *)(ent + 0x24) = 0;
            *(s32 *)(ent + 4) |= 0xD0000000;
            func_80128EA8(ent, (s32)a0 + 0x24, D_800CB470);
            *(s32 *)((s32)a0 + 0x20) = ent;
            *(s32 *)((s32)a0 + 0x34) = 0;
            *(s16 *)((s32)a0 + 2) = 2;
        }
        if (*(s32 *)((s32)a0 + 0x34) != 0) {
            return;
        }
        ent = func_801465C0();
        if (ent == 0) {
            func_80146C3C(a0);
            return;
        }
        *(s32 *)((s32)a0 + 0x34) = ent;
        func_8001CD9C(ent, &D_800CB51C);
        *(u16 *)(ent + 0x2C) = 0x8001;
        *(s32 *)(ent + 4) |= 0xE0000000;
    }
}
