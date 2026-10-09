/* SC02.CD member35: func_8017F8A0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
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
extern s32 func_8004787C(s32 a0);

void func_8017F8A0(a0)
s32 a0;
{
    s32 v0;
    s32 s0;
    s0 = *(s32 *)(a0 + 0x20);
    v0 = func_8004787C(*(s32 *)(a0 + 0x1C) << 6);
    *(u16 *)(s0 + 0x1C) = v0;
    *(u16 *)(s0 + 0x1A) = v0;
    *(u16 *)(s0 + 0x18) = v0;
    v0 = *(s32 *)(a0 + 0x1C) + 1;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 >= 0x11) {
        *(u16 *)(a0 + 0x2) = 1;
        *(u16 *)(a0 + 0x5C) = *(u16 *)(*(s32 *)(a0 + 0x78) + 2);
    }
}
