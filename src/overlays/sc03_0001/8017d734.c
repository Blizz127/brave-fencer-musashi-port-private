/* sc03_0001: func_8017D734 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8012BE98(s32 a0, u16 *a1);
extern void func_8012A828(s32, s32);
s32 func_8017D5F0(s32 a0, s32 a1);
extern s32 func_8012B744(void *a0, void *a1);
extern s32 func_8012BE98(s32 a0, u16 *a1);
extern void func_8012B2CC(s32 a0);
extern void func_8012A828(s32 a0, s32 a1);
extern s32 func_8012CBCC(s32 a0);
extern s32 func_8012E544(s32 a0);
extern s32 func_8017D5F0(s32 a0, s32 a1);
extern void func_8012B1B4(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s16 D_80191010;
extern s16 D_801BE3F0;
extern s16 D_801BE498;
extern s16 D_8019102C;

void func_8017D734(s32 param_1) {
    if (*(s16 *)(param_1 + 0x100) > 0) {
        if (func_8012CBCC(param_1) & 0x6000) {
            *(s16 *)(param_1 + 0x16) = -4;
        }
        {
            s32 r = func_8012E544(0xAD);
            if (r != 0) {
                func_8017D5F0(param_1, r);
            }
        }
        if (*(s16 *)(param_1 + 0xA) < *(s16 *)(param_1 + 0x8A) - 0x30) {
            *(u16 *)(param_1 + 0xE) = *(u16 *)(param_1 + 0xE) + 0x40;
        }
    }
    if (--*(s32 *)(param_1 + 0x1C) == 0) {
        s32 phase = (u16)(*(u16 *)(param_1 + 0x100) + 1) & 3;
        *(u16 *)(param_1 + 0x100) = phase;
        if (phase == 0) {
            *(s32 *)(param_1 + 0x1C) = 0x14;
            func_8012A828(param_1, (s32)&D_801BE3F0);
        } else if (phase >= 0) {
          if (phase < 4) {
            u16 *s1 = (u16 *)&D_80191010;
            s32 t;
            *(s32 *)(param_1 + 0x1C) = 0x1E;
            func_8012A828(param_1, (s32)&D_801BE498);
            t = func_8012BE98(param_1, s1);
            if (t < 0x4000) {
                s32 r2 = func_8005C49C();
                s32 v1 = *(s32 *)(param_1 + 0x20);
                *(u16 *)(v1 + 0x12) = *(u16 *)(v1 + 0x12) + (r2 & 0x1FF);
            } else {
                s32 v0 = func_8012B744((void *)(param_1 + 4), s1);
                s32 v1 = *(s32 *)(param_1 + 0x20);
                *(u16 *)(v1 + 0x12) = (u16)v0;
            }
            func_8012B2CC(param_1);
            func_8012B1B4(param_1, (s32)&D_8019102C);
          }
        }
    }
}
