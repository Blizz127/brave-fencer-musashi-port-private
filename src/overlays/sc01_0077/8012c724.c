/* sc01_0077: func_8012C724 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
s32 func_8012C890(s32 a0, s32 a1, s32 a2);

void func_8012C724(s32 a0, s32 a1) {
    *(u16 *)((s32)a0 + 0xA) |= 0x8000;
    func_8012C890(a0, a1, 0);
}
