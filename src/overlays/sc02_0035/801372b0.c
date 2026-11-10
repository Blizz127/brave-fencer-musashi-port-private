/* SC02.CD member35: func_801372B0 from Druthulu/BFM-decomp
 * src/ov_SC02_035/ov_SC02_035_jr_80135D20.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc02_0035 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef struct { s16 vx, vy, vz, pad; } Svec_801372B0;
typedef struct { u32 attr; s16 x0, y0, x1, y1; u8 r, g, b, code; } Gline_801372B0;
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
extern u8 D_800B9A11;
extern u8 D_800AF630[];
extern void *memcpy(void *, const void *, unsigned int);
extern void func_8012A568(void (*a0)(void));
extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_800B9A02;
extern void *memcpy(void *, const void *, u32);
extern void func_8005C324(int dst, int src, int n) __asm__("memcpy");
extern s16 D_800B9A02;
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
void func_80137030(s16 a0, s16 a1);
extern u8 D_800A6518[];
extern void func_80051DC8(void *a0, void *a1, s32 a2);
void func_80137178(s32 a0, s32 a1);
extern void func_80048FBC(void *m, Svec_801372B0 *in, Svec_801372B0 *out);
extern void aGsSortLine(Gline_801372B0 *p, void *ot, s32 z) __asm__("func_80051DC8");
extern void aF80137030(s32 x, s32 y) __asm__("func_80137030");
extern void func_80137178(s32 x, s32 y);
extern u8 D_800B9A11;
extern u8 D_800AF630[];
extern u16 aD800B9A02 __asm__("D_800B9A02");
extern u8 D_800A6518[];

void func_801372B0(void) {
    Svec_801372B0 in;
    Svec_801372B0 out;
    Gline_801372B0 prim;
    register u8 *mat __asm__("$23") = D_800AF630;
    s32 white;
    s16 ax;
    s16 ay;
    s16 bx;
    register s16 by __asm__("$20");
    in.vz = 0;
    in.vy = 0;
    in.vx = 0;
    if (D_800B9A11 != 1) {
        mat += 0x18;
        white = 0xFF;
        in.vx = 0x10;
        func_80048FBC(mat, &in, &out);
        {
            s16 vx = out.vx;
            s16 vy = out.vy;
            prim.attr = 0;
            prim.r = white; prim.g = white; prim.b = white;
            prim.x0 = 0x78;
            prim.y0 = -0x5A;
            { s16 x1v = vx + 0x78; prim.x1 = x1v; }
            { s16 y1v = vy - 0x5A; prim.y1 = y1v; }
            aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        }
        in.vx = in.vx + 6;
        func_80048FBC(mat, &in, &out);
        prim.attr = 0;
        prim.r = white; prim.g = 0; prim.b = 0;
        bx = out.vy;
        ay = out.vx;
        by = bx - 0x5D;
        ax = ay + 0x7B;
        bx = bx - 0x57;
        {
        Gline_801372B0 *op = (Gline_801372B0*)&D_800A6518[(u32)aD800B9A02 * 0x14];
        __asm__("" : "=r"(op) : "0"(op));
        ay = ay + 0x75;
        prim.x0 = ay; prim.y0 = by; prim.x1 = ax; prim.y1 = bx;
        aGsSortLine(&prim, op, 0);
        }
        __asm__("" : "=r"(ax) : "0"(ax));
        __asm__("" : "=r"(by) : "0"(by));
        prim.attr = 0;
        prim.r = white; prim.g = 0; prim.b = 0;
        prim.x0 = ax; prim.y0 = by; prim.x1 = ay; prim.y1 = bx;
        aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        in.vx = 0;
        in.vy = 0x10;
        func_80048FBC(mat, &in, &out);
        {
            register s16 vx __asm__("$7") = out.vx;
            s16 vy = out.vy;
            prim.x0 = 0x78;
            prim.attr = 0;
            prim.r = white; prim.g = white; prim.b = white;
            prim.y0 = -0x5A;
            { s16 x1v = vx + 0x78; prim.x1 = x1v; }
            { s16 y1v = vy - 0x5A; prim.y1 = y1v; }
            aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        }
        in.vy = in.vy + 6;
        func_80048FBC(mat, &in, &out);
        aF80137030((s32)(s16)(out.vx + 0x78), (s32)(s16)(out.vy - 0x5A));
        in.vy = 0;
        in.vz = 0x10;
        func_80048FBC(mat, &in, &out);
        {
            s16 vx = out.vx;
            s16 vy = out.vy;
            prim.x0 = 0x78;
            prim.attr = 0;
            prim.r = white; prim.g = white; prim.b = white;
            prim.y0 = -0x5A;
            { s16 x1v = vx + 0x78; prim.x1 = x1v; }
            { s16 y1v = vy - 0x5A; prim.y1 = y1v; }
            aGsSortLine(&prim, &D_800A6518[(u32)aD800B9A02 * 0x14], 0);
        }
        in.vz = in.vz + 6;
        func_80048FBC(mat, &in, &out);
        func_80137178((s32)(s16)(out.vx + 0x78), (s32)(s16)(out.vy - 0x5A));
    }
    return;
}
