/* sc03_0098: func_8016DB34 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_80146C3C();
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C();

void func_8016DB34(s32 param_1)
{
    s32 iVar2;
    iVar2 = *(s32 *)(param_1 + 0x20);
    if (((s32 (*)(s32, s32))func_80128ED8)(iVar2, param_1 + 0x24) != 0) {
        ((void (*)(s32))func_80146C3C)(param_1);
    } else {
        *(s8 *)(iVar2 + 0x27) = *(u8 *)(param_1 + 0x28) - 0x70;
        *(s32 *)(param_1 + 0x10) = *(s32 *)(param_1 + 0x10) - 0x60000;
        *(s32 *)(param_1 + 0x14) = *(s32 *)(param_1 + 0x14) + *(s32 *)(param_1 + 0x10);
        *(s32 *)(param_1 + 0x8) = *(s32 *)(param_1 + 0x8) + *(s32 *)(param_1 + 0x14);
        *(s16 *)(iVar2 + 0x18) = *(s16 *)(iVar2 + 0x18) - 0x500;
        *(s16 *)(iVar2 + 0x1a) = *(s16 *)(iVar2 + 0x1a) - 0x300;
    }
}
