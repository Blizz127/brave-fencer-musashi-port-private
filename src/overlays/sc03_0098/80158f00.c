/* sc03_0098: func_80158F00 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801588CC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef int s32;
struct Actor;
struct Actor {
    char pad0[0x12];
    u16 timer;
};
extern void func_80146CA0(void *a0);
extern s32 func_8005C49C(void);
extern s32 D_801C436C;
extern int D_801C436C;
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern void func_80146CA0(void *a0);
extern s32 D_801C436C;
extern s32 D_80187690[];
extern int func_8005C49C(void);
extern s32 func_8013767C(s32 a0);
extern void func_80146CA0(void *a0);

void func_80158F00(int param_1) {
    int *self = (int *)param_1;
    struct Actor *act = (struct Actor *)self[0x20 / 4];
    int gate = D_801C436C;
    act->timer = (u16)((act->timer + 0x16) & 0xfff);
    if (gate == 0) {
        s32 r = func_8005C49C();
        *(s32 *)(param_1 + 0x198) = func_8013767C(D_80187690[r % 0xb]);
        ((void (*)(int))func_80146CA0)(param_1);
    }
}
