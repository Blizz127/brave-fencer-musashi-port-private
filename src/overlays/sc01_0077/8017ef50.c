/* sc01_0077: func_8017EF50 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
struct vec;
struct vec {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};
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

void func_8017EF50(s32 param_1)
{
    extern void func_8012931C(struct vec *a0);
    extern void func_801292C8(u8 *a0);
    register unsigned short c __asm__("$5");
    int d;
    register int g __asm__("$6");
    int a;
    int e;
    ((void (*)(int))func_8012931C)(((int)param_1));
    a = *(int *)(((int)param_1) + 0x10);
    c = *(unsigned short *)(((int)param_1) + 0x34);
    e = *(int *)(((int)param_1) + 0x2c);
    __asm__ __volatile__("" : : "r"(a));
    d = *(int *)(((int)param_1) + 0x30);
    {
        unsigned short cp1 = c + 1;
        *(int *)(((int)param_1) + 0x10) = a + e;
        *(unsigned short *)(((int)param_1) + 0x34) = cp1;
    }
    *(int *)(((int)param_1) + 8) = *(int *)(((int)param_1) + 8) + 0x10000;
    *(int *)(((int)param_1) + 0x18) = *(int *)(((int)param_1) + 0x18) + d;
    g = *(short *)(((int)param_1) + 0xa);
    if (g > *(short *)(((int)param_1) + 0x36)) {
        ((void (*)(int))func_801292C8)(((int)param_1));
    } else if (*(short *)(((int)param_1) + 0x34) == 8) {
        *(int *)(((int)param_1) + 0x2c) = -*(int *)(((int)param_1) + 0x2c);
        *(int *)(((int)param_1) + 0x30) = -*(int *)(((int)param_1) + 0x30);
        *(int *)(((int)param_1) + 0x14) = -*(int *)(((int)param_1) + 0x14);
    } else if (*(short *)(((int)param_1) + 0x34) == 0x10) {
        *(short *)(((int)param_1) + 0x34) = 0;
        *(int *)(((int)param_1) + 0x14) = -*(int *)(((int)param_1) + 0x14);
    }
}
