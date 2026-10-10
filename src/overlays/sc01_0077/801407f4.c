/* sc01_0077: func_801407F4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_80028D58(void);
extern s32 func_80028DE0(void);
extern s32 func_80028FBC(void);
extern s32 func_80029000(void);
extern s32 func_80028D9C(void);
extern u8 *D_80187B74;
extern u8 *D_80187B78;
extern u8 *D_80187B7C;
extern u8 *D_80187B80;
extern u8 *D_80187B84;
extern u16 *D_80187B88[];
extern u16 *D_80187B90[];
extern u16 *D_80187BB0[];
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
    puVar1 = D_80187B74;
    iVar2 = func_80028D58();
    puVar3 = D_80187B88[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    puVar1 = D_80187B78;
    iVar2 = func_80028DE0();
    puVar3 = D_80187B88[iVar2];
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    iVar2 = func_80028FBC();
    *(s16 *)(D_80187B7C + 0x18) = *D_80187B90[iVar2];
    iVar2 = func_80029000();
    *(s16 *)(D_80187B80 + 0x18) = *D_80187B90[iVar2];
    puVar1 = D_80187B84;
    iVar2 = func_80028D9C();
    puVar3 = D_80187BB0[iVar2];
    *(s16 *)(puVar1 + 0x12) = *puVar3++;
    *(s16 *)(puVar1 + 0x14) = *puVar3++;
    *(s16 *)(puVar1 + 0x16) = *puVar3++;
    *(s16 *)(puVar1 + 0x18) = *puVar3++;
    *(s16 *)(puVar1 + 0x1a) = *puVar3++;
    *(s16 *)(puVar1 + 0x1c) = *puVar3++;
}
