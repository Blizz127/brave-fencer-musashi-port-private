/* SC02.CD member35: func_80181F50 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_8017BEBC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern int func_8005C49C(void);
extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012C218(void *a0);
extern void func_8012C218(void *a0);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8018016C(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_80182318_def(s32 a0, s32 a1) __asm__("func_8018016C");
s32 func_80182318_def(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8012C218(void *a0);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8005C49C(void);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s32 func_8012B77C(s32 out, s32 from, s32 to);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012C218(void *a0);
extern s32 func_80143C74(s32 a0, s32 a1);
extern s32 func_8005C49C(void);

void func_80181F50(s32 param_1)
{
    extern s32 D_801151D4;
    s32 sp10[4];
    s32 sp20;
    s32 v0;
    s32 v1;
    v0 = *(s32 *)(param_1 + 0x1C);
    v1 = D_801151D4;
    *(s32 *)(param_1 + 0x1C) = v0 - 1;
    *(s16 *)((s32)sp10 + 0x2) = *(s32 *)(v1 + 0x5C);
    *(s16 *)((s32)sp10 + 0x6) = *(s32 *)(v1 + 0x60);
    *(s16 *)((s32)sp10 + 0xA) = *(s32 *)(v1 + 0x64);
    func_8012B77C((s32)&sp20, param_1 + 4, (s32)sp10);
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x10) = (sp20 + 0x400) & 0xFFF;
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x18) += 0x55;
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x1A) += 0x55;
    v1 = *(s32 *)(param_1 + 0x1C);
    if (v1 == 0xF) {
        func_8002D4C8(0xCBA, 0);
        v1 = *(s32 *)(param_1 + 0x1C);
    }
    if (v1 < 0x10) {
        if (v1 == 0) {
            func_8012C218((void *)param_1);
        } else {
            param_1 = func_80143C74(param_1, 0);
            if (param_1 != 0) {
                *(s16 *)(param_1 + 0x16) = -4;
                v0 = func_8005C49C();
                *(s16 *)(param_1 + 0x12) = (v0 & 7) - 4;
                v0 = func_8005C49C();
                *(s16 *)(param_1 + 0x1A) = (v0 & 7) - 4;
                v0 = func_8005C49C();
                { s32 t = *(u16 *)(param_1 + 0x6) - 0x10; *(s16 *)(param_1 + 0x6) = t + (v0 & 0x1F); }
                v0 = func_8005C49C();
                { s32 t = *(u16 *)(param_1 + 0xE) - 0x10; *(s16 *)(param_1 + 0xE) = t + (v0 & 0x1F); }
            }
        }
    }
}
