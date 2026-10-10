/* sc01_0077: func_8017E224 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern s32 func_80171D1C(void *a0, void *a1, s32 a2);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80171D1C(void * a0, void * a1, s32 a2);
typedef struct { u8 c[8]; } Blk8_8017E224;

void func_8017E224(s32 param_1)
{
    extern s32 func_80171D1C(void *a0, void *a1, s32 a2);
    extern Blk8_8017E224 D_801D90F0;
    Blk8_8017E224 buffer;
    buffer = D_801D90F0;
    if (func_80171D1C((void *)param_1, &buffer, 0x80) != 0) {
        *(u8 *)(param_1 + 0x214) += 1;
    }
}
