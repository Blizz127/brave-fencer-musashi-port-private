/* sc03_0001: func_8013F350 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8013F350.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
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
extern s32 func_80029178(s32);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern short D_800B9A02;
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern void func_80137030(s16 a0, s16 a1);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern u16 D_80115110;
extern u16 D_8011511A;
extern u8 D_80115140[];
extern u16 D_8011511E;
extern s16 D_8011514C;
extern s16 func_8014168C(s16 a0);
extern short D_80115128;
extern s16 D_8011512A;
extern void func_80141C0C(s32);
extern u16 D_80115110;
extern u16 D_8011511A;
extern u16 D_8011511C;
extern u16 D_8011511E;
extern u16 D_80115120;
extern u16 D_80115122;
extern s16 D_80115128;
extern s16 D_8011512A;
extern u16 D_8011512E;
extern u8 D_80115140[];
extern s16 D_8011514C;
extern s16 D_8011514E;
extern u8 D_80115152;
extern u8 D_80115158[];
extern u8 D_8011515C;
extern u8 D_8018E5A8[];
extern u8 D_8018E5C0[];
extern u16 D_8018E4C4[];
extern s32 func_80029178(s32 arg);
extern s32 func_800291B4(s32 arg);
extern s16 func_8014168C(s16 a0);
extern void func_8014AA04(s32 a0);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_801415C0(s32 a0, s32 a1);
extern void func_80141C0C(s32 a0);
extern s32 func_80140608(s32 a0);
extern void func_801407F4(void);
extern s32 func_801416D4(s16);

s32 func_8013F350(void) {
    register u16 *pd __asm__("$5") = &D_8011511C;
    u16 *ps;
    u16 *pf;
    u16 *pg;
    u16 pad;
    u16 st;
    u8 *pcur;
    u8 *pmax;
    u8 *p2e;
    u8 *p3e;
    register s32 off __asm__("$4");
    s16 i;
    s32 r;
    s16 rs;
    s16 d;
    u8 b;
    u8 bb;
    u8 m;
    s32 chg;
    __asm__ __volatile__("" : "=r"(pd) : "0"(pd));
    pad = *pd;
    chg = 0;
    if (pad != 0) {
        if (pad == pd[2]) {
            D_80115122 = D_80115122 - 1;
            if (D_80115122 == 0) {
                D_8011511E = pad & 0xF000;
                D_80115122 = 3;
            }
        } else {
            pd[2] = pad;
            D_80115122 = 6;
        }
    } else {
        D_80115120 = 0;
        D_80115122 = 0xC;
    }
    i = 0;
    do {
        if ((func_80029178(D_8018E5A8[i]) & 0xFF) == 0) {
            break;
        }
        i = i + 1;
    } while (i < 6);
    *(u16 *)D_80115158 = i | 0x100;
    switch (D_8011511A) {
    case 0:
        r = ((s32 (*)(s32))func_8014168C)(0);
        rs = (s16)r;
        if ((func_80029178(D_8018E5A8[rs]) & 0xFF) != 0 && (D_8011511E & 0x40) != 0) {
            func_8014AA04((r + 1) & 0xFF);
            if (rs != 0) {
                func_8002D4C8(0x461, 0);
            } else {
                func_8002D4C8(0x460, 0);
            }
        }
        break;
    case 1:
        if ((D_8011511E & 0x40) != 0) {
            D_80115128 = ((s32 (*)(s32))func_8014168C)(1) + 1;
            D_8011511A = 2;
            func_80141C0C(3);
            return 1;
        }
        if (D_80115128 != 4) {
            break;
        }
        goto tail7;
    case 2:
        switch (D_80115128) {
        case 0:
            break;
        case 1:
            r = ((s32 (*)(s32))func_8014168C)(2);
            pf = &D_8011511E;
            if ((*pf & 0x40) != 0) {
                if ((*(s16 *)&D_8011512E) == 0) {
                    if ((func_800291B4(D_8018E5C0[(s16)r]) & 0xFF) != 0 && (*pf & 0x40) != 0) {
                        D_8011511A = 5;
                        *(s16 *)&D_80115152 = 0;
                        func_80141C0C(3);
                        return 1;
                    }
                    func_80141C0C(5);
                } else {
                    func_801415C0((s16)r, (*(s16 *)&D_8011512E) & 0xF);
                    D_8011512E = 0;
                    func_80141C0C(3);
                    return 1;
                }
            } else if ((*pf & 0x20) != 0) {
                if ((*(s16 *)&D_8011512E) == 0) {
                    D_8011512E = r | 0x8000;
                } else {
                    func_801415C0((s16)r, (*(s16 *)&D_8011512E) & 0xF);
                    D_8011512E = 0;
                }
                func_80141C0C(3);
            }
            break;
        case 4:
            if ((D_8011511E & 0xA000) != 0) {
                chg = func_80140608(2);
            }
            func_801407F4();
            break;
        case 2:
            break;
        case 3:
            break;
        }
        if (D_80115128 != 0 && (D_8011511E & 0x10) != 0 && D_80115110 != 1) {
            D_8011511E = D_8011511E & 0xFFEF;
            D_8011511A = 1;
            D_8011512E = 0;
            func_80141C0C(6);
        }
        break;
    case 3:
        if (D_8011514E == 0 && (D_8011511E & 0x40) != 0) {
            D_8011511A = D_8011511A + 3;
            func_80141C0C(3);
            return 1;
        }
        break;
    case 5:
        if ((D_8011511E & 0x40) != 0) {
            rs = (s16)((s32 (*)(s32))func_801416D4)(D_80115152);
            if (rs != 0) {
                if (rs < 0) {
                    D_8011512A = 1;
                } else {
                    D_8011511A = D_8011511A - 3;
                    func_80141C0C(4);
                    return 1;
                }
            }
            break;
        }
        if ((D_8011511E & 0x10) != 0) {
            goto tail6;
        }
        break;
    case 6:
        if ((D_8011511E & 0x10) == 0) {
            break;
        }
    tail6:
        pg = &D_8011511E;
        *pg = *pg & 0xFFEF;
        D_8011511A = D_8011511A - 3;
        func_80141C0C(6);
        return 1;
    case 7:
        if ((D_8011511E & 0xA000) != 0) {
            chg = func_80140608(7);
        }
    tail7:
        func_801407F4();
        break;
    }
    ps = &D_8011511A;
    st = *ps;
    p2e = (u8 *)ps + 0x2E;
    p3e = (u8 *)ps + 0x3E;
    off = st << 1;
    pcur = p2e + off;
    pmax = p3e + off;
    if (st == 2 || 1 < pmax[0]) {
        if ((D_8011511E & 0x1000) != 0) {
            pcur[0] = pcur[0] - 1;
            chg = 1;
            if (0x7F < pcur[0]) {
                if (D_8011511A != 3) {
                    pcur[0] = pmax[0] - 1;
                } else {
                    pcur[0] = 0;
                    chg = 0;
                }
            }
        }
        if ((D_8011511E & 0x4000) != 0) {
            b = pcur[0];
            pcur[0] = b + 1;
            chg = 1;
            if (pmax[0] <= (u8)(b + 1)) {
                if (D_8011511A != 3) {
                    pcur[0] = 0;
                } else {
                    pcur[0] = b;
                    chg = 0;
                }
            }
        }
        if (D_8011511A == 2 && D_80115128 == 1) {
            if ((D_8011511E & 0x8000) != 0) {
                pcur[1] = pcur[1] - 1;
                chg = 1;
                if (0x7F < pcur[1]) {
                    pcur[1] = pmax[1] - 1;
                }
            }
            if ((D_8011511E & 0x2000) != 0) {
                pcur[1] = pcur[1] + 1;
                chg = 1;
                if (pmax[1] <= pcur[1]) {
                    pcur[1] = 0;
                }
            }
        } else {
            bb = pcur[0];
            m = D_80115140[D_8011511A];
            d = (s8)bb - (s8)m;
            if (d > 0) {
                D_80115140[D_8011511A] = bb;
            } else if (d < 0) {
                D_80115140[D_8011511A] = bb;
            }
        }
        if (D_8011511A == 1) {
            D_80115128 = ((s32 (*)(s32))func_8014168C)(1) + 1;
            if ((D_8011511E & 0x5000) != 0) {
                D_8011514C = 0;
            }
        }
        *(u16 *)&D_8011515C = D_8018E4C4[D_80115128];
        if ((chg << 0x10) != 0) {
            func_80141C0C(1);
        }
    }
    return 0;
}
