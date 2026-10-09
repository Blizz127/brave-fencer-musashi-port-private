/* SC02.CD member35: func_80180B38 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012B6D4(s16 *a0, s16 *a1);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8012B6D4(s16 *a0, s16 *a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
typedef struct { s32 w[8]; } Blk20_80180B38;
extern s32 func_8012B6D4(s16 *a0, s16 *a1);
extern void func_8004A0DC(s32 a0, void *a1);
extern void func_800484EC(s32 a0, s32 a1, s32 a2);
extern Blk20_80180B38 D_800AE620;

s32 func_80180B38(s32 a0, s32 a1)
{
    s32 partner;
    s32 pad[4];
    Blk20_80180B38 mat;
    s32 ang;
    s32 trailing[4];
    partner = *(s32 *)(a0 + 0x2C);
    if (*(u16 *)partner == 0) {
        return 0;
    }
    mat = D_800AE620;
    ang = func_8012B6D4((s16 *)(a0 + 4), (s16 *)(partner + 4));
    func_8004A0DC(ang, &mat);
    trailing[1] = 0;
    trailing[0] = 0;
    trailing[2] = a1;
    func_800484EC((s32) &mat, (s32) trailing, a0 + 0x10);
    return 1;
}
