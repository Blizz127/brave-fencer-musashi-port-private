/* sc02_0037: func_8012E470 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef short s16;
typedef int s32;

s32 func_8012E470(s32 a0) {
    s32 a1 = *(s32*)(a0 + 0x20);
    s32 v1 = *(s16*)(a1 + 0x18);
    s32 v0 = v1 + (0x1000 - v1) / 4;
    *(s16*)(a1 + 0x18) = (*(s16*)(a1 + 0x1C) = v0);
    v0 = *(s32*)(a0 + 0x1C);
    if (v0 != 0) {
        v0 -= 1;
        *(s32*)(a0 + 0x1C) = v0;
        v1 = v0;
        return (u32)v1 < 1;
    }
    return 1;
}
