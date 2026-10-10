/* sc01_0077: func_8012C218 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_80016714(void *a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80016714(void *a0, s32 a1);

void func_8012C218(void *a0) {
    u16 *p = ((u16 **)a0)[8];
    if (p) {
        s32 a1;
        switch (*p) {
        case 2: a1 = 0x38; break;
        case 1: a1 = 0x84; break;
        default: goto skip;
        }
        func_80016714(p, a1);
    }
skip:
    func_80016714(a0, 0x10C);
}
