/* sc03_0001: func_801549F8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8015444C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;

s32 func_801549F8(s32 param_1, s32 _arg1, s32 _arg2)
{
    s32 i, j;
    u8 n;
    u8 count;
    s32 *base;
    count = 0;
    i = 0;
    if (*(u8 *)(param_1 + 0xBC) != 0) {
        base = *(s32 **)(param_1 + 0xB4);
        n = *(u8 *)(param_1 + 0xBC);
        do {
            j = i;
            switch (base[j]) {
            case 0: case 2: case 7: case 8: case 9: case 10:
            case 0xd: case 0x10: case 0x11: case 0x12: case 0x13:
            case 0x14: case 0x19: case 0x1a:
                i = j + 1;
                break;
            case 3: case 4: case 5: case 6: case 0xb: case 0xc:
            case 0xe: case 0xf: case 0x15: case 0x16:
                i = j + 2;
                break;
            default:
                i = j + 1;
                count += 1;
                break;
            }
        } while (i != n);
    }
    return count;
}
