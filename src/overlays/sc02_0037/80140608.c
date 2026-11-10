/* sc02_0037: func_80140608 from Druthulu/BFM-decomp
 * src/ov_SC02_037/ov_SC02_037_jr_8013F350.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0037 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
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
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void func_80019064(void *);
extern void *memcpy(void *, const void *, u32);
extern void func_80019064(void *a0);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern u16 D_8011511E;
extern u16 D_8011511E;
extern void func_8002D4C8(s32 a0, s32 a1);
extern u8 D_80115148[];
extern u16 D_8011511E;
extern u8 D_80062BDC;
extern s32 func_80028D58(void);
extern void func_80028D78(s32 a0);
extern void func_80019064(void *a0);
extern s32 func_80028DE0(void);
extern void func_80028E00(s32 a0);
extern s32 func_80028FBC(void);
extern void func_80028FDC(s32 a0);
extern s32 func_80029000(void);
extern void func_80029020(s32 a0);
extern s32 func_80028D9C(void);
extern void func_80028DBC(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);

s32 func_80140608(s32 a0) {
    s16 t;
    s32 iVar2;
    register s32 zr __asm__("$0");
    s32 uVar3;
    u32 uVar4;
    s32 uVar5 = 1;
    switch (D_80115148[(s16)a0 * 2]) {
    case 0:
        t = func_80028D58() ^ 1;
        func_80028D78(t);
        if (t != 0) {
            return uVar5;
        }
        func_80019064(&D_80062BDC);
        return uVar5;
    case 1:
        func_80028E00((s16)(func_80028DE0() ^ 1));
        return uVar5;
    case 2:
        iVar2 = func_80028FBC();
        if (D_8011511E & 0x8000) {
            iVar2 = iVar2 - 1;
            uVar4 = iVar2 + zr;
            if ((s16)iVar2 < 0) {
                uVar4 = 0;
                uVar5 = 0;
            }
        } else {
            iVar2 = iVar2 + 1;
            uVar4 = iVar2 + zr;
            if ((s16)iVar2 >= 8) {
                uVar4 = 7;
                uVar5 = 0;
            }
        }
        func_80028FDC((s16)uVar4);
        func_8002D4C8(0x21, uVar4 & 0xFFFF);
        goto ret;
    case 3:
        iVar2 = func_80029000();
        if (D_8011511E & 0x8000) {
            iVar2 = iVar2 - 1;
            uVar4 = iVar2 + zr;
            if ((s16)iVar2 < 0) {
                uVar4 = 0;
                uVar5 = 0;
            }
        } else {
            iVar2 = iVar2 + 1;
            uVar4 = iVar2 + zr;
            if ((s16)iVar2 >= 8) {
                uVar4 = 7;
                uVar5 = 0;
            }
        }
        func_80029020((s16)uVar4);
        func_8002D4C8(0x22, uVar4 & 0xFFFF);
        goto ret;
    case 4:
        t = func_80028D9C() ^ 1;
        func_80028DBC(t);
        uVar3 = 0xB;
        if (t == 0) {
            uVar3 = 0xC;
        }
        func_8002D4C8(uVar3, 0);
        goto ret;
    default:
        goto ret;
    }
ret:
    return uVar5;
}
