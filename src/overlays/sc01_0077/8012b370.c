/* sc01_0077: func_8012B370 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80049A1C(void *m, void *p);

void func_8012B370(int a0) {
    int q;
    int p;
    q = *(int *)(a0 + 0x20);
    if (q != 0) {
        func_80049A1C((void *)(q + 0x10), (void *)(q + 0x34));
        p = *(int *)(a0 + 0x20);
        *(s16 *)(p + 0x8) = *(u16 *)(a0 + 0x6) + *(u16 *)(a0 + 0x50);
        *(s32 *)(p + 0x48) = *(s16 *)(p + 0x8);
        *(s16 *)(p + 0xA) = *(u16 *)(a0 + 0xA) + *(u16 *)(a0 + 0x52);
        *(s32 *)(p + 0x4C) = *(s16 *)(p + 0xA);
        {
            u16 e = *(u16 *)(a0 + 0xE);
            u16 t2c = *(u16 *)(p + 0x2C) | 0x1;
            s16 sum = e + *(u16 *)(a0 + 0x54);
            *(s16 *)(p + 0xC) = sum;
            *(u16 *)(p + 0x2C) = t2c;
            *(s32 *)(p + 0x50) = sum;
        }
    }
}
