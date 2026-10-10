/* sc03_0098: func_8017C940 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
void func_8017BEBC(s32 param_1, s32 param_2);
extern s32 func_8005C49C(void);
extern void func_8017BEBC(s32 a0, s32 a1);
extern s16 func_80128CFC(u16 a0);
extern void func_8017BEBC(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s16 func_80128CFC(u16 a0);
extern void func_8017BEBC(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern u16 D_801152BA;
extern s16 D_80115214;

void func_8017C940(void *a0) {
    void *v1;
    void *s2;
    void *s1;
    u16 arg;
    s16 v0_s16;
    u16 tmp;
    s32 v0;
    s32 rand_val;
    s32 pads[4];
    v1 = *(void **)(a0 + 0xDC);
    s2 = *(void **)(a0 + 0xCC);
    s1 = *(void **)(a0 + 0xD0);
    if (*(u8 *)(v1 + 1) != 0) {
        if (*(s16 *)(a0 + 0x108) == 0) {
            arg = *(u16 *)(v1 + 2);
            v0_s16 = func_80128CFC(arg);
            *(s16 *)(a0 + 0x108) = v0_s16;
        }
    }
    tmp = *(u16 *)((s32)s1 + 0x1A) + 0x20;
    *(u16 *)((s32)s1 + 0x1A) = tmp;
    *(u16 *)((s32)s1 + 0x18) = tmp;
    v0 = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 != -1) {
        rand_val = func_8005C49C();
        func_8017BEBC((s32)a0, rand_val & 1);
    } else {
        D_80115214 = 4;
        D_801152BA -= 1;
        func_8002D4C8(0x62E, 0);
        *(u16 *)s2 = 0;
        *(u16 *)(a0 + 2) += 1;
        *(s32 *)(a0 + 0x1C) = 0x28;
    }
}
