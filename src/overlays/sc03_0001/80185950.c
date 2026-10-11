/* sc03_0001: func_80185950 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80184F64.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef int s32;
extern void func_8012A568(void (*a0)(void));
extern void func_8012E8E0(s32 a0, s32 a1);
extern void func_8012A828(s32, s32);
extern void func_8012E8E0(s32, s32);
extern void func_8012E88C(s32);
extern void func_80187750(s32);
extern void func_8012A828(s32 a0, s32 a1);
extern void func_8012E88C(s32 a0);
extern void func_80187750(s32 a0);
extern void func_8012A828(s32, s32);
extern void func_8012A828(s32, s32);
extern short D_80192864;
extern short D_80192864;
extern short D_80192864;
extern short D_80192864;
extern short D_80192864;
extern void func_8012E8E0(s32, s32);
extern void func_8012E88C(s32);
extern void func_8012A828(s32, s32);
extern void func_80187750(s32);

void func_80185950(void *arg0) {
    extern short D_80192864;
    extern short D_801C36E8;
    *(short *)((char *)arg0 + 0x2) = 27;
    *(short *)((char *)arg0 + 0x34) = 0;
    func_8012E8E0((s32)arg0, (s32)&D_80192864);
    func_8012E88C((s32)arg0);
    ((void (*)(s32 *, s32))func_8012A828)((s32 *)arg0, (s32)&D_801C36E8);
    func_80187750((s32)arg0);
}
