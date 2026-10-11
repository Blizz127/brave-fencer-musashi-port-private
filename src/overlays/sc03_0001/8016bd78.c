/* sc03_0001: func_8016BD78 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);
extern M2C_UNK D_801EDA84;
extern M2C_UNK D_801EDA88;
void func_8016BFA8(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_8016BD78(s32 param_1)
{
    extern void func_8016BF50(void);
    extern u8 D_801EDA85;
    extern u8 D_801EDA86;
    extern u8 D_801EDA89;
    extern u8 D_801EDA8A;
    s32 iVar2;
    u16 uVar1;
    u8 *p1;
    u8 *p2;
    iVar2 = *(s32 *)(param_1 + 0x20);
    func_8016BF50();
    p1 = &(*(u8 *)&D_801EDA84);
    if (*p1 != 0) *p1 -= 4;
    if (D_801EDA85 != 0) D_801EDA85 -= 4;
    if (D_801EDA86 != 0) D_801EDA86 -= 4;
    p2 = &(*(u8 *)&D_801EDA88);
    if (*p2 != 0) *p2 -= 4;
    if (D_801EDA89 != 0) D_801EDA89 -= 4;
    if (D_801EDA8A != 0) D_801EDA8A -= 4;
    uVar1 = *(u16 *)(iVar2 + 0x18) - 0x80;
    *(u16 *)(iVar2 + 0x18) = uVar1;
    if ((s32)((unsigned int)uVar1 << 0x10) < 0) {
        *(u16 *)(iVar2 + 0x18) = 0;
        *(s16 *)(param_1 + 2) = *(s16 *)(param_1 + 2) + 1;
    }
    *(u16 *)(iVar2 + 0x12) = (*(u16 *)(iVar2 + 0x12) + 0x22) & 0xfff;
    ((void (*)(s32, u8 *, u8 *, s32))func_8016BFA8)(param_1, p1, p2, iVar2 + 0x18);
}
