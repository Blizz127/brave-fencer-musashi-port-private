/* sc03_0098: func_8012C31C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_80120194[];
extern u8 D_80120194[];

s32 func_8012C31C(void) {
    s32 a0;
    s32 v1;
    a0 = (s32)D_80120194;
    v1 = a0 + 0x6480;
    if (v1 != a0) {
        do {
            if (*(u16 *)v1 == 0) {
                return v1;
            }
            v1 -= 0x10C;
        } while (v1 != a0);
    }
    return 0;
}
