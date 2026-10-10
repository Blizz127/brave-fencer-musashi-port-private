/* sc01_0077: func_8016E2E8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80146C3C();
extern void func_8016E3CC(s32 a0);
extern void func_8016E3CC(s32 a0);
extern void func_8016E3CC(s32 a0);
extern void func_80146C3C();
void func_8016E3CC(s32 a0);

void func_8016E2E8(void *a0) {
    s32 *s1 = *(s32 **)((s32)a0 + 0x20);
    func_8016E3CC((s32)a0);
    if (--*(s32 *)((s32)a0 + 0x1C) != 0) {
        *(u16 *)((s32)s1 + 0x18) -= 0x100;
        *(u16 *)((s32)s1 + 0x1A) -= 0x120;
    } else {
        ((void (*)(s32))func_80146C3C)((s32)a0);
    }
}
