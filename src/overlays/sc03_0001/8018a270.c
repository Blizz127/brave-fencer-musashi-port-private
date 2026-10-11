/* sc03_0001: func_8018A270 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_80189030.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
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
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A568(void (*a0)(void));
extern short D_800B9A02;
extern s16 D_800B9A02;
extern void func_8002D4C8(s32 arg0, s32 arg1);
extern s16 D_801EEB10;
extern u16 D_8011511A;

void func_8018A270(void) {
    extern s32 D_801151D0;
    extern s32 D_801151C8[];
    extern u16 xf02 __asm__("D_800B9A02");
    extern s16 xa __asm__("D_8011511A");
    extern u16 xb __asm__("D_8011511A");
    extern s32 func_8014168C(s32 a0);
    extern u8 D_80115138[];
    extern s32 D_801EF1E0;
    extern s32 D_80115130;
    extern void func_80139954(void);
    extern s32 func_801376E8(s32 a0, s32 a1);
    extern s32 D_801C17F0;
    extern s32 D_801EF1E4;
    extern void func_80137B80(void);
    extern s32 func_8018AEE8(void);
    extern void func_8018B238(void);
    extern s32 func_8018B8DC(s32 a0, s32 a1);
    extern u8 D_800B9A15;
    extern s16 D_801EEB10;
    extern u16 D_80115112;
    s32 pad[2];
    s32 v;
    s32 r2;
    s32 ret;
    s16 rn;
    s32 b;
    s32 *p30;
    u16 *p12;
    D_801151D0 = ((s32 *)D_801151C8)[xf02];
    ret = func_8018AEE8();
    func_8018B238();
    r2 = func_8014168C(xa);
    b = D_80115138[xb];
    if (D_801EF1E0 == 0) {
        v = func_8018B8DC(b, (s16)r2);
    } else {
        v = D_801EF1E0;
    }
    if (v != 0) {
        p30 = &D_80115130;
        if (v != *p30) {
            *p30 = v;
            func_80139954();
            D_801EF1E4 = func_801376E8(v, &D_801C17F0);
        }
    }
    func_80137B80();
    rn = ret;
    if (rn < 0) {
        func_80139954();
        D_800B9A15 = 0;
        if (D_801EEB10 == 0) {
            func_8002D4C8(0x474, 0);
        }
        p12 = &D_80115112;
        *p12 += 2;
    }
}
