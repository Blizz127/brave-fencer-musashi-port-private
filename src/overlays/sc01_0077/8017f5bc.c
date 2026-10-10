/* sc01_0077: func_8017F5BC from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct buf_8017F5BC;
struct buf_8017F5BC {
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
extern void func_8012A568(void (*a0)(void));
extern s32 func_8012C51C(void *a0, s32 a1);
extern s32 func_8012C51C(void *a0, s32 a1);

void func_8017F5BC(int param_1)
{
    int iVar1;
    int c70;
    short vf4;
    register unsigned short v5c __asm__("$2");
    struct buf_8017F5BC sp;
    *(short *)(param_1 + 2) = 2;
    *(short *)(param_1 + 0x34) = 0;
    *(short *)(*(int *)(param_1 + 0x20) + 0x10) = 0;
    *(int *)(param_1 + 0xe0) = 0x100000;
    *(int *)(param_1 + 0xe4) = 0x40000;
    *(int *)(param_1 + 0x1c) = 0x10;
    c70 = *(char *)(param_1 + 0x70);
    *(int *)(param_1 + 0xdc) = 0;
    v5c = *(unsigned short *)(param_1 + 0x5c) & 0x73ff;
    *(unsigned short *)(param_1 + 0x5c) = v5c;
    if (c70 != 4) {
        sp.f0 = *(short *)(param_1 + 6) + 0xf0;
        sp.f2 = *(short *)(param_1 + 10);
        vf4 = *(short *)(param_1 + 0xe) + 0x20;
        sp.f6 = 0x2f;
        sp.f8 = 0x600;
        sp.fa = 0;
        sp.f10 = 0;
        sp.fe = 0;
        sp.f4 = vf4;
        iVar1 = ((int (*)(int, int))func_8012C51C)((int)&sp, param_1);
        if (iVar1 != 0) {
            *(short *)(*(int *)(iVar1 + 0x20) + 0x12) =
                *(short *)(*(int *)(param_1 + 0x20) + 0x12);
        }
    }
    return;
}
