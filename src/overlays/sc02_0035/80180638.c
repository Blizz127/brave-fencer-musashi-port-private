/* SC02.CD member35: func_80180638 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
s32 func_801809E4(s32 a0, s32 a1, s32 a2);

void func_80180638(s32 a0) {
    extern u8 D_800D3918[];
    extern void func_801292C8(u8 *a0);
    extern s32 func_801809E4(s32 a0, s32 a1, s32 a2);
    s32 ret;
    s32 partner;
    ret = func_801809E4(a0, (s32)D_800D3918, 0x11);
    if ((ret & 0xFF) == 0) {
        if ((ret & 0x2000) != 0) {
            if (*(s32 *)(a0 + 0x2C) == 0) {
                func_801292C8((u8 *)a0);
                return;
            }
            *(s32 *)(a0 + 0x1C) = 0x1E;
            *(s16 *)(a0 + 0x2) = 4;
            return;
        } else {
            if (*(s32 *)(a0 + 0x1C) < 0x23) {
                *(s32 *)(a0 + 0x14) += 0x10000;
                if (*(s32 *)(a0 + 0x2C) != 0) {
                    *(u8 *)(*(s32 *)(a0 + 0x20) + 0x27) = 0x62;
                }
            }
            if (--*(s32 *)(a0 + 0x1C) != 0) {
                return;
            }
        }
    }
    partner = *(s32 *)(a0 + 0x2C);
    if (partner != 0) {
        if (partner != -1) {
            *(s32 *)(partner + 0x30) -= 1;
        }
    }
    func_801292C8((u8 *)a0);
}
