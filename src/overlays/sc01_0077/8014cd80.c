/* sc01_0077: func_8014CD80 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_after.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
typedef struct Rec801466F0 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Rec801466F0;
typedef struct { u16 a, b, c, d; } V4U_8014C4AC;
extern s32 D_80126B58;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 D_80126B58;
extern u16 D_801152B8;
extern u16 D_8012693A;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3,
                          s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern u16 *func_80146750(u16 *param_1);
extern u16 *func_8014680C(short *param_1);
extern void aF801466F0(u16 a0, s32 a1, u16 a2, u16 a3, u16 sp5, s32 sp6, s32 sp7, s32 sp8)
    __asm__("func_801466F0");

unsigned short *func_80146750(unsigned short *a0);
unsigned short *func_8014680C(short *param_1);
extern s32 D_8011D030;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 D_8011D030;
extern void func_80146AFC(void*);
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");
void aF80146A6C(s16 a0, s32 a1, s16 a2, s16 a3, u16 a4, s32 a5, s32 a6) __asm__("func_80146A6C");

extern s32 D_8011D030;
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");
s32 aF80146AFC(void *arg0) __asm__("func_80146AFC");

extern void func_80147364();
extern void func_80147364();
extern s16 D_800B9A08;
extern s32 D_80126B58;
extern void func_80015978(s32, s32*);
extern s32 aF8012E5CC(s32, s32, s32) __asm__("func_8012E5CC");
extern void func_8002D4C8(s32 a0, s32 a1);
void aF80147364(u16 param_1, u16 param_2) __asm__("func_80147364");

extern void func_80015978(int a0, int *a1);
extern s32 D_80126B58;
extern s32 D_80126B58;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80015978(s32 a0, s32 *a1);
extern s16 D_800B9A08;
extern u16 *func_80146750(u16 *param_1);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8012E5CC(s32 param_1, u16 param_2, u16 param_3);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_80147364();
extern u16 *func_80146750(u16 *param_1);
extern s16 D_800B9A08;
extern s16 D_800B9A08;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern void func_80015978(s32 a0, s32 *a1);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
extern s32 D_80126B58;
extern s32 D_8011D030;
extern void func_80146AFC(void *a0);
extern s32 D_80126B58;
extern s32 D_80126B58;
extern s32 D_80126B58;
extern s32 D_80126B58;
extern s16 D_800B9A08;
extern void func_80015978(s32 a0, s32 *a1);
extern void func_80146AFC(void *a0);
extern s32 D_8011D030;
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);
s32 aF8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4) __asm__("func_8014C4AC");
s32 aF8014C4AC() __asm__("func_8014C4AC");

extern void func_80015978(s32 a0, s32 *a1);
s32 func_8014C918(s32 a0, s32 a1);
extern void func_80147364();
extern void func_80147364();
extern int func_80135A4C();
extern int func_80135888();
extern int func_8014C918();

int func_8014CD80(int param_1, unsigned short *param_2, unsigned short *param_3)
{
    short *psVar4;
    register int iVar3 __asm__("$3");
    unsigned short uVar1;
    unsigned short uVar2;
    psVar4 = *(short **)(param_1 + 0x174);
    if (*(unsigned short *)psVar4 == 0) goto LAB_ce00;
    if (((*(unsigned short *)((int)psVar4 + 0x5c) & 0x400) == 0) ||
        (*(int *)((int)psVar4 + 0x58) == 0) ||
        (*(short *)((int)psVar4 + 0xa) < *(short *)(param_1 + 0xa))) {
        if (*(unsigned short *)psVar4 != 0) {
            *(char *)((int)psVar4 + 0x74) = 0;
        }
LAB_ce00:
        *(int *)(param_1 + 0x174) = 0;
        return 0;
    }
    *param_2 = *(unsigned short *)(param_1 + 0x98);
    param_2[1] = *(unsigned short *)(param_1 + 0x9a) - 3;
    param_2[2] = *(unsigned short *)(param_1 + 0x9c);
    if ((*(unsigned short *)((int)psVar4 + 0x5c) & 8) != 0) {
        param_3[1] = param_2[1] + 0xc;
        iVar3 = func_80135A4C(*(int *)((int)psVar4 + 0x20),
                              *(int *)((int)psVar4 + 0x58), param_2, param_3);
        if (iVar3 == 0) goto LAB_cec4;
        uVar1 = param_3[0];
        *(unsigned short *)(param_1 + 0x78) = uVar1;
        *(unsigned short *)(param_1 + 6) = uVar1;
        uVar1 = param_3[1];
        *(unsigned short *)(param_1 + 0x7a) = uVar1;
        *(unsigned short *)(param_1 + 0xa) = uVar1;
        uVar1 = param_3[2];
        *(unsigned short *)(param_1 + 0x7c) = uVar1;
        *(unsigned short *)(param_1 + 0xe) = uVar1;
    } else {
        iVar3 = func_80135888(*(int *)((int)psVar4 + 0x20),
                              *(int *)((int)psVar4 + 0x58), param_2, param_3);
    }
    if (iVar3 != 0) goto LAB_ced0;
LAB_cec4:
    *(char *)((int)psVar4 + 0x74) = 0;
    *(int *)(param_1 + 0x174) = 0;
    return 0;
LAB_ced0:
    uVar2 = func_8014C918(param_1, *(unsigned char *)((int)psVar4 + 0x75)) & 0xff;
    *(unsigned short *)(param_1 + 0x16e) = uVar2;
    return 1;
}
