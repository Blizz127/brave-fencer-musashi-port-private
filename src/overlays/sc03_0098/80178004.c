/* sc03_0098: func_80178004 from Druthulu/BFM-decomp
 * src/ov_SC03_098/ov_SC03_098_jr_801734BC.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc03_0098 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef unsigned int uint;
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
extern u32 func_801783D0(s32, s32);
extern s16 D_8011F81E;
extern u32 func_801783D0(s32 a0, s32 a1);
extern u32 func_801783D0(s32 a0, s32 a1);
extern u32 func_801783D0(s32 a0, s32 a1);
extern u32 func_801783D0(s32 a0, s32 a1);
extern u32 func_801783D0(s32 a0, s32 a1);
u32 func_801783D0(s32 a0, s32 a1);

s32 func_80178004(uint *param_1, uint param_2, int param_3)
{
    extern short D_8011F81E;
    register uint *p __asm__("$18");
    register uint p2 __asm__("$17");
    uint u6;
    uint mask;
    uint c74;
    uint q0;
    p = param_1;
    p2 = param_2;
    u6 = param_3 << 0x10;
    q0 = 0x6d165828;
    mask = 0xffffff;
    c74 = 0x74808080;
    {
        p[0] = ((uint)(p + -5) & mask) | 0x3000000;
        p[1] = c74;
        p[2] = u6 | (p2 & 0xffff);
        p[3] = q0;
        p += 5;
    }
    {
        uint q;
        q = 0x6d160048;
        p[0] = ((uint)(p + -5) & mask) | 0x3000000;
        p[1] = c74;
        p[2] = u6 | ((p2 + 7) & 0xffff);
        p[3] = q;
        p += 5;
    }
    {
        uint q;
        q = 0x6d160818;
        p[0] = ((uint)(p + -5) & mask) | 0x3000000;
        p[1] = c74;
        p[2] = u6 | ((p2 + 0xd) & 0xffff);
        p[3] = q;
        p += 5;
    }
    {
        uint q;
        q = 0x6d160028;
        p[0] = ((uint)(p + -5) & mask) | 0x3000000;
        p[1] = c74;
        p[2] = u6 | ((p2 + 0x13) & 0xffff);
        p[3] = q;
        p += 5;
    }
    {
        uint q;
        q = 0x6d160020;
        p[0] = ((uint)(p + -5) & mask) | 0x3000000;
        p[1] = c74;
        p[2] = u6 | ((p2 + 0x19) & 0xffff);
        p[3] = q;
        p += 5;
    }
    {
        uint q;
        q = 0x6d164058;
        p[0] = ((uint)(p + -5) & mask) | 0x3000000;
        p[1] = c74;
        p[2] = u6 | ((p2 + 0x3a) & 0xffff);
        p[3] = q;
        p += 5;
    }
    {
        uint uVar1;
        register uint *q __asm__("$4");
        register uint *r __asm__("$5");
        int iVar4;
        register uint uVar5 __asm__("$9");
        uint base6;
        uint m2;
        uint c3b;
        int two;
        int ff;
        int a0arg;
        a0arg = 100 - (D_8011F81E * 0xa198 >> 0x10);
        {
            uint ret;
            ret = ((uint (*)(int, int))func_801783D0)(a0arg, 4);
            q = p;
            uVar1 = ret;
        }
        p2 = p2 + 0x22;
        base6 = 0x6d160000;
        uVar5 = 0x1000000;
        iVar4 = 0;
        two = 2;
        ff = 0xff;
        m2 = 0xffffff;
        c3b = 0x3000000;
        r = q + 3;
        {
        int nx;
        do {
            register uint uVar2 __asm__("$6");
            register uint c74v __asm__("$3");
            register uint rval __asm__("$2");
            uint t;
            t = (uVar1 << 16) >> 28;
            uVar2 = t;
            if (t != 0) {
                uVar5 = 0;
            } else if ((short)iVar4 == two) {
                uVar5 = 0;
            } else if ((short)iVar4 == ff) {
                uVar5 = 0;
            }
            c74v = 0x74808080;
            q[0] = ((uint)(q + -5) & m2) | c3b;
            r[-1] = u6 | (p2 & 0xffff) | uVar5;
            __asm__ __volatile__("" : : "r"(uVar2));
            rval = (uVar2 * 8 + 8) | 0x4000;
            rval = base6 | rval;
            r[-2] = c74v;
            r[0] = rval;
            r = r + 5;
            q = q + 5;
            p2 = p2 + 8;
            nx = iVar4 + 1;
            iVar4 = nx;
            __asm__ __volatile__("" : "=r"(nx) : "0"(nx));
            uVar1 = uVar1 << 4;
        } while (nx * 0x10000 >> 0x10 < 3);
        }
        return q;
    }
}
