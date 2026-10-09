/* SC02.CD member35: func_80180948 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern void func_80180C10(s32 a0);
extern void func_801292C8(u8 *a0);
extern void func_80180C10(s32 a0);
extern void func_801292C8(u8 *a0);
extern void func_80180C10(s32 a0);
extern void func_801292C8(u8 *a0);
extern void func_80180C10(s32 a0);
extern s32 func_8012C51C(void *a0, s32 a1);
extern void func_801292C8(u8 *a0);
typedef struct {
    u16 vx, vy, vz;
    u16 f6, f8, fA, fC, fE;
    s32 f10;
} SV3L2;
void func_80180C10(s32 param);

void func_80180948(s32 a0) {
    SV3L2 sp10;
    func_80180C10(a0);
    *(s32 *)(a0 + 0x1C) += 1;
    if (*(s32 *)(a0 + 0x1C) >= 0x1F) {
        sp10.vx = *(u16 *)(a0 + 6);
        sp10.vy = *(u16 *)(a0 + 0xA);
        sp10.vz = *(u16 *)(a0 + 0xE);
        sp10.f6 = 0x17F;
        sp10.f8 = 0x8000;
        sp10.fA = 0;
        sp10.f10 = 0;
        sp10.fE = 0;
        sp10.fC = 0x7FFF;
        func_8012C51C((void *)&sp10, *(s32 *)(a0 + 0x24));
        func_801292C8((u8 *)a0);
    }
}
