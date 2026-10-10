/* sc01_0077: func_801787D4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern void func_80178840();
void func_80178840(int param_1);

void func_801787D4(void) {
    u8 *p = D_801202A0;
    s32 i;
    for (i = 0; i < 0x60; i++) {
        if (*(u16 *)(p + 0) != 0 && p[0xC0] != 0) {
            func_80178840(p);
        }
        p += 0x10C;
    }
}
