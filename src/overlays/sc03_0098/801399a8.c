/* sc03_0098: func_801399A8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern int D_801269F0;
extern s32 D_801269F0;
extern s32 D_801269F0;
extern s32 D_80126A3C;

s32 func_801399A8(void) {
    s32 iVar2; s32 puVar3; s32 iVar1;
    for (iVar2 = 1, puVar3 = (s32)&D_80126A3C, iVar1 = 0x4C; iVar2 < 3; puVar3 += 0x4C, iVar2++, iVar1 += 0x4C) {
        if (*(s32 *)((s32)&D_801269F0 + iVar1) == 0) return puVar3;
    }
    return 0;
}
