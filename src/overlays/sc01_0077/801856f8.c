/* sc01_0077: func_801856F8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { short a, b, c; } SV3;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_8012A568(void (*a0)(void));
extern void func_8012B2CC(s32 a0);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8012B2CC(int);
extern void func_8012B23C(int);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012B23C(s32 a0);
extern int func_8012BEE8(int a0);
extern void func_8012B2CC(int a0);
extern void func_8012B23C(int a0);
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8012B23C(s32 a0);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012AD80(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012BEE8(s32);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012B2CC(s32);
extern void func_8012B14C(s32 a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern void func_8012B2CC(s32 a0);
extern void func_8012B23C(s32 a0);
extern void func_8012B14C(s32 a0, s32 a1);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern void func_8012AD80(s32 a0);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern int D_801B12AC;

void func_801856F8(int param_1)
{
    SV3 in;
    SV3 out;
    short c;
    if (*(unsigned short *)(param_1 + 0x34) == 0) {
        *(short *)(*(int *)(param_1 + 0x20) + 0x12) =
            *(short *)(*(int *)(*(int *)(param_1 + 0x64) + 0x20) + 0x12);
        ((void (*)(void))func_8012B2CC)();
        func_8012B23C(param_1);
        ((void (*)(int, void *))func_8012B14C)(param_1, &D_801B12AC);
        in.a = 0;
        in.b = 0;
        in.c = 0x10;
        ((void (*)(int, void *, void *))func_8012F214)(param_1, &in, &out);
        *(short *)(param_1 + 6) = out.a;
        *(short *)(param_1 + 0xa) = out.b;
        c = out.c;
        *(int *)(param_1 + 0x1c) = 0x5a;
        *(short *)(param_1 + 0x34) = 1;
        *(short *)(param_1 + 0xe) = c;
    }
    *(short *)(*(int *)(param_1 + 0x20) + 0x10) =
        *(short *)(*(int *)(param_1 + 0x20) + 0x10) - 0x80;
    *(short *)(*(int *)(param_1 + 0x20) + 0x12) =
        *(short *)(*(int *)(param_1 + 0x20) + 0x12) + 4;
    *(short *)(*(int *)(param_1 + 0x20) + 0x14) =
        *(short *)(*(int *)(param_1 + 0x20) + 0x14) + 5;
    func_8012AD80(param_1);
    if (func_8012BEE8(param_1) != 0) {
        ((void (*)(int))func_8012C218)(param_1);
    }
}
