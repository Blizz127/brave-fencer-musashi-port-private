/* sc03_0098: func_801407F4 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80140608.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80028D58(void);
extern s32 func_80028DE0(void);
extern s32 func_80028FBC(void);
extern s32 func_80029000(void);
extern s32 func_80028D9C(void);
extern u8 *D_80186378;
extern u8 *D_8018637C;
extern u8 *D_80186380;
extern u8 *D_80186384;
extern u8 *D_80186388;
extern u16 *D_8018638C[];
extern u16 *D_80186394[];
extern u16 *D_801863B4[];
extern s32 func_80028D58(void);
extern s32 func_80028DE0(void);
extern s32 func_80028FBC(void);
extern s32 func_80029000(void);
extern s32 func_80028D9C(void);

void func_801407F4(void)
{
    u8 *puVar1;
    s32 iVar2;
    u16 *puVar3;
    puVar1 = D_80186378;
    iVar2 = func_80028D58();
    puVar3 = D_8018638C[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    puVar1 = D_8018637C;
    iVar2 = func_80028DE0();
    puVar3 = D_8018638C[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    iVar2 = func_80028FBC();
    *(s16 *)(D_80186380 + 0x18) = *D_80186394[iVar2];
    iVar2 = func_80029000();
    *(s16 *)(D_80186384 + 0x18) = *D_80186394[iVar2];
    puVar1 = D_80186388;
    iVar2 = func_80028D9C();
    puVar3 = D_801863B4[iVar2];
    *(s16 *)(puVar1 + 0x12) = *puVar3++;
    *(s16 *)(puVar1 + 0x14) = *puVar3++;
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    *(s16 *)(puVar1 + 0x1c) = *puVar3++;
}
