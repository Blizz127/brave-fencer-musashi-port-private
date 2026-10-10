/* sc03_0098: func_80185178 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80184E24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct B16_80185794 { s32 w[4]; };
extern void func_80028620(s32, void *);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern void func_80028620(s32 a0, void *a1);
extern s32 func_8004787C(s32 a0);
extern void func_80028620(s32 a0, void *a1);

void func_80185178(void *a0) {
    extern struct B16_80185794 D_800A5E88;
    extern struct B16_80185794 D_801C2A24;
    extern s32 D_800A5E90;
    D_800A5E88 = D_801C2A24;
    D_800A5E90 = func_8004787C(*(s16 *)((s32)a0 + 0xFE)) * 20 / 4096 - 10;
    *(u16 *)((s32)a0 + 0xFE) = (*(u16 *)((s32)a0 + 0xFE) + 0x71) & 0xFFF;
    func_80028620(0, &D_800A5E88);
}
