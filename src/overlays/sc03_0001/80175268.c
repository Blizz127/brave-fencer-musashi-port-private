/* sc03_0001: func_80175268 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef void (*VoidFn)(void);
extern u8 D_80078EC0;
extern u8 D_80078EC0;
extern u8 D_80078EC0;

s32 func_80175268(s32 param_1)
{
    extern VoidFn D_80190BB4[];
    *(u32 *)(param_1 + 0x44) |= 2;
    (*(VoidFn *)((s32)D_80190BB4 + ((D_80078EC0 - 1) << 2)))();
}
