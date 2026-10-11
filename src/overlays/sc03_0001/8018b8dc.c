/* sc03_0001: func_8018B8DC from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
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
extern s32 func_800291B4(s32 arg);
extern void func_8012A568(void (*a0)(void));
extern s16 D_80115126;
extern u8 D_80115148[];
extern void func_80139A68(s32 a0, u16 a1);
void *func_8018C89C(s32 a0);

s32 func_8018B8DC(s32 param_1, s32 param_2) {
    extern void *func_8018C89C(s32 a0);
    extern u8 D_801117EC[];
    extern u8 * D_801EF1D4;
    extern u8 * D_801EF1DC;
    extern u8 D_801EF298[];
    extern u8 D_8018E5C0[];
    extern void * D_8018E680[];
    extern void * D_801EB58C[];
    extern void * D_801C17B4[];
    extern void * D_801C17D0[];
    extern s32 * D_801EF254[];
    extern s16 D_8010EDEE;
    extern u8 D_8010EDF2;
    extern s16 D_800A6586[];
    extern u8 D_801F0700[];
    extern u8 D_801F0B80[];
    extern u8 D_801F44B4[];
    extern u8 D_801F44E0[];
    extern u8 D_801F44F8[];
    extern u8 D_801F4524[];
    void *result;
    result = D_801117EC;
    switch ((short)param_1) {
    case 10:
        if (D_80115126 != 5) {
            result = D_8018E680[D_801EF1D4[(short)param_2]];
        } else {
            result = D_801C17B4[(short)param_2];
        }
        break;
    case 7: {
        s32 t = func_800291B4(D_8018E5C0[(short)param_2]) & 0xFF;
        if (t != 0) {
            s32 idx = t * 0xC;
            if (*(s16 *)((u8 *)&D_8010EDEE + idx) != 0 &&
                D_80115126 == *((u8 *)&D_8010EDF2 + idx)) {
                result = func_8018C89C(((short)param_2 & 3) + 6);
                func_80139A68(*(s16 *)((u8 *)&D_8010EDEE + idx), 0);
            } else {
                result = func_8018C89C(5);
            }
        }
        break;
    }
    case 8:
        if (D_80115148[0] != 0) {
            s32 t = func_800291B4(D_8018E5C0[(short)param_2]) & 0xFF;
            if (t != 0) {
                s32 idx = t * 0xC;
                if (*(s16 *)((u8 *)&D_8010EDEE + idx) != 0 &&
                    D_80115126 == *((u8 *)&D_8010EDF2 + idx)) {
                    result = func_8018C89C(((short)param_2 & 3) + 6);
                    func_80139A68(*(s16 *)((u8 *)&D_8010EDEE + idx), 0);
                } else {
                    result = func_8018C89C(5);
                }
            }
        } else {
            s32 t = func_800291B4(D_8018E5C0[(short)param_2]) & 0xFF;
            if (t != 0) {
                result = D_8018E680[t];
            }
        }
        break;
    case 13: {
        s32 e = D_801EF1DC[(short)param_2];
        if ((func_800291B4(e + 0x62) & 0x80) != 0) {
            result = D_801EB58C[e];
        }
        break;
    }
    case 14: {
        u8 v = D_801EF298[(short)param_2];
        if (v != 0xFF) {
            s32 code;
            v = v + 1;
            code = v + 0x62;
            if ((func_800291B4(code) & 0xF0) == 0xC0) {
                result = func_8018C89C(((short)param_2 & 1) | 6);
                func_80139A68((s16)(D_800A6586[v] * 9 / 10), 0);
            } else if ((func_800291B4(code) & 0xF0) == 0xE0) {
                result = D_801F0700;
            }
        }
        break;
    }
    case 11:
        if (D_80115126 == 4) {
            if (D_80115148[0] == 0) {
                result = D_801F44B4;
                if (D_801EF254[(short)param_2] == 0) {
                    result = D_801C17D0[(short)param_2];
                }
            } else {
                s32 *p = D_801EF254[(short)param_2];
                if (p != 0) {
                    result = D_801F4524;
                    if (p[1] != 0) {
                        result = D_801F44F8;
                    }
                } else {
                    result = D_801F44E0;
                }
            }
        } else {
            if (D_801EF254[(short)param_2] != 0) {
                result = D_801F0B80;
            }
        }
        break;
    default:
        result = func_8018C89C(0);
        break;
    }
    return (s32)result;
}
