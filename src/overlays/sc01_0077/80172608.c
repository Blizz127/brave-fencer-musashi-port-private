/* sc01_0077: func_80172608 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

s32 func_80172608(u8 *a0) {
    s32 v0 = *(u32 *)((s32)a0 + 0x1F4) | 0x40;
    *(u32 *)((s32)a0 + 0x1F4) = v0;
    return v0;
}
