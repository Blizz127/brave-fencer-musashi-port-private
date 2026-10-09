/* SC02.CD member35: func_801827F8 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);
extern s32 func_80153BD8(s32 arg);
extern s32 func_80153BF0(s32 a0);
extern s32 func_80153BD8(s32 a0);
extern s32 func_80153BF0(s32 a0);

void func_801827F8(s32 a0)
{
    s32 v0;
    if (*(u8 *)((s32)a0 + 0x5E) == 0x23) {
        *(u16 *)((s32)a0 + 0x100) |= 0x4000;
    }
    v0 = func_80153BD8(a0);
    if (v0 != 0) {
        func_80153BF0(a0);
    }
}
