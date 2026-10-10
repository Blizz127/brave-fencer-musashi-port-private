/* sc01_0077: func_8012AD50 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;

s32 func_8012AD50(void * arg0)
{
    (*(s16 *)((s8 *)(arg0) + (0x34))) = 0;
    (*(u16 *)((s8 *)(arg0) + (2))) = (u16) ((*(u16 *)((s8 *)(arg0) + (2))) + 1);
}
