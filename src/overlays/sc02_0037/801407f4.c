/* sc02_0037: func_801407F4 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013F350.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80028D58(void);
extern s32 func_80028DE0(void);
extern s32 func_80028FBC(void);
extern s32 func_80029000(void);
extern s32 func_80028D9C(void);
extern s32 func_80028D58(void);
extern s32 func_80028DE0(void);
extern s32 func_80028FBC(void);
extern s32 func_80029000(void);
extern s32 func_80028D9C(void);

void func_801407F4(void)
{
    extern u8 *D_80184C64;
    extern u8 *D_80184C68;
    extern u8 *D_80184C6C;
    extern u8 *D_80184C70;
    extern u8 *D_80184C74;
    extern u16 *D_80184C78[];
    extern u16 *D_80184C80[];
    extern u16 *D_80184CA0[];
    u8 *puVar1;
    s32 iVar2;
    u16 *puVar3;
    puVar1 = D_80184C64;
    iVar2 = func_80028D58();
    puVar3 = D_80184C78[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    puVar1 = D_80184C68;
    iVar2 = func_80028DE0();
    puVar3 = D_80184C78[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    iVar2 = func_80028FBC();
    *(s16 *)(D_80184C6C + 0x18) = *D_80184C80[iVar2];
    iVar2 = func_80029000();
    *(s16 *)(D_80184C70 + 0x18) = *D_80184C80[iVar2];
    puVar1 = D_80184C74;
    iVar2 = func_80028D9C();
    puVar3 = D_80184CA0[iVar2];
    *(s16 *)(puVar1 + 0x12) = *puVar3++;
    *(s16 *)(puVar1 + 0x14) = *puVar3++;
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    *(s16 *)(puVar1 + 0x1c) = *puVar3++;
}
