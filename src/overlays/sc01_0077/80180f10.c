/* sc01_0077: func_80180F10 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80180B64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 dx, s32 dy);
extern u16 D_80126B5E;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32, s32);
extern s16 D_8018AACC;
extern s16 D_8018AAD0;
extern s32 func_8004CFEC(s32, s32);
extern s16 D_8018AACC;
extern s16 D_8018AAD0;
extern u16 D_80126B5E;
extern s32 func_80013478(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32, s32);

s32 func_80180F10(s32 param_1, s32 param_2) {
    s32 local_20[2] = {0x3c100, 0x51000};
    s32 iVar1;
    s32 iVar2;
    if ((s32)((u32)*(u16 *)(param_1 + 0x70) << 0x10) >> 0x18 == 4) {
        iVar1 = ((s32 (*)(s32, void *))func_80013478)(param_1 + 4, &D_8018AACC);
        if (param_2 == 1) {
            iVar2 = func_8004CFEC((s32)*(s16 *)(param_1 + 0xe) - (s32)D_8018AAD0,
                           (s32)D_8018AACC - (s32)*(s16 *)(param_1 + 6));
            if ((((u32)iVar2 - 0x400U) & 0xfff) - 0x381 < 0xff && 0x2df < (*(s16 *)&D_80126B5E) &&
                0x3c100 < iVar1) { return 1; }
        }
        if (local_20[param_2] < iVar1 && *(s32 *)(param_1 + 0xe8) < iVar1) {
            *(s32 *)(param_1 + 0xe8) = iVar1; return 1;
        }
        *(s32 *)(param_1 + 0xe8) = iVar1;
    }
    return 0;
}
