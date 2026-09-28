/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC424 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_80146E90(void *a0, s32 a1);

void func_800CC424(void *a0) {
    void *a2 = *(void **)((u8 *)a0 + 0x20);
    *(u16 *)((u8 *)a0 + 0x60) += 0x60;
    *(u16 *)((u8 *)a2 + 0x1A) += 0x200;
    *(u16 *)((u8 *)a2 + 0x18) = *(u16 *)((u8 *)a2 + 0x1A);
    *(u16 *)((u8 *)a0 + 0x5A) += *(u16 *)((u8 *)a0 + 0x60);
    *(u16 *)((u8 *)a0 + 0x58) = *(u16 *)((u8 *)a0 + 0x5A);
    *(u16 *)((u8 *)a2 + 0x10) = (*(u16 *)((u8 *)a2 + 0x10) + 0x9F) & 0xFFF;
    *(u16 *)((u8 *)a2 + 0x12) = (*(u16 *)((u8 *)a2 + 0x12) + 0x71) & 0xFFF;
    func_800CC6C4(a0, &D_800CCB10, &D_800CCB14, (u8 *)a0 + 0x58);
    if (*(s16 *)((u8 *)a0 + 0x5A) >= 0x1001) {
        *(u16 *)((u8 *)a0 + 0x58) = 0x1000;
        *(u16 *)((u8 *)a0 + 0x5A) = 0x1000;
        func_80146E90(a0, 0x20);
        func_80146CA0(a0);
    }
}
