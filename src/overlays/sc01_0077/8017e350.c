/* sc01_0077: func_8017E350 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef s32 M2C_UNK;
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_8013767C(s32 a0);
extern void func_8012A568(void (*a0)(void));
void func_80154274(s32 *a0, s32 a1);
extern s32 D_8012695C;
extern s32 D_8012695C;
extern s32 D_8012695C;
extern s32 D_8012695C;
extern s32 func_8013767C(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 func_8013767C(s32 a0);
extern s32 D_8012695C;
extern s32 func_8013767C(s32 a0);
extern void func_80154274(s32 *a0, s32 a1);
extern s32 D_80126958;
extern s32 D_8012695C;
extern M2C_UNK D_8018A59C;
extern M2C_UNK D_801B17AC;

void func_8017E350(void *arg0) {
    s32 temp_v0;
    s32 temp_v0_2;
    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x204))) - 1;
    (*(s32 *)((s8 *)(arg0) + (0x204))) = temp_v0;
    if (temp_v0 != -1) {
        temp_v0_2 = D_80126958 + 8;
        D_80126958 = temp_v0_2;
        D_8012695C = temp_v0_2;
        return;
    }
    (*(s32 *)((s8 *)(arg0) + (0x204))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x198))) = func_8013767C(&D_801B17AC);
    func_80154274(arg0, &D_8018A59C);
    (*(u8 *)((s8 *)(arg0) + (0x4D))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x4D))) + 1);
    (*(u8 *)((s8 *)(arg0) + (0x214))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x214))) + 1);
}
