/* sc01_0077: func_80171EC8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80171B4C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef signed char s8;
typedef short s16;
typedef int s32;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 D_801151D4;
extern s32 func_8004CFEC(s32 dx, s32 dy);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8004CFEC(s32, s32);
extern s32 D_801151D4;
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_8004CFEC(s32 a0, s32 a1);
extern s32 func_80047948(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 D_801151D4;

void func_80171EC8(s32 a0) {
    s32 base = D_801151D4;
    s32 s0;
    s32 s1;
    s32 v1;
    s32 ang;
    *(s8 *)(a0 + 0xA9) = 0x73;
    ang = func_8004CFEC(*(s32 *)(base + 0x68) - *(s32 *)(base + 0x5C),
                 *(s32 *)(base + 0x70) - *(s32 *)(base + 0x64));
    s0 = (ang + 0x800) & 0xFFF;
    s0 = (*(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) - s0) & 0xFF8;
    if (s0 == 0x400 || s0 == 0xC00) {
        s1 = 0x80;
    } else {
        s32 t = -(func_80047948(s0) << 7);
        if (t < 0) {
            t += 0xFFF;
        }
        s1 = (t >> 12) + 0x80;
    }
    if (s1 < 0) {
        s1 = 0;
    }
    if (!(s1 < 0x100)) {
        s1 = 0xFF;
    }
    if (s0 == 0 || s0 == 0x800) {
        v1 = 0x80;
    } else {
        s32 t = func_8004787C(s0);
        if (t < 0) {
            t += 0x1F;
        }
        v1 = (t >> 5) + 0x80;
    }
    if (v1 < 0) {
        v1 = 0;
    }
    if (!(v1 < 0x100)) {
        v1 = 0xFF;
    }
    *(s16 *)(a0 + 0xAE) = (v1 & 0xFF) | (s1 << 8);
}
