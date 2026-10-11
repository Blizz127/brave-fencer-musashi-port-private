/* sc03_0001: func_801775E0 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_801734BC.c (preprocessed; only the declarations it uses),
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
extern void func_8012A568(void (*a0)(void));
extern u8 D_8011F837;
extern u8 D_8011F7F0;
extern u8 D_8011F83B;
extern u8 D_8011F837;
extern u8 D_8011F7F0;
extern void func_801776EC(u8 *a0);
void func_801776EC(u8 *a0);

void func_801775E0(s32 param_1, s32 param_2) {
    s32 s0 = param_1;
    s32 pp = param_2;
    u8 *base = &D_8011F7F0;
    s16 sVar1; s32 t; s32 v;
    s32 c = D_8011F83B;
    if (c != 0) {
        if (c < 0) goto store;
        if (c >= 0xf7) goto store;
        if (c < 0xf3) goto store;
        goto docall;
    }
    if (D_8011F837 != 0x80) {
        *(u8 *)(s0 + 4) = 0xff;
        *(u8 *)(s0 + 6) = 0x10;
        *(u8 *)(s0 + 5) = 0x10;
        goto L684;
    }
    func_801776EC((u8 *)s0);
    goto L684;
docall:
    func_801776EC((u8 *)s0);
    goto L684;
store:
    *(u8 *)(s0 + 5) = 0xff;
    *(u8 *)(s0 + 6) = 0x10;
    *(u8 *)(s0 + 4) = 0x10;
L684:
    sVar1 = (s16)((u32)(base[0x47] * 9) >> 4);
    t = pp + 0x48;
    *(s16 *)(s0 + 0xe) = sVar1;
    *(s16 *)(s0 + 0xa) = t - sVar1;
    if (base[0x47] != 0) { s0 = param_1 + 0x14; v = 0xa0; } else { s0 = param_1 + 0x14; v = 0x40; }
    *(u8 *)(s0 + 6) = v;
    *(s16 *)(s0 + 0xa) = pp;
}
