/* sc03_0001: func_80180BCC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, s32);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012A828(s32, s32);
extern void func_8012A828(s32, s32);
extern short D_801C3B38;
extern void func_80188A78(s32 a0, s32 a1, s32 a2);
extern void func_8012E88C(s32);
extern void func_8012A828(s32, s32);
extern void func_80187750(s32);
extern void func_80187994(s32, s32, s32, s32);
extern void func_8012E88C(s32 a0);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_80187750(s32 a0);
extern void func_80188A78(s32 a0, s32 a1, s32 a2);
extern void func_80187994(s32 a0, s32 a1, s32 a2, s32 a3);

void func_80180BCC(void *arg0) {
    extern short D_801C3B38;
    extern short D_801B92FC;
    s32 s0;
    s0 = (s32)arg0;
    *(short *)((char *)arg0 + 0x2) = 3;
    func_8012E88C((s32)arg0);
    ((void (*)(s32 *, s32))func_8012A828)((s32 *)s0, (s32)&D_801C3B38);
    func_80187750((s32)s0);
    func_80188A78((s32)s0, 0xC, 1);
    func_80187994((s32)s0, (s32)&D_801B92FC, 0, 0x40);
}
