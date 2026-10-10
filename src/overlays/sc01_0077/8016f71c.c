/* sc01_0077: func_8016F71C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8016AB6C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_801719A4(int a0, int a1);
extern void *D_8011F738;
extern void *D_8011F738;
extern void func_801719A4(int a0, int a1);
extern s32 func_80171990(u8 *a0);
extern void func_8016F764(void *a0);
void func_8016F764(void *a0);
s32 func_80171990(u8 *a0);
void func_801719A4(int a0, int a1);

void func_8016F71C(u8 *a0) {
    func_801719A4((int)a0, 1);
    *(void **)(a0 + 0x200) = D_8011F738;
    func_80171990(a0);
    func_8016F764((s32)a0);
}
