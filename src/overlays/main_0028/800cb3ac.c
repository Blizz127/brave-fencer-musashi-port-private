/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB3AC - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800CB600();
extern void func_80146578(void);
extern void func_8001CC3C(s32 a0, void *a1, s32 a2, s32 a3);
extern void func_8001CB00(s32 a0, void *a1, s32 a2, s32 a3);
extern void func_80149374(s32 a0, s32 a1);
extern void func_8014964C(s32 a0, s32 a1);
extern void func_800CB620();
extern void func_80146CA0(void *a0);
extern u8 D_800CBEA0[];
extern void (*D_800CBEAC[])(void);

void func_800CB3AC(s32 a0) {
    s32 s2;
    s32 s1;

    s2 = *(s32 *)(a0 + 0x4C);
    s1 = ((s32 (*)(void))func_80146578)();
    *(s32 *)(a0 + 0x20) = s1;
    if (s1 != 0) {
        if (*(s32 *)(a0 + 0x54) == 0) {
            func_8001CC3C(s1, D_800CBEA0, 0x1A8, 0x100);
            func_80149374(s2, a0 + 4);
        } else {
            func_8001CB00(s1, D_800CBEAC, 0x1A0, 0x100);
            *(u16 *)(s1 + 0x2C) = 1;
            func_8014964C(s2, a0 + 4);
        }
        *(u8 *)(s1 + 0x27) = 0x19;
        *(u16 *)(a0 + 0x18) = 0;
        func_800CB620(a0);
        func_80146CA0((void *)a0);
    } else {
        func_800CB600(a0);
    }
}
