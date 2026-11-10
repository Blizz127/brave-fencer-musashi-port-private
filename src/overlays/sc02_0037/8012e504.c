/* sc02_0037: func_8012E504 from Druthulu/BFM-decomp
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

s32 func_8012E504(s32 a0, s32 a1) {
    s32 p;
    s32 end;
    p = (s32)D_801202A0;
    end = (s32)D_801202A0 + 0x6480;
    for (; p != end; p += 0x10C) {
        if (p != a0) {
            if (*(u16*)p == a1) {
                return p;
            }
        }
    }
    return 0;
}
