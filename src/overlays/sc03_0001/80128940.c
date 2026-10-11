/* sc03_0001: func_80128940 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern s32 D_801EBC68;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern s32 D_801EBC68;
extern int D_800C7C60;
extern int *D_800C7C64;
extern int D_800A2E20;
extern int D_801EBC68;
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern void func_8001ABBC(s32 a0, s32 a1, void *a2, s32 a3, s32 sp10);
extern int D_800C7C60;
extern int *D_800C7C64;
extern int D_800A2E20;
extern u8 D_800AF560;
extern s32 D_801EBC68;

s32 func_80128940(s32 _arg0)
{
    s32 *p = &D_800C7C60;
    *p = 0x5E;
    D_800C7C64 = &D_800A2E20;
    ((void (*)(s32, s32, void *, s32, void *))func_8001ABBC)(0, 0, &D_800AF560, D_801EBC68, p);
}
