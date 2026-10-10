/* sc03_0098: func_8012B608 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);

s32 func_8012B608(s32 a0, s32 a1, s32 a2) {
    s32 v1;
    s32 t;
    a0 &= 0xFFF;
    a1 &= 0xFFF;
    v1 = a1 - a0;
    if (a0 == a1) {
        return 0;
    }
    if (v1 >= 0x801) {
        t = a0 + 0x1000;
        v1 = a1 - t;
    }
    if (v1 < -0x800) {
        t = a0 - 0x1000;
        v1 = a1 - t;
    }
    if (v1 >= 0) {
        v1 = v1 / a2;
        if (v1 != 0) {
            return v1;
        }
        v1 = 1;
    } else {
        v1 = v1 / a2;
        if (v1 != 0) {
            return v1;
        }
        v1 = -1;
    }
    return v1;
}
