/* SC02.CD member35: func_801827C4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012B14C(s32 a0, s32 a1);

void func_801827C4(s32 a0)
{
    extern u8 D_8019C1AC[];
    *(s32 *)(a0 + 0xC4) = *(s32 *)(a0 + 0xC4) & -5;
    func_8012B14C(a0, (s32)D_8019C1AC);
}
