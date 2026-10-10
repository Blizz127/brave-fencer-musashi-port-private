/* sc01_0077: func_8015E95C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8015C32C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern u8 D_80078EC0;
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8015E9B8(s32 *a0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8015E9B8(s32 *a0);
extern u8 D_80078EC0;
void func_8015E9B8(s32 *a0);

void func_8015E95C(s32 a0) {
    if ((D_80078EC0 & 0x80) == 0) {
        func_80146A6C(0x14, (void *)a0, 0, 0, 0, 0, 0);
    }
    func_8015E9B8(a0);
}
