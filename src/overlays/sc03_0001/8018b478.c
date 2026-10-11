/* sc03_0001: func_8018B478 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018A3A8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
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
typedef struct Prim4_8017E978_8018B478 {
    s16 f0;
    s16 f2;
} Prim4_8017E978_8018B478;
typedef struct Panel_8017E978_8018B478 {
    s16 f0;
    s16 f2;
    void *f4;
    void *f8;
    s16 fC;
    s16 fE;
    s16 f10;
    s16 f12;
    void *f14;
    Prim4_8017E978_8018B478 *f18;
    void *f1C;
} Panel_8017E978_8018B478;
extern void func_8012A568(void (*a0)(void));
extern void func_80024054(void *a0, void *a1);
extern s32 *func_800D2650(s32 *, void *, s32, s32, s32, s32);
extern s32 func_800D27DC(s32, s32 *, void *, s32, s32);
extern s32 *func_800D29F8(s32, s32, void *, s32, s32);
extern s32 *func_8018BCD4(s32 *, void *, s32, void *, s32);
extern s32 func_8018B644(void *, s32, s32, s32, s32 *);
s32 func_8018B644(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4);

s32 *func_8018B478(s32 *ot, Panel_8017E978_8018B478 *w0, s16 idx) {
    extern u16 D_8011511A;
    register Panel_8017E978_8018B478 *w __asm__("$18");
    u8 sp18[72];
    s32 sp60[2];
    register s32 zr __asm__("$0");
    s32 flag;
    s32 flag2;
    s32 flag3;
    s32 flag4;
    s16 i;
    Prim4_8017E978_8018B478 *p;
    s32 r;
    w = w0;
    flag = -(D_8011511A != idx) & 0xFF;
    func_80024054(w->f14, sp18);
    flag2 = flag + zr;
    ot = func_800D2650(ot, sp18, w->f10, w->f12, 1,
                       flag != 0 ? 0x585858 : 0x808080);
    ot = func_8018BCD4(ot, w->f18, idx, w->f8,
                       flag2 != 0 ? 0x585858 : 0x808080);
    i = 0;
    flag3 = flag2;
    p = w->f18;
    for (;;) {
        r = func_8018B644(w->f1C, w->f0, idx, i++, sp60);
        if (r == 0) {
            break;
        }
        if (r < 0) {
            func_80024054((void *)r, sp18);
            if (flag3 != 0) {
                sp60[0] += -0x282828;
            }
            ot = func_800D2650(ot, sp18, p->f0, p->f2, 1, sp60[0]);
        }
        p++;
    }
    flag4 = flag2 + zr;
    return func_800D29F8(flag4,
                         func_800D27DC(flag4 != 0, ot, w->f4, w->fC, 0),
                         w->f8, w->fE, 0);
}
