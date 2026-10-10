/* sc03_0098: func_8012956C from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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
typedef struct { s32 a, b, c, d; } Blk16_956C;
typedef struct {
    u8 pad0[0x1C];
    s16 f1C;
    s16 f1E;
    u8 pad20[0x14];
    u16 f34;
    u16 f36;
    u16 f38;
    u16 f3A;
    u8 pad3C[2];
    s16 f3E;
    u16 f40;
    u16 f42;
    u8 pad44[0x10];
} Ent_956C;
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
extern s32 D_801C418C;
extern s16 D_80114EE0;
extern s16 D_80114EE0;
extern s16 D_80114EE0;
extern u8 D_800B9A78;
extern void func_801299C8();
extern s32 D_801C418C;
extern void func_801299C8();
extern void func_80015B6C(s32, s16, s32, s16, s32, s32, s32, s32, s32, s32);
extern void func_8005080C(s32 *, void *, u16, s32 *);
extern void func_80051044(s32 *, void *, u16, s32 *);
void func_801299C8();

void func_8012956C(void) {
    extern s16 D_80114EE0;
    extern u8 D_800B9A78;
    extern u8 D_801C418D[];
    extern u8 D_801C418E[];
    extern u8 D_801C4190[];
    extern u8 D_801C4191[];
    extern u8 D_801C4192[];
    extern u8 D_801C5828;
    extern u8 D_800AF630[];
    extern u8 D_800A6518[];
    s32 *sp10;
    u8 *afbase;
    s32 *sp0;
    Ent_956C *base;
    s32 i;
    s16 a1;
    register u32 temp_a3 __asm__("$7");
    register u32 arg0 __asm__("$4");
    u32 s;
    register u32 s2 __asm__("$3");
    u32 t6;
    s32 code;
    sp10 = (s32 *)0x1F800010;
    sp0 = (s32 *)0x1F800000;
    afbase = (u8 *)&D_800AF630;
    if (D_80114EE0 == 0) {
        return;
    }
    base = (Ent_956C *)&D_800B9A78;
    i = 0;
    do {
        s32 idx = i * 8 + 4;
        code = base->f34;
        if (code == 0x7FFE) {
            goto case_7FFE;
        }
        if (code < 0x7FFF) {
            a1 = i + 3;
            if (code == 0x7FFD) {
                goto case_7FFD;
            }
            goto do_default;
        }
        a1 = i + 3;
        if (code != 0x7FFF) {
            goto do_default;
        }
        goto next;
    case_7FFD:
        if (i == 0) {
            func_801299C8(D_801C5828, 1, base);
        }
        func_80015B6C(-0xA0, -0x74, 0x140, 0x8C,
                      D_801C4190[0], D_801C4190[1], D_801C4190[2],
                      D_801C4190[4], D_801C4190[5], D_801C4190[6]);
        func_80015B6C(-0xA0, 0x18, 0x140, 0x3C,
                      D_801C4190[4], D_801C4190[5], D_801C4190[6],
                      D_801C4190[8], D_801C4190[9], D_801C4190[0xA]);
        func_80015B6C(-0xA0, 0x54, 0x140, 0x28,
                      D_801C4190[8], D_801C4190[9], D_801C4190[0xA],
                      D_801C4190[0xC], D_801C4190[0xD], D_801C4190[0xE]);
        goto next;
    case_7FFE:
        func_801299C8(D_801C5828, (s16)(i * 2), base);
        func_80015B6C(-0xA0, *(s16 *)&base->f3A, 0x140, base->f3E,
                      ((u8 *)&D_801C418C)[idx], D_801C418D[idx], D_801C418E[idx],
                      D_801C4190[idx], D_801C4191[idx], D_801C4192[idx]);
        goto next;
    do_default:
        __asm__("");
        arg0 = D_801C5828;
        s = base->f40;
        temp_a3 = base->f38;
        s += temp_a3;
        base->f1C = s;
        s2 = base->f42;
        t6 = base->f3A;
        s2 += t6;
        base->f1E = s2;
        ((void (*)(s32, s32, void *, s32))func_801299C8)(arg0, a1, base, temp_a3);
        *(Blk16_956C *)sp0 = *(Blk16_956C *)base;
        {
            s32 *dst = sp10;
            s32 *src = (s32 *)((u8 *)base + 0x10);
            s32 *end = (s32 *)((u8 *)base + 0x30);
            do {
                *(Blk16_956C *)dst = *(Blk16_956C *)src;
                src += 4;
                dst += 4;
            } while (src != end);
            *dst = *src;
            sp10[5] = (s32)sp0;
            if (base->f36 == 0) {
                func_80051044(sp10, &D_800A6518[(*(u16 *)(afbase + 0xA3D2)) * 0x14], base->f34, dst);
            } else {
                func_8005080C(sp10, &D_800A6518[(*(u16 *)(afbase + 0xA3D2)) * 0x14], base->f34, dst);
            }
        }
    next:
        base += 1;
        i += 1;
    } while (i < 2);
}
