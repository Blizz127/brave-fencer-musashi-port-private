/* SC02.CD member35: func_80184328 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80183FD4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { s32 w[4]; } Blk16_80184328;
extern void func_80028620(s32, void *);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern void func_80028620(s32 a0, void *a1);
extern s32 func_8004787C(s32 a0);
extern void func_80028620(s32 a0, void *a1);
extern s32 func_8004787C(s32 a0);
extern void func_80028620(s32, void *);
extern Blk16_80184328 D_800A5E88;
extern Blk16_80184328 D_801BBE34;

void func_80184328(s32 a0) {
    extern s32 D_800A5E90;
    Blk16_80184328 *s1 = &D_800A5E88;
    *s1 = D_801BBE34;
    D_800A5E90 = func_8004787C(*(s16 *)(a0 + 0xFE)) * 20 / 4096 - 10;
    *(s16 *)(a0 + 0xFE) = (*(u16 *)(a0 + 0xFE) + 0x71) & 0xFFF;
    func_80028620(0, s1);
}
