/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC4E8 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
} Quad4_800CCB14;
extern void func_80146CA0(void *a0);
extern Quad4_800CCB14 D_800CCB14;
extern u8 D_800CCB10;
extern void func_800CC6C4(void *a0, void *a1, void *a2, void *a3);
extern s32 func_80146E98(s32 a0);

void func_800CC4E8(void *a0) {
    void *s1;
    register s32 t __asm__("$2");

    s1 = *(void **)((u8 *)a0 + 0x20);
    func_80146E98((s32)a0);
    if (*(s32 *)((u8 *)a0 + 0x1c) < 8) {
        t = *(u16 *)((u8 *)a0 + 0x58) - 0x100;
        *(s16 *)((u8 *)a0 + 0x58) = t;
        __asm__ __volatile__("");
        if ((t << 16) < 0) {
            *(s16 *)((u8 *)a0 + 0x58) = 0;
        }

        t = *(u16 *)((u8 *)a0 + 0x5a) - 0x100;
        *(s16 *)((u8 *)a0 + 0x5a) = t;
        __asm__ __volatile__("");
        if ((t << 16) < 0) {
            *(s16 *)((u8 *)a0 + 0x5a) = 0;
        }

        t = *(u16 *)((u8 *)s1 + 0x1a) - 0x100;
        *(s16 *)((u8 *)s1 + 0x1a) = t;
        *(s16 *)((u8 *)s1 + 0x18) = t;
        if (*(s16 *)((u8 *)s1 + 0x1a) < 0) {
            *(s16 *)((u8 *)a0 + 0x60) = 0;
            *(s16 *)((u8 *)s1 + 0x1a) = 0;
            *(s16 *)((u8 *)s1 + 0x18) = 0;
            func_80146CA0(a0);
        }
    }

    {
        register u16 x __asm__("$2") = (*(u16 *)((u8 *)s1 + 0x10) + 0x2d) & 0xfff;
        u16 y = (*(u16 *)((u8 *)s1 + 0x12) + 0x16) & 0xfff;
        *(u16 *)((u8 *)s1 + 0x10) = x;
        *(u16 *)((u8 *)s1 + 0x12) = y;
        func_800CC6C4(a0, &D_800CCB10, &D_800CCB14, (u8 *)a0 + 0x58);
    }
}
