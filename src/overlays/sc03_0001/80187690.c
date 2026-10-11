/* sc03_0001: func_80187690 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));

s32 func_80187690(u8 a0, u8 a1, u8 a2, u8 a3) {
    extern u8 D_80078EB0;
    s32 pad[8];
    s32 v0, h0, l0, h1, l1, x, y;
    v0 = 0;
    h0 = a0;
    l0 = a1;
    x = (h0 << 8) | l0;
    h1 = a2;
    l1 = a3;
    y = (h1 << 8) | l1;
    if ((s16)x <= *(s16 *)&D_80078EB0) {
        v0 = (s16)y;
        v0 = *(s16 *)&D_80078EB0 < v0;
    }
    return v0;
}
