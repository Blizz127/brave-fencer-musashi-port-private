/* sc03_0098: func_80174EF0 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
extern void func_8012A568(void (*a0)(void));
extern void func_8012A018(s32 a, s32 b);
extern void func_8012A018(s32 a, s32 b);
extern void func_8012A018(s32 a, s32 b);
extern s32 D_8012697C;
extern u16 D_80126980;
extern s32 func_80174F28(void *a0);
extern u16 D_80126980;
extern void func_8012A018(s32 a, s32 b);
extern s32 D_8012697C;
extern u16 D_80126980;
extern s32 func_80174F28(void *a0);
s32 func_80174F28(void *a0);

void func_80174EF0(s32 a0, s16 a1) {
    D_8012697C = a0;
    D_80126980 = a1;
    func_8012A018((s32)func_80174F28, 1);
}
