/* sc03_0098: func_8013EF88 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_8013C98C.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
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
typedef struct { s32 f0; } E4;
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
extern unsigned short D_80115112;
extern u16 D_80115124;
extern s32 D_80115188;
extern s16 D_80186698;
extern s16 D_8018669A;
extern unsigned short D_80115112;
extern void func_8013FAF8(s16 a0, s16 a1);
extern short D_800B9A02;
extern s32 D_801151D0;
extern unsigned short D_80115112;
extern void func_8013FAF8(s16 a0, s16 a1);
extern short D_800B9A02;
extern s32 D_801151D0;
extern unsigned short D_80115112;
extern void func_8013FAF8(s16 a0, s16 a1);
extern short D_800B9A02;
extern s32 D_801151D0;
extern u16 D_80115112;
extern short D_800B9A02;
extern unsigned short D_80115112;
extern s32 D_801151D0;
extern s16 D_80186698;
extern s16 D_8018669A;
extern void func_8013FAF8(s16 a0, s16 a1);
extern s16 D_800B9A02;
extern s32 D_801151D0;
extern E4 aD80115188[] __asm__("D_80115188");
extern u16 D_80115124;
extern u16 D_80115112;
extern s16 D_8018669A;
extern s16 D_80186698;
extern void func_8013FAF8(s16 a0, s16 a1);
extern s32 func_800D0488(s16 a0);
extern void func_800D2624(void);

void func_8013EF88(void)
{
    extern u16 D_80115118;
    extern E4 D_80115168[];
    extern u16 D_80115114;
    u16 *p = &D_80115118;
    u16 old = *p;
    short i;
    if (old != 0) {
        u16 nw = old - 1;
        *p = nw;
        if (nw != 0) {
            D_801151D0 = *(s32 *)((char *)&D_80115118 + 0xB0 + (u16)D_800B9A02 * 4);
            func_8013FAF8(0, 5);
            for (i = 0; i < 5; i++) {
                s32 t = aD80115188[i].f0 * 3;
                aD80115188[i].f0 = t;
                D_80115168[i].f0 = D_80115168[i].f0 + t;
            }
            if (D_80115118 < 3) {
                u16 *s = &(*(u16 *)&D_8018669A);
                *s -= 1;
            }
            {
                u16 *w = &(*(u16 *)&D_80186698);
                *w -= 2;
                if ((s16)*w < 0) {
                    *w = 0;
                }
            }
        }
    }
    {
        s16 *pv = &(*(s16 *)&D_80115124);
        if (*pv != 0) {
            if (func_800D0488(*pv) == 0) return;
            *pv = 0;
        }
    }
    if (D_80115118 == 0) {
        if (D_80115114 == ((u16)D_800B9A02 ^ 1)) {
            func_800D2624();
        } else {
            D_80115112 += 1;
        }
    }
}
