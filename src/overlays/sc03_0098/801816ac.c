/* sc03_0098: func_801816AC from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B23C(void *a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B178(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
s32 func_80181F88(void *a0, s32 a1, s32 a2, s32 a3);

void func_801816AC(s32 a0) {
    extern s32 func_8005C49C(void);
    extern s32 func_80181F88(void *a0, s32 a1, s32 a2, s32 a3);
    extern void func_8012B23C(void *a0);
    extern void func_8012B178(s32 a0, s32 a1);
    s32 m;
    s32 i;
    m = ((*(u16 *)(a0 + 0x70) & 0xF) | -0x8000) << 16;
    for (i = 0; i < 4; i++) {
        func_80181F88((void *)(a0 + 0x7C),
                      *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12),
                      func_8005C49C() % 4 * -0x10000 + -0x40000,
                      m >> 16);
    }
    *(s32 *)(a0 + 0xEC) = 0x40000;
    func_8012B23C((void *)a0);
    func_8012B178(a0, *(s32 *)(a0 + 0xEC));
    *(s32 *)(a0 + 0x1C) = 0x10;
    *(s16 *)(a0 + 0x34) = 0;
}
