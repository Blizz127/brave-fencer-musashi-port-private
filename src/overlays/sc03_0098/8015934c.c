/* sc03_0098: func_8015934C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef int s32;
extern void func_80145BF8(void);
extern void func_80146CA0(void *a0);
extern s32 D_801C4360;
extern int D_801C4360;
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern s32 D_801C4360;
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80145BF8(void);
extern void func_80146CA0(void *a0);
extern u8 D_800AE6BD;
extern s32 D_801C4360;
extern s32 D_801C4368;

void func_8015934C(void *arg0) {
    void *temp_v1;
    if (D_801C4360 == 4) {
        D_801C4360 = 5;
    }
    if (D_801C4368 != 0) {
        func_80145BF8();
        func_80146CA0(arg0);
        D_800AE6BD += 1;
    }
    temp_v1 = (*(void **)((s8 *)(arg0) + (0x20)));
    (*(u16 *)((s8 *)(temp_v1) + (0x12))) = (u16) (((*(u16 *)((s8 *)(temp_v1) + (0x12))) + 0x16) & 0xFFF);
}
