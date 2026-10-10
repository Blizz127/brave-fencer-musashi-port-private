/* sc01_0077: func_8016BD78 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
M2C_UNK func_8016BF50();
extern void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);
extern M2C_UNK D_801D9BC4;
extern M2C_UNK D_801D9BC8;
s32 func_8016BF50(s32 param);
void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_8016BD78(s32 param_1)
{
    extern u8 D_801D9BC5;
    extern u8 D_801D9BC6;
    extern u8 D_801D9BC9;
    extern u8 D_801D9BCA;
    s32 iVar2;
    u16 uVar1;
    u8 *p1;
    u8 *p2;
    iVar2 = *(s32 *)(param_1 + 0x20);
    ((void(*)())func_8016BF50)();
    p1 = &(*(u8 *)&D_801D9BC4);
    if (*p1 != 0) *p1 -= 4;
    if (D_801D9BC5 != 0) D_801D9BC5 -= 4;
    if (D_801D9BC6 != 0) D_801D9BC6 -= 4;
    p2 = &(*(u8 *)&D_801D9BC8);
    if (*p2 != 0) *p2 -= 4;
    if (D_801D9BC9 != 0) D_801D9BC9 -= 4;
    if (D_801D9BCA != 0) D_801D9BCA -= 4;
    uVar1 = *(u16 *)(iVar2 + 0x18) - 0x80;
    *(u16 *)(iVar2 + 0x18) = uVar1;
    if ((s32)((unsigned int)uVar1 << 0x10) < 0) {
        *(u16 *)(iVar2 + 0x18) = 0;
        *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
    }
    *(u16 *)(iVar2 + 0x12) = (*(u16 *)(iVar2 + 0x12) + 0x22) & 0xfff;
    ((void (*)(s32, u8 *, u8 *, s32))func_8016BFA8)(param_1, p1, p2, iVar2 + 0x18);
}
