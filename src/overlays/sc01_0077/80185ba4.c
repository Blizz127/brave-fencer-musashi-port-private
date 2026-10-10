/* sc01_0077: func_80185BA4 from Druthulu/BFM-decomp
 * src/ov_SC01_077/ov_SC01_077_jr_80183CF4.c (preprocessed; only the declarations it uses),
 * byte-identical to the sc01_0077 retail words (gcc-2.7.2 -O2). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;
struct A;
struct A {
    u16 unk00; u16 unk02; u16 unk04;
    u16 unk06;
    u16 unk08; u16 unk0A; u16 unk0C;
    u16 unk0E;
    u8 unk10; u8 unk11; u8 unk12;
    u8 unk13;
    u8 unk14; u8 unk15; u8 unk16;
    u8 unk17;
    s32 unk18;
};
typedef struct { u16 vx, vy, vz, pad; } SVEC;
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
extern s32 func_8004787C(s32 a0);
extern short D_800B9A02;
extern s16 D_800B9A02;
extern s32 func_8004955C(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern void func_8012B0B4(SVEC *, s32, s32);
extern void func_8012E32C(void);
extern s32 func_8004787C(s32 a0);
extern void func_8012B0B4();
extern void *func_80010A08(s32);
extern s32 func_8004955C(s32 a0, s32 a1, s32 *a2, s32 *a3);
extern s32 func_80058C6C(s32, void *);
extern void func_8012E28C(s32 arg0, s32 arg1);
extern u32 D_801D55F4[];
extern s32 D_800A651C;
extern s16 D_800B9A02;

void func_80185BA4(void* p)
{
    struct { s16 vx, vy, vz, pad; } v[4];
    u16 base[3];
    s32 buf[2];
    s32 sp40;
    s32 sp44;
    s32 A;
    s32 rs, i, ang, k, d, r;
    u32 *prim;
    func_8012E32C();
    rs = func_8004787C((*(s32 *)(p + 0x1C) * 0x800) / 30);
    base[0] = *(u16 *)(p + 6);
    base[1] = *(u16 *)(p + 0xA);
    A = (rs << 8) >> 12;
    base[2] = *(u16 *)(p + 0xE);
    ang = *(s32 *)(p + 0x1C) << 4;
    i = 0;
    do {
        func_8012B0B4((unsigned int *)buf, ang, 0x20);
        k = rs * 3 + 0x1000;
        d = buf[0];
        v[0].vx = base[0] + d;
        v[0].vy = base[1];
        v[0].vz = base[2] + (d >> 16);
        v[2].vx = base[0] + (((s16)d * k) >> 12);
        v[2].vy = base[1] - A;
        v[2].vz = base[2] + (((d >> 16) * k) >> 12);
        func_8012B0B4((unsigned int *)buf, ang + 0x2AA, 0x20);
        d = buf[0];
        v[1].vx = base[0] + d;
        v[1].vy = base[1];
        v[1].vz = base[2] + (d >> 16);
        v[3].vx = base[0] + (((s16)d * k) >> 12);
        v[3].vy = base[1] - A;
        v[3].vz = base[2] + (((d >> 16) * k) >> 12);
        prim = (u32 *)func_80010A08(0x24);
        prim[1] = D_801D55F4[i];
        prim[3] = D_801D55F4[i + 1];
        *((u8 *)prim + 7) = 0x3A;
        prim[7] = 0;
        prim[5] = 0;
        prim[0] = 0x8000000;
        r = func_8004955C((s32)&v[0], (s32)(prim + 2), &sp40, &sp44);
        func_8004955C((s32)&v[1], (s32)(prim + 4), &sp40, &sp44);
        func_8004955C((s32)&v[2], (s32)(prim + 6), &sp40, &sp44);
        func_8004955C((s32)&v[3], (s32)(prim + 8), &sp40, &sp44);
        func_80058C6C(*(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + r * 4, prim);
        func_8012E28C(r, 1);
        i++;
        ang = ang + 0x2AA;
    } while (i < 6);
}
