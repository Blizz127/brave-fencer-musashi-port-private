/* sc01_0077: func_80175218 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern u8 D_80078EC0;
extern void func_80146CA0(void *a0);
extern void func_8012A568(void (*a0)(void));
extern void func_80146CA0(void *a0);
extern u8 D_80078EC0;
extern void (*D_8018A1AC[])(s32);
extern void func_80146CA0(void *a0);

s32 func_80175218(void * param_1)
{
    s32 i = D_80078EC0 - 1;
    D_8018A1AC[i](param_1);
    ((void (*)(s32))func_80146CA0)(param_1);
}
