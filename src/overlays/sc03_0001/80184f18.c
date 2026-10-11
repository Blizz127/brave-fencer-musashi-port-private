/* sc03_0001: func_80184F18 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184DDC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef short s16;
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012A828(s32, s32);
extern void func_8012E88C(s32);
extern void func_80187750(s32);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012E88C(s32 a0);
extern void func_80187750(s32 a0);

void func_80184F18(s32 *arg0)
{
    extern void func_8012E88C(s32 a0);
    extern void func_8012A828(s32 a0, s32 a1);
    extern void func_80187750(s32 a0);
    extern short D_801C36E8;
    *(s16 *)((s32)arg0 + 2) = 9;
    *(s16 *)((s32)arg0 + 0x34) = 0;
    func_8012E88C((s32)arg0);
    func_8012A828((s32)arg0, (s32)&D_801C36E8);
    func_80187750((s32)arg0);
}
