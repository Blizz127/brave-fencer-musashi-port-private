/* SC02.CD member35: func_8015C0C4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8015AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_80146CA0(void *a0);
extern s16 D_801152B0;
extern s16 D_801152B4;
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80146CA0(void *a0);
extern void func_801553A8(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80146CA0(void *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80146CA0(void *a0);
extern s16 D_801152B0;
extern s16 D_801152B4;

void func_8015C0C4(s32 a0) {
    s32 t = D_801152B0 << 6;
    *(s32 *)(a0 + 0x238) = 0x80000;
    *(s32 *)(a0 + 0x234) = t;
    *(s32 *)(a0 + 0x23C) = D_801152B4 << 6;
    func_80154150(a0, 0x11);
    func_801553A8((s32 *)a0);
    func_80146CA0((void *)a0);
}
