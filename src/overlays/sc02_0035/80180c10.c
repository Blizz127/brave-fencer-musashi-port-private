/* SC02.CD member35: func_80180C10 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
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
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8004787C(s32 a0);
extern s32 func_8004787C(s32 a0);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);

void func_80180C10(s32 param)
{
    s32 base = param;
    s32 x = *(s32 *)(base + 0x1C);
    s32 r = func_8004787C((x << 7) & 0x780);
    s32 y = *(s32 *)(base + 0x34);
    s32 q = y >> 2;
    s32 prod = q * r;
    s32 ptr = *(s32 *)(base + 0x20);
    s32 hi = prod >> 12;
    y = y - hi;
    *(s16 *)(ptr + 0x1A) = y;
    *(s16 *)(ptr + 0x18) = y;
}
