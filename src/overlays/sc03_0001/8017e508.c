/* sc03_0001: func_8017E508 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern s32 D_80126B9C;
extern u16 D_801270C0;
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8016EDEC(s32 _arg0, s32 _arg1, s32 _arg2);
extern void func_8012A568(void (*a0)(void));
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern void func_8017E8AC(void *a0);
extern void func_8016EDEC(s32 a0, s32 a1, s32 a2);
extern s32 D_80126B9C;
extern u16 D_801270C0;
void func_8017E8AC(void *a0);

s32 func_8017E508(s32 param_1)
{
    ((void (*)(void *, s32))func_8016EDEC)(func_8017E8AC, 0x1000000);
    D_801270C0 = 2;
    D_80126B9C = D_80126B9C | 0x4000000;
    *(u8 *)(param_1 + 0x15) = *(u8 *)(param_1 + 0x15) + 1;
    *(s32 *)(param_1 + 0x28) = 0xA;
    return 0;
}
