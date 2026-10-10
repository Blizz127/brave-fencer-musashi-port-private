/* sc01_0077: func_80156370 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80154C24.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { s32 a, b, c; } S801563EC;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern S801563EC *func_801563EC(u16 idx);
extern s32 func_8005C49C(void);
extern S801563EC *func_801563EC(u16 idx);
extern s32 func_8005C49C(void);
S801563EC *func_801563EC(u16 idx);

u16 func_80156370(u16 param_1) {
    u16 *puVar3;
    u16 uVar1;
    u16 uVar2;
    s32 iVar4;
    s32 iVar5;
    puVar3 = ((u16 * (*)(s32))func_801563EC)(param_1 & 0xFFFF);
    uVar1 = puVar3[0] & 0xfff;
    uVar2 = puVar3[1];
    iVar4 = func_8005C49C();
    iVar5 = uVar2 + 1;
    return (u16)(uVar1 + iVar4 % iVar5);
}
