/* sc03_0001: func_8018B238 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018A3A8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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
typedef struct { s16 x, y, z, pad; } SVEC_80167AE0;
typedef struct { s16 x, y, z, pad; } SVEC_8016A290;
typedef void (*code)(unsigned short *);
struct Fr {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_80167AE0 {
    u8 matrix[0x20];
    SVEC_80167AE0 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
struct Fr_8016A290 {
    SVEC_8016A290 center;
    SVEC_8016A290 diff;
    s32 pos[3];
    s32 _pad1c;
    s16 mtx[32];
    SVEC_8016A290 v[4];
    struct { u8 r, g, b, pad; } col[4];
    u32 code;
};
typedef struct { s16 x, y, z, pad; } SVec_801670E4;
typedef struct {
               u16 cx, cy, cz;
               u16 _p06;
               u16 a8[4];
               s32 pos[3];
               s32 _p1C;
               SVec_801670E4 v[4];
               struct { u8 r, g, b, cd; } col[4];
               u32 code;
               s32 _p54;
               u8 m1[0x20];
               u8 m2[0x20];
} Fr_801670E4;
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
extern short D_800B9A02;
extern s16 D_800B9A02;
extern s16 D_800B9A02;
extern s32 D_801151D0;
extern s16 D_80115126;
extern s16 D_801EF274;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_S40_8018B238;
typedef struct { u32 w; } W_S40_8018B238;
typedef struct { u32 *ot; u32 pad[4]; } Env_S40_8018B238;
typedef struct { s16 v; } Flag_S40_8018B238;
typedef struct Panel_S40_8018B238 {
    s16 f0;
    s16 f2;
    void *f4;
    void *f8;
    s16 fC;
    s16 fE;
    s16 f10;
    s16 f12;
    void *f14;
    void *f18;
    void *f1C;
} Panel_S40_8018B238;

void func_8018B238(void) {
    extern short D_800B9A02;
    extern u16 aD800B9A02 __asm__("D_800B9A02");
    extern Env_S40_8018B238 D_800AE7B8[];
    extern Env_S40_8018B238 D_800AE7BC[];
    extern s32 D_801151D0;
    extern Panel_S40_8018B238 *D_80115134;
    extern s16 D_801EF274;
    extern s16 D_80115126;
    extern u16 D_8011511A;
    extern Flag_S40_8018B238 D_80115158[];
    extern u8 D_801C0E80[];
    extern u8 D_801C0E94[];
    extern u8 D_801C17E8[];
    extern Panel_S40_8018B238 D_801C1568;
    extern int func_80137D08(int arg0, int arg1, short arg2);
    extern s32 func_800D27DC(s32, s32 *, void *, s32, s32);
    extern s32 func_8013AB54(s32 a0, s32 a1, s32 a2, s32 a3);
    extern s32 *func_8018B478(s32 *ot, Panel_S40_8018B238 *w0, s16 idx);
    extern s32 func_8005A600(s32, s32, s32, s32, s32);
    Panel_S40_8018B238 *w;
    s32 *ot;
    s32 n;
    s32 cnt;
    register s32 zr __asm__("$0");
    s16 i;
    volatile u16 *pbh;
    w = D_80115134;
    ot = (s32 *)func_80137D08(D_801151D0, (int)&D_800AE7B8[aD800B9A02], 2);
    if (D_801EF274 == 3 || D_801EF274 == 7) {
        ot = (s32 *)func_800D27DC(2, ot, D_801C0E94, 1, 0);
    } else {
        ot = (s32 *)func_800D27DC(2, ot, D_801C0E80, 1, 0);
    }
    ot = (s32 *)func_8013AB54((s32)ot, (s32)(D_800AE7BC[aD800B9A02].ot + 2),
                              (s32)D_801C17E8, 0);
    if (D_80115126 == 3) {
        if (D_8011511A == 3) {
            ot = func_8018B478(ot, &D_801C1568, 3);
            n = 3 + zr;
        } else {
            n = 4;
        }
    } else {
        n = 3 + zr;
    }
    i = 0;
    if (n != 0) {
        cnt = n;
        do {
            if (D_80115158[i].v != 0) {
                __asm__("");
                ot = func_8018B478(ot, w, i);
            }
            i++;
            w++;
        } while (i < cnt);
    }
    func_8005A600((s32)ot, 0, 0, 0x15, 0);
    pbh = (u16 *)&D_800B9A02;
    ((W_S40_8018B238 *)ot)->w = 0x02000000;
    ((PTag_S40_8018B238 *)ot)->addr =
        ((PTag_S40_8018B238 *)(D_800AE7BC[*pbh].ot + 2))->addr;
    ((PTag_S40_8018B238 *)(D_800AE7BC[*pbh].ot + 2))->addr = (u32)ot;
    ot += 10;
    __asm__ __volatile__("" ::: "memory");
    D_801151D0 = (s32)ot;
}
