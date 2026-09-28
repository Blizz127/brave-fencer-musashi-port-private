/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC310 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
} Quad4_800CCB14;
typedef struct {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
} Quad4_800CCAD0;
extern void func_80146578(void);
extern void func_8001CD9C(void *a0, void *a1);
extern void func_800233CC(void *a0, u16 a1);
extern void func_80146CA0(void *a0);
extern void func_800CC6A4();
extern Quad4_800CCAD0 D_800CCAD0;
extern Quad4_800CCAD0 D_800CCAD4;
extern Quad4_800CCB14 D_800CCB14;
extern u8 D_800CCB10;
extern u8 D_800CCB11;
extern u8 D_800CCB12;

void func_800CC310(void *a0)
{
    void *s1;
    void *s0;

    s1 = ((void *(*)(void))func_80146578)();
    *(void **)((u8 *)a0 + 0x20) = s1;

    if (s1 != ((void *)0) ) {
        s0 = &D_800CCAD0;
        func_8001CD9C(s1, s0);
        func_800233CC(s0, 0xC0);

        *(s16 *)((u8 *)s1 + 0x2C) = 1;
        *(s32 *)((u8 *)s1 + 4) |= 0x50000000;
        *(s16 *)((u8 *)s1 + 0x1A) = 0;
        *(s16 *)((u8 *)s1 + 0x18) = 0;
        *(s16 *)((u8 *)s1 + 0x10) = 0;
        *(s16 *)((u8 *)s1 + 0x12) = 0;
        *(s16 *)((u8 *)s1 + 0x14) = 0;

        *(s16 *)((u8 *)a0 + 0x5A) = 0;
        *(s16 *)((u8 *)a0 + 0x58) = 0;
        *(s16 *)((u8 *)a0 + 0x60) = 0;
        *(s16 *)((u8 *)a0 + 0x62) = 0;

        (*(Quad4_800CCAD0 *)&D_800CCB14).f0 = 0x20;
        (*(Quad4_800CCAD0 *)&D_800CCB14).f1 = 0;
        (*(Quad4_800CCAD0 *)&D_800CCB14).f2 = 0x20;
        D_800CCAD4 = (*(Quad4_800CCAD0 *)&D_800CCB14);

        D_800CCB10 = 0xFF;
        D_800CCB11 = 0xFF;
        D_800CCB12 = 0xFF;

        func_80146CA0(a0);
    } else {
        func_800CC6A4(a0);
    }
}
