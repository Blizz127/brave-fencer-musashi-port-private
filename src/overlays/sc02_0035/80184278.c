/* SC02.CD member35: func_80184278 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80183FD4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct B16_801841C8 { s32 w[4]; };
extern void func_80028620(s32, void *);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8004787C(s32 a0);
extern struct B16_801841C8 D_801BBDE4;
extern s32 D_800A5EB0;
extern s32 func_8004787C(s32 a0);
extern void func_80028620(s32 a0, void *a1);
typedef struct { s32 w[4]; } B16_local;
extern struct B16_801841C8 D_800A5EA8;
extern B16_local D_801BBE1C;
extern s32 D_800A5EB0;
extern s32 func_8004787C(s32 a0);
extern void func_80028620(s32 a0, void *a1);

void func_80184278(void *a0) {
    (*(B16_local *)&D_800A5EA8) = D_801BBE1C;
    D_800A5EB0 = func_8004787C(*(s16 *)((s32)a0 + 0xFE)) * 6 / 4096 - 3;
    *(u16 *)((s32)a0 + 0xFE) = (*(u16 *)((s32)a0 + 0xFE) + 0x71) & 0xFFF;
    func_80028620(2, &(*(B16_local *)&D_800A5EA8));
}
