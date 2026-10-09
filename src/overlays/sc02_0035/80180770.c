/* SC02.CD member35: func_80180770 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { s16 vx, vy, vz, pad; } SV3_8012CC88;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_80180C10(s32 a0);
extern s32 func_80180B38(s32 a0, s32 a1);
extern void func_801292C8(u8 *a0);
extern void func_80180C10(s32 a0);
extern s32 func_801809E4(s32 a0, s32 a1, s32 a2);
extern s32 func_800132BC(s32 a0, s32 a1);
s32 func_801809E4(s32 a0, s32 a1, s32 a2);
s32 func_80180B38(s32 a0, s32 a1);
void func_80180C10(s32 param);

void func_80180770(s32 a0) {
    extern u8 D_800D3918[];
    s32 partner;
    s32 ret;
    if (func_80180B38(a0, -0x18000) == 0) {
        func_801292C8((u8 *)a0);
    } else {
        partner = *(s32 *)(a0 + 0x2C);
        *(s32 *)(a0 + 0x14) = 0x18000;
        if (*(s32 *)(a0 + 0x1C) >= 0x150) {
            *(s32 *)(partner + 0x30) -= 1;
            func_801292C8((u8 *)a0);
        } else {
            SV3_8012CC88 sp10;
            SV3_8012CC88 sp18;
            s32 pad[4];
            func_80180C10(a0);
            func_801809E4(a0, (s32)D_800D3918, 0);
            sp10.vx = *(u16 *)(a0 + 0x6);
            sp10.vy = 0;
            sp10.vz = *(u16 *)(a0 + 0xE);
            sp18.vx = *(u16 *)(partner + 0x6);
            sp18.vy = 0;
            sp18.vz = *(u16 *)(partner + 0xE);
            ret = func_800132BC((s32)&sp10, (s32)&sp18);
            if (ret < 0x41) {
                *(s32 *)(partner + 0x30) -= 1;
                *(s16 *)(a0 + 0x2) = 5;
            }
            *(s32 *)(a0 + 0x1C) += 1;
        }
    }
}
