/* SC02.CD member35: func_8017869C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_80178744(s32 a0, s32 a1);
void func_80178744(s32 a0, s32 a1);

void func_8017869C(s32 a0) {
    s32 v1;
    s32 a1;
    if (*(s16 *)(a0 + 0xAA) == 0) {
        return;
    }
    *(s16 *)(a0 + 0xAA) = *(s16 *)(a0 + 0xAA) - 1;
    v1 = *(s16 *)(a0 + 0xAA);
    if (v1 == 0) {
        a1 = 0x1000;
        if (*(u16 *)(a0 + 0x5E) == 0x1E) {
            *(s16 *)(a0 + 0x5E) = 0;
        }
    } else if (v1 >= 0xF1) {
        a1 = 0x1000 - (0x100 - v1) * 0x90;
    } else {
        if (v1 < 0x10) {
            a1 = 0x1000 - v1 * 0x90;
        } else {
            a1 = 0x700;
        }
    }
    func_80178744(a0, a1);
}
