/* sc01_0077: func_8017E4B4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;
typedef s32 M2C_UNK;
extern s32 func_8013767C(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8013767C(s32 a0);
extern s32 func_8013767C(s32 a0);
extern s32 func_8013767C(s32 a0);
extern s32 func_8013767C(s32 a0);
extern M2C_UNK D_801B17F0;

void func_8017E4B4(void *arg0) {
    s32 temp_v0;
    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x204))) - 1;
    (*(s32 *)((s8 *)(arg0) + (0x204))) = temp_v0;
    if (temp_v0 == -1) {
        (*(u8 *)((s8 *)(arg0) + (0x4D))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x4D))) - 1);
        (*(s32 *)((s8 *)(arg0) + (0x198))) = func_8013767C(&D_801B17F0);
        (*(s32 *)((s8 *)(arg0) + (0x204))) = 0x20;
        (*(u8 *)((s8 *)(arg0) + (0x214))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x214))) + 1);
    }
}
