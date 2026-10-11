/* sc03_0001: func_80139A68 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_80127540[4];
extern s16 D_80127540[4];

void func_80139A68(s32 a0, u16 a1) {
    if (a1 < 4) {
        D_80127540[a1] = (s16)a0;
    }
}
