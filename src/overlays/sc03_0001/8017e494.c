/* sc03_0001: func_8017E494 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_800167B8(s32 a0);
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8016EDEC(s32 _arg0, s32 _arg1, s32 _arg2);
extern void func_8012A568(void (*a0)(void));
extern void func_8017E824(void *arg0);
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_800167B8(s32 a0);
void func_8017E824(void *a0);

s32 func_8017E494(s32 param_1)
{
    ((void (*)(void *, s32))func_8016EDEC)(func_8017E824, 0x1000000);
    func_800167B8(0);
    *(u8 *)(param_1 + 0x15) = *(u8 *)(param_1 + 0x15) + 1;
    return 0;
}
