/* sc01_0077: func_80175268 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef void (*VoidFn)(void);
extern u8 D_80078EC0;
extern u8 D_80078EC0;
extern u8 D_80078EC0;
extern VoidFn D_8018A1C4[];

s32 func_80175268(s32 param_1)
{
    *(u32 *)(param_1 + 0x44) |= 2;
    (*(VoidFn *)((s32)D_8018A1C4 + ((D_80078EC0 - 1) << 2)))();
}
