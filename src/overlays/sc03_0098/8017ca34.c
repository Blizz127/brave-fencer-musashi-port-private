/* sc03_0098: func_8017CA34 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void func_8012A568(void (*a0)(void));
extern s16 func_80128CFC(u16 a0);
extern s16 func_80128CFC(u16 a0);
extern s16 func_80128CFC(u16 a0);

void func_8017CA34(void *a0) {
    void *v1 = *(void **)(a0 + 0xDC);
    s16 v0;
    if (*(u8 *)(v1 + 1) == 0) {
        v0 = 1;
    } else {
        v0 = *(s16 *)(a0 + 0x108);
        if (v0 == 0) {
            u16 arg = *(u16 *)(v1 + 2);
            v0 = func_80128CFC(arg);
            *(s16 *)(a0 + 0x108) = v0;
        }
        v0 = *(s16 *)(a0 + 0x108);
    }
    if (v0 != 0) {
        *(u16 *)(a0 + 0x2) += 1;
    }
}
