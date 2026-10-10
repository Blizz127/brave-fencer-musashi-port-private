/* sc01_0077: func_8017A3D8 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80178D40.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern short D_801DA754;
extern short D_801DA750;
extern int func_800D0CA0(int);
extern int func_8001AAA0(void);
extern int func_800D0CE0(void);

int func_8017A3D8(void)
{
    switch (D_801DA754) {
    case 0:
        func_800D0CA0(1);
        D_801DA754 = D_801DA754 + 1;
        return 0;
    case 100:
    {
        register int a __asm__("$4");
        a = D_801DA750;
        if (a != -1) {
            return func_8001AAA0() != 0;
        }
        return func_800D0CE0() == 1;
    }
    default:
        D_801DA754 = D_801DA754 + 1;
        if (D_801DA754 < 0x1E) {
            return 0;
        }
        D_801DA754 = 100;
        return 0;
    }
}
