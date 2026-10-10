/* sc01_0077: func_80155F80 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned int u32;
typedef int s32;
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);

s32 func_80155F80(s32 a0)
{
    *(u32 *)(a0 + 0x44) = *(u32 *)(a0 + 0x44) & ~2;
    func_80154A74(a0, 0x11);
}
