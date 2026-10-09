/* SC02.CD member35: func_80174E9C from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
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
s32 func_80174F28(void *a0);

void func_80174E9C(s32 a0) {
    D_8012697C = a0;
    D_80126980 = 0;
    func_8012A018((s32)func_80174F28, 0);
}
extern u16 D_80126980;
