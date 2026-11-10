/* sc02_0037: func_80134510 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_80131340.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
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
typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    s16 f6;
} Foo_80134510;
s32 func_801345F8(s32 arg);

s32 func_80134510(s32 param) {
    extern s32 func_801345F8(s32);
    extern Foo_80134510 * D_8018419C;
    extern Foo_80134510 * D_801841A0;
    extern Foo_80134510 * D_801841A4;
    extern s32 D_801C8418;
    extern u16 D_801C8428;
    s32 ret = 0;
    Foo_80134510 *b0 = D_801841A0;
    Foo_80134510 *ac = D_8018419C;
    u16 t0 = ((Foo_80134510 *)param)->f0;
    u16 t2, t4;
    ((Foo_80134510 *)param)->f6 = 0;
    ac->f0 = t0;
    b0->f0 = t0;
    t2 = ((Foo_80134510 *)param)->f2;
    ac->f2 = t2 - 4;
    b0->f2 = t2 + 0x2FC;
    t4 = ((Foo_80134510 *)param)->f4;
    ac->f4 = t4;
    b0->f4 = t4;
    if (func_801345F8(D_801C8418) != 0) {
        s16 x;
        ((Foo_80134510 *)param)->f2 = D_801841A4->f2 - 2;
        x = D_8018419C->f6;
        if (x >= -3019) {
            if (x < -1400) {
                ret = 0x4000;
            } else {
                ret = 0x8000;
            }
        } else {
            ret = 0x2000;
        }
        D_8018419C->f6 = D_801C8428;
    }
    return ret;
}
