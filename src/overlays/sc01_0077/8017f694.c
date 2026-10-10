/* sc01_0077: func_8017F694 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef signed char s8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C588(s32 a0, s32 a1);

void func_8017F694(void *arg0) {
    (*(s16 *)((s8 *)(arg0) + (2))) = 3;
    (*(s16 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x20)))) + (0x10))) = 0x400;
    (*(u16 *)((s8 *)(arg0) + (0x5C))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x5C))) | 0xCC00);
    func_8012C588(0x25, 0);
}
