/* sc03_0001: func_80158F00 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
struct Actor;
struct Actor {
    char pad0[0x12];
    u16 timer;
};
extern void func_80146CA0(void *a0);
extern s32 func_8005C49C(void);
extern s32 D_801ED524;
extern int D_801ED524;
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern s32 D_801ED524;
extern s32 D_8018F87C[];
extern int func_8005C49C(void);
extern s32 func_8013767C(s32 a0);
extern void func_80146CA0(void *a0);

void func_80158F00(int param_1) {
    int *self = (int *)param_1;
    struct Actor *act = (struct Actor *)self[0x20 / 4];
    int gate = D_801ED524;
    act->timer = (u16)((act->timer + 0x16) & 0xfff);
    if (gate == 0) {
        s32 r = func_8005C49C();
        *(s32 *)(param_1 + 0x198) = func_8013767C(D_8018F87C[r % 0xb]);
        ((void (*)(int))func_80146CA0)(param_1);
    }
}
