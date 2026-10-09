/* SC02.CD member35: func_80181E98 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern u8 D_801202A0[];

void func_80181E98(u8 *s0) {
    extern void (*D_8019C4A4[])(void *);
    extern u8 D_801202A0[];
    u16 v0;
    s32 a0;
    u8 *v1;
    v0 = *(u16 *)(s0 + 0x2);
    ((void (*)(u8 *))D_8019C4A4[v0])(s0);
    v0 = *(u16 *)(s0);
    if (v0 == 0) return;
    v0 = *(u16 *)(s0 + 0x100);
    if ((v0 & 0x1000) == 0) return;
    v1 = D_801202A0;
    for (a0 = 0; a0 < 0x60; a0++) {
        if (*(u16 *)(v1) == 0x15E) {
            s16 v1_val = *(s16 *)(v1 + 0x6);
            s16 s0_val = *(s16 *)(s0 + 0x6);
            if (s0_val < v1_val + 0xF0) {
                *(s16 *)(s0 + 0x6) = v1_val + 0xF0;
            }
            return;
        }
        v1 += 0x10C;
    }
}
