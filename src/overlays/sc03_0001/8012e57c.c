/* sc03_0001: func_8012E57C from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8012ACE0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];
extern u8 D_801202A0[];

s32 func_8012E57C(s32 a0, s32 a1) {
    u8 *p = D_801202A0;
    u8 *end = D_801202A0 + 0x6480;
    if (p != end) {
        s32 key = (s16)a1;
        do {
            if (*(u16 *)(p + 0x0) == a0) {
                if (*(s16 *)(p + 0x70) == key) {
                    return (s32)p;
                }
            }
            p += 0x10C;
        } while (p != end);
    }
    return 0;
}
