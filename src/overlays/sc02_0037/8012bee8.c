/* sc02_0037: func_8012BEE8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef int s32;

s32 func_8012BEE8(s32 a0) {
    s32 v0;
    v0 = *(s32*)(a0 + 0x1C);
    if (!v0) goto ret1;
    *(s32*)(a0 + 0x1C) = v0 - 1;
    return (u32)(v0 - 1) < 1;
ret1:
    return 1;
}
