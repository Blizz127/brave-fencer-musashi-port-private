/* sc03_0001: func_8017250C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_80172560(u8 *a0, u8 *a1);
s32 func_80172560(u8 *a0, u8 *a1);

int func_8017250C(short *a0, short *a1) {
    if (func_80172560(a0, a1) == 0) {
        return 0;
    }
    a0[3] = a1[0];
    a0[7] = a1[2];
    return 1;
}
