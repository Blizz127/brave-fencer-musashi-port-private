/* sc03_0098: func_80136824 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
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
extern void *memcpy(void *, const void *, unsigned int);
extern u8 D_80126720[];
extern u8 D_801152A8[];
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern void memcpy();
extern u8 D_801858B4;
extern u8 D_801858B0;
extern s16 *D_801858B8;
extern u8 D_801858BC;
extern u8 D_801858B0;
extern u8 D_801858B4;
extern s16 *D_801858B8;
extern u8 D_801858BC;
extern u8 D_80126720[];
extern u8 D_801858B4;
extern u8 D_801858B0;
extern s16 *D_801858B8;
extern u8 D_801858BC;
extern u8 D_80126720[];

s32 func_80136824(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 D_801152A8[];
    extern s16 D_801152AA;
    extern s16 D_801152AC;
    extern s16 D_80126722;
    extern s16 D_80126724;
    u16 *ac;
    s16 *b8;
    s16 *b4;
    s32 r;
    register s32 pos __asm__("$12");
    register s32 a1v __asm__("$5");
    s16 temp_v0;
    s16 temp_v1;
    s32 var_a3;
    s16 var_v0_3;
    s32 temp_a1;
    s32 var_t0;
    s32 var_v1;
    s16 *b4b;
    u16 *p;
    __asm__ ("" : "=r"(a1v) : "0"(arg1));
    pos = arg2;
    if (!(a1v & 1)) {
        var_t0 = (s16) arg2 - (*(s16 **)&D_801858B0)[1];
        var_v1 = var_t0;
        var_a3 = -(*(s16 **)&D_801858BC)[1];
    } else {
        var_a3 = (*(s16 **)&D_801858BC)[1];
        var_v1 = (*(s16 **)&D_801858B0)[1] - (s16) arg2;
        var_t0 = -var_v1;
    }
    b8 = (*(s16 **)&D_801858BC);
    ac = (*(u16 **)&D_801858B0);
    b4 = D_801858B8;
    temp_a1 = -var_v1;
    r = (temp_a1 * b8[0]) / var_a3;
    b4[0] = ac[0] + r;
    b4[1] = ac[1] + var_t0;
    r = (temp_a1 * b8[2]) / var_a3;
    temp_v0 = ac[2] + r;
    b4[2] = temp_v0;
    temp_v1 = b4[0];
    if (temp_v1 < (*(s16 *)((s8 *)(((void *)arg0)) + (4)))) {
        return 0;
    }
    if ((*(s16 *)((s8 *)(((void *)arg0)) + (6))) < temp_v1) {
        return 0;
    }
    if (temp_v0 < (*(s16 *)((s8 *)(((void *)arg0)) + (0xC)))) {
        return 0;
    }
    if ((*(s16 *)((s8 *)(((void *)arg0)) + (0xE))) < temp_v0) {
        return 0;
    }
    if (arg1 & 0x8000) {
        p = (*(u16 **)&D_801858B4);
        b4[0] = (s16) p[0];
        b4[2] = (s16) p[2];
    }
    D_801152AC = 0;
    (*(s16 *)D_801152A8) = 0;
    if (arg1 & 1) {
        b4b = D_801858B8;
        D_801152AA = 0xFFF;
        __asm__ __volatile__("");
        var_v0_3 = pos + 2;
    } else {
        b4b = D_801858B8;
        D_801152AA = -0xFFF;
        __asm__ __volatile__("");
        var_v0_3 = pos - 2;
    }
    b4b[1] = var_v0_3;
    __asm__ __volatile__("" :: "r"(pos));
    (*(s16 *)D_80126720) = (s16) ((s32) ((*(s16 *)((s8 *)(((void *)arg0)) + (4))) + (*(s16 *)((s8 *)(((void *)arg0)) + (6)))) >> 1);
    D_80126722 = (s16) ((s32) ((*(s16 *)((s8 *)(((void *)arg0)) + (8))) + (*(s16 *)((s8 *)(((void *)arg0)) + (0xA)))) >> 1);
    D_80126724 = (s16) ((s32) ((*(s16 *)((s8 *)(((void *)arg0)) + (0xC))) + (*(s16 *)((s8 *)(((void *)arg0)) + (0xE)))) >> 1);
    return 1;
}
