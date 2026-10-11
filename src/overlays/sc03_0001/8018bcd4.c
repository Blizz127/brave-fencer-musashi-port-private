/* sc03_0001: func_8018BCD4 from Druthulu/BFM-decomp
 * src/ov_SC03_001/ov_SC03_001_jr_8018B8DC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0001 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
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
typedef struct {
        u32 *ot;
        u32 pad[4];
    } Env_8018BCD4;
typedef struct { u32 addr : 24; u32 len : 8; } PTag_8018BCD4;
typedef struct { u32 w; } W_8018BCD4;
extern void func_8012A568(void (*a0)(void));
extern short D_800B9A02;
extern s16 D_800B9A02;
extern u8 D_80115138[];
extern u8 D_80115148[];
extern s16 func_8014168C(s16 a0);

s32 *func_8018BCD4(out, src, idx, w, col)
    s32 *out;
    void *src;
    s16 idx;
    void *w;
    s32 col;
{
    extern short D_800B9A02;
    extern s16 func_8014168C(s16 a0);
    extern u16 D_8011511A;
    extern u16 D_80115116;
    extern u8 D_80115138[];
    extern u8 D_80115140[];
    extern u8 D_80115148[];
    extern u8 D_80115158[];
    extern u16 D_801C11BA;
    extern u16 D_801C11CE;
    extern Env_8018BCD4 D_800AE7BC[];
    s32 c;
    s16 t;
    u16 *q;
    s32 m;
    volatile u16 *pbh;
    c = D_80115138[idx];
    ((W_8018BCD4 *)out)->w = 0x04000000;
    *((u8 *)out + 0xC) = 0x30;
    *((u8 *)out + 0xD) = 0x48;
    *(s16 *)((u8 *)out + 0xE) = 0x4056;
    out[1] = col | 0x64000000;
    if (c < 10) {
        t = ((s32 (*)(s16)) func_8014168C)(idx) * 2;
    } else {
        t = (D_80115148[idx * 2] - D_80115140[idx]) * 2;
    }
    q = (u16 *)(t * 2 + (s32)src);
    pbh = (u16 *)&D_800B9A02;
    *(s16 *)((u8 *)out + 0x8) = q[0] - 8;
    *(s16 *)((u8 *)out + 0xA) = q[1];
    *(s16 *)((u8 *)out + 0x12) = 8;
    *(s16 *)((u8 *)out + 0x10) = 8;
    ((PTag_8018BCD4 *)out)->addr =
        ((PTag_8018BCD4 *)(D_800AE7BC[*pbh].ot + 2))->addr;
    ((PTag_8018BCD4 *)(D_800AE7BC[*pbh].ot + 2))->addr = (u32)out;
    out += 5;
    if (c < 10) {
        return out;
    }
    m = D_8011511A;
    if (m == idx) {
        if ((D_80115116 & 8) != 0) {
            s16 j;
            s32 k;
            s16 y;
            s16 eight;
            u16 *pb;
            register u32 m24 __asm__("$6");
            u32 mhi;
            s32 vsum;
            j = 0;
            k = m;
            eight = 8;
            pb = (u16 *)&D_800B9A02;
            m24 = 0xFFFFFF;
            mhi = 0xFF000000;
            for (; j < 2; j++) {
                if (j == 0) {
                    if (D_80115140[k] == 0) {
                        continue;
                    }
                    *((u8 *)out + 0xD) = 0x30;
                    y = D_801C11BA - 2;
                } else {
                    s32 k2 = k * 2;
                    if ((((s8 *)D_80115158)[k2] - ((s8 *)D_80115140)[k]) < 7) {
                        continue;
                    }
                    *((u8 *)out + 0xD) = 0x38;
                    y = D_801C11CE + 1;
                }
                *(s16 *)((u8 *)out + 0xA) = y;
                __asm__("" ::: "memory");
                *(u32 *)out = 0x04000000;
                *((u8 *)out + 0xC) = 0x78;
                *(u32 *)((u8 *)out + 0x4) = 0x64808080;
                *(s16 *)((u8 *)out + 0xE) = 0x4056;
                vsum = *(s32 *)((u8 *)w + 8) + *(s32 *)((u8 *)w + 0xC) - 0xC;
                *(s16 *)((u8 *)out + 0x8) = vsum;
                *(s16 *)((u8 *)out + 0x10) = eight;
                *(s16 *)((u8 *)out + 0x12) = eight;
                *(u32 *)out = ((*(u32 *)out) & mhi) | (D_800AE7BC[*pb].ot[2] & m24);
                {
                    register u32 *op __asm__("$4");
                    op = D_800AE7BC[*pb].ot;
                    op[2] = (op[2] & mhi) | (((u32)out) & m24);
                }
                out += 5;
            }
        }
    }
    return out;
}
