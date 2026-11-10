/* sc02_0037: func_8013FAF8 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013F350.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { s32 w[8]; } Blk20;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
typedef struct { u8 d[0x60]; } Blk60;
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
typedef struct { s16 x; s16 y; } Hw4;
typedef struct { u16 f0; s16 f2; } Prim4;
typedef struct { s32 f0; u32 *f4; s32 f8; s32 fC; s32 f10; } Rec20;
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern s32 func_8005A600(s32, s32, s32, s32, s32);
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern int func_80137D08(int arg0, int arg1, short arg2);
extern s32 func_8013AB54(s32 a0, s32 a1, s32 a2, s32 a3);
extern s16 func_8014168C(s16 a0);
extern s16 D_80115128;
extern s16 func_8014168C(s16 a0);
extern void func_80140E6C(void);
extern void func_80140F00(void);
extern s32 *func_80140958();
extern int func_80141100(int);
extern s16 func_8014168C(s16);
extern s32 func_8013FFD8(s16, s32, s32 *);
extern void func_80024054(void *a0, void *a1);
extern s32 *func_800D2650(s32 *, void *, s32, s32, s32, s32);
extern s32 func_8005A600(s32, s32, s32, s32, s32);
extern s32 func_800D27DC(s32, s32 *, void *, s32, s32);
extern s32 *func_800D29F8(s32, s32, void *, s32, s32);
extern int func_80137D08(int arg0, int arg1, short arg2);
extern s32 func_8013AB54(s32 a0, s32 a1, s32 a2, s32 a3);
s32 func_8013FFD8(s16 arg0, s32 arg1, s32 *arg2);
s32 *func_80140958();
void func_80140E6C(void);
void func_80140F00(void);
int func_80141100(int param_1);
s16 func_8014168C(s16 a0);

void func_8013FAF8(s16 arg0, s16 arg1) {
    extern s32 D_801151D0;
    extern u16 D_8011511A;
    extern Hw4 D_8011516A[];
    extern u8 D_80078EC0;
    extern Rec20 D_800AE7B8[];
    extern Blk60 D_8018460C[];
    extern Blk20 D_8018490C[];
    extern Prim4 D_80184A0C[];
    extern Prim4 D_80184A7C[];
    extern Prim4 *D_80184B70[];
    extern s32 D_80184B90[];
    extern u8 D_80184BB0;
    extern s16 D_80184F84;
    extern s16 D_80184F86;
    u8 sp18[72];
    s32 sp60[2];
    s32 *ot;
    s16 i;
    s16 j;
    s32 flag;
    s32 addr;
    Prim4 *p;
    s32 r;
    s32 t;
    s16 *pp;
    s32 flag2;
    register s32 flag3 __asm__("$18");
    func_80140E6C();
    func_80140F00();
    ot = func_80140958((s32 *)D_801151D0, arg0, arg1);
    if (D_8011511A < 6) {
        ot = (s32 *)func_80141100((int)ot);
    }
    for (i = arg0; i < arg1; i++) {
        if (i == D_8011511A || i == 2 || i == 4) {
            flag = 0;
        } else {
            flag = 0xFF;
        }
        p = &D_80184A0C[i];
        if (i != 5) {
            if (i == 2) {
                addr = ((s32 *)&D_80184BB0)[*(s16 *)&D_80115128];
            } else {
                addr = D_80184B90[i];
            }
        } else {
            addr = func_8013FFD8(2, func_8014168C(2), sp60);
        }
        func_80024054(addr, sp18);
        ot = func_800D2650(ot, sp18, (s16)(p->f0 + (u16)D_8011516A[i].x), p->f2, 1,
                           flag != 0 ? 0x585858 : 0x808080);
        p = D_80184B70[i];
        j = 0;
        if (p != 0) {
            if (i == 2 && *(s16 *)&D_80115128 != 0) {
                p = D_80184A7C;
            }
            flag2 = flag;
            for (;;) {
                r = func_8013FFD8(i, j++, sp60);
                if (r == 0) {
                    break;
                }
                if (r < 0) {
                    func_80024054(r, sp18);
                    t = 1;
                    if (i == 0 && (D_80078EC0 & 0x7F) == j) {
                        t = 0xB6;
                    }
                    if (flag2 != 0) {
                        sp60[0] += -0x282828;
                    }
                    ot = func_800D2650(ot, sp18, (s16)(p->f0 + (u16)D_8011516A[i].x), p->f2, t, sp60[0]);
                }
                p++;
            }
        }
        func_8005A600((s32)ot, 0, 0, 0x15, 0);
        flag3 = flag;
        *ot = 0x2000000;
        *ot = (D_800AE7B8[*(u16 *)&D_800B9A02].f4[2] & 0xFFFFFF) | 0x2000000;
        D_800AE7B8[*(u16 *)&D_800B9A02].f4[2] =
            (D_800AE7B8[*(u16 *)&D_800B9A02].f4[2] & 0xFF000000) | ((u32)ot & 0xFFFFFF);
        ot = func_800D29F8(flag3,
                           func_800D27DC(flag3 != 0, ot + 10, &D_8018460C[i], 8, D_8011516A[i].x),
                           &D_8018490C[i], 2, D_8011516A[i].x);
    }
    pp = &D_80184F84;
    if (*pp == 0xE) {
        ot = func_80137D08(ot, &D_800AE7B8[*(u16 *)&D_800B9A02], 2);
    }
    if (*pp != 0 && D_80184F86 != 0) {
        ot = func_8013AB54(ot, D_800AE7B8[*(u16 *)&D_800B9A02].f4 + 2, (s32)(pp - 2), 0x8000);
    }
    D_801151D0 = (s32)ot;
}
