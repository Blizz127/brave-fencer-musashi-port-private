/* SC02.CD member35: func_801803A4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 D_801202A0[];

s32 func_801803A4(void) {
    s32 count = 0;
    s32 i = 0;
    u8 *p = D_801202A0;
    do {
        if (*(u16 *)p == 0x17F && (*(u16 *)(p + 0x70) & 0xF) == 0) {
            count++;
        }
        i++;
        p += 0x10C;
    } while (i < 0x60);
    return count < 0xB;
}
