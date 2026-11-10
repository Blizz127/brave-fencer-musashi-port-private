/* sc02_0037: func_8012DE2C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];

s32 func_8012DE2C(s32 a0) {
    extern u8 D_801202A0[];
    extern u8 * D_801C83CC;
    extern u8 * D_801C83C8;
    u8 *base;
    u8 *end;
    u8 *p;
    base = D_801202A0;
    end = base + 0x6480;
    D_801C83CC = base;
    D_801C83C8 = ((u8 *)a0);
    while (D_801C83CC != end) {
        p = D_801C83CC;
        if (*(u16 *)p != 0 && p != ((u8 *)a0)) {
            D_801C83CC = p + 0x10C;
            return p;
        }
        D_801C83CC += 0x10C;
    }
    D_801C83CC = 0;
    return 0;
}
