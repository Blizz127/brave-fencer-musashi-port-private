/* sc02_0037: func_8012C51C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 D_80126720[];
extern u8 D_80126720[];
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);
s32 func_8012C890(s32 a0, s32 a1, s32 a2);

s32 func_8012C51C(void *a0, s32 a1) {
    u8 *base = D_80126720;
    u8 *p;
    s32 ret;
    if (a1 == 0) {
        p = base - 0x6480;
    } else {
        p = (u8 *)(a1 + 0x10C);
    }
    if (p != base) {
        do {
            if (*(u16 *)p == 0) goto found;
            p += 0x10C;
        } while (p != base);
    }
    p = 0;
found:
    ret = 0;
    if (p != 0) {
        ret = func_8012C890((s32)a0, (s32)p, a1);
    }
    return ret;
}
