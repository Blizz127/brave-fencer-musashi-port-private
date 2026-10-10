/* sc01_0077: func_8013E448 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern s16 D_80126CAC;
extern s32 (*D_801274D0)(s32);
extern s32 D_801274D8;
extern s32 D_801274DC;
extern s16 D_80126CAC;
extern s32 func_800132BC(s32 a0, s32 a1);

s32 func_8013E448(s32 param_1)
{
    s32 iVar1;
    register s32 uVar2 __asm__("$2");
    if (D_801274D0 == 0) {
        iVar1 = func_800132BC((s32)&D_80126CAC, param_1);
        uVar2 = 0;
        if (D_801274D8 < iVar1) {
            uVar2 = (iVar1 < D_801274DC);
        }
        return uVar2;
    }
    return (*D_801274D0)(param_1);
}
