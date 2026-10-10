/* sc01_0077: func_8017E51C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern void func_8012A568(void (*a0)(void));
extern s16 D_80126976;
extern s16 D_8012697A;
extern s16 D_80126976;
extern s16 D_8012697A;
extern s16 D_80126976;
extern s16 D_8012697A;
extern s16 D_80126976;
extern s16 D_8012697A;
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern s32 func_80012B04(s32 a0, s32 a1, s32 a2);
extern u16 D_80126970;
extern u16 D_80126974;
extern s16 D_80126976;
extern s16 D_8012697A;

void func_8017E51C(void *arg0) {
    s16 temp_v0;
    s32 temp_v0_2;
    u16 temp_v0_3;
    u16 temp_v1;
    void *temp_a0;
    temp_v0 = func_80012B04((*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x20)))) + (0x12))), 0x400, 4);
    temp_a0 = (*(void **)((s8 *)(arg0) + (0x20)));
    (*(s16 *)((s8 *)(temp_a0) + (0x12))) = (s16) (((u16) (*(s16 *)((s8 *)(temp_a0) + (0x12))) + temp_v0) & 0xFFF);
    if (temp_v0 == 0) {
        (*(u8 *)((s8 *)(arg0) + (0x214))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x214))) + 1);
    }
    temp_v0_2 = (*(s32 *)((s8 *)(arg0) + (0x204)));
    if (((temp_v0_2 == 0) || ((*(s32 *)((s8 *)(arg0) + (0x204))) = (s32) (temp_v0_2 - 1), temp_v0_3 = D_80126970 - 4, temp_v1 = D_80126974 - 4, D_80126970 = temp_v0_3, D_80126976 = temp_v0_3, D_80126974 = temp_v1, D_8012697A = temp_v1, ((*(s32 *)((s8 *)(arg0) + (0x204))) == 0))) && (temp_v0 == 0)) {
        (*(u8 *)((s8 *)(arg0) + (0x214))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x214))) + 1);
    }
}
