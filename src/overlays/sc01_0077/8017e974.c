/* sc01_0077: func_8017E974 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern s32 func_80172664(s32 *a0);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80172664(s32 *a0);

void func_8017E974(s32 param_1)
{
    if (((s32 (*)(void))func_80172664)() != 0) {
        *(u16 *)(param_1 + 0xac) = 0xc040;
        *(u16 *)(param_1 + 0xaa) = 0xc040;
    } else {
        *(u8 *)(param_1 + 0x214) = *(u8 *)(param_1 + 0x214) + 1;
    }
}
