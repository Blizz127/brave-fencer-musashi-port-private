/* sc03_0098: func_80181430 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017D898.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);

void func_80181430(s32 a0) {
    s32 sub;
    s32 t;
    sub = *(s32 *)(a0 + 0x20);
    t = func_8004787C(*(s32 *)(a0 + 0x1C) << 6);
    *(s16 *)(sub + 0x1C) = t;
    *(s16 *)(sub + 0x1A) = t;
    *(s16 *)(sub + 0x18) = t;
    *(s32 *)(a0 + 0x1C) = *(s32 *)(a0 + 0x1C) + 1;
    if (*(s32 *)(a0 + 0x1C) < 17) {
        return;
    }
    *(u16 *)(a0 + 2) = 1;
    *(u16 *)(a0 + 0x5C) = *(u16 *)(*(s32 *)(a0 + 0x78) + 2);
}
