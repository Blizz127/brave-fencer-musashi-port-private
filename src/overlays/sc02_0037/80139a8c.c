/* sc02_0037: func_80139A8C from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_801380E0.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80014E80(s32 a0, s32 a1);
extern void func_8001931C(void);
extern s16 D_8012752C;
extern s32 func_80014E80(s32 a0, s32 a1);
extern void func_8001931C(void);
extern s16 D_8012752C;

void func_80139A8C(s32 a0) {
    s32 s0 = a0;
    s32 v0;
    s32 v1;
    v0 = *(s32 *)(s0 + 0x8);
    if ((v0 & 0x2021) != 0) {
        return;
    }
    if ((s16)func_80014E80(0, 0x20) == 0) {
        return;
    }
    v0 = *(s32 *)(s0 + 0x8);
    v1 = v0 | 0x20;
    *(s32 *)(s0 + 0x8) = v1;
    if ((v1 & 0x10000) == 0) {
        return;
    }
    *(s32 *)(s0 + 0x8) = (v1 & 0xFFFEFFFF) | 0x20000;
    func_8001931C();
    D_8012752C = 0;
}
