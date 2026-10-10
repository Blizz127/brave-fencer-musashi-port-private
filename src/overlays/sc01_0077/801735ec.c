/* sc01_0077: func_801735EC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B32;
extern void func_80171A1C(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B40;
extern s16 D_80126B32;
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_80171A1C(u8 *a0);
extern s16 D_80126B40;
extern s16 D_80126B32;

void func_801735EC(void *a0) {
    if (D_80126B40 != 0) {
        *(s32 *)((u8 *)a0 + 0x44) |= 0x40000;
    }
    func_801477E8((s32 *)a0, D_80126B32 << 16);
    func_80171A1C((u8 *)a0);
}
