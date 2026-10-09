/* SC02.CD member35: func_801843E0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80183FD4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct B16_8018584C { s32 w[4]; };
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
extern s32 func_8004787C(s32 a0);
extern void func_80028620(s32 a0, void *a1);

void func_801843E0(void *a0) {
    extern struct B16_8018584C aD800A5E88 __asm__("D_800A5E88");
    extern struct B16_8018584C D_801BBE6C;
    extern s32 D_800A5E90;
    s32 t;
    aD800A5E88 = D_801BBE6C;
    t = func_8004787C(*(s16 *)((s32)a0 + 0xFE));
    if (t < 0) t += 0x1FF;
    D_800A5E90 = (t >> 9) + 8;
    *(u16 *)((s32)a0 + 0xFE) = (*(u16 *)((s32)a0 + 0xFE) + 0x71) & 0xFFF;
    func_80028620(0, &aD800A5E88);
}
