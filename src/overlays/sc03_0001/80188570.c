/* sc03_0001: func_80188570 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801870B0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern s32 func_8012E57C(s32 a0, s32 a1);
extern void func_80188AEC(s32 a0, s32 a1);

void func_80188570(s32 a0) {
    s32 v0 = func_8012E57C(0x61, (s16)a0);
    if (v0 != 0) {
        if (*(u16 *)((char *)v0 + 0x2) == 2) {
            *(s32 *)((char *)v0 + 0xB0) = 1;
        }
        func_80188AEC(a0, 0x3C);
    }
}
