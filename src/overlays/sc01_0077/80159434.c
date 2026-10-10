/* sc01_0077: func_80159434 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;

s32 func_80159434(s32 a0, s32 a1) {
    s32 a2 = *(s32 *)((s32)a0 + 0x20);
    u16 v1 = *(u16 *)((s32)a0 + 0x23A);
    u16 v0 = *(u16 *)((s32)a2 + 0x10);
    *(u16 *)((s32)a2 + 0x10) = (v0 - v1) & 0xFFF;
    return (*(s32 *)((s32)a0 + 0x238) += a1);
}
