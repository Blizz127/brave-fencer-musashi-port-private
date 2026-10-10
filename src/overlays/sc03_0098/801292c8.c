/* sc03_0098: func_801292C8 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *a0, s32 a1);

void func_801292C8(u8 *a0) {
    u16 *p = *(u16 **)(a0 + 0x20);
    if (p != 0) {
        func_80016714(p, (p[0] == 1) ? 0x84 : 0x38);
    }
    *(s16 *)a0 = 0;
}
