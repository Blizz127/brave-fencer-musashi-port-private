/* sc03_0098: func_8015AB7C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8015A3C8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern u8 D_800D48DC;

s32 func_8015AB7C(s32 a0) {
    u8 v1;
    if (*(s32*)(a0 + 0xB4) == (s32)&D_800D48DC) {
        v1 = *(u8*)(a0 + 0xDC);
        if (v1 < 6) {
            return 0x10;
        }
        if (v1 < 0xB) {
            return 0x12;
        }
        if (v1 < 0x10) {
            return 0x7;
        }
        return 0x9;
    }
    return *(u8*)(a0 + 0xBC);
}
