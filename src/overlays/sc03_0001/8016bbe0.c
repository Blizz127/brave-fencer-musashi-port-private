/* sc03_0001: func_8016BBE0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_801465C0(void);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_801465C0(void);
extern void func_80146C3C();
extern void func_80146C3C();
void func_8016BF34(void *a0);

s32 func_8016BBE0(s32 param_1) {
    extern void func_8016BF34(void *a0);
    extern void func_8016BF50(s32);
    extern void func_8001CF00(s32);
    extern M2C_UNK D_801EDA84;
    extern u8 D_801EDA85;
    extern u8 D_801EDA86;
    extern M2C_UNK D_801EDA88;
    extern u8 D_801EDA89;
    extern u8 D_801EDA8A;
    int iVar1;
    int temp;
    iVar1 = ((s32 (*)(void))func_801465C0)();
    *(int *)(((int)param_1) + 0x20) = iVar1;
    if (iVar1 != 0) {
        ((void (*)(s32))func_8016BF34)(((int)param_1));
        func_8016BF50(((int)param_1));
        func_8001CF00(iVar1);
        *(s16 *)(iVar1 + 0x10) = 0;
        temp = *(int *)(((int)param_1) + 0x2c);
        *(s16 *)(iVar1 + 0x14) = 0;
        *(s16 *)(iVar1 + 0x1a) = 0;
        *(s16 *)(iVar1 + 0x18) = 0;
        *(s16 *)(iVar1 + 0x12) = temp * 0x555;
        *(s16 *)(((int)param_1) + 0x10) = 0;
        *(s16 *)(((int)param_1) + 0x14) = 0;
        (*(u8 *)&D_801EDA84) = 0x20;
        D_801EDA85 = 0x20;
        D_801EDA86 = 0;
        (*(u8 *)&D_801EDA88) = 0xc0;
        D_801EDA89 = 0xc0;
        D_801EDA8A = 0;
        *(u16 *)(((int)param_1) + 2) += 1;
    } else {
        ((void (*)(s32))func_80146C3C)(((int)param_1));
    }
}
