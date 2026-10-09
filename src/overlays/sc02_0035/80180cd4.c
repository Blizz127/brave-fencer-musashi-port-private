/* SC02.CD member35: func_80180CD4 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_800183E0(s32 a0);
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_800183E0(s32 a0);

void func_80180CD4(a0)
s32 *a0;
{
    s32 v0;
    s32 v1;
    s32 a1;
    v0 = a0[56];
    if (v0 == 0) {
        return;
    }
    v0 -= 1;
    a0[56] = v0;
    if (v0 > 0) {
        return;
    }
    v1 = a0[52];
    v1 += 8;
    a1 = *(s32 *)v1;
    if (a1 & 0x40000000) {
        v1 = a0[51];
    } else if (a1 < 0) {
        a0[56] = 0;
        return;
    }
    v0 = *(s32 *)v1;
    a0[52] = v1;
    a0[56] = v0;
    func_800183E0(*(s32 *)(v1 + 4));
}
