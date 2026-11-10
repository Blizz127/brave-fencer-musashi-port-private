/* sc02_0037: func_8012E544 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];

s32 func_8012E544(s32 a0) {
    s32 a1;
    s32 v1;
    v1 = (s32)D_801202A0;
    a1 = v1 + 0x6480;
    if (v1 != a1) {
        do {
            if (*(u16 *)v1 == a0) {
                return v1;
            }
            v1 += 0x10C;
        } while (v1 != a1);
    }
    return 0;
}
