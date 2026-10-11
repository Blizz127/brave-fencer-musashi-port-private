/* sc03_0001: func_8018AEE8 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018A3A8.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
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
extern void func_8002D4C8(s32 arg0, s32 arg1);
extern u8 D_80115138[];
extern void func_8002D4C8(s32 a0, s32 a1);
extern s16 func_8014168C(s16 a0);
extern s32 func_8018C000(s32 a0, s16 a1);
extern s16 func_8014168C(s16 a0);
extern void func_8002D4C8(s32 a0, s32 a1);

s32 func_8018AEE8(void) {
    extern s32 func_80014ED4(s32 a0);
    extern s32 func_80015018(s32 a0);
    extern s16 func_8014168C(s16 a0);
    extern s32 func_8018C000(s32 a0, s16 a1);
    extern void func_8002D4C8(s32 a0, s32 a1);
    extern void func_801898E4(void);
    extern s32 D_801EF1E0;
    extern u16 D_8011511A;
    extern u16 D_80115120;
    extern u16 D_80115122;
    extern u8 D_80115138[];
    extern u8 D_80115140[];
    extern u8 D_8011514E;
    extern u8 D_80115143;
    s32 flags;
    s32 pad;
    s16 effectVal;
    s32 byteVal;
    s16 changed;
    u16 *p;
    u8 *pcur;
    u8 *pmax;
    s16 ret;
    s32 v;
    u8 b;
    u8 bb;
    u8 m;
    s16 d;
    register s32 zr __asm__("$0");
    changed = 0;
    flags = func_80014ED4(0);
    if ((u16)flags != 0) {
        D_801EF1E0 = 0;
    }
    pad = func_80015018(0);
    p = &D_8011511A;
    effectVal = func_8014168C(*(s16 *)p);
    byteVal = D_80115138[*p];
    if (flags & 0x40) {
        ret = func_8018C000(byteVal, effectVal);
        {
            s16 ret2 = ret;
            return ret & -(ret2 != 0);
        }
    } else if (flags & 0x10) {
        pad = byteVal + zr;
        if (pad < 7) {
            return -1;
        }
        func_8002D4C8(0x473, 0);
        if (pad != 0xD) {
            *p = 0;
        } else {
            *p = 1;
        }
        return 0;
    } else {
        pcur = (u8 *)&D_8011511A + (*p * 2 + 0x2E);
        pmax = (u8 *)&D_8011511A + (*p * 2 + 0x3E);
        if ((u16)pad != 0) {
            if ((u16)pad == D_80115120) {
                if (--D_80115122 == 0) {
                    flags = pad & 0xF000;
                    D_80115122 = 3;
                }
            } else {
                D_80115120 = pad;
                D_80115122 = 8;
            }
        } else {
            D_80115120 = 0;
            D_80115122 = 0xC;
        }
        if (flags & 0x1000) {
            v = pcur[0] - 1;
            pcur[0] = v;
            changed = 1;
            if ((u8)v >= 0x80) {
                if (byteVal < 10) {
                    pcur[0] = pmax[0] - 1;
                } else {
                    pcur[0] = 0;
                    changed = 0;
                }
            }
        }
        if (flags & 0x4000) {
            b = pcur[0];
            v = b + 1;
            pcur[0] = v;
            changed = 1;
            if ((u8)v >= pmax[0]) {
                if (byteVal < 10) {
                    pcur[0] = 0;
                } else {
                    pcur[0] = b;
                    changed = 0;
                }
            }
        }
        if (byteVal == 7 || byteVal == 8) {
            if (flags & 0x8000) {
                v = pcur[1] - 1;
                pcur[1] = v;
                changed = 1;
                if ((u8)v > 0x7F) {
                    pcur[1] = pmax[1] - 1;
                }
            }
            if (flags & 0x2000) {
                v = pcur[1] + 1;
                pcur[1] = v;
                changed = 1;
                if (pmax[1] <= (u8)v) {
                    pcur[1] = 0;
                }
            }
        } else {
            u16 idx2;
            bb = pcur[0];
            idx2 = D_8011511A;
            m = D_80115140[idx2];
            d = (s8)bb - (s8)m;
            if (d >= 6) {
                D_80115140[idx2] = bb - 5;
            } else if (d < 0) {
                D_80115140[idx2] = bb;
            }
        }
        if (changed != 0) {
            func_8002D4C8(0x45A, 0);
            if (byteVal + zr == 0xC) {
                D_8011514E = 0;
                D_80115143 = 0;
                func_801898E4();
            }
        }
        return 0;
    }
}
