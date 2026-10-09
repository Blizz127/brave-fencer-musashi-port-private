/* SC02.CD member35: func_80183A14 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern s32 *D_80126B78;
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern u8 D_801152A8[];
extern u8 D_801152A8[];
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012B2CC(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B2CC(s32 a0);
extern s32 func_8005C49C(void);
extern void func_8012B178(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8018016C(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8012B178(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8012B2CC(s32 a0);
extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern s32 func_80135888(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F568(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
extern u8 D_801152A8[];
extern s32 D_80198E04;
extern s32 *D_80126B78;
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1)
{
    s32 *m;
    s32 b1[2];
    s32 b2[2];
    m = &D_80198E04;
    func_8012F14C((s32)D_80126B78 + 0x34, (s32)m, (s32)b1);
    func_8012F14C((s32)D_80126B78 + 0x34, (s32)(m + 2), (s32)b2);
    if (func_80135888(*(s32 *)(a0 + 0x20), *(s32 *)(a0 + 0x58), (s32)b1, (s32)b2) == 0) {
        return 0;
    }
    func_8012F568(1,
                  (*(u16 *)(a0 + 0x70) & 0xF) != 0 ? 0x2001 : 1,
                  *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12),
                  a1,
                  (s32)b2,
                  (s32)D_801152A8);
    return 1;
}
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);
extern s32 func_8005C49C(void);
extern void func_8012B2CC(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B2CC(s32 a0);
extern void func_8012B2CC(s32 a0);
extern s32 func_8005C49C(void);
extern void func_8012B2CC(s32 a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B200(void *a0);
extern void func_80183E68(s32 *a0, s32 a1, s32 a2);
extern void func_8012B178(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B200(void *a0);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);
extern void func_8012B178(s32 a0, s32 a1);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8012B0B4(unsigned int *param_1, int param_2, int param_3);
extern void func_80183E68(s32 *a0, s32 a1, s32 a2);
extern void func_8012B200(void *a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012B178(s32 a0, s32 a1);
void func_80183E68(s32 *a0, s32 a1, s32 a2);

void func_80183A14(s32 a0) {
    s16 sp10[4];
    s32 sp18[2];
    s16 r;
    s32 t;
    s32 u;
    r = func_8005C49C();
    func_8012B0B4((unsigned int *)sp18, (s16)(r % 4095), (s16)(r % 128) + 0xC0);
    t = sp18[0];
    sp10[1] = -0x30;
    sp10[0] = t;
    sp10[2] = t >> 16;
    func_80183E68(sp18, a0, (s32)sp10);
    u = sp18[0];
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x10) = u;
    *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12) = u >> 16;
    func_8012B200((void *)a0);
    func_8012B2CC(a0);
    func_8012B178(a0, *(s32 *)(a0 + 0xE4) + 0xFFFE0000);
    *(s16 *)(a0 + 0x2) = 6;
    *(s16 *)(a0 + 0x34) = 0;
}
