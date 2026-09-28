/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB1BC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(s32);
extern void func_80146CA0(s32 a0);
extern s32 func_80146E98(s32 a0);
extern void func_80146578(void);
extern void func_8001CD9C(void *a0, void *a1);
extern void func_800233CC(void *, unsigned short);
extern void func_800CB3D0();
extern u8 D_800CBD68;
extern u8 D_800CBD69;
extern u8 D_800CBD6A;
extern u8 D_800CBD6B;
extern u8 D_800CBD6C;
extern u8 D_800CBD6D;
extern u8 D_800CBD6E;
extern u8 D_800CBD6F;

void func_800CB1BC(void *a0)
{
    void *s0;
    void *s2;
    s32 v0;
    s32 vtemp;

    if (func_80146E98((s32)a0) != 0) {
        s2 = ((void *(*)(void))func_80146578)();
        *(void **)((u8 *)a0 + 0x20) = s2;

        if (s2 != ((void *)0) ) {
            s0 = &D_800CBD68;
            func_8001CD9C(s2, s0);
            func_800233CC(s0, 0x20);

            vtemp = *(s32 *)((u8 *)s2 + 4);
            *(s16 *)((u8 *)s2 + 0x1A) = 0;
            *(s16 *)((u8 *)s2 + 0x18) = 0;
            *(s32 *)((u8 *)s2 + 4) = vtemp | 0x50000000;

            *(s16 *)((u8 *)a0 + 0x62) = 0x1000;
            *(s16 *)((u8 *)a0 + 0x60) = 0;
            *(s16 *)((u8 *)s2 + 0x14) = -0x155;

            v0 = *(s32 *)((u8 *)a0 + 0x54);
            *(s16 *)((u8 *)s2 + 0x12) =
                v0 * 1365 + *(s32 *)((u8 *)a0 + 0x50) * 11;

            *(u8 *)s0 = 0xF0;
            D_800CBD69 = 0xF0;
            D_800CBD6A = 0xF0;
            D_800CBD6B = 0;
            D_800CBD6C = 0;
            D_800CBD6D = 0x20;
            D_800CBD6E = 0x20;
            D_800CBD6F = 0;

            func_80146CA0((s32)a0);
        } else {
            func_800CB3D0(a0);
        }
    }
}
