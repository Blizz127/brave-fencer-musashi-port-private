/* sc02_0037: func_8012A048 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;
extern s16 D_80126940;
extern s16 D_80126942;
extern s16 D_80126944;

void func_8012A048(void *a0, s32 a1, u8 a2) {
    *(s32 *)((s32)a0 + 0x0) = a1;
    *(u8 *)((s32)a0 + 0x4) = a2;
    *(s32 *)((s32)a0 + 0x9C) = 0;
    *(s16 *)((s32)a0 + 0xA0) = 0;
    *(s16 *)((s32)a0 + 0xA2) = 0;
    D_80126940 = D_80126B5E;
    D_80126942 = D_80126B62;
    D_80126944 = D_80126B66;
}
