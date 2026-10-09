/* SC02.CD member35: func_80181D4C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012CBCC(s32 a0);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);
extern s32 func_8012B8E4(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern void func_8012CBCC(s32 a0);

void func_80181D4C(s32 a0) {
    extern u8 D_80126B5C;
    extern u16 D_80126B62;
    extern s32 D_80126B64;
    s32 sp10[4];
    s16 t;
    s32 y;
    if (*(s32 *)(a0 + 0x94) == 0xA) {
        *(s16 *)(a0 + 0x98) = 0;
    }
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) += func_8012B8E4(a0, 0x4);
    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) &= 0xFFF;
    sp10[0] = 0;
    sp10[1] = 0;
    sp10[2] = *(s32 *)(a0 + 0x4) - *(s32 *)&D_80126B5C;
    if (sp10[2] > 0) {
        sp10[2] = -sp10[2];
    }
    sp10[3] = *(s32 *)(a0 + 0xC) - D_80126B64;
    if (sp10[3] > 0) {
        sp10[3] = -sp10[3];
    }
    sp10[2] = (sp10[2] + sp10[3]) >> 4;
    func_8012B1B4(a0, (s32)sp10);
    t = *(s16 *)(a0 + 0xA);
    y = *(s16 *)&D_80126B62;
    if (t <= y - 0xA) {
        *(s16 *)(a0 + 0xA) = t + 0x8;
    } else if (t >= y) {
        *(s16 *)(a0 + 0xA) = t - 0x8;
    } else if (*(s32 *)(a0 + 0x94) == 0xA) {
        *(s16 *)(a0 + 0x2) = 0xB;
        *(s16 *)(a0 + 0x98) = 1;
    }
    func_8012CBCC(a0);
}
