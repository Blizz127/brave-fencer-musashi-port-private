/* sc01_0077: func_801752BC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_80154A74(s32 a0, s32 a1);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(int, int);
void func_80154A74(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_801553A8(s32 *a0);
extern void func_801553A8(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_801752BC(s32 *a0) {
    *(s16 *)((u8 *)a0 + 0xF6) = 0x1000;
    func_801553A8(a0);
    func_80154A74((s32)a0, 0x11);
    *(s32 *)((u8 *)a0 + 0x44) &= ~2;
}
