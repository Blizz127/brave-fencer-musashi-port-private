/* sc03_0098: func_8016DC20 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
extern s32 D_8011D030;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80149374(s32 a0, s32 a1);
extern void func_80149374(s32 arg0, s32 arg1);
extern s32 func_801619D0(void *a0);
extern void func_80149374(int, int);
extern s32 func_800D21C4(s32 a0, void *a1, s32 a2);
extern void func_800D1FC8(s32 a0, s32 a1);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_80146C3C();
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C(void);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C(void);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_800D20C0();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C();
extern void func_80149374(s32 a0, s32 a1);
extern void func_800D1FC8(s32 a0, s32 a1);
extern s32 D_8011D030;
extern void func_80149374(s32 a0, s32 a1);
extern s32 func_801619D0(void *a0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_800D20C0(void *a0, void *a1, s32 a2);
extern void func_800D23D0(void *a0);
extern s32 func_800D21C4(s32 a0, void *a1, s32 a2);
extern void func_800D1FC8(s32 a0, s32 a1);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C(void);

void func_8016DC20(s16 *param_1) {
    extern s16 D_801C4FC8;
    extern s16 D_801C4FCC;
    extern u8 D_80188624[];
    extern u8 D_80188630[];
    u16 *psVar1;
    s32 iVar2;
    s32 iVar3;
    s32 iVar4;
    s16 i;
    s16 sp[6];
    i = 0;
    psVar1 = (u16 *)&D_8011D030;
    iVar4 = *(s32 *)((u8 *)param_1 + 0x34);
    do {
        if ((psVar1 != (u16 *)param_1) && (*psVar1 == 0x34)) goto end;
        i = i + 1;
        psVar1 = psVar1 + 0x2c;
    } while (i < 0x1e);
    func_80149374(iVar4, (s32)param_1 + 4);
    iVar2 = func_801619D0((void *)iVar4);
    i = 0;
    if (iVar2 == 0) goto ddb0;
    psVar1 = (u16 *)&D_8011D030;
    do {
        if (*psVar1 == 0x11) goto ddb0;
        i = i + 1;
        psVar1 = psVar1 + 0x2c;
    } while (i < 0x1e);
    func_80146A6C(0x11, param_1, *(s16 *)((u8 *)param_1 + 6),
                  (s16)(*(u16 *)((u8 *)param_1 + 0xa) - 8),
                  *(s16 *)((u8 *)param_1 + 0xe), 0, 0);
    sp[0] = *(u16 *)((u8 *)param_1 + 6);
    sp[1] = *(u16 *)((u8 *)param_1 + 0xa);
    sp[2] = *(u16 *)((u8 *)param_1 + 0xe);
    func_800D20C0(&sp[0], &sp[4], 0);
    sp[5] = 0;
    func_800D23D0(&sp[4]);
    i = 0;
    do {
        iVar3 = func_80146A6C(0x12, param_1, *(s16 *)(iVar4 + 6),
                              *(s16 *)(iVar4 + 0xa), *(s16 *)(iVar4 + 0xe),
                              i, 0);
        if (iVar3 != 0) {
            *(u16 *)(iVar3 + 0x12) = sp[4];
            *(u16 *)(iVar3 + 0x16) = sp[5];
            *(u16 *)(iVar3 + 0x1a) = 0;
        }
        i = i + 2;
    } while (i < 3);
    goto end;
ddb0:
    if (((D_801C4FC8 != *(s16 *)(iVar4 + 6)) || (D_801C4FCC != *(s16 *)(iVar4 + 0xe))) &&
        (iVar2 = func_800D21C4((s32)param_1, D_80188624, 0x18), iVar2 != 0)) {
        D_801C4FC8 = *(u16 *)(iVar4 + 6);
        D_801C4FCC = *(u16 *)(iVar4 + 0xe);
        func_800D1FC8((s32)param_1, 7);
        *(s32 *)((u8 *)param_1 + 0x20) = iVar2;
        *(u16 *)(iVar2 + 0x1a) = 0x3000;
        *(u16 *)(iVar2 + 0x18) = 0x3000;
        *(u8 *)(iVar2 + 0x26) = 0xff;
        *(u32 *)(iVar2 + 4) = *(u32 *)(iVar2 + 4) | 0x50000000;
        func_80128EA8(iVar2, (s32)param_1 + 0x24, (s32)D_80188630);
        func_80128ED8((void *)iVar2, (void *)((s32)param_1 + 0x24));
        *(u16 *)((u8 *)param_1 + 2) = *(u16 *)((u8 *)param_1 + 2) + 1;
        return;
    }
end:
    ((void (*)(s16 *))func_80146C3C)(param_1);
}
