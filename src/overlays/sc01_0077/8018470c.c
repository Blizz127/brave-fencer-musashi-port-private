/* sc01_0077: func_8018470C from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct sprite8;
struct sprite8 {
    short f0;
    short f2;
    short f4;
    short f6;
    short f8;
    short fa;
    short fc;
    short fe;
    int f10;
};
typedef struct { u16 a, b, c, d; } SV4U;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04;
typedef struct {
    u8 f0, f1, f2, f3;
    struct { s16 a, b, c, d, e, g; } ent[16];
} Blk_8016CF04_8016CF04;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012C51C(void *a0, s32 a1);
extern void func_8012A828(s32, void *);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(int, void *);
extern int func_8012BEE8(int a0);
extern void func_8012A828(int a0, void *a1);
extern void func_8002D4C8(s32, s32);
extern void func_8012A828(s32 a0, void *a1);
extern void D_80196F3C;
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern void D_80196F3C;
extern void func_8012A828(s32 a0, void *a1);
extern void func_8012A828(s32 a0, void *a1);
extern s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012C51C(void *a0, s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_8002D4C8(s32 a0, s32 a1);
extern u8 D_8018AF78;
extern u8 D_8018AF88;
extern unsigned short D_80126B96;
extern void D_80196F3C;

void func_8018470C(s32 param_1)
{
    SV4U svec;
    struct sprite8 spr;
    s32 base;
    u16 uVar1;
    if (*(int *)(param_1 + 0x1c) == 9) {
        base = (s32)&D_8018AF78;
        if (func_8012D5E4(param_1, base, base + 8, 9) != 0
            && (*(unsigned short *)(param_1 + 0x70) & 1) != 0) {
            D_80126B96 = D_80126B96 | 0x800;
        }
        if ((*(short *)(param_1 + 0x70) & 0x8000) != 0) {
            func_8012F214(param_1, (s32)&D_8018AF88, (s32)&svec);
            spr.f6 = 0xda;
            spr.fa = 0;
            spr.fc = 0x7fff;
            spr.f0 = svec.a;
            spr.f2 = svec.b;
            spr.f4 = svec.c;
            spr.fe = *(u16 *)(*(int *)(param_1 + 0x20) + 0x12);
            func_8012C51C(&spr, param_1);
            spr.fe = *(u16 *)(*(int *)(param_1 + 0x20) + 0x12) + 0x100;
            func_8012C51C(&spr, param_1);
            spr.fe = *(u16 *)(*(int *)(param_1 + 0x20) + 0x12) - 0x100;
            func_8012C51C(&spr, param_1);
        }
        func_8002D4C8(0x43e, 0);
    }
    if (func_8012BEE8(param_1) != 0) {
        *(int *)(param_1 + 0x1c) = 0x3c;
        *(short *)(param_1 + 2) = 3;
        func_8012A828(param_1, &D_80196F3C);
        uVar1 = *(u16 *)(*(int *)(param_1 + 0x78) + 2);
        *(short *)(param_1 + 0x5e) = 0;
        *(short *)(param_1 + 0xdc) = 0;
        *(int *)(param_1 + 0x1c) = 0x2d;
        *(short *)(param_1 + 0x5c) = uVar1;
    }
}
