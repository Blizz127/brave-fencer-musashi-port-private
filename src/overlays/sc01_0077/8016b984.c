/* sc01_0077: func_8016B984 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_80016714(void *a0, s32 a1);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern void func_80146C3C();
extern void func_80016714(void *a0, s32 a1);
extern void func_80146C3C();

void func_8016B984(void *a0) {
    if (*(s32*)((s32)a0 + 0x10) != 0) {
        func_80016714(*(void**)((s32)a0 + 0x10), 0x38);
    }
    if (*(s32*)((s32)a0 + 0x14) != 0) {
        func_80016714(*(void**)((s32)a0 + 0x14), 0x38);
    }
    if (*(s32*)((s32)a0 + 0x18) != 0) {
        func_80016714(*(void**)((s32)a0 + 0x18), 0x38);
    }
    ((void (*)(void *))func_80146C3C)(a0);
}
