/* sc03_0098: func_8012DE2C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];

s32 func_8012DE2C(s32 a0) {
    extern u8 * D_801C41AC;
    extern u8 * D_801C41A8;
    u8 *base;
    u8 *end;
    u8 *p;
    base = D_801202A0;
    end = base + 0x6480;
    D_801C41AC = base;
    D_801C41A8 = ((u8 *)a0);
    while (D_801C41AC != end) {
        p = D_801C41AC;
        if (*(u16 *)p != 0 && p != ((u8 *)a0)) {
            D_801C41AC = p + 0x10C;
            return p;
        }
        D_801C41AC += 0x10C;
    }
    D_801C41AC = 0;
    return 0;
}
