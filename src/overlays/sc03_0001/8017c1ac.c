/* sc03_0001: func_8017C1AC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8017AE2C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef struct { s16 a, b, c, d; } SV4;
typedef struct {
    s32 op;
    union {
        s32 w;
        void *p;
        s16 h[2];
        u16 uh[2];
    } a;
} Cmd_80178D40;
extern void func_80049A1C(void *a0, void *a1);
extern void func_8012A568(void (*a0)(void));
extern s16 D_801EE880;
extern void func_80049A1C(void *a0, void *a1);
extern s16 D_801EE880;

void func_8017C1AC(s32 param_1)
{
    SV4 sv4;
    s32 s0;
    s32 a1;
    s0 = *(s32 *)(param_1 + 0x20);
    sv4.a = -0x20;
    sv4.c = 0;
    sv4.b = D_801EE880;
    a1 = *(s32 *)(s0 + 0x34);
    func_80049A1C(&sv4, a1);
}
